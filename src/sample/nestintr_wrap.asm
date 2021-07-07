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
*******************************************************************************/
/********************************************************************************
* System Name  : RZ/T1 Init program
* File Name    : nestintr_wrap.asm
* Version      : 1.4
* Device       : R7S910017
* Abstract     : Sample program for nested interrupt.
* Tool-Chain   : e2studio
* OS           : not use
* H/W Platform : RZ/T1 Evaluation Board (RTK7910022C00000BR)
* Description  : A Wapper function for nested interrupt service routine of RZ/T1
* Limitation   : FPU implementation (PUSH/POP) is just for example
*******************************************************************************/
/********************************************************************************
* History      : DD.MM.YYYY Version  Description
*              : 31.05.2018 1.4      First Release
******************************************************************************/

    .section .text,"ax"

	.global __NESTED_INTERRUPT_PUSH
    .type   __NESTED_INTERRUPT_PUSH, %function
	.global __NESTED_INTERRUPT_PUSH_FPU
    .type   __NESTED_INTERRUPT_PUSH_FPU, %function
	.global __NESTED_INTERRUPT_POP
    .type   __NESTED_INTERRUPT_POP, %function
	.global __NESTED_INTERRUPT_POP_FPU
    .type   __NESTED_INTERRUPT_POP_FPU, %function

/***********************************************************************
* Function Name : __NESTED_INTERRUPT_PUSH
* Description   : Pre-process to push registers and switch to system mode
*                 for nested interrupt.
*                 The value of lr register before calling this function
*                 needed to be given by caller as first argument.
*                 Second argument is to let compiler save r1 register
*                 at entry of interrupt.
*                 Must be used with __NESTED_INTERRUPT_POP() otherwise
*                 cause runaway
* Arguments     : r0: dummy r1:dummy (To let compiler push r0, r1 reg)
* Return Value  : none
***********************************************************************/
__NESTED_INTERRUPT_PUSH:
    SRSFD   sp!, #0x12   /* Push LR_irq, SPSR_irq to IRQ stack */
    MOV     r1, lr       /* Save LR_fnc */

    CPS     #0x1f        /* Change to system mode */

    AND     r0, sp, #4   /* Adjust SP_sys to 8 byte align */
    SUB     sp, sp, r0
    PUSH    {r0, lr}     /* Push adjust value and LR_sys */
    BX      r1           /* LR_fnc */


/***********************************************************************
* Function Name : __NESTED_INTERRUPT_PUSH_FPU
* Description   : Pre-process to push registers and switch to system mode
*                 for nested interrupt with VFP is enabled.
*                 The value of lr register before calling this function
*                 needed to be pushed so it is given by first argument.
*                 Second argument is to let compiler save r1 register
*                 at entry of interrupt.
* Limitation    : Must be used with __NESTED_INTERRUPT_POP_FPU() otherwise
*                 cause runaway
*                 FPU implementation (PUSH/POP) may need to modify to fit project
* Arguments     : r0: dummy r1:dummy
* Return Value  : none
***********************************************************************/
__NESTED_INTERRUPT_PUSH_FPU:
    SRSFD   sp!, #0x12   /* Push LR_irq, SPSR_irq to IRQ stack */

    VMRS    r0, fpscr    /* Get FPSCR register */
    VMRS    r1, fpexc    /* Get FPEXC register */
    PUSH    {r0, r1}     /* Push FPSCR, FPEXC values to IRQ stack */
    VPUSH   {d0-d15}     /* Push Extension registers to IRQ stack */

    MOV     r1, lr       /* Save LR_fnc */

    CPS     #0x1f        /* Change to system mode */

    AND     r0, sp, #4   /* Adjust SP_sys to 8 byte align */
    SUB     sp, sp, r0
    PUSH    {r0, lr}     /* Push adjust value and LR_sys */
    BX      r1           /* LR_fnc */


/***********************************************************************
* Function Name : __NESTED_INTERRUPT_POP
* Description   : Post-process to pop registers and switch to IRQ mode
*                 for nested interrupt.
* Limitation    : Must be used with __NESTED_INTERRUPT_PUSH() otherwise
*                 cause runaway
* Arguments     : none
* Return Value  : none
************************************************************************/
__NESTED_INTERRUPT_POP:
    POP     {r0, r1}     /* Pop LR_sys and SP adjusted value */
    MOV     r1, lr       /* Save LR_fnc */
    ADD     sp, sp, r0   /* Restore SP before aligned */

    CPS     #0x12        /* Change to IRQ mode */

    MOV     lr, r1       /* Set LR_fnc */
    POP     {r0, r1}     /* Pop LR_irq to r0 and SPSR to r1 */
    MSR     spsr_cxsf, r1     /* Restore SPSR */

    BX      lr           /* LR_fnc */


/***********************************************************************
* Function Name : __NESTED_INTERRUPT_POP_FPU
* Description   : Post-process to pop registers and switch to IRQ mode
*                 for nested interrupt with VFP is enabled.
* Limitation    : Must be used with __NESTED_INTERRUPT_PUSH_FPU()
*                 otherwise cause runaway
*                 FPU implementation (PUSH/POP) may need to modify to fit project
* Arguments     : none
* Return Value  : none
***********************************************************************/
__NESTED_INTERRUPT_POP_FPU:
    POP     {r0, r1}     /* Pop LR_sys and SP adjusted value */
    MOV     r1, lr       /* Save LR_fnc */
    ADD     sp, sp, r0   /* Restore SP before aligned */

    CPS     #0x12        /* Change to IRQ mode */

    MOV     lr, r1       /* Set LR_fnc */

    VPOP    {d0-d15}     /* Pop Extension registers from IRQ stack */
    POP     {r0, r1}     /* Pop FPSCR, FPEXC values from IRQ stack */
    VMSR    fpscr, r0    /* Set FPSCR register */
    VMSR    fpexc, r1    /* Set FPEXC register */

    POP     {r0, r1}     /* Pop LR_irq to r0 and SPSR to r1 */
    MSR     spsr_cxsf, r1     /* Restore SPSR */

    BX      lr           /* LR_fnc */


    .end

