/*
 * -----------------------------------------------------------
 * Autor		Joschka Randerath
 * Funktion		UART-Kommuniktion steuern
 * Version		4.0
 * Datum		09.06.2021
 * -----------------------------------------------------------
 */
 
 #include "UART.h"



#include "iodefine.h"


#include "r_system.h"
#include <machine/_default_types.h>


extern uint8_t	UART_AKTIV_HANDLER	= 0;			// Flag, um UART State Maschine zu aktivierem
				SDO_REQ_FLAG = 0,					// Flag ob eine SDO-Request bearbeitet werden soll (dann 0xff)
				SDO_IND_FLAG = 0,					// Flag, ob die SDO-Request vom EC-Master an den UART Slave weitergeleitet wurde (Indication)
				SDO_RES_FLAG = 0,					// Flag, ob Antowort vom UART-Slave auf die SDO-Request erhalten
				SDO_TIMEOUT = 0;					// Flag, ob wartezeit auf SDO-Antwort größer als die Timeoutzeit (UART_TIMEOUT), wird erst im nächsten Sendezyklus resettet

extern uint16_t controlword = 0,					// Controlword from EtherCAT Master
				statusword = 0;						// Statusword from UART Slave 

extern uint32_t	targetPosition 		= 0, 			// Target Position from EchterCAT Master
				targetVelocity		= 0,			// Target Velocity from EchterCAT Master
				actuellePosition 	= 0,			// Aktuelle Position vom UART Slave
				actuelleVelocity	= 0,			// Aktuelle Velocity vom UART Slave 
				headerSDO		 	= 0,			// SDO Header (xzy [1], Index [2], Subindex [1])
				sdoData				= 0,			// SDO Data
				sdo_res_data		= 0;			// Daten der Antwort vom UART Slave


/*
* Function Name: initUartModul
* Description  : Funktion initialisiert die UART Funktionen inkl. der Pins
*/
void initUartModul(void)
{
    asm("isb");

    /* Enable writing to registers related to operating modes, LPC, CGC and ATCM */
    SYSTEM.PRCR.LONG = 0x0000A50BU;

    /* Enable writing to MPC pin function control registers */
    MPC.PWPR.BIT.B0WI = 0U;
    MPC.PWPR.BIT.PFSWE = 1U;


    // Set peripheral settings
    initUartIO();

    createCmt1();

    creatUartCh1();

    /* Disable writing to MPC pin function control registers */
    MPC.PWPR.BIT.PFSWE = 0U;
    MPC.PWPR.BIT.B0WI = 1U;

    /* Enable protection */
    SYSTEM.PRCR.LONG = 0x0000A500U;
    asm("isb");
}

/*
* Function Name: initUartIO
* Description  : Funktion configuriert die Pinne der UART Kommunikation
*/
void initUartIO(void)
{
    // Set TXD1 pin, PORT72
    MPC.P72PFS.BYTE |= 0x0AU;
    PORT7.PDR.WORD |= 0b11 << 4;			// PDR -> Port direction Register (0b11 Output)
    PORT7.PMR.BYTE |= 0x04U;				// PMR -> Port mode register (0b1, PIN als IO Port nutzen)

    // Set RXD1 pin, PORT73
    MPC.P73PFS.BYTE |= 0x0AU;
    PORT7.PDR.WORD |= 0b11 << 6;			// PDR -> Port direction Register (0b10 Input)
    PORT7.PMR.BYTE |= 0x08U;				// PMR -> Port mode register (0b1, PIN als IO Port nutzen)

	// Set P25 als Ausgang
    PORT2.PDR.WORD |= 0b11 << 10;			// PDR -> Port direction Register (0b11 Output)
    PORT2.PMR.BYTE &= ~(1<<5);				// PMR -> Port mode register (0b1, PIN als IO Port nutzen)	
    PORT2.PODR.BYTE &= ~(1 << 5);			// PODR -> Port output data register (Setze DE auf Low) 
}



