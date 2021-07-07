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
* Copyright (C) 2015 Renesas Electronics Corporation. All rights reserved.
******************************************************************************/
/******************************************************************************
* System Name : RZ/T1 EtherCAT  SSC CiA402 Sample Program
* File Name   : readme_E.txt
******************************************************************************/
/******************************************************************************
* History     : Dec. 01, 2015 Rev.1.00.00     Initial documentation
******************************************************************************/

1. Before Use

  This sample program has been written for and tested upon the RZ/T1 evaluation board.


  ****************************** CAUTION ******************************
   This sample program is for reference only. Please use this sample
   program for technical reference.
  ****************************** CAUTION ******************************


2. Overview & Features

  This sample software is the EtherCAT control program (created by SSC Tool)
  and CiA402 Drive Profile running on the RZ/T1 Evaluation Board.

  - Copy Cortex-M3 program to Intstruction RAM, then boot Cortex-M3.

  - Sets CMT0 and settings as below.
        Clock   : PCLKD / 512 (PCLKD=75MHz)
        Interval: CMT0 = 1000Hz
        Interrupt: CMI0 is enabled.

  - After CMT0 is started, CMT0 execute the dummy motor function.

  - The dummy motor function.

        While the SW1 is pushed, LED1 is on and the actual value is
        incremented up to the target value.
        When The SW1 is released, the actual value is cleared.


3. Operation Confirmation Conditions

  (1) System
      CPU                      : RZ/T1 group (R7S910017)
      Evaluation board         : RSK+RZT1 (RTK7910022C00000BR)
      Development environment  : e2 studio
                                 SEGGER j-link
      Operation mode           : SPI boot mode (Serial flash),
                                 16-bit bus boot mode (NOR flash)

  (2) Operating frequency
      The RZ/T1 evaluation board has the following clock inputs.
      - Main oscillator clock           : 25MHz
      - CPU clock (CPUCLK)              : 450MHz

  (3) Setting for DIP switches and jumpers
      Set the  DIP switches and jumpers of the RTK7910022C00000BR as follows.

      SW4   - SW4-1 ON, SW4-2 ON, SW4-3 ON, SW4-4 ON, SW4-5 ON, SW4-6 OFF
              (SPI boot mode)
                or
              SW4-1 ON, SW4-2 OFF, SW4-3 ON, SW4-4 ON, SW4-5 ON, SW4-6 OFF
              (16-bit bus boot mode)
      JP2   - 2-3
      JP7   - 1-2

  (4) LAN connector for EtherCAT
      EtherCAT1 (to Master), EtherCAT2


4. Create sample software by SSC tool

  Note. The SSC tool Ver5.11 is available.

  (1) Create sample software by SSC tool
      Double click SSC project file in the sample software and run SSC tool.

      \RZT1_Sample_single_xxxxxx\workspace\kpitgcc\EtherCAT_SSC_CiA402\src\sample\src
      \ssc_project\RZT1-R EtherCAT demo CiA402 s.esp

  (2) "Project" -> "Create new Slave Files" -> "Start" -> "OK"

  (3) SSC Tool creates sample source files in the following folder.
      "../Src"

  (4) Prepare patch command

      GNU Patch Ver2.5.9 or a later version is needed.

      Download the patch command (Ver2.5.9) from the following web and store
      "patch.exe" on the directory path.

      http://gnuwin32.sourceforge.net/packages/patch.htm

  (5) Double-click the batch file to patch.
      The patch file contains some modifications to SSC source files of RZ/T1.

      \RZT1_Sample_single_xxxxxx\workspace\kpitgcc\EtherCAT_SSC_CiA402\src\sample\src
      \apply_patch.bat

  (6) You can build "Slave Stack Code".


5. Setup TwinCAT3

  Copy the "RZT1-R EtherCAT demo CiA402.xml" ESI file from the folder

  \RZT1_Sample_single_xxxxxx\workspace\kpitgcc\EtherCAT_SSC_CiA402\src\sample\src
  \ESI_File

  to the folder

  \TwinCAT\3.x\Config\IO\EtherCAT


6. Build Cortex-R4 project

  Next, You should build Cortex-R4 part project.

  The project folder is below.

  \RZT1_Sample_single_xxxxxx\workspace\kpitgcc\EtherCAT_SSC_CiA402


7. Linkup with TwinCAT3


8. Reference

  Implementation Guide of CiA402 Drive Profile R-IN32M3, RZ/T1


9. Other

  - EtherCAT is registered trademark and patented technology, licensed by Beckhoff Automation GmbH, Germany.

  - TwinCAT3 is registered trademark of and licensed by Beckhoff Automation GmbH.

/* End of File */
