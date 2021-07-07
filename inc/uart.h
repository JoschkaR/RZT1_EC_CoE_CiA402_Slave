/*
 * -----------------------------------------------------------
 * Autor		Joschka Randerath
 * Funktion		UART-Kommuniktion steuern
 * Version		4.0
 * Datum		09.06.2021
 * -----------------------------------------------------------
 */

#ifndef _UART_H
#define _UART_H


// #include "iodefine.h"
// #include "r_system.h"
// #include <machine/_default_types.h>

/*
#ifndef _UINT32_T_DECLARED
typedef __uint32_t uint32_t ;
#define _UINT32_T_DECLARED
#endif

#ifndef _UINT16_T_DECLARED
typedef __uint16_t uint16_t ;
#define _UINT16_T_DECLARED
#endif

#ifndef _UINT8_T_DECLARED
typedef __uint8_t uint8_t ;
#define _UINT8_T_DECLARED
#endif
*/

#ifndef _SYS__STDINT_H
#define _SYS__STDINT_H

#include <machine/_default_types.h>


#ifdef __cplusplus
extern "C" {
#endif

#ifdef ___int8_t_defined
#ifndef _INT8_T_DECLARED
typedef __int8_t int8_t ;
#define _INT8_T_DECLARED
#endif
#ifndef _UINT8_T_DECLARED
typedef __uint8_t uint8_t ;
#define _UINT8_T_DECLARED
#endif
#define __int8_t_defined 1
#endif /* ___int8_t_defined */

#ifdef ___int16_t_defined
#ifndef _INT16_T_DECLARED
typedef __int16_t int16_t ;
#define _INT16_T_DECLARED
#endif
#ifndef _UINT16_T_DECLARED
typedef __uint16_t uint16_t ;
#define _UINT16_T_DECLARED
#endif
#define __int16_t_defined 1
#endif /* ___int16_t_defined */

#ifdef ___int32_t_defined
#ifndef _INT32_T_DECLARED
typedef __int32_t int32_t ;
#define _INT32_T_DECLARED
#endif
#ifndef _UINT32_T_DECLARED
typedef __uint32_t uint32_t ;
#define _UINT32_T_DECLARED
#endif
#define __int32_t_defined 1
#endif /* ___int32_t_defined */

#ifdef ___int64_t_defined
#ifndef _INT64_T_DECLARED
typedef __int64_t int64_t ;
#define _INT64_T_DECLARED
#endif
#ifndef _UINT64_T_DECLARED
typedef __uint64_t uint64_t ;
#define _UINT64_T_DECLARED
#endif
#define __int64_t_defined 1
#endif /* ___int64_t_defined */

#ifndef _INTMAX_T_DECLARED
typedef __intmax_t intmax_t;
#define _INTMAX_T_DECLARED
#endif

#ifndef _UINTMAX_T_DECLARED
typedef __uintmax_t uintmax_t;
#define _UINTMAX_T_DECLARED
#endif

#ifndef _INTPTR_T_DECLARED
typedef __intptr_t intptr_t;
#define _INTPTR_T_DECLARED
#endif

#ifndef _UINTPTR_T_DECLARED
typedef __uintptr_t uintptr_t;
#define _UINTPTR_T_DECLARED
#endif

#ifdef __cplusplus
}
#endif

#endif /* _SYS__STDINT_H */


typedef enum{
	bereit,
	sende_daten,
	warte_datenversand,
	warte_datenempfang_PDO,
	warte_datenempfang_SDO
}state_t;

// Error Code UART Hadnler
#define UART_BEREIT					0U		// UART Handler SM bereit fuer Datentransver per UART
#define UART_BUSSY					32U		// UART Datentransfer in bearbeitung
#define UART_KOM_ABGESCHLOSSEN		64U		// UART Datentransver abgeschlossen
#define UART_ERROR					128U	// Fehler bei der UART Kommuniktion
#define UART_TIMEOUT				200U	// Timeout in ms Wert zwischen 1 und 400

// UART Kommuniktion
#define PDO_SIZE 					10U				// Groeße der POD in Bytes
#define SDO_SIZE 					4U				// GRoeße der SDO in Bytes
#define SDO_HEADER_SIZE				4U				// Groeße der SDO Header in Bytes
#define STARTSTOP_SIZE				2U				// Groeße des Start und Stopt Bytes in Bytes
	
