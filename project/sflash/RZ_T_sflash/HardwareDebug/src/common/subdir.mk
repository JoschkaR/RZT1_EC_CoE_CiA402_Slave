################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
ASM_SRCS += \
C:/Users/josch/OneDrive/Studium/Semester/6.\ Semester/Fachpraktikum/EtherCAT_CiA402/1_Workspace/workspace_selfmade_ssc/1_V2.x/EtherCAT_SSC_CiA402/src/common/loader_init.asm \
C:/Users/josch/OneDrive/Studium/Semester/6.\ Semester/Fachpraktikum/EtherCAT_CiA402/1_Workspace/workspace_selfmade_ssc/1_V2.x/EtherCAT_SSC_CiA402/src/common/vector.asm 

C_SRCS += \
C:/Users/josch/OneDrive/Studium/Semester/6.\ Semester/Fachpraktikum/EtherCAT_CiA402/1_Workspace/workspace_selfmade_ssc/1_V2.x/EtherCAT_SSC_CiA402/src/common/exit.c \
C:/Users/josch/OneDrive/Studium/Semester/6.\ Semester/Fachpraktikum/EtherCAT_CiA402/1_Workspace/workspace_selfmade_ssc/1_V2.x/EtherCAT_SSC_CiA402/src/common/loader_init2.c \
C:/Users/josch/OneDrive/Studium/Semester/6.\ Semester/Fachpraktikum/EtherCAT_CiA402/1_Workspace/workspace_selfmade_ssc/1_V2.x/EtherCAT_SSC_CiA402/src/common/r_atcm_init.c \
C:/Users/josch/OneDrive/Studium/Semester/6.\ Semester/Fachpraktikum/EtherCAT_CiA402/1_Workspace/workspace_selfmade_ssc/1_V2.x/EtherCAT_SSC_CiA402/src/common/r_cpg.c \
C:/Users/josch/OneDrive/Studium/Semester/6.\ Semester/Fachpraktikum/EtherCAT_CiA402/1_Workspace/workspace_selfmade_ssc/1_V2.x/EtherCAT_SSC_CiA402/src/common/r_mpc.c \
C:/Users/josch/OneDrive/Studium/Semester/6.\ Semester/Fachpraktikum/EtherCAT_CiA402/1_Workspace/workspace_selfmade_ssc/1_V2.x/EtherCAT_SSC_CiA402/src/common/r_reset.c 

C_DEPS += \
./src/common/exit.d \
./src/common/loader_init2.d \
./src/common/r_atcm_init.d \
./src/common/r_cpg.d \
./src/common/r_mpc.d \
./src/common/r_reset.d 

OBJS += \
./src/common/exit.o \
./src/common/loader_init.o \
./src/common/loader_init2.o \
./src/common/r_atcm_init.o \
./src/common/r_cpg.o \
./src/common/r_mpc.o \
./src/common/r_reset.o \
./src/common/vector.o 

ASM_DEPS += \
./src/common/loader_init.d \
./src/common/vector.d 