/*
* Function Name: createCmt1
* Description  : This function initializes the CMT1 channel.
*/
void createCmt1(void)
{
    // Set Compar match control registers
	CMT1.CMCR.WORD = _CMT_CMCR_CKS_PCLK512;			// Set Clock select to 512 , d.h Zählerclock  75/512 MHz

    CMT1.CMCOR = _CMT_CMCOR_MAX_VALUE;				// Maximaler Zaehlerwert

    /*
     * Zykluszeit = (CMCOR + 1) * Clockselectwert / 75 MHz
     *
     * Bei CKS = 512 und CMCOR = 2^16 - 1 ergibt sich eine Zaehlermaximalzeit von
     * 		-> ca. 450 ms
     */
}


/*
* Function Name: startCmt1
* Description  : This function starts the CMT1 channel counter.
*/
void startCmt1(void)
{
    /* Start CMT1 count */
    CMT.CMSTR0.BIT.STR1 = 1U;
}


/*
* Function Name: stopCmt1
* Description  : This function stops the CMT1 channel counter.
*/
void stopCmt1(void)
{
    /* Stop CMT0 count */
    CMT.CMSTR0.BIT.STR1 = 0U;
}


/*
* Function Name	: creatUartCh1
* Description  	: This function initializes SCIFA1.
* Author		: Joschka Randerath
*/
void creatUartCh1(void)
{
    uint32_t w_count;

    /* Cancel SCIFA1 module stop state */
    MSTP(SCIFA1) = 0U;



    // Clear transmit/receive enable bits
    SCIFA1.SCR.BIT.TE = 0U;							// Data transmission is disable
    SCIFA1.SCR.BIT.RE = 0U;							// Data reception is disable

    // Reset transmit/receive FIFO data register operation
    SCIFA1.FCR.BIT.TFRST = 1U;						// Reset the FTDR register
    SCIFA1.FCR.BIT.RFRST = 1U;						// Reset the FRDR register

    // Read and clear status flags
    SCIFA1.FSR.WORD = 0x00U;						// Reset Serial Status register
    SCIFA1.LSR.BIT.ORER = 0U;						// Reset Overrun error Flag

    // Set clock enable bits
    SCIFA1.SCR.WORD = _SCIF_INTERNAL_SCK_UNUSED;	// Reset serial control register -> no communication

    // Set transmission/reception format (1 Stobit, 8 Nutzbit, keine Parity etc)
    SCIFA1.SMR.WORD = _SCIF_CLOCK_SERICLK | _SCIF_STOP_1 | _SCIF_PARITY_DISABLE | _SCIF_DATA_LENGTH_8 |
                      _SCIF_ASYNCHRONOUS_MODE;


    // Set Serial extended mode Register (LSB first etc)
    SCIFA1.SEMR.BYTE = _SCIF_8_BASE_CLOCK | _SCIF_NOISE_FILTER_DISABLE | _SCIF_DATA_TRANSFER_LSB_FIRST |
                       _SCIF_BAUDRATE_DOUBLE;

    /* Clear modulation duty register select */
    SCIFA1.SEMR.BIT.MDDRS = 0U;

    // Set bit rate
    SCIFA1.BRR_MDDR.BRR = 0x1U;


    /* Wait for at least 1-bit interval */
    for (w_count = 0U; w_count < _SCIF_1BIT_INTERVAL_1; w_count++)
    {

    }

    // Set FIFO trigger conditions
    SCIFA1.FTCR.WORD = _SCIF_TX_FIFO_TRIGGER_NUM_0 | _SCIF_TX_TRIGGER_TFTC_VALID | _SCIF_RX_FIFO_TRIGGER_NUM_1 |
                       _SCIF_RX_TRIGGER_RFTC_VALID;


    // Reset the FIFO control register -> Set modem control enalbe (MCE)
    SCIFA1.FCR.WORD = _SCIF_LOOPBACK_DISABLE | _SCIF_MODEM_CONTROL_DISABLE;

    /* Disable transmit/receive FIFO data register reset operation */
    SCIFA1.FCR.BIT.TFRST = 0U;		// transmit FIFO data register reset -> normal mode (dont reset)
    SCIFA1.FCR.BIT.RFRST = 0U;		// receive FIFO data register reset -> normal mode (dont reset)
}





