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
* System Name  : interface file of MCU and board.
* File Name    : platform.h
* Version      : 1.4
* Device       : R7S910017
* Abstract     : include file of MCU and board setting.
* Tool-Chain   : e2studio
* OS           : not use
* H/W Platform : RZ/T1 Evaluation Board (RTK7910022C00000BR)
* Description  : The user chooses which MCU and board they are developing for in this file.
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

#ifndef PLATFORM_H
#define PLATFORM_H

/*******************************************************************************
DEFINE YOUR SYSTEM - UNCOMMENT THE INCLUDE PATH FOR THE PLATFORM YOU ARE USING.
*******************************************************************************/
#if   defined(__ICCARM__)
#include <stdint.h>
#include <stdbool.h>
#endif
#if defined(__CC_ARM)
#include <stdint.h>
#include <stdbool.h>
#else
#if defined(__GNUC__)
#include <stdint.h>
#include <stdbool.h>
#endif
#endif

#include "iodefine.h"

#if   defined(__ICCARM__)
#include <intrinsics.h>
#endif

#ifndef NULL
#define NULL (void *)0
#endif

#define FIT_NO_PTR              (void *)0x10000000
#define FIT_NO_FUNC             ((void (*)(void *))0x10000000)

/*******************************************************************************
MAKE SURE AT LEAST ONE PLATFORM WAS DEFINED - DO NOT EDIT BELOW THIS POINT
*******************************************************************************/

#endif /* PLATFORM_H */