# Each subdirectory must supply rules for building sources it contributes
src/common/exit.o: C:/Users/josch/OneDrive/Studium/Semester/6.\ Semester/Fachpraktikum/EtherCAT_CiA402/1_Workspace/workspace_selfmade_ssc/1_V2.x/EtherCAT_SSC_CiA402/src/common/exit.c
	$(file > $@.in,-mcpu=cortex-r4f -march=armv7-r -marm -mthumb-interwork -mlittle-endian -mfloat-abi=softfp -mfpu=vfp -O0 -ffunction-sections -fdata-sections -Wnull-dereference -g3 -I"C:/Users/josch/OneDrive/Studium/Semester/6. Semester/Fachpraktikum/EtherCAT_CiA402/1_Workspace/workspace_selfmade_ssc/1_V2.x/EtherCAT_SSC_CiA402/project/sflash/RZ_T_sflash/../../../inc" -I"C:/Users/josch/OneDrive/Studium/Semester/6. Semester/Fachpraktikum/EtherCAT_CiA402/1_Workspace/workspace_selfmade_ssc/1_V2.x/EtherCAT_SSC_CiA402/project/sflash/RZ_T_sflash/../../../src/sample/src/Src" -DDOUBLE_HAS_64_BITS -MMD -MP -MF"src/common/exit.d" -MT"src/common/exit.d" -c -o "$@" "$<")
	@echo 'arm-none-eabi-gcc -mcpu=cortex-r4f -march=armv7-r -marm -mthumb-interwork -mlittle-endian -mfloat-abi=softfp -mfpu=vfp -O0 -ffunction-sections -fdata-sections -Wnull-dereference -g3 -I"C:/Users/josch/OneDrive/Studium/Semester/6. Semester/Fachpraktikum/EtherCAT_CiA402/1_Workspace/workspace_selfmade_ssc/1_V2.x/EtherCAT_SSC_CiA402/project/sflash/RZ_T_sflash/../../../inc" -I"C:/Users/josch/OneDrive/Studium/Semester/6. Semester/Fachpraktikum/EtherCAT_CiA402/1_Workspace/workspace_selfmade_ssc/1_V2.x/EtherCAT_SSC_CiA402/project/sflash/RZ_T_sflash/../../../src/sample/src/Src" -DDOUBLE_HAS_64_BITS -MMD -MP -MF"src/common/exit.d" -MT"src/common/exit.d" -c -o "$@" "$<"'

	@arm-none-eabi-gcc @"$@.in"
src/common/loader_init.o: C:/Users/josch/OneDrive/Studium/Semester/6.\ Semester/Fachpraktikum/EtherCAT_CiA402/1_Workspace/workspace_selfmade_ssc/1_V2.x/EtherCAT_SSC_CiA402/src/common/loader_init.asm
	$(file > $@.in,-mcpu=cortex-r4f -march=armv7-r -marm -mthumb-interwork -mlittle-endian -mfloat-abi=softfp -mfpu=vfp -O0 -ffunction-sections -fdata-sections -Wnull-dereference -g3 -x assembler-with-cpp -MMD -MP -MF"src/common/loader_init.d" -MT"src/common/loader_init.d" -c -o "$@" "$<")
	@echo 'arm-none-eabi-gcc -mcpu=cortex-r4f -march=armv7-r -marm -mthumb-interwork -mlittle-endian -mfloat-abi=softfp -mfpu=vfp -O0 -ffunction-sections -fdata-sections -Wnull-dereference -g3 -x assembler-with-cpp -MMD -MP -MF"src/common/loader_init.d" -MT"src/common/loader_init.d" -c -o "$@" "$<"'

	@arm-none-eabi-gcc @"$@.in"
src/common/loader_init2.o: C:/Users/josch/OneDrive/Studium/Semester/6.\ Semester/Fachpraktikum/EtherCAT_CiA402/1_Workspace/workspace_selfmade_ssc/1_V2.x/EtherCAT_SSC_CiA402/src/common/loader_init2.c
	$(file > $@.in,-mcpu=cortex-r4f -march=armv7-r -marm -mthumb-interwork -mlittle-endian -mfloat-abi=softfp -mfpu=vfp -O0 -ffunction-sections -fdata-sections -Wnull-dereference -g3 -I"C:/Users/josch/OneDrive/Studium/Semester/6. Semester/Fachpraktikum/EtherCAT_CiA402/1_Workspace/workspace_selfmade_ssc/1_V2.x/EtherCAT_SSC_CiA402/project/sflash/RZ_T_sflash/../../../inc" -I"C:/Users/josch/OneDrive/Studium/Semester/6. Semester/Fachpraktikum/EtherCAT_CiA402/1_Workspace/workspace_selfmade_ssc/1_V2.x/EtherCAT_SSC_CiA402/project/sflash/RZ_T_sflash/../../../src/sample/src/Src" -DDOUBLE_HAS_64_BITS -MMD -MP -MF"src/common/loader_init2.d" -MT"src/common/loader_init2.d" -c -o "$@" "$<")
	@echo 'arm-none-eabi-gcc -mcpu=cortex-r4f -march=armv7-r -marm -mthumb-interwork -mlittle-endian -mfloat-abi=softfp -mfpu=vfp -O0 -ffunction-sections -fdata-sections -Wnull-dereference -g3 -I"C:/Users/josch/OneDrive/Studium/Semester/6. Semester/Fachpraktikum/EtherCAT_CiA402/1_Workspace/workspace_selfmade_ssc/1_V2.x/EtherCAT_SSC_CiA402/project/sflash/RZ_T_sflash/../../../inc" -I"C:/Users/josch/OneDrive/Studium/Semester/6. Semester/Fachpraktikum/EtherCAT_CiA402/1_Workspace/workspace_selfmade_ssc/1_V2.x/EtherCAT_SSC_CiA402/project/sflash/RZ_T_sflash/../../../src/sample/src/Src" -DDOUBLE_HAS_64_BITS -MMD -MP -MF"src/common/loader_init2.d" -MT"src/common/loader_init2.d" -c -o "$@" "$<"'

	@arm-none-eabi-gcc @"$@.in"