/*
* Function Name	: r_scifa1_txif1_interrupt
* Description  	: This function send tx_buf data to the FTDR
* Arguments    	: tx_buf -> Pointer to data
* 				  tx_num -> Size of tx_buf Array
* Author 		: Joschka Randerath
*/
void sendUartCh1(const uint8_t * tx_buf, uint16_t tx_num)
{
    SCIFA1.SCR.BIT.TE = 1U;		// Transmit Enable
    SCIFA1.SCR.BIT.TIE = 0U;	// Transmit Interrupt Enable (TXI)

    uint16_t count = 0;

    /* Get the amount of untransmitted data stored in the FRDR register */
    uint16_t dummy_fdr = SCIFA1.FDR.BIT.T;


    /* Write data to the transmit FIFO data register */
    while ((0U < tx_num) && (count < _SCIF_FIFO_MAX_SIZE - dummy_fdr))
    {
        SCIFA1.FTDR = *tx_buf;
        tx_buf++;
        tx_num--;
        count++;
    }

    if (1U == SCIFA1.FSR.BIT.TDFE)
    {
        SCIFA1.FSR.BIT.TDFE = 0U;		// Reset Transmit FIFO data empty Flag

    }
}


/*
* Function Name	: sendUartCh1
* Description  	: This function read data from the FRDR register to the rx_buf
* Arguments    	: rx_buf -> Pointer to the rx-data Array
* Return Value	: rx_num -> Size of receive data
* Author 		: Joschka Randerath
*
* Important 	: rx_buf array must be large enough (maximum data in FRDR -> 16 Byte)
*/
void receiveUartCh1(uint8_t * rx_buf, uint16_t rx_num)
{
    uint16_t g_scifa1_rx_count = 0U;


    SCIFA1.FTCR.BIT.RFTC = _SCIF_RX_TRIG_NUM_1;

    SCIFA1.SCR.BIT.RE = 1U;
    SCIFA1.SCR.BIT.RIE = 0U;
    SCIFA1.SCR.BIT.REIE = 0U;

    // Funktionswechsel

    uint16_t count = 0;


    /* Get the amount of receive data stored in FRDR register */
    uint16_t dummy_fdr = SCIFA1.FDR.BIT.R;

    /* Clear receive FIFO data full flag */
    if (1U == SCIFA1.FSR.BIT.RDF)
    {
        // SCIFA1.FSR.BIT.RDF = 0U;		// Reset "receive FIFO data full Flag"
    }


    /* Read data from the receive FIFO data register */
    while ((rx_num > g_scifa1_rx_count) && (count < dummy_fdr))
    {
        *rx_buf = SCIFA1.FRDR;
        rx_buf++;
        g_scifa1_rx_count++;
        count++;
    }

    /* If remaining data is less than the receive trigger number, receive interrupt will not occur.
       In this case, set trigger number to 1 to force receive interrupt for each one byte of data in FRDR */
    if ((rx_num - g_scifa1_rx_count < _SCIF_RX_TRIG_NUM_1) && (1U != SCIFA1.FTCR.BIT.RFTC))
    {
        SCIFA1.FTCR.BIT.RFTC = 1U;
    }

    /* Clear receive FIFO data full flag
    if (1U == SCIFA1.FSR.BIT.RDF)
    {
        SCIFA1.FSR.BIT.RDF = 0U;		// Reset "receive FIFO data full Flag"
    }
*/

    VIC.HVA0.LONG = 0x00000000UL;
    asm("dmb");
}

/*
 * Function Name	: 	uartHandler
 * Description  	:	Die Funktion versendet die PDO und ggs. die SDO-Daten per UART zum UART-Slave.
 * 						Anschließend werden die PDO unf ggfs. die SDO Daten vom UART-Slave empfangen.
 * 						Innherhalb dieser Funktion gibt es warte-Schleifen.
 * Author 			: 	Joschka Randerath
 */
