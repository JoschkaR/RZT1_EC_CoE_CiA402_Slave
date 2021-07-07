################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
C:/Users/josch/OneDrive/Studium/Semester/6.\ Semester/Fachpraktikum/EtherCAT_CiA402/1_Workspace/workspace_selfmade_ssc/1_V2.x/EtherCAT_SSC_CiA402/src/drv/cmt/cmt_userdef.c \
C:/Users/josch/OneDrive/Studium/Semester/6.\ Semester/Fachpraktikum/EtherCAT_CiA402/1_Workspace/workspace_selfmade_ssc/1_V2.x/EtherCAT_SSC_CiA402/src/drv/cmt/r_cmt.c 

C_DEPS += \
./src/drv/cmt/cmt_userdef.d \
./src/drv/cmt/r_cmt.d 

OBJS += \
./src/drv/cmt/cmt_userdef.o \
./src/drv/cmt/r_cmt.o 


# Each subdirectory must supply rules for building sources it contributes
src/drv/cmt/cmt_userdef.o: C:/Users/josch/OneDrive/Studium/Semester/6.\ Semester/Fachpraktikum/EtherCAT_CiA402/1_Workspace/workspace_selfmade_ssc/1_V2.x/EtherCAT_SSC_CiA402/src/drv/cmt/cmt_userdef.c
	$(file > $@.in,-mcpu=cortex-r4f -march=armv7-r -marm -mthumb-interwork -mlittle-endian -mfloat-abi=softfp -mfpu=vfp -O0 -ffunction-sections -fdata-sections -Wnull-dereference -g3 -I"C:/Users/josch/OneDrive/Studium/Semester/6. Semester/Fachpraktikum/EtherCAT_CiA402/1_Workspace/workspace_selfmade_ssc/1_V2.x/EtherCAT_SSC_CiA402/project/sflash/RZ_T_sflash/../../../inc" -I"C:/Users/josch/OneDrive/Studium/Semester/6. Semester/Fachpraktikum/EtherCAT_CiA402/1_Workspace/workspace_selfmade_ssc/1_V2.x/EtherCAT_SSC_CiA402/project/sflash/RZ_T_sflash/../../../src/sample/src/Src" -DDOUBLE_HAS_64_BITS -MMD -MP -MF"src/drv/cmt/cmt_userdef.d" -MT"src/drv/cmt/cmt_userdef.d" -c -o "$@" "$<")
	@echo 'arm-none-eabi-gcc -mcpu=cortex-r4f -march=armv7-r -marm -mthumb-interwork -mlittle-endian -mfloat-abi=softfp -mfpu=vfp -O0 -ffunction-sections -fdata-sections -Wnull-dereference -g3 -I"C:/Users/josch/OneDrive/Studium/Semester/6. Semester/Fachpraktikum/EtherCAT_CiA402/1_Workspace/workspace_selfmade_ssc/1_V2.x/EtherCAT_SSC_CiA402/project/sflash/RZ_T_sflash/../../../inc" -I"C:/Users/josch/OneDrive/Studium/Semester/6. Semester/Fachpraktikum/EtherCAT_CiA402/1_Workspace/workspace_selfmade_ssc/1_V2.x/EtherCAT_SSC_CiA402/project/sflash/RZ_T_sflash/../../../src/sample/src/Src" -DDOUBLE_HAS_64_BITS -MMD -MP -MF"src/drv/cmt/cmt_userdef.d" -MT"src/drv/cmt/cmt_userdef.d" -c -o "$@" "$<"'

	@arm-none-eabi-gcc @"$@.in"
src/drv/cmt/r_cmt.o: C:/Users/josch/OneDrive/Studium/Semester/6.\ Semester/Fachpraktikum/EtherCAT_CiA402/1_Workspace/workspace_selfmade_ssc/1_V2.x/EtherCAT_SSC_CiA402/src/drv/cmt/r_cmt.c
	$(file > $@.in,-mcpu=cortex-r4f -march=armv7-r -marm -mthumb-interwork -mlittle-endian -mfloat-abi=softfp -mfpu=vfp -O0 -ffunction-sections -fdata-sections -Wnull-dereference -g3 -I"C:/Users/josch/OneDrive/Studium/Semester/6. Semester/Fachpraktikum/EtherCAT_CiA402/1_Workspace/workspace_selfmade_ssc/1_V2.x/EtherCAT_SSC_CiA402/project/sflash/RZ_T_sflash/../../../inc" -I"C:/Users/josch/OneDrive/Studium/Semester/6. Semester/Fachpraktikum/EtherCAT_CiA402/1_Workspace/workspace_selfmade_ssc/1_V2.x/EtherCAT_SSC_CiA402/project/sflash/RZ_T_sflash/../../../src/sample/src/Src" -DDOUBLE_HAS_64_BITS -MMD -MP -MF"src/drv/cmt/r_cmt.d" -MT"src/drv/cmt/r_cmt.d" -c -o "$@" "$<")
	@echo 'arm-none-eabi-gcc -mcpu=cortex-r4f -march=armv7-r -marm -mthumb-interwork -mlittle-endian -mfloat-abi=softfp -mfpu=vfp -O0 -ffunction-sections -fdata-sections -Wnull-dereference -g3 -I"C:/Users/josch/OneDrive/Studium/Semester/6. Semester/Fachpraktikum/EtherCAT_CiA402/1_Workspace/workspace_selfmade_ssc/1_V2.x/EtherCAT_SSC_CiA402/project/sflash/RZ_T_sflash/../../../inc" -I"C:/Users/josch/OneDrive/Studium/Semester/6. Semester/Fachpraktikum/EtherCAT_CiA402/1_Workspace/workspace_selfmade_ssc/1_V2.x/EtherCAT_SSC_CiA402/project/sflash/RZ_T_sflash/../../../src/sample/src/Src" -DDOUBLE_HAS_64_BITS -MMD -MP -MF"src/drv/cmt/r_cmt.d" -MT"src/drv/cmt/r_cmt.d" -c -o "$@" "$<"'

	@arm-none-eabi-gcc @"$@.in"

