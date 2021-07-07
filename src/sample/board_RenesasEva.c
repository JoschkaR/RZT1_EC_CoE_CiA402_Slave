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
* Copyright (C) 2015 Renesas Electronics Corporation. All rights reserved.
*******************************************************************************/
/*******************************************************************************
* System Name  : EtherCAT SSC CiA402 dummy Motor program for RZ/T1
* File Name    : board_RenesasEva.c
* Version      : 1.0
* Device       : R7S910017
* Tool-Chain   : IAR Embedded Workbench for ARM
*              : e2studio
*              : ARM DS-5 Development Studio
* OS           : not use
* H/W Platform : RZ/T1 Evaluation Board (RTK7910022C00000BR)
* Description  : This is the main tutorial code.
* Limitations  :
******************************************************************************/
/*******************************************************************************
* History      : DD.MM.YYYY Version  Description
*              : 01.12.2015 1.0      First Release
*              : 21.01.2016 1.1      Change PHY KSZ8041TL setting
******************************************************************************/

/******************************************************************************
Includes <System Includes> , "Project Includes"
******************************************************************************/
#include <stdint.h>

#include "iodefine.h"


/******************************************************************************
Macro definitions
******************************************************************************/

/******************************************************************************
Typedef definitions
******************************************************************************/

/******************************************************************************
Exported global variables (to be accessed by other files)
******************************************************************************/

/******************************************************************************
Private global variables and functions
******************************************************************************/