void uartHandler(){
	uint8_t outData[PDO_SIZE + SDO_SIZE + SDO_HEADER_SIZE + STARTSTOP_SIZE] = {0};
	uint8_t inData[PDO_SIZE] = {0};

	uint8_t sizeDataOut = PDO_SIZE + STARTSTOP_SIZE;

	outData[0] = (uint8_t) STARTBYTE;
	outData[1] = (uint8_t)((targetPosition & (0xff << 24)) >> 24);
	outData[2] = (uint8_t)((targetPosition & (0xff << 16)) >> 16);
	outData[3] = (uint8_t)((targetPosition & (0xff << 8)) >> 8);
	outData[4] = (uint8_t)((targetPosition & (0xff << 0)) >> 0);
	outData[5] = (uint8_t) STOPBYTE;

	if(SDO_REQ_FLAG){
		sizeDataOut = PDO_SIZE + SDO_SIZE + SDO_HEADER_SIZE + STARTSTOP_SIZE;

		// Kopiere SDO Header
		outData[5] = (uint8_t)((headerSDO & (0xff << 24)) >> 24);		// Header
		outData[6] = (uint8_t)((headerSDO & (0xff << 16)) >> 16);		// Index
		outData[7] = (uint8_t)((headerSDO & (0xff << 8)) >> 8);			// Index 2
		outData[8] = (uint8_t)((headerSDO & (0xff << 0)) >> 0);			// Subindex

		// Kopiere SDO-Data
		outData[9] = (uint8_t)((sdoData & (0xff << 24)) >> 24);
		outData[10] = (uint8_t)((sdoData & (0xff << 16)) >> 16);
		outData[11] = (uint8_t)((sdoData & (0xff << 8)) >> 8);
		outData[12] = (uint8_t)((sdoData & (0xff << 0)) >> 0);
		outData[13] = (uint8_t) STOPBYTE;

		SDO_REQ_FLAG = 0; 		// Request wird verarbeitet/weitergeleitet

		if(outData[5] == READ_REQ_HEADER)
			SDO_IND_FLAG = 0xff;			// SDO-Request wird weitergeleitet und auf INC wird gewartet
	}

	// Stelle ein das die RDF Flag bei ein empfangenden Bytes aktiviert wird
	SCIFA1.FCR.BIT.RTRG = 0b01;

	// Disable data receive
	SCIFA1.SCR.BIT.RE = 0U;

	// Versende Daten
	sendUartCh1(outData, sizeDataOut);

	// Enable data transive and DE from RS485 Phy
	while(SCIFA1.FSR.BIT.TEND == 0){
		PORT2.PODR.BIT.B5 = !SCIFA1.FSR.BIT.TEND;
	}

	PORT2.PODR.BIT.B5 = 0U;

	// Enable data receive
	SCIFA1.SCR.BIT.RE = 1U;

	// Warte bis 4 Byte empfangen wurden -> PDO
	while(SCIFA1.FDR.BIT.R != 4U){}

	// lese empfangende Bytes aus FRDR aus
	receiveUartCh1(inData, 4U);

	actuellePosition = ((uint32_t) inData[0]) << 24;
	actuellePosition |= ((uint32_t) inData[1]) << 16;
	actuellePosition |= ((uint32_t) inData[2]) << 8;
	actuellePosition |= ((uint32_t) inData[3]) << 0;

	if(SDO_IND_FLAG){
		// Eine Antwort auf eine SDO-Request wird erwartet (muss nicht unbedingt stattfinden

		CMT1.CMCNT = 0; 			// Reset Counter
		startCmt1();

		// Warte bis weitere 4 Byte empfangen werden oder ein Timeout von 866 us geschieht
		while((SCIFA1.FDR.BIT.R != 4U) && (CMT1.CMCNT < 30000) ){}

		stopCmt1();

		if(SCIFA1.FDR.BIT.R == 4U){
			// SDO Antwort empfangen

			// lese empfangende Bytes aus FRDR aus
			receiveUartCh1(inData, 4U);

			sdo_res_data = ((uint32_t) inData[0]) << 24;
			sdo_res_data |= ((uint32_t) inData[1]) << 16;
			sdo_res_data |= ((uint32_t) inData[2]) << 8;
			sdo_res_data |= ((uint32_t) inData[3]) << 0;

			// Aktualisiere Flags
			SDO_IND_FLAG = 0;
			SDO_RES_FLAG = 0xff;
		}
	}

}


/*
 * Function Name	: 	uartHandlerFsm
 * Description  	:	Die Funktion versendet die PDO und ggs. die SDO-Daten per UART zum UART-Slave.
 * 						Anschließend werden die PDO unf ggfs. die SDO Daten vom UART-Slave empfangen.
 * 						Diese Funktion ist als Mealy Automat implementiert 
 * Return Value		: 	Aussage über den aktuellen Staus der UART Kommunikation (UART_BEREIT, UART_BUSSY, UART_KOM_ABGESCHLOSSEN, UART_ERROR)
 * Author 			: 	Joschka Randerath
 */	

