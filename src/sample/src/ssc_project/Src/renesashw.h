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
* File Name    : renesashw.h
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

#ifndef _RENESASHW_H_
#define _RENESASHW_H_

/*-----------------------------------------------------------------------------------------
------
------    Includes
------
-----------------------------------------------------------------------------------------*/
#include <string.h>
#include "esc.h"

/*-----------------------------------------------------------------------------------------
------
------    Defines and Types
------
-----------------------------------------------------------------------------------------*/

#define ESC_MEM_ADDR    UINT8
#define ESC_MEM_SHIFT   0

#define ESC_LED_OVERRIDE_OFF	(0x00)
#define ESC_LED_OFF				(0x10)
#define ESC_LED_BLINKING		(0x1D)
#define ESC_LED_SINGLE_FLASH	(0x11)
#define ESC_LED_DOUBLE_FLASH	(0x12)
#define ESC_LED_FLICKERING		(0x1E)
#define ESC_LED_ON				(0x1F)

#ifdef __GNUC__
/** \brief  Enable IRQ Interrupts

  This function enables IRQ interrupts by clearing the I-bit in the CPSR.
  Can only be executed in Privileged modes.
 */
__attribute__( ( always_inline ) ) static inline void __enable_irq(void)
{
  __asm volatile ("cpsie i");
}


/** \brief  Disable IRQ Interrupts

  This function disables IRQ interrupts by setting the I-bit in the CPSR.
  Can only be executed in Privileged modes.
 */
__attribute__( ( always_inline ) ) static inline void __disable_irq(void)
{
  __asm volatile ("cpsid i");
}
#endif // __gnuc__

///////////////////////////////////////////////////////////////
//
//    EtherCAT Slave Controller
//


#ifndef TIMER_INT_HEADER
    #define    TIMER_INT_HEADER
#endif

#define     ESC_RD                    0x02            /* read access to ESC */
#define     ESC_WR                    0x04            /* write access to ESC */
/*-----------------------------------------------------------------------------------------
------
------    variables
------
-----------------------------------------------------------------------------------------*/

#endif //_RENESASHW_H_
#if _RENESASHW_
    #define PROTO
#else
    #define PROTO extern
#endif

PROTO MEM_ADDR ESCMEM *            pEsc;            // pointer to the ESC

/*-----------------------------------------------------------------------------------------
------
------    function prototypes
------
-----------------------------------------------------------------------------------------*/

PROTO UINT16 HW_GetTimer();
PROTO void HW_ClearTimer();

#define ECAT_TIMER_INC_P_MS 9375 //the timer unit 107ns per tick (75MHz/8)

PROTO void HW_SetLed(BOOL RunLed,BOOL ErrLed);

PROTO UINT16 HW_Init(void);
PROTO void HW_Release(void);
#define     HW_GetALEventRegister()             ((((UINT16 ESCMEM *)pEsc)[((ESC_AL_EVENT_OFFSET)>>1)]))
#define     HW_GetALEventRegister_Isr           HW_GetALEventRegister

#define     HW_EscRead(pData,Address,Len)       ESCMEMCPY((MEM_ADDR *)(pData), &((ESC_MEM_ADDR ESCMEM *) pEsc)[((Address) >> ESC_MEM_SHIFT)], (Len))
#define     HW_EscReadIsr                       HW_EscRead
#define     HW_EscReadDWord(DWordValue, Address)    ((DWordValue) = (UINT32)(((UINT32 *)pEsc)[(Address>>2)]))
#define     HW_EscReadDWordIsr(DWordValue, Address) ((DWordValue) = (UINT32)(((UINT32 *)pEsc)[(Address>>2)]))
#define     HW_EscReadWord(WordValue, Address)  ((WordValue) = (((UINT16 *)pEsc)[((Address)>>1)]))    //the esc pointer is handled as a word pointer so the address must be devided by 2
#define     HW_EscReadWordIsr(WordValue, Address) HW_EscReadWord(WordValue, Address)    //the esc pointer is handled as a word pointer so the address must be devided by 2
#define     HW_EscReadByte(ByteValue, Address)  ((ByteValue) = (((UINT8 *)pEsc)[(Address)]))
#define     HW_EscReadByteIsr(ByteValue, Address) HW_EscReadByte(ByteValue, Address)
/* ECATCHANGE_START(V5.01) HW2*/
#define     HW_EscReadMbxMem(pData,Address,Len) ESCMBXMEMCPY((MEM_ADDR *)(pData), &((ESC_MEM_ADDR ESCMEM *) pEsc)[((Address) >> ESC_MEM_SHIFT)], (Len))


#define     HW_EscWrite(pData,Address,Len)      ESCMEMCPY(&((ESC_MEM_ADDR ESCMEM *) pEsc)[((Address)>>ESC_MEM_SHIFT)], (MEM_ADDR *)(pData), (Len))
/* ECATCHANGE_END(V5.01) HW2*/
#define     HW_EscWriteIsr                      HW_EscWrite
#define     HW_EscWriteDWord(DWordValue, Address)   ((((UINT32 *)pEsc)[(Address>>2)]) = (DWordValue))
#define     HW_EscWriteDWordIsr(DWordValue, Address)((((UINT32 *)pEsc)[(Address>>2)]) = (DWordValue))
#define     HW_EscWriteWord(WordValue, Address) ((((UINT16 *)pEsc)[((Address)>>1)]) = (WordValue))    //the esc pointer is handled as a word pointer so the address must be devided by 2
#define     HW_EscWriteWordIsr(WordValue, Address) HW_EscWriteWord(WordValue, Address)    //the esc pointer is handled as a word pointer so the address must be devided by 2
#define     HW_EscWriteByte(ByteValue, Address) ((((UINT8 *)pEsc)[(Address)]) = (ByteValue))
#define     HW_EscWriteByteIsr(ByteValue, Address) HW_EscWriteByte(ByteValue, Address)
#define     HW_EscWriteMbxMem(pData,Address,Len)    ESCMBXMEMCPY(&((ESC_MEM_ADDR ESCMEM *) pEsc)[((Address)>>ESC_MEM_SHIFT)],(MEM_ADDR *)(pData), (Len))

PROTO void DISABLE_ESC_INT();
PROTO void ENABLE_ESC_INT();

#undef PROTO





