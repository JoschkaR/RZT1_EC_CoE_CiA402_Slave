@echo off

pushd %0\..
cls

@echo --- Patching process start ---

@echo --- Move Src folder ---

set SRCDIR=Src

if exist %SRCDIR% rmdir /S /Q %SRCDIR%

set SRCDIR=ssc_project\Src

if exist %SRCDIR% move /Y %SRCDIR%

patch -u -p0 --binary < SSC_CiA402_20180515.patch

@echo --- Patching process end ---

pause