#define READ_REQ_HEADER				0x40U			// Header einer lesenden EC-Request (Daten vom UART Slave anfragen)
#define STARTBYTE 					255U			// UART Startbyte
#define STOPBYTE					254U			// UART Stoppbyte


/*
    System Clock Control Register (SCKCR)
*/
/* Peripheral Module Clock G (PCLKG) */
#define _CGC_PCLKG_0                  (0x00000000UL) /* 60 MHz */
#define _CGC_PCLKG_1                  (0x00000001UL) /* 30 MHz */
#define _CGC_PCLKG_2                  (0x00000002UL) /* 15 MHz */
#define _CGC_PCLKG_3                  (0x00000003UL) /* 7.5 MHz */
/* Peripheral Module Clock F (PCLKF) */
#define _CGC_PCLKF_0                  (0x00000000UL) /* 60 MHz */
#define _CGC_PCLKF_1                  (0x00000004UL) /* 30 MHz */
#define _CGC_PCLKF_2                  (0x00000008UL) /* 15 MHz */
#define _CGC_PCLKF_3                  (0x0000000CUL) /* 7.5 MHz */
/* Peripheral Module Clock E (PCLKE) */
#define _CGC_PCLKE_0                  (0x00000000UL) /* 75 MHz */
#define _CGC_PCLKE_1                  (0x00000010UL) /* 37.5 MHz */
#define _CGC_PCLKE_2                  (0x00000020UL) /* 18.75 MHz */
/* External Bus Clock (CKIO) */
#define _CGC_CKIO_0                   (0x00000000UL) /* 75 MHz */
#define _CGC_CKIO_1                   (0x00000100UL) /* 50 MHz */
#define _CGC_CKIO_2                   (0x00000200UL) /* 37.5 MHz */
#define _CGC_CKIO_3                   (0x00000300UL) /* 30 MHz */
#define _CGC_CKIO_4                   (0x00000400UL) /* 25 MHz */
#define _CGC_CKIO_5                   (0x00000500UL) /* 21.43 MHz */
#define _CGC_CKIO_6                   (0x00000600UL) /* 18.75 MHz */
/* Ether Clock E  (ETCLKE) */
#define _CGC_ETCKE_0                  (0x00000000UL) /* 25 MHz */
#define _CGC_ETCKE_1                  (0x00001000UL) /* 50 MHz */
/* Ether Clock D  (ETCLKD) */
#define _CGC_ETCKD_0                  (0x00000000UL) /* 12.5 MHz */
#define _CGC_ETCKD_1                  (0x00004000UL) /* 6.25 MHz */
#define _CGC_ETCKD_2                  (0x00008000UL) /* 3.125 MHz */
#define _CGC_ETCKD_3                  (0x0000C000UL) /* 1.563 MHz */
/* High-Speed Serial Clock (SERICLK) */
#define _CGC_SERICLK_0                (0x00000000UL) /* 150 MHz */
#define _CGC_SERICLK_1                (0x00010000UL) /* 120 MHz */
/* USB Clock (USBMCLK) */
#define _CGC_UCK_0                    (0x00000000UL) /* 50 MHz */
#define _CGC_UCK_1                    (0x00020000UL) /* 24 MHz */
/* Trace Interface Clock (TCLK) */
#define _CGC_TCLK_0                   (0x00000000UL) /* 150 MHz */
#define _CGC_TCLK_1                   (0x00100000UL) /* 75 MHz */


/*
    Compare Match Timer Control Register (CMCR)
*/
/* Clock Select (CKS[1:0]) */
#define _CMT_CMCR_CKS_PCLK8                     (0x0000U) /* PCLK/8 */
#define _CMT_CMCR_CKS_PCLK32                    (0x0001U) /* PCLK/32 */
#define _CMT_CMCR_CKS_PCLK128                   (0x0002U) /* PCLK/128 */
#define _CMT_CMCR_CKS_PCLK512                   (0x0003U) /* PCLK/512 */
/* Compare Match Interrupt Enable (CMIE) */
#define _CMT_CMCR_CMIE_DISABLE                  (0x0000U) /* Compare match interrupt (CMIn) disabled */
#define _CMT_CMCR_CMIE_ENABLE                   (0x0040U) /* Compare match interrupt (CMIn) enabled */