src/common/r_atcm_init.o: C:/Users/josch/OneDrive/Studium/Semester/6.\ Semester/Fachpraktikum/EtherCAT_CiA402/1_Workspace/workspace_selfmade_ssc/1_V2.x/EtherCAT_SSC_CiA402/src/common/r_atcm_init.c
	$(file > $@.in,-mcpu=cortex-r4f -march=armv7-r -marm -mthumb-interwork -mlittle-endian -mfloat-abi=softfp -mfpu=vfp -O0 -ffunction-sections -fdata-sections -Wnull-dereference -g3 -I"C:/Users/josch/OneDrive/Studium/Semester/6. Semester/Fachpraktikum/EtherCAT_CiA402/1_Workspace/workspace_selfmade_ssc/1_V2.x/EtherCAT_SSC_CiA402/project/sflash/RZ_T_sflash/../../../inc" -I"C:/Users/josch/OneDrive/Studium/Semester/6. Semester/Fachpraktikum/EtherCAT_CiA402/1_Workspace/workspace_selfmade_ssc/1_V2.x/EtherCAT_SSC_CiA402/project/sflash/RZ_T_sflash/../../../src/sample/src/Src" -DDOUBLE_HAS_64_BITS -MMD -MP -MF"src/common/r_atcm_init.d" -MT"src/common/r_atcm_init.d" -c -o "$@" "$<")
	@echo 'arm-none-eabi-gcc -mcpu=cortex-r4f -march=armv7-r -marm -mthumb-interwork -mlittle-endian -mfloat-abi=softfp -mfpu=vfp -O0 -ffunction-sections -fdata-sections -Wnull-dereference -g3 -I"C:/Users/josch/OneDrive/Studium/Semester/6. Semester/Fachpraktikum/EtherCAT_CiA402/1_Workspace/workspace_selfmade_ssc/1_V2.x/EtherCAT_SSC_CiA402/project/sflash/RZ_T_sflash/../../../inc" -I"C:/Users/josch/OneDrive/Studium/Semester/6. Semester/Fachpraktikum/EtherCAT_CiA402/1_Workspace/workspace_selfmade_ssc/1_V2.x/EtherCAT_SSC_CiA402/project/sflash/RZ_T_sflash/../../../src/sample/src/Src" -DDOUBLE_HAS_64_BITS -MMD -MP -MF"src/common/r_atcm_init.d" -MT"src/common/r_atcm_init.d" -c -o "$@" "$<"'

	@arm-none-eabi-gcc @"$@.in"