uint8_t uartHandlerFsm(void){

	uint8_t result = UART_BEREIT;

	static state_t state = bereit;

	uint8_t outData[PDO_SIZE + SDO_SIZE + SDO_HEADER_SIZE + STARTSTOP_SIZE] = {0},
			inData[PDO_SIZE] = {0},
			sizeDataOut = PDO_SIZE + STARTSTOP_SIZE;


	if(state != bereit && UART_AKTIV_HANDLER){
		// UART Handler aktiviert obwohl der zurvor begonnene Prozess nicht abgeschlossen
	    // Reset transmit/receive FIFO data register operation
	    SCIFA1.FCR.BIT.TFRST = 1U;					// Reset the FTDR register
	    SCIFA1.FCR.BIT.RFRST = 1U;					// Reset the FRDR register

	    SCIFA1.FCR.BIT.TFRST = 0U;
	    SCIFA1.FCR.BIT.RFRST = 0U;

	    state = bereit;

		result = UART_ERROR;
	}

	switch(state){
	case bereit:

		if(UART_AKTIV_HANDLER){
			// UART Kommunikation wurde aktiviert
			state = sende_daten;
			UART_AKTIV_HANDLER = 0;

			// reset timeout
			SDO_TIMEOUT = 0;

			result |= UART_BUSSY;
		}

		break;

	case sende_daten:
		outData[0] = (uint8_t) STARTBYTE;
		outData[1] = (uint8_t)((controlword & (0xff << 8)) >> 8);
		outData[2] = (uint8_t)((controlword & (0xff << 0)) >> 0);
		outData[3] = (uint8_t)((targetPosition & (0xff << 24)) >> 24);
		outData[4] = (uint8_t)((targetPosition & (0xff << 16)) >> 16);
		outData[5] = (uint8_t)((targetPosition & (0xff << 8)) >> 8);
		outData[6] = (uint8_t)((targetPosition & (0xff << 0)) >> 0);
		outData[7] = (uint8_t)((targetVelocity & (0xff << 24)) >> 24);
		outData[8] = (uint8_t)((targetVelocity & (0xff << 16)) >> 16);
		outData[9] = (uint8_t)((targetVelocity & (0xff << 8)) >> 8);
		outData[10] = (uint8_t)((targetVelocity & (0xff << 0)) >> 0);
		outData[11] = (uint8_t) STOPBYTE;

		if(SDO_REQ_FLAG){
			/** Nicht Upgedetet -> Funktioniert nicht" **/ 
			sizeDataOut += SDO_SIZE + SDO_HEADER_SIZE;

			// Kopiere SDO Header
			outData[11] = (uint8_t)((headerSDO & (0xff << 24)) >> 24);		// Header
			outData[12] = (uint8_t)((headerSDO & (0xff << 16)) >> 16);		// Index
			outData[13] = (uint8_t)((headerSDO & (0xff << 8)) >> 8);			// Index 2
			outData[14] = (uint8_t)((headerSDO & (0xff << 0)) >> 0);			// Subindex

			// Kopiere SDO-Data
			outData[15] = (uint8_t)((sdoData & (0xff << 24)) >> 24);
			outData[16] = (uint8_t)((sdoData & (0xff << 16)) >> 16);
			outData[17] = (uint8_t)((sdoData & (0xff << 8)) >> 8);
			outData[18] = (uint8_t)((sdoData & (0xff << 0)) >> 0);
			outData[19] = (uint8_t) STOPBYTE;



			if(outData[11] == READ_REQ_HEADER){
				SDO_IND_FLAG = 0xff;			// SDO-Request wird weitergeleitet und auf INC wird gewartet

				// Starte Zeitmessung für Timeout
				CMT1.CMCNT = 0;
				startCmt1();
			}
		}

		// Disable data receive
		SCIFA1.SCR.BIT.RE = 0U;
		SCIFA1.SCR.BIT.TE = 1U;

		// Enable DE (RS485 PHY)
		PORT2.PODR.BIT.B5 = 1U;

		// Versende Daten
		sendUartCh1(outData, sizeDataOut);	

		state = warte_datenversand;

		result |= UART_BUSSY;

		break;

	case warte_datenversand:
		result |= UART_BUSSY;

		if(SCIFA1.FSR.BIT.TEND){
			if(SDO_REQ_FLAG){
				SDO_REQ_FLAG = 0;

				outData[16] = (uint8_t)((sdoData & (0xff << 16)) >> 16);
				outData[17] = (uint8_t)((sdoData & (0xff << 8)) >> 8);
				outData[18] = (uint8_t)((sdoData & (0xff << 0)) >> 0);
				outData[19] = (uint8_t) STOPBYTE;

				// Versende Daten
				sendUartCh1(&outData[16], 4);
			}else{
				// Disable DE (RS485)
				PORT2.PODR.BIT.B5 = 0U;

				// Enable data receive
				SCIFA1.SCR.BIT.RE = 1U;
				SCIFA1.SCR.BIT.TE = 0U;

				state = warte_datenempfang_PDO;
			}
		}

		break;

	case warte_datenempfang_PDO:
		result |= UART_BUSSY;

		if(SCIFA1.FDR.BIT.R >= (PDO_SIZE - 4)){
			// 10 Bytes wurden empfangen

			// lese empfangende Bytes aus FRDR aus
			receiveUartCh1(inData, PDO_SIZE - 4);
			
			
			statusword 	 		 = 	((uint16_t) inData[0]) << 8;
			statusword		 	|= 	((uint16_t) inData[1]) << 0;
			
			actuellePosition 	 = 	((uint32_t) inData[2]) << 24;
			actuellePosition 	|= 	((uint32_t) inData[3]) << 16;
			actuellePosition 	|= 	((uint32_t) inData[4]) << 8;
			actuellePosition 	|= 	((uint32_t) inData[5]) << 0;
			

			// setStatuswordValue(statusword);
			// setPositionActualValue(actuellePosition);
			
			if(SDO_IND_FLAG){
				state = warte_datenempfang_SDO;
			}else{
				result = UART_KOM_ABGESCHLOSSEN;
				state = bereit;
			}
		}

		break;

	case warte_datenempfang_SDO:
		result = UART_BUSSY;

		if(SCIFA1.FDR.BIT.R == 4U){
			// Daten Empfangen, lese Bytes aus FRDR aus
			receiveUartCh1(inData, 4U);

			sdo_res_data = ((uint32_t) inData[0]) << 24;
			sdo_res_data |= ((uint32_t) inData[1]) << 16;
			sdo_res_data |= ((uint32_t) inData[2]) << 8;
			sdo_res_data |= ((uint32_t) inData[3]) << 0;

			// setStoreData(sdo_res_data);

			// Aktualisiere Flags
			SDO_IND_FLAG = 0;
			SDO_RES_FLAG = 0xff;

			// Stoppe Timer
			stopCmt1();

			state = bereit;

			result = UART_KOM_ABGESCHLOSSEN;
		}else if(((CMT1.CMCNT * 512)/75000) > UART_TIMEOUT){
			// Timeout, da SDO Antwort zu lange gedauert
			SDO_IND_FLAG = 0;
			SDO_TIMEOUT = 0xff;

			stopCmt1();

			if(state == warte_datenempfang_SDO)
				state = bereit;

			result = UART_KOM_ABGESCHLOSSEN;
		}
		break;

	}// End switch case

	return (result);
}



