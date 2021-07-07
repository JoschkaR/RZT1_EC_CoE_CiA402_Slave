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
* System Name  : RZ/T1 Ether program
* File Name    : r_ether.c
* Version      : 1.1
* Device       : R7S910017
* Abstract     : API for Ether function
* Tool-Chain   : e2studio
* OS           : not use
* H/W Platform : RZ/T1 Evaluation Board (RTK7910022C00000BR)
* Description  : Ether setting API of RZ/T1
* Limitation   : none
*******************************************************************************/
/*******************************************************************************
* History      : DD.MM.YYYY Version  Description
*              : 01.12.2015 1.0      First Release
*              : 01.09.2016 1.1      Second Release
*                                     - No modification
*******************************************************************************/

/*******************************************************************************
Includes <System Includes> , "Project Includes"
*******************************************************************************/
#include <stdint.h>
#ifdef __ICCARM__
#include "intrinsics.h"
#endif // __iccarm__
#include "iodefine.h"
#include "r_system.h"
#include "r_icu_init.h"
#include "r_ether.h"

#include "ecatappl.h"


/*******************************************************************************
Typedef definitions
*******************************************************************************/
#define PHY_RESET_WAIT_TIME	(500*1000)	/* ns */
#define CPU_CLK				(150)		/* MHz */
#define WAIT_LOOP_CYCLE		(7)

/*******************************************************************************
Macro definitions
*******************************************************************************/


/*******************************************************************************
Imported global variables and functions (from other files)
*******************************************************************************/


/*******************************************************************************
Exported global variables and functions (to be accessed by other files)
*******************************************************************************/


/*******************************************************************************
Private global variables and functions
*******************************************************************************/
int32_t ether_irq_init( void );

#ifdef __ICCARM__
__irq __nested __arm	void ecat_sync0_isr(void);			// Vector No.[073] : EtherCAT Sync0
__irq __nested __arm	void ecat_sync1_isr(void);			// Vector No.[074] : EtherCAT Sync1
__irq __nested __arm	void ecat_isr(void);				// Vector No.[075] : EtherCAT
#elif __CC_ARM
__irq					void ecat_sync0_isr(void);			// Vector No.[073] : EtherCAT Sync0
__irq					void ecat_sync1_isr(void);			// Vector No.[074] : EtherCAT Sync1
__irq					void ecat_isr(void);				// Vector No.[075] : EtherCAT
#elif __GNUC__
void ecat_sync0_isr(void)	__attribute__ ((interrupt));	// Vector No.[073] : EtherCAT Sync0
void ecat_sync1_isr(void)	__attribute__ ((interrupt));	// Vector No.[074] : EtherCAT Sync1
void ecat_isr(void)			__attribute__ ((interrupt));	// Vector No.[075] : EtherCAT
#endif // __gnuc__

void ether_write_phyreg(uint8_t phyadr, uint8_t regadr, uint16_t val);
uint16_t ether_read_phyreg(uint8_t phyadr, uint8_t regadr);
void ether_wait_ns(uint32_t value);

