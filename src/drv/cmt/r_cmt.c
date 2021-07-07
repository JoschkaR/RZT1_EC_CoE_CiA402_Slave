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
* File Name    : r_cmt.c
* Version      : 1.2
* Device       : R7S910017
* Abstract     : API for CMT function
* Tool-Chain   : e2studio
* OS           : not use
* H/W Platform : RZ/T1 Evaluation Board (RTK7910022C00000BR)
* Description  : CMT setting API of RZ/T1
* Limitation   : none
*******************************************************************************/
/*******************************************************************************
* History      : DD.MM.YYYY Version  Description
*              : 01.07.2015 1.1      First Release
*              : 30.11.2015 1.2      Second Release
*                                     - No modification
*******************************************************************************/

/*******************************************************************************
Includes <System Includes> , "Project Includes"
*******************************************************************************/
#include "platform.h"
#include "iodefine.h"
#include "r_cmt.h"


/*******************************************************************************
Typedef definitions
*******************************************************************************/


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


/*******************************************************************************
* Function Name: R_CMT_Init
* Description  : This function initialize the CMT settings.
* Arguments    : uint32_t channel : 0 to 3
*              : uint16_t cks     : Select CMT clock source
*              :                  : (Setting value of CMCR.CKS bit)
*              :                  :   CMT_CKS_DIVISION_8   : PCLKD / 8
*              :                  :   CMT_CKS_DIVISION_32  : PCLKD / 32
*              :                  :   CMT_CKS_DIVISION_128 : PCLKD / 128
*              :                  :   CMT_CKS_DIVISION_512 : PCLKD / 512
* Return Value : int32      :   CMT_SECCESS
*              :            :   CMT_ERR
*******************************************************************************/
int32_t R_CMT_Init (uint32_t channel, uint16_t cks)
{
    int32_t ret;

    if (cks > CMT_CKS_DIVISION_512)
    {
        return CMT_ERR;
    }

    ret = userdef_cmt_init(channel, cks);

    return ret;
}

/*******************************************************************************
* Function Name: R_CMT_CreatePeriodic
* Description  :
* Arguments    : uint32_t channel: 0 ~ 3
*              : uint32_t frequency_hz :
*              : void * callback       : callback function
* Return Value : int32          : CMT_SECCESS
*              :                : CMT_ERR
*******************************************************************************/
int32_t R_CMT_CreatePeriodic (uint32_t channel, uint32_t frequency_hz, void (* callback)(uint32_t channnel))
{
    int32_t ret;

    ret = userdef_cmt_create(channel, frequency_hz, callback, CMT_MODE_PERIODEC);

    return ret;
}

/*******************************************************************************
* Function Name: R_CMT_CreateOneShot
* Description  :
* Arguments    : uint32_t channel: 0 ~ 3
*              : uint32_t period_us : micro seconds time.
*              : void * callback    : callback function
* Return Value : int32          : CMT_SECCESS
*              :                : CMT_ERR
*******************************************************************************/
int32_t R_CMT_CreateOneShot (uint32_t channel, uint32_t period_us, void(* callback)(uint32_t channel))
{
    int32_t ret;

    ret = userdef_cmt_create(channel, 1000000 / period_us, callback, CMT_MODE_ONESHOT);

    return ret;
}

/*******************************************************************************
* Function Name: R_CMT_Stop
* Description  :
* Arguments    : uint32_t channel: 0 ~ 3
* Return Value : int32          : CMT_SECCESS
*              :                : CMT_ERR
*******************************************************************************/
int32_t R_CMT_Stop (uint32_t channel)
{
    int32_t ret;

    ret = userdef_cmt_stop(channel);

    return ret;
}


/* End of File */

