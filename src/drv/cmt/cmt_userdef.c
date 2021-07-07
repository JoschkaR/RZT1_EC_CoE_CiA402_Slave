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
* Copyright (C) 2015 Renesas Electronics Corporation. All rights reserved.
*******************************************************************************/
/*******************************************************************************
* System Name  : RZ/T1 CMT Userdefine program
* File Name    : cmt_userdef.c
* Version      : 1.2
* Device       : R7S910017
* Abstract     : API userdefine settings for CMT function
* Tool-Chain   : e2studio
* OS           : not use
* H/W Platform : RZ/T1 Evaluation Board (RTK7910022C00000BR)
* Description  : CMT userdefine setting API of RZ/T1
* Limitation   : none
*******************************************************************************/
/*******************************************************************************
* History      : DD.MM.YYYY Version  Description
*              : 01.07.2015 1.1      First Release
*              : 30.11.2015 1.2      Second Release
*                                     - No modification
*******************************************************************************/

/*******************************************************************************
Includes   <System Includes> , "Project Includes"
*******************************************************************************/
#include "platform.h"
#include "iodefine.h"
#include "r_system.h"
#include "r_cmt.h"
#include "r_icu_init.h"


/*******************************************************************************
Typedef definitions
*******************************************************************************/


/*******************************************************************************
Macro definitions
*******************************************************************************/
#define CMT_FLAG_OFF     (0)
#define CMT_FLAG_ON      (1)

/*******************************************************************************
Imported global variables and functions (from other files)
*******************************************************************************/


/*******************************************************************************
Exported global variables and functions (to be accessed by other files)
*******************************************************************************/

/*******************************************************************************
Private global variables and functions
*******************************************************************************/
static uint32_t g_cmt_modes[CMT_CH_TOTAL];
static void (* g_cmt_callbacks[CMT_CH_TOTAL])(uint32_t channel);

void cmt0_isr (void) __attribute__ ((interrupt));
void cmt1_isr (void) __attribute__ ((interrupt));
void cmt2_isr (void) __attribute__ ((interrupt));
void cmt3_isr (void) __attribute__ ((interrupt));

/*******************************************************************************
* Function Name: userdef_cmt_init
* Description  :
* Arguments    : uint32_t channel : 0 ~ 3
*              : uint16_t cks     : Select CMT clock source
*              :                  : (Setting value of CMCR CKS bit)
*              :                  :   CMT_CKS_DIVISION_8   : PCLKD / 8
*              :                  :   CMT_CKS_DIVISION_32  : PCLKD / 32
*              :                  :   CMT_CKS_DIVISION_128 : PCLKD / 128
*              :                  :   CMT_CKS_DIVISION_512 : PCLKD / 512
* Return Value : int32          : CMT_SECCESS
*              :                : CMT_ERR
*******************************************************************************/
int32_t userdef_cmt_init (uint32_t channel, uint16_t cks)
{
    int32_t ret = CMT_SUCCESS;

    switch (channel)
    {
        case CMT_CH_0:
            g_cmt_modes[CMT_CH_0]     = 0;
            g_cmt_callbacks[CMT_CH_0] = 0;
            CMT.CMSTR0.BIT.STR0 = CMT_FLAG_OFF;
            CMT0.CMCNT          = 0;
            CMT0.CMCR.BIT.CKS   = cks;
            R_ICU_Disable(ICU_VEC_NUM_21);
            R_ICU_Regist(ICU_VEC_NUM_21, ICU_TYPE_EDGE, ICU_PRIORITY_15, (uint32_t)cmt0_isr);
            R_ICU_Enable(ICU_VEC_NUM_21);
        break;

        case CMT_CH_1:
            g_cmt_modes[CMT_CH_1]     = 0;
            g_cmt_callbacks[CMT_CH_1] = 0;
            CMT.CMSTR0.BIT.STR1 = CMT_FLAG_OFF;
            CMT1.CMCNT          = 0;
            CMT1.CMCR.BIT.CKS   = cks;
            R_ICU_Disable(ICU_VEC_NUM_22);
            R_ICU_Regist(ICU_VEC_NUM_22, ICU_TYPE_EDGE, ICU_PRIORITY_15, (uint32_t)cmt1_isr);
            R_ICU_Enable(ICU_VEC_NUM_22);
        break;

        case CMT_CH_2:
            g_cmt_modes[CMT_CH_2]     = 0;
            g_cmt_callbacks[CMT_CH_2] = 0;
            CMT.CMSTR1.BIT.STR2 = CMT_FLAG_OFF;
            CMT2.CMCNT          = 0;
            CMT2.CMCR.BIT.CKS   = cks;
            R_ICU_Disable(ICU_VEC_NUM_23);
            R_ICU_Regist(ICU_VEC_NUM_23, ICU_TYPE_EDGE, ICU_PRIORITY_15, (uint32_t)cmt2_isr);
            R_ICU_Enable(ICU_VEC_NUM_23);
        break;

        case CMT_CH_3:
            g_cmt_modes[CMT_CH_3]     = 0;
            g_cmt_callbacks[CMT_CH_3] = 0;
            CMT.CMSTR1.BIT.STR3 = CMT_FLAG_OFF;
            CMT3.CMCNT          = 0;
            CMT3.CMCR.BIT.CKS   = cks;
            R_ICU_Disable(ICU_VEC_NUM_24);
            R_ICU_Regist(ICU_VEC_NUM_24, ICU_TYPE_EDGE, ICU_PRIORITY_15, (uint32_t)cmt3_isr);
            R_ICU_Enable(ICU_VEC_NUM_24);
        break;

        default:
            ret = CMT_ERR;
        break;
    }

    return ret;
}