src/common/r_cpg.o: C:/Users/josch/OneDrive/Studium/Semester/6.\ Semester/Fachpraktikum/EtherCAT_CiA402/1_Workspace/workspace_selfmade_ssc/1_V2.x/EtherCAT_SSC_CiA402/src/common/r_cpg.c
	$(file > $@.in,-mcpu=cortex-r4f -march=armv7-r -marm -mthumb-interwork -mlittle-endian -mfloat-abi=softfp -mfpu=vfp -O0 -ffunction-sections -fdata-sections -Wnull-dereference -g3 -I"C:/Users/josch/OneDrive/Studium/Semester/6. Semester/Fachpraktikum/EtherCAT_CiA402/1_Workspace/workspace_selfmade_ssc/1_V2.x/EtherCAT_SSC_CiA402/project/sflash/RZ_T_sflash/../../../inc" -I"C:/Users/josch/OneDrive/Studium/Semester/6. Semester/Fachpraktikum/EtherCAT_CiA402/1_Workspace/workspace_selfmade_ssc/1_V2.x/EtherCAT_SSC_CiA402/project/sflash/RZ_T_sflash/../../../src/sample/src/Src" -DDOUBLE_HAS_64_BITS -MMD -MP -MF"src/common/r_cpg.d" -MT"src/common/r_cpg.d" -c -o "$@" "$<")
	@echo 'arm-none-eabi-gcc -mcpu=cortex-r4f -march=armv7-r -marm -mthumb-interwork -mlittle-endian -mfloat-abi=softfp -mfpu=vfp -O0 -ffunction-sections -fdata-sections -Wnull-dereference -g3 -I"C:/Users/josch/OneDrive/Studium/Semester/6. Semester/Fachpraktikum/EtherCAT_CiA402/1_Workspace/workspace_selfmade_ssc/1_V2.x/EtherCAT_SSC_CiA402/project/sflash/RZ_T_sflash/../../../inc" -I"C:/Users/josch/OneDrive/Studium/Semester/6. Semester/Fachpraktikum/EtherCAT_CiA402/1_Workspace/workspace_selfmade_ssc/1_V2.x/EtherCAT_SSC_CiA402/project/sflash/RZ_T_sflash/../../../src/sample/src/Src" -DDOUBLE_HAS_64_BITS -MMD -MP -MF"src/common/r_cpg.d" -MT"src/common/r_cpg.d" -c -o "$@" "$<"'

	@arm-none-eabi-gcc @"$@.in"
src/common/r_mpc.o: C:/Users/josch/OneDrive/Studium/Semester/6.\ Semester/Fachpraktikum/EtherCAT_CiA402/1_Workspace/workspace_selfmade_ssc/1_V2.x/EtherCAT_SSC_CiA402/src/common/r_mpc.c
	$(file > $@.in,-mcpu=cortex-r4f -march=armv7-r -marm -mthumb-interwork -mlittle-endian -mfloat-abi=softfp -mfpu=vfp -O0 -ffunction-sections -fdata-sections -Wnull-dereference -g3 -I"C:/Users/josch/OneDrive/Studium/Semester/6. Semester/Fachpraktikum/EtherCAT_CiA402/1_Workspace/workspace_selfmade_ssc/1_V2.x/EtherCAT_SSC_CiA402/project/sflash/RZ_T_sflash/../../../inc" -I"C:/Users/josch/OneDrive/Studium/Semester/6. Semester/Fachpraktikum/EtherCAT_CiA402/1_Workspace/workspace_selfmade_ssc/1_V2.x/EtherCAT_SSC_CiA402/project/sflash/RZ_T_sflash/../../../src/sample/src/Src" -DDOUBLE_HAS_64_BITS -MMD -MP -MF"src/common/r_mpc.d" -MT"src/common/r_mpc.d" -c -o "$@" "$<")
	@echo 'arm-none-eabi-gcc -mcpu=cortex-r4f -march=armv7-r -marm -mthumb-interwork -mlittle-endian -mfloat-abi=softfp -mfpu=vfp -O0 -ffunction-sections -fdata-sections -Wnull-dereference -g3 -I"C:/Users/josch/OneDrive/Studium/Semester/6. Semester/Fachpraktikum/EtherCAT_CiA402/1_Workspace/workspace_selfmade_ssc/1_V2.x/EtherCAT_SSC_CiA402/project/sflash/RZ_T_sflash/../../../inc" -I"C:/Users/josch/OneDrive/Studium/Semester/6. Semester/Fachpraktikum/EtherCAT_CiA402/1_Workspace/workspace_selfmade_ssc/1_V2.x/EtherCAT_SSC_CiA402/project/sflash/RZ_T_sflash/../../../src/sample/src/Src" -DDOUBLE_HAS_64_BITS -MMD -MP -MF"src/common/r_mpc.d" -MT"src/common/r_mpc.d" -c -o "$@" "$<"'

	@arm-none-eabi-gcc @"$@.in"
