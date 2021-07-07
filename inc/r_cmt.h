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
* System Name  : RZ/T1 CMT program
* File Name    : r_cmt.h
* Version      : 1.2
* Device       : R7S910017
* Abstract     : API for reset function
* Tool-Chain   : e2studio
* OS           : not use
* H/W Platform : RZ/T1 Evaluation Board (RTK7910022C00000BR)
* Description  : CMT settings API of RZ/T1
* Limitation   : none
*******************************************************************************/
/*******************************************************************************
* History      : DD.MM.YYYY Version  Description
*              : 01.07.2015 1.1      First Release
*              : 30.11.2015 1.2      Second Release
*                                     - No modification
*******************************************************************************/

#ifndef _R_CMT_HEADER_
#define _R_CMT_HEADER_

/*******************************************************************************
Macro definitions
*******************************************************************************/
#define CMT_SUCCESS                 (0)
#define CMT_ERR                     (-1)
#define CMT_CH_TOTAL                (4)
#define CMT_CH_0                    (0)
#define CMT_CH_1                    (1)
#define CMT_CH_2                    (2)
#define CMT_CH_3                    (3)
#define CMT_CKS_DIVISION_8          (0)
#define CMT_CKS_DIVISION_32         (1)
#define CMT_CKS_DIVISION_128        (2)
#define CMT_CKS_DIVISION_512        (3)

#define CMT_MODE_PERIODEC           (0)
#define CMT_MODE_ONESHOT            (1)

#define PCLKD_Hz                    (75000000)

/*******************************************************************************
Exported global variables and functions (to be accessed by other files)
*******************************************************************************/
int32_t R_CMT_Init(uint32_t channel, uint16_t cks);
int32_t R_CMT_CreatePeriodic(uint32_t channel, uint32_t frequency_hz, void (* callback)(uint32_t channnel));
int32_t R_CMT_CreateOneShot(uint32_t channel, uint32_t period_us, void(* callback)(uint32_t channel));
int32_t R_CMT_Stop(uint32_t channel);

int32_t userdef_cmt_init(uint32_t channel, uint16_t cks);
int32_t userdef_cmt_create(uint32_t channel, uint32_t frequency_hz, void (* callback)(uint32_t channnel), uint32_t mode);
int32_t userdef_cmt_stop(uint32_t channel);
int32_t userdef_cmt_isr_cmi(uint32_t channel);

#endif /* _R_CMT_HEADER_ */