/* Compare Match Timer Constant Register (CMCOR) */
#define _CMT0_CMCOR_VALUE                   	(0xE4E1U)
#define _CMT_CMCOR_MAX_VALUE					(0xFFFEU)

/*
    Delta-Sigma Interface Clock Control Register (DSCR)
*/
#define _CGC_DSSEL0_SLAVE             (0x00000000UL) /* Supplied from outside the LSI (slave operation) */
#define _CGC_DSSEL0_MASTER            (0x00000001UL) /* Supplied from CGC (master operation) */
#define _CGC_DSCLK0_0                 (0x00000000UL) /* 25 MHz */
#define _CGC_DSCLK0_1                 (0x00000002UL) /* 18.75 MHz */
#define _CGC_DSCLK0_2                 (0x00000004UL) /* 12.5 MHz */
#define _CGC_DSCLK0_3                 (0x00000006UL) /* 9.375 MHz */
#define _CGC_DSCLK0_4                 (0x00000008UL) /* 6.25 MHz */
#define _CGC_DSCLK0_POL_NORMAL        (0x00000000UL) /* Polarity not inverted (master and slave operation) */
#define _CGC_DSCLK0_POL_INVERT        (0x00000010UL) /* Polarity inverted (master and slave operation) */
#define _CGC_DSCLK0_SLAVE_MCLK0_2     (0x00000000UL) /* Clock input to MCLK0,MCLK1,MCLK2 pins are used */
#define _CGC_DSCLK0_SLAVE_MCLK0       (0x00000020UL) /* Clock input to MCLK0 pin is used */
#define _CGC_DSSEL1_SLAVE             (0x00000000UL) /* Supplied from outside the LSI (slave operation) */
#define _CGC_DSSEL1_MASTER            (0x00010000UL) /* Supplied from CGC (master operation) */
#define _CGC_DSCLK1_0                 (0x00000000UL) /* 25 MHz */
#define _CGC_DSCLK1_1                 (0x00020000UL) /* 18.75 MHz */
#define _CGC_DSCLK1_2                 (0x00040000UL) /* 12.5 MHz */
#define _CGC_DSCLK1_3                 (0x00060000UL) /* 9.375 MHz */
#define _CGC_DSCLK1_4                 (0x00080000UL) /* 6.25 MHz */
#define _CGC_DSCLK1_POL_NORMAL        (0x00000000UL) /* Polarity not inverted (master and slave operation) */
#define _CGC_DSCLK1_POL_INVERT        (0x00100000UL) /* Polarity inverted (master and slave operation) */


/*
    Serial mode register (SMR)
*/
/* Clock select (CKS[1:0]) */
#define _SCIF_CLOCK_SERICLK                     (0x0000U) /* SERICLK */
#define _SCIF_CLOCK_SERICLK_4                   (0x0001U) /* SERICLK/4 */
#define _SCIF_CLOCK_SERICLK_16                  (0x0002U) /* SERICLK/16 */
#define _SCIF_CLOCK_SERICLK_64                  (0x0003U) /* SERICLK/64 */
/* Stop bit length (STOP) */
#define _SCIF_STOP_1                            (0x0000U) /* 1 stop bit */
#define _SCIF_STOP_2                            (0x0008U) /* 2 stop bits */
/* Parity mode (PM) */
#define _SCIF_PARITY_EVEN                       (0x0000U) /* Parity even */
#define _SCIF_PARITY_ODD                        (0x0010U) /* Parity odd */
/* Parity enable (PE) */
#define _SCIF_PARITY_DISABLE                    (0x0000U) /* Parity disable */
#define _SCIF_PARITY_ENABLE                     (0x0020U) /* Parity enable */
/* Character length (CHR) */
#define _SCIF_DATA_LENGTH_8                     (0x0000U) /* Data length 8 bits */
#define _SCIF_DATA_LENGTH_7                     (0x0040U) /* Data length 7 bits */
/* Communications mode (CM) */
#define _SCIF_ASYNCHRONOUS_MODE                 (0x0000U) /* Asynchronous mode */
#define _SCIF_CLOCK_SYNCHRONOUS_MODE            (0x0080U) /* Clock synchronous mode */

