/*******************************************************************************
* DISCLAIMER
* This software is supplied by Renesas Electronics Corporation and is only
* intended for use with Renesas products. No other uses are authorized. This
* software is owned by Renesas Electronics Corporation and is protected under
* all applicable laws, including copyright laws.
* THIS SOFTWARE IS PROVIDED "AS IS" AND RENESAS MAKES NO WARRANTIES REGARDING
* THIS SOFTWARE, WHETHER EXPRESS, IMPLIED OR STATUTORY, INCLUDING BUT NOT
* LIMITED TO WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE
* AND NON-INFRINGEMENT. ALL SUCH WARRANTIES ARE EXPRESSLY DISCLAIMED.
* TO THE MAXIMUM EXTENT PERMITTED NOT PROHIBITED BY LAW, NEITHER RENESAS
* ELECTRONICS CORPORATION NOR ANY OF ITS AFFILIATED COMPANIES SHALL BE LIABLE
* FOR ANY DIRECT, INDIRECT, SPECIAL, INCIDENTAL OR CONSEQUENTIAL DAMAGES FOR
* ANY REASON RELATED TO THIS SOFTWARE, EVEN IF RENESAS OR ITS AFFILIATES HAVE
* BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGES.
* Renesas reserves the right, without notice, to make changes to this software
* and to discontinue the availability of this software. By using this software,
* you agree to the additional terms and conditions found by accessing the
* following link:
* http://www.renesas.com/disclaimer
*
* Copyright (C) 2018 Renesas Electronics Corporation. All rights reserved.
*******************************************************************************/
/*******************************************************************************
* System Name  : EtherCAT SSC CiA402 dummy Motor program for RZ/T1
* File Name    : main.c
* Version      : 1.1
* Device       : R7S910017
* Abstract     : EtherCAT SSC CiA402 dummy Motor program for RZ/T1
* Tool-Chain   : IAR Embedded Workbench for ARM
*              : e2studio
*              : ARM DS-5 Development Studio
* OS           : not use
* H/W Platform : RZ/T1 Evaluation Board (RTK7910022C00000BR)
* Description  : EtherCAT SSC CiA402 dummy Motor program for RZ/T1
* Limitation   : none
*******************************************************************************/
/*******************************************************************************
* History      : DD.MM.YYYY Version  Description
*              : 01.12.2015 1.0      First Release
*              : 19.07.2018 1.1      Second Release
******************************************************************************/
/**
	Joschka Randerath -> Version 2.3
**/ 
/*******************************************************************************
Includes <System Includes> , "Project Includes"
*******************************************************************************/
#include <stdint.h>
#include "iodefine.h"
#include "r_system.h"
#include "r_cmt.h"
#include "r_mpc2.h"
#include "r_reset2.h"
#include "r_port.h"
#include "r_ecm.h"
#include "r_ether.h"

#include "board.h"
#include "renesashw.h"
#include "applInterface.h"
#include "CiA402Example.h"
#include "ecatslv.h"

#include "uart.h"

/*******************************************************************************
Macro definitions
*******************************************************************************/
#define	ESC_BASE				(0xA00D0000)						// ESC base address
/* MOTOR */
#define		MTR_MODE_STOP       (0)
#define		MTR_MODE_RUN        (1)
/* SW */
#define		SW_ON               (0)                            /* active level of SW */
#define		SW_OFF              (1)                            /* inactive level of SW */
#define		CHATTERING_CNT      (10)                           /* remove chattering count */


/*******************************************************************************
Exported global variables and functions (to be accessed by other files)
*******************************************************************************/
int main(void);



/*******************************************************************************
Private variables and functions
*******************************************************************************/

static void ctrl_ui(void);
static void cmt_standby(void);
static void port_init(void);
static void ecm_init(void);
static void icu_init(void);
static uint8_t get_sw1(void);
static uint8_t get_sw2(void);
static void led0_out(uint8_t status);
static void led1_out(uint8_t status);
static void DummyMotor(uint32_t channel);


/*******************************************************************************
* Outline      : main processing
* Function Name: main
* Description  : SHM sample program of RZ/T1.
* Arguments    : none
* Return Value : none
*******************************************************************************/
int main (void)
{
	// --- Initialize board depend ---
	board_init();

    /* Initialize the port function */
    port_init();

    /* Initialize the ECM function */
    ecm_init();

   /* Initialize the ICU settings */
    icu_init();

    cmt_standby();

    /* ---- CMT Setting ---- */
    /* Initialize CMT */
    R_CMT_Init(CMT_CH_0, CMT_CKS_DIVISION_512);

	/*----------------------------------------------------------------------*/
	/* setup EtherCAT														*/
	/*----------------------------------------------------------------------*/
	// --- Initialize EtherCAT ---
	EtherCAT_init();

	/* set esc register base address */
	pEsc = (MEM_ADDR ESCMEM *) ESC_BASE;

	/* initialize the EtherCAT slave interface */
	HW_Init();

	/* enable irq */
	R_ETHER_IRQ_Init();

	/* init stack */
	MainInit();

	/* create basic mapping */
	APPL_GenerateMapping(&nPdInputSize,&nPdOutputSize);

	/* Init UART Modul */
	initUartModul();

	/*----------------------------------------------------------------------*/
	/* Main loop process													*/
	/*----------------------------------------------------------------------*/
	/* set stack run flag */
	bRunApplication = TRUE;

	/* main loop */
	do
	{
		/* EtherCAT : stack main loop */
		MainLoop();

		/* UART Modul : main loop */
		uartHandlerFsm();
	}while (bRunApplication == TRUE);


	/* hw release */
	HW_Release();
}
/*******************************************************************************
 End of function main
*******************************************************************************/