src/common/r_reset.o: C:/Users/josch/OneDrive/Studium/Semester/6.\ Semester/Fachpraktikum/EtherCAT_CiA402/1_Workspace/workspace_selfmade_ssc/1_V2.x/EtherCAT_SSC_CiA402/src/common/r_reset.c
	$(file > $@.in,-mcpu=cortex-r4f -march=armv7-r -marm -mthumb-interwork -mlittle-endian -mfloat-abi=softfp -mfpu=vfp -O0 -ffunction-sections -fdata-sections -Wnull-dereference -g3 -I"C:/Users/josch/OneDrive/Studium/Semester/6. Semester/Fachpraktikum/EtherCAT_CiA402/1_Workspace/workspace_selfmade_ssc/1_V2.x/EtherCAT_SSC_CiA402/project/sflash/RZ_T_sflash/../../../inc" -I"C:/Users/josch/OneDrive/Studium/Semester/6. Semester/Fachpraktikum/EtherCAT_CiA402/1_Workspace/workspace_selfmade_ssc/1_V2.x/EtherCAT_SSC_CiA402/project/sflash/RZ_T_sflash/../../../src/sample/src/Src" -DDOUBLE_HAS_64_BITS -MMD -MP -MF"src/common/r_reset.d" -MT"src/common/r_reset.d" -c -o "$@" "$<")
	@echo 'arm-none-eabi-gcc -mcpu=cortex-r4f -march=armv7-r -marm -mthumb-interwork -mlittle-endian -mfloat-abi=softfp -mfpu=vfp -O0 -ffunction-sections -fdata-sections -Wnull-dereference -g3 -I"C:/Users/josch/OneDrive/Studium/Semester/6. Semester/Fachpraktikum/EtherCAT_CiA402/1_Workspace/workspace_selfmade_ssc/1_V2.x/EtherCAT_SSC_CiA402/project/sflash/RZ_T_sflash/../../../inc" -I"C:/Users/josch/OneDrive/Studium/Semester/6. Semester/Fachpraktikum/EtherCAT_CiA402/1_Workspace/workspace_selfmade_ssc/1_V2.x/EtherCAT_SSC_CiA402/project/sflash/RZ_T_sflash/../../../src/sample/src/Src" -DDOUBLE_HAS_64_BITS -MMD -MP -MF"src/common/r_reset.d" -MT"src/common/r_reset.d" -c -o "$@" "$<"'

	@arm-none-eabi-gcc @"$@.in"
src/common/vector.o: C:/Users/josch/OneDrive/Studium/Semester/6.\ Semester/Fachpraktikum/EtherCAT_CiA402/1_Workspace/workspace_selfmade_ssc/1_V2.x/EtherCAT_SSC_CiA402/src/common/vector.asm
	$(file > $@.in,-mcpu=cortex-r4f -march=armv7-r -marm -mthumb-interwork -mlittle-endian -mfloat-abi=softfp -mfpu=vfp -O0 -ffunction-sections -fdata-sections -Wnull-dereference -g3 -x assembler-with-cpp -MMD -MP -MF"src/common/vector.d" -MT"src/common/vector.d" -c -o "$@" "$<")
	@echo 'arm-none-eabi-gcc -mcpu=cortex-r4f -march=armv7-r -marm -mthumb-interwork -mlittle-endian -mfloat-abi=softfp -mfpu=vfp -O0 -ffunction-sections -fdata-sections -Wnull-dereference -g3 -x assembler-with-cpp -MMD -MP -MF"src/common/vector.d" -MT"src/common/vector.d" -c -o "$@" "$<"'

	@arm-none-eabi-gcc @"$@.in"