/**
 ******************************************************************************
  @brief  Initialize EtherCAT
  @param  none
  @retval none
 ******************************************************************************
*/
void EtherCAT_init( void )
{
    volatile uint32_t dummy32;
	volatile uint16_t tmp16;

	// ====== Unlock ethernet system register ======
	ETHERC.ETSPCMD.LONG			= 0x000000A5;
	ETHERC.ETSPCMD.LONG			= 0x00000001;
	ETHERC.ETSPCMD.LONG			= 0x0000FFFE;
	ETHERC.ETSPCMD.LONG			= 0x00000001;

	//---------------------------------
	// Initialize PHY Link
	//---------------------------------
	ETHERSW.ETHPHYLNK.LONG = 0x0000000C;			// PHYLINK0 Active Level : Low
													// PHYLINK1 Active Level : Low
	//---------------------------------
	// Initialize EtherCAT
	//---------------------------------
	// --- PHY address offset ---
	ECATC.CATOFFADD.LONG = 0x000000001;				// address offset : 1

	// --- EEPROM size ---
	ECATC.CATEMMD.LONG = 0x000000000;				// EEPROM  0:lower 16Kbit, 1:upper 32Kbit

	// --- TXC delay ---
	ECATC.CATTXCSFT.LONG = 0x000000000;				// [1:0] ETH0_TXC delay 00:0ns, 01:10ns, 10:20ns, 11:30ns
													// [3:2] ETH1_TXC delay 00:0ns, 01:10ns, 10:20ns, 11:30ns

	// ====== Lock ethernet system register ======
	ETHERC.ETSPCMD.LONG = 0x00000000;

	//=========================================
	// Module stop control
	//=========================================
	// ====== Unlock system register ======
	SYSTEM.PRCR.LONG			= 0x0000A502;					// Enable MSTPCRB write access

	//------------------------------------
	// Release EtherCAT, PHY Clock module
	//------------------------------------
	SYSTEM.MSTPCRB.LONG			&= ~(0x00088000);				// Module start
																//  [15] EtherCAT
																//  [19] CLKOUT25Mn
	dummy32 = SYSTEM.MSTPCRB.LONG;

	// ====== Lock MPC register ======
	SYSTEM.PRCR.LONG = 0x0000A500;								// Disable MSTPCRB write access

	// ====== Unlock ethernet system register ======
	ETHERC.ETSPCMD.LONG			= 0x000000A5;
	ETHERC.ETSPCMD.LONG			= 0x00000001;
	ETHERC.ETSPCMD.LONG			= 0x0000FFFE;
	ETHERC.ETSPCMD.LONG			= 0x00000001;

	//=========================================
	// Initialize MACSEL
	//=========================================
	ETHERC.MACSEL.LONG 			= 0x00000001;					// Port 0 : EtherCAT
																// Port 1 : EtherCAT
																// Port 2 : EtherMAC (w/o Switch)
	ETHERC.EMACRST.LONG   = 0x00000001;				// EtherMAC
	//=========================================
	// Initialize MII converter
	//=========================================
	ETHERC.MII_CTRL0.LONG		= 0x00000100;					// MII full
	ETHERC.MII_CTRL1.LONG		= 0x00000100;					// MII full
	ETHERC.MII_CTRL2.LONG		= 0x00000100;					// MII full

	//=========================================
	// EtherCAT Release reset
	//=========================================
	ETHERC.ETHSFTRST.LONG 		= 0x00000001;		// [0] EtherCAT

    // Wait Loading ESC EEPROM 
	while(1){
		if(ECATC.ESC_DL_STATUS.BIT.PDIOPE == 1)
			break;									// Loading successful, PDI operations
		tmp16 = ECATC.EEP_CONT_STAT.WORD & 0x2800;
		if(tmp16 == 0x0800)							// ACMDERR,CKSUMERR = 01
		   break;									// EEPROM is loaded, but it is blank
		if(tmp16 == 0x2800)							// ACMDERR,CKSUMERR = 11
		   break;									// I2C bus error
	}
	//=========================================
	// PHY Release reset
	//=========================================
	ETHERC.ETHSFTRST.LONG 		= 0x0000001D;					// [0] EtherCAT
																// [2] PHYRESETOUT
																// [3] PHYRESETOUT2
																// [4] MII Converter
	// ====== Lock ethernet system register ======
	ETHERC.ETSPCMD.LONG			= 0x00000000;

	// Wait after reset
	ether_wait_ns(PHY_RESET_WAIT_TIME);

	//---------------------------------
	// Change PHY KSZ8041TL setting
	//---------------------------------
	//
	//  Deafult LED0 pin status does not match RZ/T1 PHYLINK specification.
	//
	ether_write_phyreg(0, 0x1E, 0x4000);			// LED mode = [01]
	ether_write_phyreg(1, 0x1E, 0x4000);			// LED0 : Link
	//
	//  To satisfy EthreCAT requirement, the PHYs must not modify the preamble length.
	//
	ether_write_phyreg(0, 0x14, 0x0080);			// MII 100Mbps Preamble Restore mode
	ether_write_phyreg(1, 0x14, 0x0080);

}