/*
    Serial control register (SCR)
*/
/* Clock enable (CKE[1:0]) */
#define _SCIF_INTERNAL_SCK_UNUSED               (0x0000U) /* Internal clock selected, SCK pin unused */
#define _SCIF_INTERNAL_SCK_OUTPUT               (0x0001U) /* Internal clock selected, SCK pin as clock output */
/* Clock enable (CKE[1:0]) for clock synchronous mode */
#define _SCIF_INTERNAL_SCK_OUTPUT_SYNC          (0x0000U) /* Internal clock, SCK pin is used for clock output */
#define _SCIF_EXTERNAL_SCK_INPUT_SYNC           (0x0002U) /* External clock, SCK pin is used for clock input */
/* Transmit end interrupt enable (TEIE) */
#define _SCIF_TEI_INTERRUPT_DISABLE             (0x0000U) /* TEI interrupt request disable */
#define _SCIF_TEI_INTERRUPT_ENABLE              (0x0004U) /* TEI interrupt request enable */
/* Receive error interrupt enable (REIE) */
#define _SCIF_ERI_BRI_INTERRUPT_DISABLE         (0x0000U) /* Disable receive-error interrupt and break interrupt */
#define _SCIF_ERI_BRI_INTERRUPT_ENABLE          (0x0008U) /* Enable receive-error interrupt and break interrupt */
/* Receive enable (RE) */
#define _SCIF_RECEIVE_DISABLE                   (0x0000U) /* Disable receive mode */
#define _SCIF_RECEIVE_ENABLE                    (0x0010U) /* Enable receive mode */
/* Transmit enable (TE) */
#define _SCIF_TRANSMIT_DISABLE                  (0x0000U) /* Disable transmit mode */
#define _SCIF_TRANSMIT_ENABLE                   (0x0020U) /* Enable transmit mode */
/* Receive interrupt enable (RIE) */
#define _SCIF_RXI_ERI_DISABLE                   (0x0000U) /* Disable RXI and ERI interrupt requests */
#define _SCIF_RXI_ERI_ENABLE                    (0x0040U) /* Enable RXI and ERI interrupt requests */
/* Transmit interrupt enable (TIE) */
#define _SCIF_TXI_DISABLE                       (0x0000U) /* Disable TXI interrupt requests */
#define _SCIF_TXI_ENABLE                        (0x0080U) /* Enable TXI interrupt requests */

