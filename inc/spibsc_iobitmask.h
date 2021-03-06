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
* System Name  : RZ/T1 Init program
* File Name    : spibsc_iobitmask.h
* Version      : 1.4
* Device       : R7S910017
* Abstract     : SPIBSC IO bit mask settings
* Tool-Chain   : e2studio
* OS           : not use
* H/W Platform : RZ/T1 Evaluation Board (RTK7910022C00000BR)
* Description  : SPIBSC IO bit mask settings for RZ/T1
* Limitation   : none
*******************************************************************************/
/*******************************************************************************
* History      : DD.MM.YYYY Version  Description
*              : 01.07.2015 1.1      First Release
*              : 30.11.2015 1.2      Second Release
*                                     - No modification
*              : 31.03.2017 1.3      Third Release
*                                     - No modification
*              : 31.05.2018 1.4      4th Release
*                                     - No modification
*******************************************************************************/
#ifndef SPIBSC_IOBITMASK_H
#define SPIBSC_IOBITMASK_H


/* ==== Mask values for IO registers ==== */
#define SPIBSC_CMNCR_BSZ               (0x00000003uL)

#define SPIBSC_CMNCR_CPOL              (0x00000008uL)
#define SPIBSC_CMNCR_SSLP              (0x00000010uL)
#define SPIBSC_CMNCR_CPHAR             (0x00000020uL)
#define SPIBSC_CMNCR_CPHAT             (0x00000040uL)

#define SPIBSC_CMNCR_IO0FV             (0x00000300uL)

#define SPIBSC_CMNCR_IO2FV             (0x00003000uL)
#define SPIBSC_CMNCR_IO3FV             (0x0000C000uL)
#define SPIBSC_CMNCR_MOIIO0            (0x00030000uL)
#define SPIBSC_CMNCR_MOIIO1            (0x000C0000uL)
#define SPIBSC_CMNCR_MOIIO2            (0x00300000uL)
#define SPIBSC_CMNCR_MOIIO3            (0x00C00000uL)
#define SPIBSC_CMNCR_SFDE              (0x01000000uL)

#define SPIBSC_CMNCR_MD                (0x80000000uL)

#define SPIBSC_SSLDR_SCKDL             (0x00000007uL)

#define SPIBSC_SSLDR_SLNDL             (0x00000700uL)

#define SPIBSC_SSLDR_SPNDL             (0x00070000uL)

#define SPIBSC_SPBCR_BRDV              (0x00000003uL)

#define SPIBSC_SPBCR_SPBR              (0x0000FF00uL)

#define SPIBSC_DRCR_SSLE               (0x00000001uL)

#define SPIBSC_DRCR_RBE                (0x00000100uL)
#define SPIBSC_DRCR_RCF                (0x00000200uL)

#define SPIBSC_DRCR_RBURST             (0x000F0000uL)

#define SPIBSC_DRCR_SSLN               (0x01000000uL)

#define SPIBSC_DRCMR_OCMD              (0x000000FFuL)

#define SPIBSC_DRCMR_CMD               (0x00FF0000uL)

#define SPIBSC_DREAR_EAC               (0x00000007uL)

#define SPIBSC_DREAR_EAV               (0x00FF0000uL)

#define SPIBSC_DROPR_OPD0              (0x000000FFuL)
#define SPIBSC_DROPR_OPD1              (0x0000FF00uL)
#define SPIBSC_DROPR_OPD2              (0x00FF0000uL)
#define SPIBSC_DROPR_OPD3              (0xFF000000uL)

#define SPIBSC_DRENR_OPDE              (0x000000F0uL)
#define SPIBSC_DRENR_ADE               (0x00000F00uL)
#define SPIBSC_DRENR_OCDE              (0x00001000uL)

#define SPIBSC_DRENR_CDE               (0x00004000uL)
#define SPIBSC_DRENR_DME               (0x00008000uL)
#define SPIBSC_DRENR_DRDB              (0x00030000uL)

#define SPIBSC_DRENR_OPDB              (0x00300000uL)

#define SPIBSC_DRENR_ADB               (0x03000000uL)

#define SPIBSC_DRENR_OCDB              (0x30000000uL)
#define SPIBSC_DRENR_CDB               (0xC0000000uL)

#define SPIBSC_SMCR_SPIE               (0x00000001uL)
#define SPIBSC_SMCR_SPIWE              (0x00000002uL)
#define SPIBSC_SMCR_SPIRE              (0x00000004uL)

#define SPIBSC_SMCR_SSLKP              (0x00000100uL)

#define SPIBSC_SMCMR_OCMD              (0x000000FFuL)

#define SPIBSC_SMCMR_CMD               (0x00FF0000uL)

#define SPIBSC_SMADR_ADR               (0xFFFFFFFFuL)

#define SPIBSC_SMOPR_OPD0              (0x000000FFuL)
#define SPIBSC_SMOPR_OPD1              (0x0000FF00uL)
#define SPIBSC_SMOPR_OPD2              (0x00FF0000uL)
#define SPIBSC_SMOPR_OPD3              (0xFF000000uL)

#define SPIBSC_SMENR_SPIDE             (0x0000000FuL)
#define SPIBSC_SMENR_OPDE              (0x000000F0uL)
#define SPIBSC_SMENR_ADE               (0x00000F00uL)
#define SPIBSC_SMENR_OCDE              (0x00001000uL)

#define SPIBSC_SMENR_CDE               (0x00004000uL)
#define SPIBSC_SMENR_DME               (0x00008000uL)
#define SPIBSC_SMENR_SPIDB             (0x00030000uL)

#define SPIBSC_SMENR_OPDB              (0x00300000uL)

#define SPIBSC_SMENR_ADB               (0x03000000uL)

#define SPIBSC_SMENR_OCDB              (0x30000000uL)
#define SPIBSC_SMENR_CDB               (0xC0000000uL)

#define SPIBSC_SMRDR0_RDATA0           (0xFFFFFFFFuL)
#define SPIBSC_SMRDR1_RDATA1           (0xFFFFFFFFuL)
#define SPIBSC_SMWDR0_WDATA0           (0xFFFFFFFFuL)
#define SPIBSC_SMWDR1_WDATA1           (0xFFFFFFFFuL)

#define SPIBSC_CMNSR_TEND              (0x00000001uL)
#define SPIBSC_CMNSR_SSLF              (0x00000002uL)

#define SPIBSC_DRDMCR_DMCYC            (0x00000007uL)

#define SPIBSC_DRDMCR_DMDB             (0x00030000uL)

#define SPIBSC_DRDRENR_DRDRE           (0x00000001uL)

#define SPIBSC_DRDRENR_OPDRE           (0x00000010uL)

#define SPIBSC_DRDRENR_ADDRE           (0x00000100uL)

#define SPIBSC_SMDMCR_DMCYC            (0x00000007uL)

#define SPIBSC_SMDMCR_DMDB             (0x00030000uL)

#define SPIBSC_SMDRENR_SPIDRE          (0x00000001uL)

#define SPIBSC_SMDRENR_OPDRE           (0x00000010uL)

#define SPIBSC_SMDRENR_ADDRE           (0x00000100uL)


#endif /* SPIBSC_IOBITMASK_H */

/* End of File */