/*******************************************************************************
* Function Name: R_ETHER_IRQ_Init
* Description  : This function initialize the CMT settings.
* Arguments    : none
* Return Value : int32          : ETHER_SECCESS
*              :                : ETHER_ERR
*******************************************************************************/
int32_t R_ETHER_IRQ_Init( void )
{
	int32_t ret;

    ret = ether_irq_init();

    return ret;
}

/*******************************************************************************
* Function Name: ether_irq_init
* Description  :
* Arguments    : none
* Return Value : int32          : ETHER_SECCESS
*              :                : ETHER_ERR
*******************************************************************************/
int32_t ether_irq_init( void )
{
    int32_t ret = ETHER_SUCCESS;

    R_ICU_Disable(ICU_VEC_NUM_73);
    R_ICU_Regist(ICU_VEC_NUM_73, ICU_TYPE_EDGE, ICU_PRIORITY_3, (uint32_t)ecat_sync0_isr);
    R_ICU_Enable(ICU_VEC_NUM_73);

    R_ICU_Disable(ICU_VEC_NUM_74);
    R_ICU_Regist(ICU_VEC_NUM_74, ICU_TYPE_EDGE, ICU_PRIORITY_3, (uint32_t)ecat_sync1_isr);
    R_ICU_Enable(ICU_VEC_NUM_74);

    R_ICU_Disable(ICU_VEC_NUM_75);
    R_ICU_Regist(ICU_VEC_NUM_75, ICU_TYPE_LEVEL, ICU_PRIORITY_3, (uint32_t)ecat_isr);
    R_ICU_Enable(ICU_VEC_NUM_75);

    return ret;
}

/*******************************************************************************
* Function Name: ecat_sync0_isr
* Description  : EtherCAT Sync0 Interrupt
* Arguments    : none
* Return Value : none
*******************************************************************************/
#ifdef __ICCARM__
__irq __nested __arm
#elif __CC_ARM
__irq
#endif // __iccarm__
void ecat_sync0_isr( void )
{
	/* clear interrupt */
    VIC.PIC2.BIT.PIC73 = 1;
	/* call interrupt handler */
	Sync0_Isr();
	/* end interrupt sequence (dummy writing) */
	HVA0_DUMMY_WRITE();
}

/*******************************************************************************
* Function Name: ecat_sync1_isr
* Description  : EtherCAT Sync1 Interrupt
* Arguments    : none
* Return Value : none
*******************************************************************************/
#ifdef __ICCARM__
__irq __nested __arm
#elif __CC_ARM
__irq
#endif // __iccarm__
void ecat_sync1_isr( void )
{
	/* clear interrupt */
    VIC.PIC2.BIT.PIC74 = 1;
	/* call interrupt handler */
	Sync1_Isr();
	/* end interrupt sequence (dummy writing) */
	HVA0_DUMMY_WRITE();
}

/*******************************************************************************
* Function Name: ecat_isr
* Description  : EtherCAT Interrupt
* Arguments    : none
* Return Value : none
*******************************************************************************/
#ifdef __ICCARM__
__irq __nested __arm
#elif __CC_ARM
__irq
#endif // __iccarm__
void ecat_isr( void )
{
	/* call interrupt handler */
	PDI_Isr();
	/* end interrupt sequence (dummy writing) */
	HVA0_DUMMY_WRITE();
}