/* Code fuer andere Files

--------------------- Fuer CiA402Example.c ---------------------------------
// Setze Statuswert
void setStatuswordValue(UINT16 statusword){
	Statusword0x6041 = statusword;
}

// Setze aktuelle Position
void setPositionActualValue(UINT32 actuellePosition){
    PositionActualValue0x6064 = actuellePosition;
}

// Setze aktuelle Geschwindigkeit
void setVelocityActualValue(UINT32 actuelleVelocity){
	VelocityActualValue0x606C = actuelleVelocity;
}

// Lese target Position
UINT32 getTargetPosition(void){
	return TargetPosition0x607A;
}

// Lese target Velocity
UINT32 getTargetVelocity(void){
	return TargetVelocity0x60FF;
}

// Lese Controlword
UINT16 getControlword(void){
	return Controlword0x6040;
}


--------------------- Fuer ecatappl.c ---------------------------------
// Globale Variabeln aus UART Modul
extern UINT8 UART_AKTIV_HANDLER;

extern UINT32 targetPosition;
extern UINT32 targetVelocity;
extern UINT16 controlword;

// Einstellungen für UART Modul
UART_AKTIV_HANDLER = 0xff;

targetPosition = getTargetPosition();
targetVelocity = getTargetVelocity();
controlword = getControlword();


--------------------- Fuer sdoserv.c ---------------------------------
// Globale Variabeln UART Modul
extern UINT32 headerSDO;
extern UINT32 sdoData;

extern UINT8 SDO_REQ_FLAG;


// SDO Write im Bereich von Index 0x3000 bis 0x5FFF abfangen
                    if(0x3000 <= index && index < 0x6000){
                    	// Speichere SDO Anfrage ab
                    	headerSDO = 	((UINT32) sdoHeader) 	<< 24;
                    	headerSDO |= 	((UINT32) index) 		<< 8;
                    	headerSDO |= 	((UINT32) subindex)		<< 0;

                    	sdoData = 		((UINT32) pData[1])		<< 16;
                    	sdoData |= 		((UINT32) pData[0])		<< 0;

                    	// Setze Flag damit SDO an MAX10 weitergeleitet wird
                    	SDO_REQ_FLAG = 0xFF;
                    }
// SDO Write im Bereich von Index 0x3000 bis 0x5FFF abfangen ende

// SDO Read im Bereich von Index 0x3000 bis 0x5FFF abfangen
                    	if( 0x3000 <= index && index < 0x6000){
                        	// the application generates the SDO-Response later on by calling SDOS_SdoRes (only possible if object access function pointer is defined)
                            u8PendingSdo = SDO_PENDING_READ;
                            bStoreCompleteAccess = bCompleteAccess;
                            u8StoreSubindex = subindex;
                            u16StoreIndex = index;
                            u32StoreDataSize = objLength;
                            pStoreData = pData;
                            pSdoPendFunc = pObjEntry->Read;

                            bSdoInWork = TRUE;
                            // we have to store the buffer and the response header
                            pSdoResStored = pSdoInd;

                            // update command field
                            pSdoResStored->SdoHeader.Sdo[SDOHEADER_COMMANDOFFSET] &= ~SDOHEADER_COMMANDMASK;
                            pSdoResStored->SdoHeader.Sdo[SDOHEADER_COMMANDOFFSET]    |= (sdoHeader & (SDOHEADER_COMPLETEACCESS | SDOHEADER_COMMAND));

                        	headerSDO = ((UINT32) sdoHeader) << 24;
                        	headerSDO |= ((UINT32) index) << 8;
                        	headerSDO |= (UINT32) subindex;

                        	sdoData = ((UINT32) pData[1]) << 16;
                        	sdoData |= ((UINT32) pData[0]);

                        	SDO_REQ_FLAG = 0xff;

                            return 0;
                    	}
// SDO Read im Bereich von Index 0x3000 bis 0x5FFF abfangen ende


// Setze Daten für die SDO Antwort per EC
void setStoreData(UINT32 data){
	if(pStoreData != NULL){
		pStoreData[1] = (UINT16)((data & 0xffff0000) >> 16);
		pStoreData[0] = (UINT16)(data & 0x0000ffff);
	}
}

// Versende SDO Antwort
void SDOResAfterUART(){
    UINT8 abort = 0;

    // Setzte Antwortlänge auf 4 Byte
    pSdoResStored->SdoHeader.Sdo[SDOHEADER_COMMANDOFFSET] = 0x43;
    u32StoreDataSize = 4;

    UINT8 sdoHeader = (pSdoResStored->SdoHeader.Sdo[SDOHEADER_COMMANDOFFSET] & SDOHEADER_COMMANDMASK);
    // the SDO-command is in bit 5-7 of the first SDO-Byte
    UINT8 command = (sdoHeader & SDOHEADER_COMMAND);

    // pStoreData[0] = 0x3132;

    SDOS_SdoRes(abort, u32StoreDataSize, pStoreData);

    pSdoResStored = NULL;

}

 */