/*
    FIFO control register (FCR)
*/
/* Loop-Back test (LOOP) */
#define _SCIF_LOOPBACK_DISABLE                  (0x0000U) /* Loop back test is disabled */
#define _SCIF_LOOPBACK_ENABLE                   (0x0001U) /* Loop back test is enabled */
/* Receive FIFO Data Register Reset (RFRST) */
#define _SCIF_RX_FIFO_RESET_DISABLE             (0x0000U) /* FRDR reset operation is disabled */
#define _SCIF_RX_FIFO_RESET_ENABLE              (0x0002U) /* FRDR reset operation is enabled */
/* Transmit FIFO Data Register Reset (TFRST) */
#define _SCIF_TX_FIFO_RESET_DISABLE             (0x0000U) /* FTDR reset operation is disabled */
#define _SCIF_TX_FIFO_RESET_ENABLE              (0x0004U) /* FTDR reset operation is enabled */
/* Modem control enable (MCE) */
#define _SCIF_MODEM_CONTROL_DISABLE             (0x0000U) /* Model signal is disabled */
#define _SCIF_MODEM_CONTROL_ENABLE              (0x0008U) /* Model signal is enabled */
/* Transmit FIFO Data Trigger Number (TTRG[1:0]) */
#define _SCIF_TX_TRIGGER_NUMBER_8               (0x0000U) /* 8 (or 8 when TDFE flag is 1) */
#define _SCIF_TX_TRIGGER_NUMBER_4               (0x0010U) /* 4 (or 12 when TDFE flag is 1) */
#define _SCIF_TX_TRIGGER_NUMBER_2               (0x0020U) /* 2 (or 14 when TDFE flag is 1) */
#define _SCIF_TX_TRIGGER_NUMBER_0               (0x0030U) /* 0 (or 16 when TDFE flag is 1) */
/* Receive FIFO Data Trigger Number (RTRG[1:0]) */
#define _SCIF_RX_TRIGGER_NUMBER_1               (0x0000U) /* 1 */
#define _SCIF_RX_TRIGGER_NUMBER_4               (0x0040U) /* 4 (for asynchronous mode) */
#define _SCIF_RX_TRIGGER_NUMBER_2               (0x0040U) /* 2 (for clock synchronous mode */
#define _SCIF_RX_TRIGGER_NUMBER_8               (0x0080U) /* 8 */
#define _SCIF_RX_TRIGGER_NUMBER_14              (0x00C0U) /* 14 */
/* RTS# Output Active Trigger Number Select (RSTRG[2:0]) */
#define _SCIF_RTS_TRIGGER_NUMBER_15             (0x0000U) /* 15 */
#define _SCIF_RTS_TRIGGER_NUMBER_1              (0x0100U) /* 1 */
#define _SCIF_RTS_TRIGGER_NUMBER_4              (0x0200U) /* 4 */
#define _SCIF_RTS_TRIGGER_NUMBER_6              (0x0300U) /* 6 */
#define _SCIF_RTS_TRIGGER_NUMBER_8              (0x0400U) /* 8 */
#define _SCIF_RTS_TRIGGER_NUMBER_10             (0x0500U) /* 10 */
#define _SCIF_RTS_TRIGGER_NUMBER_12             (0x0600U) /* 12 */
#define _SCIF_RTS_TRIGGER_NUMBER_14             (0x0700U) /* 14 */

/*
    Serial port register (SPTR)
*/
/* Serial Port Break Data (SPB2DT) */
#define _SCIF_SERIAL_BREAK_DATA_LOW             (0x0000U) /* Input/output data is at low */
#define _SCIF_SERIAL_BREAK_DATA_HIGH            (0x0001U) /* Input/output data is at high */
/* Serial Port Break input/output (SPB2IO) */
#define _SCIF_SERIAL_BREAK_TXD_NO_OUTPUT        (0x0000U) /* SPB2DT bit value is not output to TXD pin */
#define _SCIF_SERIAL_BREAK_TXD_OUTPUT           (0x0002U) /* SPB2DT bit value is output to TXD pin */
/* SCK Port Data (SCKDT) */
#define _SCIF_SCK_DATA_LOW                      (0x0000U) /* Input/output data is at low */
#define _SCIF_SCK_DATA_HIGH                     (0x0004U) /* Input/output data is at high */
/* SCK Port input/output (SCKIO) */
#define _SCIF_SCK_PORT_NO_OUTPUT                (0x0000U) /* SCKDT bit value is not output to SCK pin */
#define _SCIF_SCK_PORT_OUTPUT                   (0x0008U) /* SCKDT bit value is output to SCK pin */
/* CTS# Port Data Select (CTS2DT) */
#define _SCIF_CTS_DATA_0                        (0x0000U) /* Set b4 to 0. Controls CTS# pin with MCE, CTS2IO bit */
#define _SCIF_CTS_DATA_1                        (0x0010U) /* Set b4 to 1. Controls CTS# pin with MCE, CTS2IO bit */
/* CTS# Port Output Specify (CTS2IO) */
#define _SCIF_CTS_OUTPUT_0                      (0x0000U) /* Set b5 to 0. Controls CTS# pin with MCE, CTS2IO bit */
#define _SCIF_CTS_OUTPUT_1                      (0x0020U) /* Set b5 to 1. Controls CTS# pin with MCE, CTS2IO bit */
/* RTS# Port Data Select (RTS2DT) */
#define _SCIF_RTS_DATA_0                        (0x0000U) /* Set b6 to 0. Controls RTS# pin with MCE, RTS2IO bit */
#define _SCIF_RTS_DATA_1                        (0x0040U) /* Set b6 to 1. Controls RTS# pin with MCE, RTS2IO bit */
/* RTS# Port Output Specify (RTS2IO) */
#define _SCIF_RTS_OUTPUT_0                      (0x0000U) /* Set b7 to 0. Controls RTS# pin with MCE, RTS2IO bit */
#define _SCIF_RTS_OUTPUT_1                      (0x0080U) /* Set b7 to 1. Controls RTS# pin with MCE, RTS2IO bit */

