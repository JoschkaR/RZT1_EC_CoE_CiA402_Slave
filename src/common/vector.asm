/******************************************************************************
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
******************************************************************************/
/******************************************************************************
* System Name  : RZ/T1 Init program
* File Name    : vector.asm
* Version      : 1.4
* Device       : R7S910017
* Abstract     : vector address (in low vector)
* Tool-Chain   : e2studio
* OS           : not use
* H/W Platform : RZ/T1 Evaluation Board (RTK7910022C00000BR)
* Description  : vector address for RZ/T1 (in low vector)
* Limitation   : none
******************************************************************************/
/******************************************************************************
* History      : DD.MM.YYYY Version  Description
*              : 01.07.2015 1.1      First Release
*              : 30.11.2015 1.2      Second Release
*                                     - No modification
*              : 26.12.2016 1.2B     Third Release
*                                     - Add 3 nop at the end of table for AP4
*              : 31.03.2017 1.3      4th Release
*                                     - No modification
*              : 31.05.2018 1.4      5th Release
*                                     - No modification
******************************************************************************/

/* This program is allocated to section ".fvectors" */
    .section .fvectors, "ax"


reset_handler:
    b  reset_handler

undefined_handler:
    b  undefined_handler

svc_handler:
    b  svc_handler

prefetch_handler:
    b  prefetch_handler

abort_handler:
    b  abort_handler

reserved_handler:
    subs pc,lr,#4

irq_handler:
    b  irq_handler

fiq_handler:
    b  fiq_handler
    nop
    nop
    nop

    .end
