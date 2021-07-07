################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
C:/Users/josch/OneDrive/Studium/Semester/6.\ Semester/Fachpraktikum/EtherCAT_CiA402/1_Workspace/workspace_selfmade_ssc/1_V2.x/EtherCAT_SSC_CiA402/src/drv/ether/r_ether.c 

C_DEPS += \
./src/drv/ether/r_ether.d 

OBJS += \
./src/drv/ether/r_ether.o 


# Each subdirectory must supply rules for building sources it contributes
src/drv/ether/r_ether.o: C:/Users/josch/OneDrive/Studium/Semester/6.\ Semester/Fachpraktikum/EtherCAT_CiA402/1_Workspace/workspace_selfmade_ssc/1_V2.x/EtherCAT_SSC_CiA402/src/drv/ether/r_ether.c
	$(file > $@.in,-mcpu=cortex-r4f -march=armv7-r -marm -mthumb-interwork -mlittle-endian -mfloat-abi=softfp -mfpu=vfp -O0 -ffunction-sections -fdata-sections -Wnull-dereference -g3 -I"C:/Users/josch/OneDrive/Studium/Semester/6. Semester/Fachpraktikum/EtherCAT_CiA402/1_Workspace/workspace_selfmade_ssc/1_V2.x/EtherCAT_SSC_CiA402/project/sflash/RZ_T_sflash/../../../inc" -I"C:/Users/josch/OneDrive/Studium/Semester/6. Semester/Fachpraktikum/EtherCAT_CiA402/1_Workspace/workspace_selfmade_ssc/1_V2.x/EtherCAT_SSC_CiA402/project/sflash/RZ_T_sflash/../../../src/sample/src/Src" -DDOUBLE_HAS_64_BITS -MMD -MP -MF"src/drv/ether/r_ether.d" -MT"src/drv/ether/r_ether.d" -c -o "$@" "$<")
	@echo 'arm-none-eabi-gcc -mcpu=cortex-r4f -march=armv7-r -marm -mthumb-interwork -mlittle-endian -mfloat-abi=softfp -mfpu=vfp -O0 -ffunction-sections -fdata-sections -Wnull-dereference -g3 -I"C:/Users/josch/OneDrive/Studium/Semester/6. Semester/Fachpraktikum/EtherCAT_CiA402/1_Workspace/workspace_selfmade_ssc/1_V2.x/EtherCAT_SSC_CiA402/project/sflash/RZ_T_sflash/../../../inc" -I"C:/Users/josch/OneDrive/Studium/Semester/6. Semester/Fachpraktikum/EtherCAT_CiA402/1_Workspace/workspace_selfmade_ssc/1_V2.x/EtherCAT_SSC_CiA402/project/sflash/RZ_T_sflash/../../../src/sample/src/Src" -DDOUBLE_HAS_64_BITS -MMD -MP -MF"src/drv/ether/r_ether.d" -MT"src/drv/ether/r_ether.d" -c -o "$@" "$<"'

	@arm-none-eabi-gcc @"$@.in"