/*
    FIFO Trigger Control Register (FTCR)
*/
/* Transmit FIFO Data Trigger Number (TFTC[4:0]) */
#define _SCIF_TX_FIFO_TRIGGER_NUM_0             (0x0000U) /* 0 (no transmit data trigger) */
#define _SCIF_TX_FIFO_TRIGGER_NUM_1             (0x0001U) /* 1 (transmit data triggers) */
#define _SCIF_TX_FIFO_TRIGGER_NUM_2             (0x0002U) /* 2 (transmit data triggers) */
#define _SCIF_TX_FIFO_TRIGGER_NUM_3             (0x0003U) /* 3 (transmit data triggers) */
#define _SCIF_TX_FIFO_TRIGGER_NUM_4             (0x0004U) /* 4 (transmit data triggers) */
#define _SCIF_TX_FIFO_TRIGGER_NUM_5             (0x0005U) /* 5 (transmit data triggers) */
#define _SCIF_TX_FIFO_TRIGGER_NUM_6             (0x0006U) /* 6 (transmit data triggers) */
#define _SCIF_TX_FIFO_TRIGGER_NUM_7             (0x0007U) /* 7 (transmit data triggers) */
#define _SCIF_TX_FIFO_TRIGGER_NUM_8             (0x0008U) /* 8 (transmit data triggers) */
#define _SCIF_TX_FIFO_TRIGGER_NUM_9             (0x0009U) /* 9 (transmit data triggers) */
#define _SCIF_TX_FIFO_TRIGGER_NUM_10            (0x000AU) /* 10 (transmit data triggers) */
#define _SCIF_TX_FIFO_TRIGGER_NUM_11            (0x000BU) /* 11 (transmit data triggers) */
#define _SCIF_TX_FIFO_TRIGGER_NUM_12            (0x000CU) /* 12 (transmit data triggers) */
#define _SCIF_TX_FIFO_TRIGGER_NUM_13            (0x000DU) /* 13 (transmit data triggers) */
#define _SCIF_TX_FIFO_TRIGGER_NUM_14            (0x000EU) /* 14 (transmit data triggers) */
#define _SCIF_TX_FIFO_TRIGGER_NUM_15            (0x000FU) /* 15 (transmit data triggers) */
/* Transmit Trigger Select (TTRGS) */
#define _SCIF_TX_TRIGGER_TTRG_VALID             (0x0000U) /* TTRG[1:0] bits in FCR are valid */
#define _SCIF_TX_TRIGGER_TFTC_VALID             (0x0080U) /* TFTC[4:0] bits in FTCR are valid */
/* Receive FIFO Data Trigger Number (RFTC[4:0]) */
#define _SCIF_RX_FIFO_TRIGGER_NUM_1             (0x0100U) /* 1 (receive data trigger) */
#define _SCIF_RX_FIFO_TRIGGER_NUM_2             (0x0200U) /* 2 (receive data triggers) */
#define _SCIF_RX_FIFO_TRIGGER_NUM_3             (0x0300U) /* 3 (receive data triggers) */
#define _SCIF_RX_FIFO_TRIGGER_NUM_4             (0x0400U) /* 4 (receive data triggers) */
#define _SCIF_RX_FIFO_TRIGGER_NUM_5             (0x0500U) /* 5 (receive data triggers) */
#define _SCIF_RX_FIFO_TRIGGER_NUM_6             (0x0600U) /* 6 (receive data triggers) */
#define _SCIF_RX_FIFO_TRIGGER_NUM_7             (0x0700U) /* 7 (receive data triggers) */
#define _SCIF_RX_FIFO_TRIGGER_NUM_8             (0x0800U) /* 8 (receive data triggers) */
#define _SCIF_RX_FIFO_TRIGGER_NUM_9             (0x0900U) /* 9 (receive data triggers) */
#define _SCIF_RX_FIFO_TRIGGER_NUM_10            (0x0A00U) /* 10 (receive data triggers) */
#define _SCIF_RX_FIFO_TRIGGER_NUM_11            (0x0B00U) /* 11 (receive data triggers) */
#define _SCIF_RX_FIFO_TRIGGER_NUM_12            (0x0C00U) /* 12 (receive data triggers) */
#define _SCIF_RX_FIFO_TRIGGER_NUM_13            (0x0D00U) /* 13 (receive data triggers) */
#define _SCIF_RX_FIFO_TRIGGER_NUM_14            (0x0E00U) /* 14 (receive data triggers) */
#define _SCIF_RX_FIFO_TRIGGER_NUM_15            (0x0F00U) /* 15 (receive data triggers) */
#define _SCIF_RX_FIFO_TRIGGER_NUM_16            (0x1000U) /* 16 (receive data triggers) */
/* Transmit Trigger Select (RTRGS) */
#define _SCIF_RX_TRIGGER_RTRG_VALID             (0x0000U) /* RTRG[1:0] bits in FCR are valid */
#define _SCIF_RX_TRIGGER_RFTC_VALID             (0x8000U) /* RFTC[4:0] bits in FTCR are valid */