/*******************************************************************************
* Function Name: ether_write_phyreg
* Description  : Write PHY register
* Arguments    : uint8_t  phyadr -- Phy address
*              : (It is necessary to consider CATOFFADD addition)
*              : uint8_t  regadr -- Register address
*              : uint16_t val    -- Register value
* Return Value : none
*******************************************************************************/
void ether_write_phyreg(uint8_t phyadr, uint8_t regadr, uint16_t val)
{

	// Wait
	while (ECATC.MII_CONT_STAT.BIT.BUSY == 1)
	{
	}

	// Get PDI access right
	ECATC.MII_PDI_ACS_STAT.BIT.ACSMII = 1;
	while (ECATC.MII_ECAT_ACS_STAT.BIT.ACSMII == 1)
	{
	}

	// Write PHY register 
	ECATC.PHY_ADR.BYTE       = phyadr;
	ECATC.PHY_REG_ADR.BYTE   = regadr;
	ECATC.PHY_DATA.WORD      = val;
	ECATC.MII_CONT_STAT.WORD = (2<<8) | (1<<0);		// Write command

	// Wait
	while (ECATC.MII_CONT_STAT.BIT.BUSY == 1)
	{
	}

	// Check the error bit
	if ( (ECATC.MII_CONT_STAT.BIT.CMDERR == 1) ||
		 (ECATC.MII_CONT_STAT.BIT.READERR == 1)  )
	{
		// Error operation
//		ECATC.MII_CONT_STAT.WORD = 0x0000; // Clear error bit 
	}

	// Give the access right to ECAT
	ECATC.MII_PDI_ACS_STAT.BIT.ACSMII = 0;
}

/*******************************************************************************
* Function Name: ether_read_phyreg
* Description  : Read PHY register
* Arguments    : uint8_t  phyadr -- Phy address
*              : (It is necessary to consider CATOFFADD addition)
*              : uint8_t  regadr -- Register address
* Return Value : uint16_t -- Register value
*******************************************************************************/
uint16_t ether_read_phyreg(uint8_t phyadr, uint8_t regadr)
{
	uint16_t reg_tmp;

	// Wait
	while (ECATC.MII_CONT_STAT.BIT.BUSY == 1)
	{
	}

	// Get PDI access right
	ECATC.MII_PDI_ACS_STAT.BIT.ACSMII = 1;
	while (ECATC.MII_ECAT_ACS_STAT.BIT.ACSMII == 1)
	{
	}

	// Read PHY register
	ECATC.PHY_ADR.BYTE       = phyadr;
	ECATC.PHY_REG_ADR.BYTE   = regadr;
	ECATC.MII_CONT_STAT.WORD = (1<<8) | (1<<0);		// Read command

	// Wait
	while (ECATC.MII_CONT_STAT.BIT.BUSY == 1)
	{
	}

	// Check the error bit
	if ( (ECATC.MII_CONT_STAT.BIT.CMDERR == 1) ||
		 (ECATC.MII_CONT_STAT.BIT.READERR == 1)  )
	{
		// Error operation
//		ECATC.MII_CONT_STAT.WORD = 0x0000; // Clear error bit 
	}

	// Get read data
	reg_tmp = ECATC.PHY_DATA.WORD;

	// Give the access right to ECAT
	ECATC.MII_PDI_ACS_STAT.BIT.ACSMII = 0;

	return reg_tmp;
}

/*******************************************************************************
* Function Name: ether_wait_ns
* Description  : ns wait
* Arguments    : uint32_t value -- Wait time value(ns)
* Return Value : none
*******************************************************************************/
#if defined ( __ICCARM__ )
#pragma inline=never
#else	/* __CC_ARM__ || __GNUC__ */
__attribute__((noinline))
#endif

void ether_wait_ns(uint32_t value)
{
    uint32_t wait;
    uint16_t clk;

	clk = CPU_CLK;

    wait = (value * 10) / (10000 / clk) / WAIT_LOOP_CYCLE + 1;

#if defined ( __CC_ARM )
	__asm("mov   r0,wait   \n"
		  "eth_wait_loop:  \n"
		  "nop             \n"
		  "nop             \n"
		  "nop             \n"
		  "subs  r0,r0,#1  \n"
		  "bne   eth_wait_loop");
#else	/* __ICCARM__ || __GNUC__ */
	__asm("mov   r0,%0     \n"
		  "eth_wait_loop:  \n"
		  "nop             \n"
		  "nop             \n"
		  "nop             \n"
		  "subs  r0,r0,#1  \n"
		  "bne   eth_wait_loop"
		  : : "r"(wait));
#endif
} /* ether_wait_ns() */

/* End of File */
