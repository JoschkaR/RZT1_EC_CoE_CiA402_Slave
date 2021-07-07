################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
ASM_SRCS += \
C:/Users/josch/OneDrive/Studium/Semester/6.\ Semester/Fachpraktikum/EtherCAT_CiA402/1_Workspace/workspace_selfmade_ssc/1_V2.x/EtherCAT_SSC_CiA402/src/sample/nestintr_wrap.asm 

C_SRCS += \
C:/Users/josch/OneDrive/Studium/Semester/6.\ Semester/Fachpraktikum/EtherCAT_CiA402/1_Workspace/workspace_selfmade_ssc/1_V2.x/EtherCAT_SSC_CiA402/src/sample/board_RenesasEva.c \
C:/Users/josch/OneDrive/Studium/Semester/6.\ Semester/Fachpraktikum/EtherCAT_CiA402/1_Workspace/workspace_selfmade_ssc/1_V2.x/EtherCAT_SSC_CiA402/src/sample/main.c 

C_DEPS += \
./src/sample/board_RenesasEva.d \
./src/sample/main.d 

OBJS += \
./src/sample/board_RenesasEva.o \
./src/sample/main.o \
./src/sample/nestintr_wrap.o 

ASM_DEPS += \
./src/sample/nestintr_wrap.d 


# Each subdirectory must supply rules for building sources it contributes
src/sample/board_RenesasEva.o: C:/Users/josch/OneDrive/Studium/Semester/6.\ Semester/Fachpraktikum/EtherCAT_CiA402/1_Workspace/workspace_selfmade_ssc/1_V2.x/EtherCAT_SSC_CiA402/src/sample/board_RenesasEva.c
	$(file > $@.in,-mcpu=cortex-r4f -march=armv7-r -marm -mthumb-interwork -mlittle-endian -mfloat-abi=softfp -mfpu=vfp -O0 -ffunction-sections -fdata-sections -Wnull-dereference -g3 -I"C:/Users/josch/OneDrive/Studium/Semester/6. Semester/Fachpraktikum/EtherCAT_CiA402/1_Workspace/workspace_selfmade_ssc/1_V2.x/EtherCAT_SSC_CiA402/project/sflash/RZ_T_sflash/../../../inc" -I"C:/Users/josch/OneDrive/Studium/Semester/6. Semester/Fachpraktikum/EtherCAT_CiA402/1_Workspace/workspace_selfmade_ssc/1_V2.x/EtherCAT_SSC_CiA402/project/sflash/RZ_T_sflash/../../../src/sample/src/Src" -DDOUBLE_HAS_64_BITS -MMD -MP -MF"src/sample/board_RenesasEva.d" -MT"src/sample/board_RenesasEva.d" -c -o "$@" "$<")
	@echo 'arm-none-eabi-gcc -mcpu=cortex-r4f -march=armv7-r -marm -mthumb-interwork -mlittle-endian -mfloat-abi=softfp -mfpu=vfp -O0 -ffunction-sections -fdata-sections -Wnull-dereference -g3 -I"C:/Users/josch/OneDrive/Studium/Semester/6. Semester/Fachpraktikum/EtherCAT_CiA402/1_Workspace/workspace_selfmade_ssc/1_V2.x/EtherCAT_SSC_CiA402/project/sflash/RZ_T_sflash/../../../inc" -I"C:/Users/josch/OneDrive/Studium/Semester/6. Semester/Fachpraktikum/EtherCAT_CiA402/1_Workspace/workspace_selfmade_ssc/1_V2.x/EtherCAT_SSC_CiA402/project/sflash/RZ_T_sflash/../../../src/sample/src/Src" -DDOUBLE_HAS_64_BITS -MMD -MP -MF"src/sample/board_RenesasEva.d" -MT"src/sample/board_RenesasEva.d" -c -o "$@" "$<"'

	@arm-none-eabi-gcc @"$@.in"
src/sample/main.o: C:/Users/josch/OneDrive/Studium/Semester/6.\ Semester/Fachpraktikum/EtherCAT_CiA402/1_Workspace/workspace_selfmade_ssc/1_V2.x/EtherCAT_SSC_CiA402/src/sample/main.c
	$(file > $@.in,-mcpu=cortex-r4f -march=armv7-r -marm -mthumb-interwork -mlittle-endian -mfloat-abi=softfp -mfpu=vfp -O0 -ffunction-sections -fdata-sections -Wnull-dereference -g3 -I"C:/Users/josch/OneDrive/Studium/Semester/6. Semester/Fachpraktikum/EtherCAT_CiA402/1_Workspace/workspace_selfmade_ssc/1_V2.x/EtherCAT_SSC_CiA402/project/sflash/RZ_T_sflash/../../../inc" -I"C:/Users/josch/OneDrive/Studium/Semester/6. Semester/Fachpraktikum/EtherCAT_CiA402/1_Workspace/workspace_selfmade_ssc/1_V2.x/EtherCAT_SSC_CiA402/project/sflash/RZ_T_sflash/../../../src/sample/src/Src" -DDOUBLE_HAS_64_BITS -MMD -MP -MF"src/sample/main.d" -MT"src/sample/main.d" -c -o "$@" "$<")
	@echo 'arm-none-eabi-gcc -mcpu=cortex-r4f -march=armv7-r -marm -mthumb-interwork -mlittle-endian -mfloat-abi=softfp -mfpu=vfp -O0 -ffunction-sections -fdata-sections -Wnull-dereference -g3 -I"C:/Users/josch/OneDrive/Studium/Semester/6. Semester/Fachpraktikum/EtherCAT_CiA402/1_Workspace/workspace_selfmade_ssc/1_V2.x/EtherCAT_SSC_CiA402/project/sflash/RZ_T_sflash/../../../inc" -I"C:/Users/josch/OneDrive/Studium/Semester/6. Semester/Fachpraktikum/EtherCAT_CiA402/1_Workspace/workspace_selfmade_ssc/1_V2.x/EtherCAT_SSC_CiA402/project/sflash/RZ_T_sflash/../../../src/sample/src/Src" -DDOUBLE_HAS_64_BITS -MMD -MP -MF"src/sample/main.d" -MT"src/sample/main.d" -c -o "$@" "$<"'

	@arm-none-eabi-gcc @"$@.in"
src/sample/nestintr_wrap.o: C:/Users/josch/OneDrive/Studium/Semester/6.\ Semester/Fachpraktikum/EtherCAT_CiA402/1_Workspace/workspace_selfmade_ssc/1_V2.x/EtherCAT_SSC_CiA402/src/sample/nestintr_wrap.asm
	$(file > $@.in,-mcpu=cortex-r4f -march=armv7-r -marm -mthumb-interwork -mlittle-endian -mfloat-abi=softfp -mfpu=vfp -O0 -ffunction-sections -fdata-sections -Wnull-dereference -g3 -x assembler-with-cpp -MMD -MP -MF"src/sample/nestintr_wrap.d" -MT"src/sample/nestintr_wrap.d" -c -o "$@" "$<")
	@echo 'arm-none-eabi-gcc -mcpu=cortex-r4f -march=armv7-r -marm -mthumb-interwork -mlittle-endian -mfloat-abi=softfp -mfpu=vfp -O0 -ffunction-sections -fdata-sections -Wnull-dereference -g3 -x assembler-with-cpp -MMD -MP -MF"src/sample/nestintr_wrap.d" -MT"src/sample/nestintr_wrap.d" -c -o "$@" "$<"'

	@arm-none-eabi-gcc @"$@.in"

