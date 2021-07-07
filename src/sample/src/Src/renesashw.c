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
* File Name    : renesashw.c
* Version      : 1.0
* Device       : R7S910017
* Abstract     : EtherCAT SSC H/W Implementation for RZ/T1
* Tool-Chain   : IAR Embedded Workbench for ARM
*              : e2studio
*              : ARM DS-5 Development Studio
* OS           : not use
* H/W Platform : RZ/T1 Evaluation Board (RTK7910022C00000BR)
* Description  : EtherCAT SSC H/W Implementation for RZ/T1
* Limitation   : none
*******************************************************************************/
/*******************************************************************************
* History      : DD.MM.YYYY Version  Description
*              : 01.12.2015 1.0      First Release
*******************************************************************************/

/*-----------------------------------------------------------------------------------------
------
------    Includes
------
-----------------------------------------------------------------------------------------*/
#include "platform.h"
#include "r_icu_init.h"
#include "ecat_def.h"

#define    _RENESASHW_ 1
#include "renesashw.h"
#undef _RENESASHW_
#define    _RENESASHW_ 0

#include "ecatslv.h"

#include "mailbox.h"

#ifdef __ICCARM__
#include <time.h>
#elif __CC_ARM
#include <time.h>
#elif __GNUC__
#include <sys/times.h>
#endif // __gnuc__


/*--------------------------------------------------------------------------------------
------
------    local Types and Defines
------
--------------------------------------------------------------------------------------*/


/*-----------------------------------------------------------------------------------------
------
------    local variables and constants
------
-----------------------------------------------------------------------------------------*/
clock_t BaseTime = 0;

/*-----------------------------------------------------------------------------------------
------
------    local functions
------
-----------------------------------------------------------------------------------------*/


/*-----------------------------------------------------------------------------------------
------
------    functions
------
-----------------------------------------------------------------------------------------*/

/**
\addtogroup renesashw
@{
*/

/////////////////////////////////////////////////////////////////////////////////////////
/**
\return     Current timer value

 \brief    This function gets the value of the hardware timer. The timer ticks per ms shall be set in "ECAT_TIMER_INC_P_MS"
*////////////////////////////////////////////////////////////////////////////////////////
UINT16 HW_GetTimer()
{
  return (UINT16)(CMT5.CMCNT - BaseTime);
}

/////////////////////////////////////////////////////////////////////////////////////////
/**
 \brief    Reset the hardware timer
*////////////////////////////////////////////////////////////////////////////////////////
void HW_ClearTimer()
{
	BaseTime = CMT5.CMCNT;
}

/////////////////////////////////////////////////////////////////////////////////////////
/**
\return     0 if initialization was successful

 \brief    This function initialize the EtherCAT Slave Interface.
*////////////////////////////////////////////////////////////////////////////////////////

UINT16 HW_Init(void)
{
	volatile UINT32 dummy32;

    /* the memory interface to the ESC, the ESC-interrupt and the ECAT-timer for the
       watchdog monitoring should be initialized here microcontroller specific*/
    /* initialize ESC DPRAM pointer microcontroller specific to the beginning of the physical memory of the ESC,
       the macro MAKE_PTR_TO_ESC should be defined in renesashw.h */
    //TODO: pEsc = MAKE_PTR_TO_ESC;


    /* initialize the AL_Event Mask Register */
    ResetALEventMask( 0 );

	//=========================================
	// Module stop control
	//=========================================
	// ====== Unlock system register ======
	SYSTEM.PRCR.LONG = 0x0000A502;					// Enable MSTPCRA write access

	SYSTEM.MSTPCRA.LONG &= ~(0x00000004);			// Module start
													//  [2] CMT unit 2
	dummy32 = SYSTEM.MSTPCRA.LONG;

	// ====== Lock MPC register ======
	SYSTEM.PRCR.LONG = 0x0000A500;					// Disable MSTPCRA write access

	// --- Initialize timer ---
	CMT5.CMCR.BIT.CKS   = 0;					// CLK <= PCLKD/8
	CMT5.CMCR.BIT.CMIE  = 0;					// Disable interrupt
	CMT5.CMCOR          = 0xffff;				// Compare value = 0
	CMT.CMSTR2.BIT.STR5 = 1;					// Count start [CMT5]

    return 0;
}

void HW_Release(void)
{
}

void HW_SetLed(BOOL RunLed,BOOL ErrLed)
{
	UINT8 errled;

	switch(u8EcatErrorLed)
	{
	case LED_BLINKING:
		errled = ESC_LED_BLINKING;
		break;
	case LED_SINGLEFLASH:
		errled = ESC_LED_SINGLE_FLASH;
		break;
	case LED_DOUBLEFLASH:
		errled = ESC_LED_DOUBLE_FLASH;
		break;
	case LED_ON:
		errled = ESC_LED_ON;
		break;
	case LED_FLICKERING:
		errled = ESC_LED_FLICKERING;
		break;
	case LED_OFF:
		errled = ESC_LED_OFF;
		break;
	default:
		errled = ESC_LED_OVERRIDE_OFF;
		break;
	}
	HW_EscWriteByte(errled, ESC_ERROR_LED_OVERRIDE);
}

void DISABLE_ESC_INT()
{
	R_ICU_Disable(ICU_VEC_NUM_73);	// Disable EtherCAT Sync0
	R_ICU_Disable(ICU_VEC_NUM_74);	// Disable EtherCAT Sync1
	R_ICU_Disable(ICU_VEC_NUM_75);	// Disable EtherCAT PDI
}

void ENABLE_ESC_INT()
{
	R_ICU_Enable(ICU_VEC_NUM_73);	// Enable EtherCAT Sync0
	R_ICU_Enable(ICU_VEC_NUM_74);	// Enable EtherCAT Sync1
	R_ICU_Enable(ICU_VEC_NUM_75);	// Enable EtherCAT PDI
}

/** @} */