/*******************************************************************************
* Function Name: userdef_cmt0_start
* Description  :
* Arguments    : uint32_t channel: 0 ~ 3
*              : uint32_t frequency_hz :
*              : void * callback       : callback function
*              : uint32_t mode         : CMT operatione mode
*              :                       :   CMT_MODE_PERIODEC
*              :                       :   CMT_MODE_ONESHOT
* Return Value : int32          : CMT_SECCESS
*              :                : CMT_ERR
*******************************************************************************/
int32_t userdef_cmt_create (uint32_t channel, uint32_t frequency_hz, void (* callback)(uint32_t ch), uint32_t mode)
{
    uint32_t max_hz;
    uint32_t min_hz;
    uint16_t cks_mem;
    uint16_t constant_mem;

    switch (channel)
    {
        case CMT_CH_0:
            cks_mem = CMT0.CMCR.BIT.CKS;
        break;

        case CMT_CH_1:
            cks_mem = CMT1.CMCR.BIT.CKS;
        break;

        case CMT_CH_2:
            cks_mem = CMT2.CMCR.BIT.CKS;
        break;

        case CMT_CH_3:
            cks_mem = CMT3.CMCR.BIT.CKS;
        break;

        default:
            return CMT_ERR;
        break;
    }

    max_hz = (PCLKD_Hz / (8 << (cks_mem * 2)));
    min_hz = (max_hz / 0x0000ffffL);

    if ((frequency_hz > max_hz) || (frequency_hz <= min_hz))
    {
        return CMT_ERR;
    }
    else
    {
        constant_mem = (uint16_t)(max_hz / frequency_hz);
    }

    /* Mode set */
    g_cmt_modes[channel] = mode;

    /* Save callback function to be used. */
    g_cmt_callbacks[channel] = callback;

    /* constant set & start */
    switch (channel)
    {
        case CMT_CH_0:
            CMT0.CMCOR          = constant_mem;
            CMT0.CMCR.BIT.CMIE  = CMT_FLAG_ON;
            CMT.CMSTR0.BIT.STR0 = CMT_FLAG_ON;
        break;

        case CMT_CH_1:
            CMT1.CMCOR          = constant_mem;
            CMT1.CMCR.BIT.CMIE  = CMT_FLAG_ON;
            CMT.CMSTR0.BIT.STR1 = CMT_FLAG_ON;
        break;

        case CMT_CH_2:
            CMT2.CMCOR          = constant_mem;
            CMT2.CMCR.BIT.CMIE  = CMT_FLAG_ON;
            CMT.CMSTR1.BIT.STR2 = CMT_FLAG_ON;
        break;

        case CMT_CH_3:
            CMT3.CMCOR          = constant_mem;
            CMT3.CMCR.BIT.CMIE  = CMT_FLAG_ON;
            CMT.CMSTR1.BIT.STR3 = CMT_FLAG_ON;
        break;

        default:
            /* Do Nothing */
        break;
    }

    return CMT_SUCCESS;
}