/*******************************************************************************
* Function Name: cmt_standby
* Description  : Release the CMT module stop status.
* Arguments    : none
* Return Value : none
*******************************************************************************/
static void cmt_standby (void)
{
    volatile uint32_t dummy32;

    /* Enables writing to the registers related to Reset and Low-Power function */
    R_RST_WriteEnable();

    MSTP(CMT0) = 0;    /* CMT unit0 release */
    MSTP(CMT1) = 0;    /* CMT unit1 release */
    MSTP(CMT2) = 0;    /* CMT unit2 release */
	dummy32 = SYSTEM.MSTPCRA.LONG;

    /* Disables writing to the registers related to Reset and Low-Power function */
    R_RST_WriteDisable();
}

/*******************************************************************************
* Function Name: port_init
* Description  : Initialize port setting as following.
*                 PF7 : Output and low level.
*                 P56 : Output and low level.
* Arguments    : none
* Return Value : none
*******************************************************************************/
static void port_init(void)
{
    /* Set PF7 to Output port pin (Using LED0) */
    PORTF.PDR.BIT.B7 = PORT_DIRECTION_HIZ;     // Initialize port settings
    PORTF.PMR.BIT.B7 = PORT_MODE_GENERAL;

    PORTF.PODR.BIT.B7 = PORT_OUTPUT_LOW;       // Set output level to Low
    PORTF.PDR.BIT.B7 = PORT_DIRECTION_OUTPUT;  // Set port direction to output


    /* Set P56 to Output port pin (Using LED1) */
    PORT5.PDR.BIT.B6 = PORT_DIRECTION_HIZ;     // Initialize port settings
    PORT5.PMR.BIT.B6 = PORT_MODE_GENERAL;

    PORT5.PODR.BIT.B6 = PORT_OUTPUT_LOW;       // Set output level to Low
    PORT5.PDR.BIT.B6 = PORT_DIRECTION_OUTPUT;  // Set port direction to output

    /* Set P35 to Input port pin (Using SW1) */
    PORT3.PDR.BIT.B5 = PORT_DIRECTION_HIZ;     // Initialize port settings
    PORT3.PMR.BIT.B5 = PORT_MODE_GENERAL;

    PORT3.PDR.BIT.B5 = PORT_DIRECTION_INPUT;   // Set port direction to input

    /* Set PN5 to Input port pin (Using SW2) */
    PORTN.PDR.BIT.B5 = PORT_DIRECTION_HIZ;     // Initialize port settings
    PORTN.PMR.BIT.B5 = PORT_MODE_GENERAL;

    PORTN.PDR.BIT.B5 = PORT_DIRECTION_INPUT;   // Set port direction to input

}

/*******************************************************************************
* Function Name: ecm_init
* Description  : Initialize ECM setting as following.
*                  Error 35 : Permit to generate the ECM reset
* Arguments    : none
* Return Value : none
*******************************************************************************/
static void ecm_init(void)
{
    /* Initialize ECM function  */
    R_ECM_Init();

}

/*******************************************************************************
* Function Name: icu_init
* Description  : Initialize Interrupt Controller Unit setting.
* Arguments    : none
* Return Value : none
*******************************************************************************/
static void icu_init(void)
{
    /* Initialize VIC (dummy writing to HVA0 register) */
    HVA0_DUMMY_WRITE();

    /* Enable IRQ interrupt (Clear CPSR.I bit to 0) */
#if   defined(__ICCARM__)
    asm("cpsie i");   // Clear CPSR.I bit to 0
    asm("isb");       // Ensuring Context-changing
#elif defined(__CC_ARM)
    __enable_irq();   // Clear CPSR.I bit to 0
    __asm("isb");     // Ensuring Context-changing
#elif defined(__GNUC__)
    asm("cpsie i");   // Clear CPSR.I bit to 0
    asm("isb");       // Ensuring Context-changing
#endif
    
}



/******************************************************************************
* Function Name : get_sw1
* Description   : Get state of SW1
* Arguments     : none
* Return Value  : State of SW1
******************************************************************************/
static uint8_t get_sw1(void)
{
    uint8_t tmp_port;

    tmp_port = PORT3.PIDR.BIT.B5;

    return (tmp_port);
}

/******************************************************************************
* Function Name : get_sw2
* Description   : Get state of SW2
* Arguments     : none
* Return Value  : state of SW2
******************************************************************************/
static uint8_t get_sw2(void)
{
    uint8_t tmp_port;

    tmp_port = PORTN.PIDR.BIT.B5;

    return (tmp_port);
}

/*******************************************************************************
* Function Name: led0_out
* Description  : Turn on/off LED0
* Arguments    : none
* Return Value : none
*******************************************************************************/
static void led0_out(uint8_t status)
{
	PORTF.PODR.BIT.B7 = status;
}

/*******************************************************************************
* Function Name: led1_out
* Description  : Turn on/off LED1
* Arguments    : none
* Return Value : none
*******************************************************************************/
static void led1_out(uint8_t status)
{
	PORT5.PODR.BIT.B6 = status;
}
/* End of File */


