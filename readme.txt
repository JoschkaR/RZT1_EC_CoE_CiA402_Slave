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

1. ご注意

  本ソフトウエアはあくまで参考用であり，当社がこの動作を保証するものではありません。
  本ソフトウエアを使用する場合は，お客様のセット上で十分な評価を行ったうえでご使用
  いただきますようお願いいたします。


2. 概要と機能

  本ソフトウェアはRZ/T1評価ボードで動作するEtherCAT制御プログラム (SSCツールで生成) と
  CiA402用のサンプルアプリケーションです。

  - CMT0を次のように設定します。
        クロック    : PCLKD / 512 (PCLKD=75MHz)
        インターバル: CMT0 = 1000Hz
        割り込み    : CMI0を許可

  - CMT0はスタート後、ダミーモーター関数を実行します。

  - ダミーモーター関数

        SW1が押下されている間、LED1は点灯し、Target ValueになるまでActual Valueを
        インクリメントします。
        SW1が離されるとLED1は消灯し、Actual Valueはクリアされます。


3. 操作確認条件

  (1) システム
      CPU                      : RZ/T1 group (R7S910017)
      評価ボード               : RSK+RZT1 (RTK7910022C00000BR)
      開発環境                 : e2 studio
                                 SEGGER j-link
      動作モード               : SPI ブートモード (Serial flash),
                                 16ビットバスブートモード (NOR flash)

  (2) 動作周波数
      RZ/T1評価ボードには下記のクロック入力があります。
      - メイン発振クロック              : 25MHz
      - CPUクロック (CPUCLK)            : 450MHz

  (3) DIP SWとジャンパーの設定
      RTK7910022C00000BRのDIP SWとジャンパーを次のように設定してください。

      SW4   - SW4-1 ON, SW4-2 ON, SW4-3 ON, SW4-4 ON, SW4-5 ON, SW4-6 OFF
              (SPIブートモード)
                or
              SW4-1 ON, SW4-2 OFF, SW4-3 ON, SW4-4 ON, SW4-5 ON, SW4-6 OFF
              (16ビットバスブートモード)
      JP2   - 2-3
      JP7   - 1-2

  (4) EtherCAT通信で使用するLANコネクター
      EtherCAT1 (to Master), EtherCAT2


4. SSCツールによるサンプルソフトウェアの生成

  注意：SSCツールはVer 5.11を使用してください。

  (1) SSCツールによるサンプルソフトウェアを生成
      サンプルソフトウェアのSSCプロジェクトファイルをダブルクリックし、SSCツールを起動します。

      \RZT1_Sample_single_xxxxxx\workspace\kpitgcc\EtherCAT_SSC_CiA402\src\sample\src
      \ssc_project\RZT1-R EtherCAT demo CiA402 s.esp

  (2) "Project" -> "Create new Slave Files" -> "Start" -> "OK"

  (3) SSCツールは下記のフォルダのサンプルソフトウェアのソースファイルを作成します。
      "../Src"

  (4) パッチコマンドの準備
      GNU Patch Ver2.5.9以後が必要です。

      下記のWebサイトからパッチコマンド(Ver2.5.9)をダウンロードし
      "patch.exe"をディレクトリパスの通ったフォルダに格納します。

      http://gnuwin32.sourceforge.net/packages/patch.htm

  (5) バッチファイルをダブルクリックしてパッチを適用
      パッチファイルはSSCソースファイルに対するRZ/T1向けの修正を含んでいます。

      \RZT1_Sample_single_xxxxxx\workspace\kpitgcc\EtherCAT_SSC_CiA402\src\sample\src
      \apply_patch.bat

  (6) "Slave Stack Code"のビルドが可能となります。


5. TwinCAT3のセットアップ

  次のフォルダにあるESIファイル"RZT1-R EtherCAT demo CiA402.xml"を

  \RZT1_Sample_single_xxxxxx\workspace\kpitgcc\EtherCAT_SSC_CiA402\src\sample\src
  \ESI_File

  下記のフォルダにコピーしてください。

  \TwinCAT\3.x\Config\IO\EtherCAT


6. Cortex-R4プロジェクトのビルド

  次にCortex-R4プロジェクトをビルドしてください。

  プロジェクトフォルダは下記になります。

  \RZT1_Sample_single_xxxxxx\workspace\kpitgcc\EtherCAT_SSC_CiA402


7. TwinCAT3と接続してください。


8. リファレンス

  EtherCAT CiA402 ドライブプロファイルの実装ガイド R-IN32M3, RZ/T1


9. その他

  - EtherCATは、ドイツBeckhoff Automation GmbHによりライセンスされた特許取得済み技術
    であり登録商標です。

  - TwinCAT3はドイツBeckhoff Automation GmbHによりライセンスされた登録商標です。

/* End of File */
