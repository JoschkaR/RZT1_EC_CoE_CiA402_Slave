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
* File Name   : readme.txt
******************************************************************************/
/******************************************************************************
* History     : Dec. 01, 2015 Rev.1.00.00     Initial documentation
******************************************************************************/

1. ������

  �{�\�t�g�E�G�A�͂����܂ŎQ�l�p�ł���C���Ђ����̓����ۏ؂�����̂ł͂���܂���B
  �{�\�t�g�E�G�A���g�p����ꍇ�́C���q�l�̃Z�b�g��ŏ\���ȕ]�����s���������ł��g�p
  ���������܂��悤���肢�������܂��B


2. �T�v�Ƌ@�\

  �{�\�t�g�E�F�A��RZ/T1�]���{�[�h�œ��삷��EtherCAT����v���O���� (SSC�c�[���Ő���) ��
  CiA402�p�̃T���v���A�v���P�[�V�����ł��B

  - CMT0�����̂悤�ɐݒ肵�܂��B
        �N���b�N    : PCLKD / 512 (PCLKD=75MHz)
        �C���^�[�o��: CMT0 = 1000Hz
        ���荞��    : CMI0������

  - CMT0�̓X�^�[�g��A�_�~�[���[�^�[�֐������s���܂��B

  - �_�~�[���[�^�[�֐�

        SW1����������Ă���ԁALED1�͓_�����ATarget Value�ɂȂ�܂�Actual Value��
        �C���N�������g���܂��B
        SW1����������LED1�͏������AActual Value�̓N���A����܂��B


3. ����m�F����

  (1) �V�X�e��
      CPU                      : RZ/T1 group (R7S910017)
      �]���{�[�h               : RSK+RZT1 (RTK7910022C00000BR)
      �J����                 : e2 studio
                                 SEGGER j-link
      ���샂�[�h               : SPI �u�[�g���[�h (Serial flash),
                                 16�r�b�g�o�X�u�[�g���[�h (NOR flash)

  (2) ������g��
      RZ/T1�]���{�[�h�ɂ͉��L�̃N���b�N���͂�����܂��B
      - ���C�����U�N���b�N              : 25MHz
      - CPU�N���b�N (CPUCLK)            : 450MHz

  (3) DIP SW�ƃW�����p�[�̐ݒ�
      RTK7910022C00000BR��DIP SW�ƃW�����p�[�����̂悤�ɐݒ肵�Ă��������B

      SW4   - SW4-1 ON, SW4-2 ON, SW4-3 ON, SW4-4 ON, SW4-5 ON, SW4-6 OFF
              (SPI�u�[�g���[�h)
                or
              SW4-1 ON, SW4-2 OFF, SW4-3 ON, SW4-4 ON, SW4-5 ON, SW4-6 OFF
              (16�r�b�g�o�X�u�[�g���[�h)
      JP2   - 2-3
      JP7   - 1-2

  (4) EtherCAT�ʐM�Ŏg�p����LAN�R�l�N�^�[
      EtherCAT1 (to Master), EtherCAT2


4. SSC�c�[���ɂ��T���v���\�t�g�E�F�A�̐���

  ���ӁFSSC�c�[����Ver 5.11���g�p���Ă��������B

  (1) SSC�c�[���ɂ��T���v���\�t�g�E�F�A�𐶐�
      �T���v���\�t�g�E�F�A��SSC�v���W�F�N�g�t�@�C�����_�u���N���b�N���ASSC�c�[�����N�����܂��B

      \RZT1_Sample_single_xxxxxx\workspace\kpitgcc\EtherCAT_SSC_CiA402\src\sample\src
      \ssc_project\RZT1-R EtherCAT demo CiA402 s.esp

  (2) "Project" -> "Create new Slave Files" -> "Start" -> "OK"

  (3) SSC�c�[���͉��L�̃t�H���_�̃T���v���\�t�g�E�F�A�̃\�[�X�t�@�C�����쐬���܂��B
      "../Src"

  (4) �p�b�`�R�}���h�̏���
      GNU Patch Ver2.5.9�Ȍオ�K�v�ł��B

      ���L��Web�T�C�g����p�b�`�R�}���h(Ver2.5.9)���_�E�����[�h��
      "patch.exe"���f�B���N�g���p�X�̒ʂ����t�H���_�Ɋi�[���܂��B

      http://gnuwin32.sourceforge.net/packages/patch.htm

  (5) �o�b�`�t�@�C�����_�u���N���b�N���ăp�b�`��K�p
      �p�b�`�t�@�C����SSC�\�[�X�t�@�C���ɑ΂���RZ/T1�����̏C�����܂�ł��܂��B

      \RZT1_Sample_single_xxxxxx\workspace\kpitgcc\EtherCAT_SSC_CiA402\src\sample\src
      \apply_patch.bat

  (6) "Slave Stack Code"�̃r���h���\�ƂȂ�܂��B


5. TwinCAT3�̃Z�b�g�A�b�v

  ���̃t�H���_�ɂ���ESI�t�@�C��"RZT1-R EtherCAT demo CiA402.xml"��

  \RZT1_Sample_single_xxxxxx\workspace\kpitgcc\EtherCAT_SSC_CiA402\src\sample\src
  \ESI_File

  ���L�̃t�H���_�ɃR�s�[���Ă��������B

  \TwinCAT\3.x\Config\IO\EtherCAT


6. Cortex-R4�v���W�F�N�g�̃r���h

  ����Cortex-R4�v���W�F�N�g���r���h���Ă��������B

  �v���W�F�N�g�t�H���_�͉��L�ɂȂ�܂��B

  \RZT1_Sample_single_xxxxxx\workspace\kpitgcc\EtherCAT_SSC_CiA402


7. TwinCAT3�Ɛڑ����Ă��������B


8. ���t�@�����X

  EtherCAT CiA402 �h���C�u�v���t�@�C���̎����K�C�h R-IN32M3, RZ/T1


9. ���̑�

  - EtherCAT�́A�h�C�cBeckhoff Automation GmbH�ɂ�胉�C�Z���X���ꂽ�����擾�ς݋Z�p
    �ł���o�^���W�ł��B

  - TwinCAT3�̓h�C�cBeckhoff Automation GmbH�ɂ�胉�C�Z���X���ꂽ�o�^���W�ł��B

/* End of File */