/*******************************************************************************
* Function Name: board_init
* Description  : Initializes board dependent settings
* Arguments    : none
* Return Value : noce
*******************************************************************************/
void board_init(void)
{
	volatile uint32_t	tmp_32bit;

	//=========================================
	// Initialize Port
	//=========================================
	// ====== Unlock MPC register ======
	MPC.PWPR.BYTE = 0x00;							// Enable PFSWE write access
	MPC.PWPR.BYTE = 0x40;							// Enable PFS   write access

	//---------------------------------
	// For Ether port 0/1
	//  (include EtherCAT)
	//---------------------------------
	// --- Port 5 ---
	MPC.P50PFS.BYTE = 0x11;						// P50 : PHYLINK0
	MPC.P51PFS.BYTE = 0x11;						// P51 : PHYLINK1
	MPC.P52PFS.BYTE = 0x11;						// P52 : ETH0_INT
	MPC.P53PFS.BYTE = 0x11;						// P53 : ETH1_INT
	MPC.P54PFS.BYTE = 0x11;						// P54 : CLKOUT25M1

	PORT5.PMR.BYTE |= 0x1F;						// P50-P54 :

	// --- Port 8 ---
	MPC.P80PFS.BYTE = 0x11;						// P80 : ETH0_RXDV
	MPC.P81PFS.BYTE = 0x11;						// P81 : ETH0_RXER
	MPC.P82PFS.BYTE = 0x11;						// P82 : ETH0_TXEN
	MPC.P83PFS.BYTE = 0x11;						// P83 : ETH0_CRS
	MPC.P84PFS.BYTE = 0x11;						// P84 : ETH0_COL
	MPC.P85PFS.BYTE = 0x11;						// P85 : LKOUT25M0
	MPC.P86PFS.BYTE = 0x11;						// P86 : ETH1_TXD0
	MPC.P87PFS.BYTE = 0x11;						// P87 : ETH1_TXC

	PORT8.PMR.BYTE |= 0xFF;						// P80-P87 :

	// --- Port B ---
	MPC.PB0PFS.BYTE = 0x11;						// PB0 : ETH1_RXDV
	MPC.PB1PFS.BYTE = 0x11;						// PB1 : ETH1_RXER
	MPC.PB2PFS.BYTE = 0x11;						// PB2 : ETH1_RXC
	MPC.PB3PFS.BYTE = 0x11;						// PB3 : ETH1_CRS
	MPC.PB4PFS.BYTE = 0x11;						// PB4 : ETH1_COL
	MPC.PB5PFS.BYTE = 0x11;						// PB5 : ETH_MDIO
	MPC.PB6PFS.BYTE = 0x11;						// PB6 : ETH_MDC
	MPC.PB7PFS.BYTE = 0x11;						// PB7 : ETH1_RXD1

	PORTB.PMR.BYTE |= 0xFF;						// PB0-PB7 :

	// --- Port C ---
	MPC.PC0PFS.BYTE = 0x11;						// PC0 : ETH1_RXD2
	MPC.PC1PFS.BYTE = 0x11;						// PC1 : ETH1_RXD3
	MPC.PC2PFS.BYTE = 0x11;						// PC2 : ETH0_TXC
	MPC.PC3PFS.BYTE = 0x11;						// PC3 : ETH0_RXC
	MPC.PC4PFS.BYTE = 0x16;						// PC4 : CATI2CCLK
	MPC.PC5PFS.BYTE = 0x16;						// PC5 : CATI2CDATA

	PORTC.PMR.BYTE |= 0x3F;						// PC0-PC5 :

	// --- Port D ---
	MPC.PD5PFS.BYTE = 0x11;						// PD5 : ETH1_TXD3
	MPC.PD6PFS.BYTE = 0x11;						// PD6 : ETH1_TXD2
	MPC.PD7PFS.BYTE = 0x11;						// PD7 : ETH1_TXD1

	PORTD.PMR.BYTE |= 0xE0;						// PD5-PC7 :

	// --- Port F ---
	MPC.PF5PFS.BYTE = 0x11;						// PF5 : ETH1_TXEN
	MPC.PF6PFS.BYTE = 0x11;						// PF6 : ETH1_RXD0

	PORTF.PMR.BYTE |= 0x60;						// PF5-PF6 :

	// --- Port J ---
	MPC.PJ0PFS.BYTE = 0x11;						// PJ0 : ETH0_TXD3
	MPC.PJ1PFS.BYTE = 0x11;						// PJ1 : ETH0_TXD2
	MPC.PJ2PFS.BYTE = 0x11;						// PJ2 : ETH0_TXD1
	MPC.PJ3PFS.BYTE = 0x11;						// PJ3 : ETH0_TXD0
	MPC.PJ4PFS.BYTE = 0x11;						// PJ4 : ETH0_RXD0
	MPC.PJ5PFS.BYTE = 0x11;						// PJ5 : ETH0_RXD1
	MPC.PJ6PFS.BYTE = 0x11;						// PJ6 : ETH0_RXD2
	MPC.PJ7PFS.BYTE = 0x11;						// PJ7 : ETH0_RXD3

	PORTJ.PMR.BYTE |= 0xFF;						// PJ0-PJ7 :

	// --- Port M ---
	MPC.PM1PFS.BYTE = 0x16;						// PM1 : CATLEDERR
	MPC.PM2PFS.BYTE = 0x15;						// PM2 : CATSYNC1
	MPC.PM3PFS.BYTE = 0x15;						// PM3 : CATSYNC0
	MPC.PM4PFS.BYTE = 0x16;						// PM4 : CATLEDRUN
	MPC.PM5PFS.BYTE = 0x16;						// PM5 : CATLEDSTER
	MPC.PM6PFS.BYTE = 0x16;						// PM6 : CATLINKACT0
	MPC.PM7PFS.BYTE = 0x16;						// PM7 : CATLINKACT1

	PORTM.PMR.BYTE |= 0xFE;						// PM1-PM7 :

	// --- Port U ---
	MPC.PU6PFS.BYTE = 0x16;						// PU6 : PHYRESETOUT#

	PORTU.PMR.BYTE |= 0x40;						// PU6 :

	//---------------------------------
	// For Ether port 2
	//---------------------------------
	// --- Port D ---
	MPC.PD3PFS.BYTE = 0x14;						// PD3 : PHYRESETOUT2#
	MPC.PD4PFS.BYTE = 0x14;						// PD4 : ETH2_INT

	PORTD.PMR.BYTE |= 0x18;						// PD3-PC4 :

	// --- Port K ---
	MPC.PK4PFS.BYTE = 0x14;						// PK4 : ETH2_TXER
	MPC.PK5PFS.BYTE = 0x14;						// PK5 : ETH2_TXD1
	MPC.PK6PFS.BYTE = 0x14;						// PK6 : ETH2_TXD3
	MPC.PK7PFS.BYTE = 0x14;						// PK7 : ETH2_TXD2

	PORTK.PMR.BYTE |= 0xF0;						// PK4-PK7 :

	// --- Port L ---
	MPC.PL0PFS.BYTE = 0x14;						// PL0 : ETH2_TXD0
	MPC.PL1PFS.BYTE = 0x14;						// PL1 : ETH2_TXC
	MPC.PL2PFS.BYTE = 0x14;						// PL2 : ETH2_TXEN
	MPC.PL3PFS.BYTE = 0x14;						// PL3 : ETH2_RXD0
	MPC.PL4PFS.BYTE = 0x14;						// PL4 : ETH2_RXD1
	MPC.PL5PFS.BYTE = 0x14;						// PL5 : ETH2_RXD2
	MPC.PL6PFS.BYTE = 0x14;						// PL6 : ETH2_RXD3
	MPC.PL7PFS.BYTE = 0x14;						// PL7 : ETH2_RXDV

	PORTL.PMR.BYTE |= 0xFF;						// PL0-PL7 :

	// --- Port M ---
	MPC.PM0PFS.BYTE = 0x14;						// PM0 : CLKOUT25M2

	PORTM.PMR.BYTE |= 0x01;						// PM0 :

	// --- Port U ---
	MPC.PU0PFS.BYTE = 0x14;						// PU0 : ETH2_RXER
	MPC.PU1PFS.BYTE = 0x14;						// PU1 : ETH2_RXC
	MPC.PU2PFS.BYTE = 0x14;						// PU2 : ETH2_CRS
	MPC.PU3PFS.BYTE = 0x14;						// PU3 : ETH2_COL
	MPC.PU4PFS.BYTE = 0x14;						// PU4 : MII2_MDC
	MPC.PU5PFS.BYTE = 0x14;						// PU5 : MII2_MDIO

	PORTU.PMR.BYTE |= 0x3F;						// PU0-PU5 :

	//---------------------------------
	// For UART(USB)
	//---------------------------------
	// --- Port 9 ---
	MPC.P91PFS.BYTE = 0x0B;						// P91 : TXD2
	MPC.P92PFS.BYTE = 0x0B;						// P92 : RXD2
	MPC.P94PFS.BYTE = 0x0B;						// P94 : RTS2#
	MPC.P95PFS.BYTE = 0x0B;						// P95 : CTS2#

	PORT9.PMR.BYTE |= 0x36;						// P91,P92,P94,P95 :

	// ====== Lock MPC register ======
	MPC.PWPR.BYTE = 0x00;							// Disable PFS   write access
	MPC.PWPR.BYTE = 0x80;							// Disable PFSWE write access

}