/*
    Serial extended mode register (SEMR)
*/
/* Asynchronous base clock select (ABCS0) */
#define _SCIF_16_BASE_CLOCK                     (0x00U) /* Selects 16 base clock cycles for 1 bit period */
#define _SCIF_8_BASE_CLOCK                      (0x01U) /* Selects 8 base clock cycles for 1 bit period */
/* Noise Cancellation Enable (NFEN) */
#define _SCIF_NOISE_FILTER_DISABLE              (0x00U) /* Noise cancellation for the RxD pin input is disabled */
#define _SCIF_NOISE_FILTER_ENABLE               (0x04U) /* Noise cancellation for the RxD pin input is enabled */
/* Data Transfer Direction Select (DIR) */
#define _SCIF_DATA_TRANSFER_LSB_FIRST           (0x00U) /* Transmits the data in FTDR by the LSB-first method */
#define _SCIF_DATA_TRANSFER_MSB_FIRST           (0x08U) /* Transmits the data in FTDR by the MSB-first method */
/* Modulation Duty Register Select (MDDRS) */
#define _SCIF_BRR_USED                          (0x00U) /* BRR register can be accessed */
#define _SCIF_MDDR_USED                         (0x10U) /* MDDR register can be accessed. */
/* Bit Rate Modulation Enable (BRME) */
#define _SCIF_BIT_RATE_MODULATION_DISABLE       (0x00U) /* Bit rate modulation function is disabled */
#define _SCIF_BIT_RATE_MODULATION_ENABLE        (0x20U) /* Bit rate modulation function is enabled */
/* Baud Rate Generator Double-Speed Mode Select (BGDM) */
#define _SCIF_BAUDRATE_SINGLE                   (0x00U) /* Baud rate generator outputs normal frequency */
#define _SCIF_BAUDRATE_DOUBLE                   (0x80U) /* Baud rate generator doubles output frequency */

/*
    Interrupt Source Priority Register n (PRLn)
*/
/* Interrupt Priority Level Select (PRL[3:0]) */
#define _SCIF_PRIORITY_LEVEL0                   (0x00000000UL) /* Level 0 (highest) */
#define _SCIF_PRIORITY_LEVEL1                   (0x00000001UL) /* Level 1 */
#define _SCIF_PRIORITY_LEVEL2                   (0x00000002UL) /* Level 2 */
#define _SCIF_PRIORITY_LEVEL3                   (0x00000003UL) /* Level 3 */
#define _SCIF_PRIORITY_LEVEL4                   (0x00000004UL) /* Level 4 */
#define _SCIF_PRIORITY_LEVEL5                   (0x00000005UL) /* Level 5 */
#define _SCIF_PRIORITY_LEVEL6                   (0x00000006UL) /* Level 6 */
#define _SCIF_PRIORITY_LEVEL7                   (0x00000007UL) /* Level 7 */
#define _SCIF_PRIORITY_LEVEL8                   (0x00000008UL) /* Level 8 */
#define _SCIF_PRIORITY_LEVEL9                   (0x00000009UL) /* Level 9 */
#define _SCIF_PRIORITY_LEVEL10                  (0x0000000AUL) /* Level 10 */
#define _SCIF_PRIORITY_LEVEL11                  (0x0000000BUL) /* Level 11 */
#define _SCIF_PRIORITY_LEVEL12                  (0x0000000CUL) /* Level 12 */
#define _SCIF_PRIORITY_LEVEL13                  (0x0000000DUL) /* Level 13 */
#define _SCIF_PRIORITY_LEVEL14                  (0x0000000EUL) /* Level 14 */
#define _SCIF_PRIORITY_LEVEL15                  (0x0000000FUL) /* Level 15 */

