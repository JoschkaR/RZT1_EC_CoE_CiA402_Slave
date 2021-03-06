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
* File Name    : sflash.h
* Version      : 1.4
* Device       : R7S910017
* Abstract     : Serial flash function
* Tool-Chain   : e2studio
* OS           : not use
* H/W Platform : RZ/T1 Evaluation Board (RTK7910022C00000BR)
* Description  : Serial flash setting for RZ/T1
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
#ifndef SFLASH_H
#define SFLASH_H


/******************************************************************************
Includes   <System Includes> , "Project Includes"
******************************************************************************/


/******************************************************************************
Typedef definitions
******************************************************************************/


/******************************************************************************
Macro definitions
******************************************************************************/
/* ---- serial flash command[MX25L51245G Macronix)(uniform=64KB)] ---- */
#define SF_REQ_PROTECT               (0)
#define SF_REQ_UNPROTECT             (1)

#define SFLASHCMD_SECTOR_ERASE       (0xD8)
#define SFLASHCMD_BYTE_PROGRAM       (0x02)
#define SFLASHCMD_FAST_READ          (0x0B)
#define SFLASHCMD_QUAD_FAST_READ     (0x6B)
#define SFLASHCMD_QUAD_IO_READ       (0xEB)
#define SFLASHCMD_WRITE_ENABLE       (0x06)
#define SFLASHCMD_READ_STATUS        (0x05)
#define SFLASHCMD_READ_CONFIG        (0x15)
#define SFLASHCMD_WRITE_STATUS       (0x01)

/* 4-byte address command*/
#define SFLASHCMD_SECTOR_ERASE_4B    (0xDC)
#define SFLASHCMD_BYTE_PROGRAM_4B    (0x12)
#define SFLASHCMD_FAST_READ_4B       (0x0C)
#define SFLASHCMD_QUAD_IO_READ_4B    (0xEC)
#define SFLASHCMD_QUAD_FAST_READ_4B  (0x6C)


/* ---- serial flash register definitions ---- */
#define STREG_SRWD_BIT               (0x80)          /* Status Register Write Disable(Status Register) */
#define STREG_QUAD_BIT               (0x40)          /* Quad mode bit(Status Register) */
#define STREG_BPROTECT_BIT           (0x3C)          /* protect bit(Status Register) */
#define STREG_WEL_BIT                (0x02)          /* Write Enable Lacth(Status Register) */
#define STREG_WIP_BIT                (0x01)          /* Write in Progress(Status Register) */

#define CFREG_LC_BIT                 (0xC0)          /* Latency Code bit(Configuration Register) */
#define CFREG_4BYTE_BIT              (0x20)          /* 4 BYTE bit(Configuration Register) */


/* Page and Sector size */
#define SF_PAGE_SIZE                 (256)           /* Page size of serial flash memory */
#define SF_SECTOR_SIZE               (64 * 1024)     /* Sector size = 256 KB   */
#define SF_NUM_OF_SECTOR             (1024)          /* Sector Count : 32 */


/******************************************************************************
Functions Prototypes
******************************************************************************/


#endif /* SFLASH_H */

/* End of File */