/*******************************************************************************
* Function Name: userdef_cmt_stop
* Description  :
* Arguments    : uint32_t channel: 0 ~ 3
* Return Value : int32            : CMT_SECCESS
*              :                  : CMT_ERR
*******************************************************************************/
int32_t userdef_cmt_stop (uint32_t channel)
{
    int32_t ret = CMT_SUCCESS;

    switch (channel)
    {
        case CMT_CH_0:
            CMT.CMSTR0.BIT.STR0 = CMT_FLAG_OFF;
        break;

        case CMT_CH_1:
            CMT.CMSTR0.BIT.STR1 = CMT_FLAG_OFF;
        break;

        case CMT_CH_2:
            CMT.CMSTR1.BIT.STR2 = CMT_FLAG_OFF;
        break;

        case CMT_CH_3:
            CMT.CMSTR1.BIT.STR3 = CMT_FLAG_OFF;
        break;

        default:
            ret = CMT_ERR;
        break;
    }

    return ret;
}

/*******************************************************************************
* Function Name: userdef_cmt_isr_cmi
* Description  :
* Arguments    : uint32_t channel: 0 ~ 3
* Return Value : int32            : CMT_SECCESS
*              :                  : CMT_ERR
*******************************************************************************/
int32_t userdef_cmt_isr_cmi (uint32_t channel)
{
    /* Check for valid callback pointer before calling it. */
    if (0 != g_cmt_callbacks[channel])
    {
        /* Valid callback found, jump to it. */
        (*g_cmt_callbacks[channel])(channel);
    }

    /* If this is one-shot mode then stop timer. */
    if (CMT_MODE_ONESHOT == g_cmt_modes[channel])
    {
        userdef_cmt_stop(channel);
    }
    return CMT_SUCCESS;
}

/*******************************************************************************
* Function Name: cmt0_isr
* Description  : Interrupt when compare match for this channel occurs.
* Arguments    : none
* Return Value : none
*******************************************************************************/
void cmt0_isr (void)
{
    VIC.PIC0.BIT.PIC21 = 1;
    userdef_cmt_isr_cmi(CMT_CH_0);

    /* End interrupt sequence (dummy writing to HVA0 register) */
    HVA0_DUMMY_WRITE();
}

/*******************************************************************************
* Function Name: cmt1_isr
* Description  : Interrupt when compare match for this channel occurs.
* Arguments    : none
* Return Value : none
*******************************************************************************/
void cmt1_isr (void)
{
    VIC.PIC0.BIT.PIC22 = 1;
    userdef_cmt_isr_cmi(CMT_CH_1);

    /* End interrupt sequence (dummy writing to HVA0 register) */
    HVA0_DUMMY_WRITE();
}

/*******************************************************************************
* Function Name: cmt2_isr
* Description  : Interrupt when compare match for this channel occurs.
* Arguments    : none
* Return Value : none
*******************************************************************************/
void cmt2_isr (void)
{
    VIC.PIC0.BIT.PIC23 = 1;
    userdef_cmt_isr_cmi(CMT_CH_2);

    /* End interrupt sequence (dummy writing to HVA0 register) */
    HVA0_DUMMY_WRITE();
}

/*******************************************************************************
* Function Name: cmt3_isr
* Description  : Interrupt when compare match for this channel occurs.
* Arguments    : none
* Return Value : none
*******************************************************************************/
void cmt3_isr (void)
{
    VIC.PIC0.BIT.PIC24 = 1;
    userdef_cmt_isr_cmi(CMT_CH_3);

    /* End interrupt sequence (dummy writing to HVA0 register) */
    HVA0_DUMMY_WRITE();
}

/* End of File */