/* FIFO buffer maximum size */
#define _SCIF_FIFO_MAX_SIZE                     (0x10U) /* Size of 16-stage FIFO buffer */

/***********************************************************************************************************************
Macro definitions
***********************************************************************************************************************/
#define _SCIF_1BIT_INTERVAL_1                   (0x00000105UL) /* Wait time for 1-bit interval */
#define _SCIF_RX_TRIG_NUM_1                     (0x01U) /* Receive FIFO data trigger number */
#define _SCIF_1BIT_INTERVAL_2                   (0x00000105UL) /* Wait time for 1-bit interval */
#define _SCIF_RX_TRIG_NUM_2                     (0x01U) /* Receive FIFO data trigger number */


/*
* Function Name: initUartModul
* Description  : Funktion initialisiert die UART Funktionen inkl. der Pins
*/
void initUartModul(void);


/*
* Function Name: initUartIO
* Description  : Funktion configuriert die Pinne der UART Kommunikation
*/
void initUartIO(void);



/*
* Function Name: createCmt1
* Description  : This function initializes the CMT1 channel.
*/
void createCmt1(void);


/*
* Function Name: startCmt1
* Description  : This function starts the CMT1 channel counter.
*/
void startCmt1(void);


/*
* Function Name: stopCmt1
* Description  : This function stops the CMT1 channel counter.
*/
void stopCmt1(void);


/*
* Function Name	: creatUartCh1
* Description  	: This function initializes SCIFA1.
* Author		: Joschka Randerath
*/
void creatUartCh1(void);



/*
* Function Name	: sendUartCh1
* Description  	: This function send tx_buf data to the FTDR
* Arguments    	: tx_buf -> Pointer to data
* 				  tx_num -> Size of tx_buf Array
* Author 		: Joschka Randerath
*/
void sendUartCh1(const uint8_t * tx_buf, uint16_t tx_num);


/*
* Function Name	: receiveUartCh1
* Description  	: This function read data from the FRDR register to the rx_buf
* Arguments    	: rx_buf -> Pointer to the rx-data Array
* Return Value	: rx_num -> Size of receive data
* Author 		: Joschka Randerath
*
* Important 	: rx_buf array must be large enough (maximum data in FRDR -> 16 Byte)
*/
void receiveUartCh1(uint8_t * rx_buf, uint16_t rx_num);



/*
 * Function Name	: 	uartHandler
 * Description  	:	Die Funktion versendet die PDO und ggs. die SDO-Daten per UART zum UART-Slave.
 * 						Anschließend werden die PDO unf ggfs. die SDO Daten vom UART-Slave empfangen.
 * 						Innherhalb dieser Funktion gibt es warte-Schleifen.
 * Author 			: 	Joschka Randerath
 */
void uartHandler(void);
	
	
/*
 * Function Name	: 	uartHandlerFsm
 * Description  	:	Die Funktion versendet die PDO und ggs. die SDO-Daten per UART zum UART-Slave.
 * 						Anschließend werden die PDO unf ggfs. die SDO Daten vom UART-Slave empfangen.
 * 						Diese Funktion ist als Mealy Automat implementiert 
 * Return Value		: 	Aussage über den aktuellen Staus der UART Kommunikation (UART_BEREIT, UART_BUSSY, UART_KOM_ABGESCHLOSSEN, UART_ERROR)
 * Author 			: 	Joschka Randerath
 */	
uint8_t uartHandlerFsm(void);

#endif
