################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
C:/Users/josch/OneDrive/Studium/Semester/6.\ Semester/Fachpraktikum/EtherCAT_CiA402/1_Workspace/workspace_selfmade_ssc/1_V2.x/EtherCAT_SSC_CiA402/src/drv/heapend.c \
C:/Users/josch/OneDrive/Studium/Semester/6.\ Semester/Fachpraktikum/EtherCAT_CiA402/1_Workspace/workspace_selfmade_ssc/1_V2.x/EtherCAT_SSC_CiA402/src/drv/r_ecm.c \
C:/Users/josch/OneDrive/Studium/Semester/6.\ Semester/Fachpraktikum/EtherCAT_CiA402/1_Workspace/workspace_selfmade_ssc/1_V2.x/EtherCAT_SSC_CiA402/src/drv/r_icu_init.c \
C:/Users/josch/OneDrive/Studium/Semester/6.\ Semester/Fachpraktikum/EtherCAT_CiA402/1_Workspace/workspace_selfmade_ssc/1_V2.x/EtherCAT_SSC_CiA402/src/drv/r_mpc2.c \
C:/Users/josch/OneDrive/Studium/Semester/6.\ Semester/Fachpraktikum/EtherCAT_CiA402/1_Workspace/workspace_selfmade_ssc/1_V2.x/EtherCAT_SSC_CiA402/src/drv/r_ram_init.c \
C:/Users/josch/OneDrive/Studium/Semester/6.\ Semester/Fachpraktikum/EtherCAT_CiA402/1_Workspace/workspace_selfmade_ssc/1_V2.x/EtherCAT_SSC_CiA402/src/drv/r_reset2.c 

C_DEPS += \
./src/drv/heapend.d \
./src/drv/r_ecm.d \
./src/drv/r_icu_init.d \
./src/drv/r_mpc2.d \
./src/drv/r_ram_init.d \
./src/drv/r_reset2.d 

OBJS += \
./src/drv/heapend.o \
./src/drv/r_ecm.o \
./src/drv/r_icu_init.o \
./src/drv/r_mpc2.o \
./src/drv/r_ram_init.o \
./src/drv/r_reset2.o 


# Each subdirectory must supply rules for building sources it contributes
src/drv/heapend.o: C:/Users/josch/OneDrive/Studium/Semester/6.\ Semester/Fachpraktikum/EtherCAT_CiA402/1_Workspace/workspace_selfmade_ssc/1_V2.x/EtherCAT_SSC_CiA402/src/drv/heapend.c
	$(file > $@.in,-mcpu=cortex-r4f -march=armv7-r -marm -mthumb-interwork -mlittle-endian -mfloat-abi=softfp -mfpu=vfp -O0 -ffunction-sections -fdata-sections -Wnull-dereference -g3 -I"C:/Users/josch/OneDrive/Studium/Semester/6. Semester/Fachpraktikum/EtherCAT_CiA402/1_Workspace/workspace_selfmade_ssc/1_V2.x/EtherCAT_SSC_CiA402/project/sflash/RZ_T_sflash/../../../inc" -I"C:/Users/josch/OneDrive/Studium/Semester/6. Semester/Fachpraktikum/EtherCAT_CiA402/1_Workspace/workspace_selfmade_ssc/1_V2.x/EtherCAT_SSC_CiA402/project/sflash/RZ_T_sflash/../../../src/sample/src/Src" -DDOUBLE_HAS_64_BITS -MMD -MP -MF"src/drv/heapend.d" -MT"src/drv/heapend.d" -c -o "$@" "$<")
	@echo 'arm-none-eabi-gcc -mcpu=cortex-r4f -march=armv7-r -marm -mthumb-interwork -mlittle-endian -mfloat-abi=softfp -mfpu=vfp -O0 -ffunction-sections -fdata-sections -Wnull-dereference -g3 -I"C:/Users/josch/OneDrive/Studium/Semester/6. Semester/Fachpraktikum/EtherCAT_CiA402/1_Workspace/workspace_selfmade_ssc/1_V2.x/EtherCAT_SSC_CiA402/project/sflash/RZ_T_sflash/../../../inc" -I"C:/Users/josch/OneDrive/Studium/Semester/6. Semester/Fachpraktikum/EtherCAT_CiA402/1_Workspace/workspace_selfmade_ssc/1_V2.x/EtherCAT_SSC_CiA402/project/sflash/RZ_T_sflash/../../../src/sample/src/Src" -DDOUBLE_HAS_64_BITS -MMD -MP -MF"src/drv/heapend.d" -MT"src/drv/heapend.d" -c -o "$@" "$<"'

	@arm-none-eabi-gcc @"$@.in"
src/drv/r_ecm.o: C:/Users/josch/OneDrive/Studium/Semester/6.\ Semester/Fachpraktikum/EtherCAT_CiA402/1_Workspace/workspace_selfmade_ssc/1_V2.x/EtherCAT_SSC_CiA402/src/drv/r_ecm.c
	$(file > $@.in,-mcpu=cortex-r4f -march=armv7-r -marm -mthumb-interwork -mlittle-endian -mfloat-abi=softfp -mfpu=vfp -O0 -ffunction-sections -fdata-sections -Wnull-dereference -g3 -I"C:/Users/josch/OneDrive/Studium/Semester/6. Semester/Fachpraktikum/EtherCAT_CiA402/1_Workspace/workspace_selfmade_ssc/1_V2.x/EtherCAT_SSC_CiA402/project/sflash/RZ_T_sflash/../../../inc" -I"C:/Users/josch/OneDrive/Studium/Semester/6. Semester/Fachpraktikum/EtherCAT_CiA402/1_Workspace/workspace_selfmade_ssc/1_V2.x/EtherCAT_SSC_CiA402/project/sflash/RZ_T_sflash/../../../src/sample/src/Src" -DDOUBLE_HAS_64_BITS -MMD -MP -MF"src/drv/r_ecm.d" -MT"src/drv/r_ecm.d" -c -o "$@" "$<")
	@echo 'arm-none-eabi-gcc -mcpu=cortex-r4f -march=armv7-r -marm -mthumb-interwork -mlittle-endian -mfloat-abi=softfp -mfpu=vfp -O0 -ffunction-sections -fdata-sections -Wnull-dereference -g3 -I"C:/Users/josch/OneDrive/Studium/Semester/6. Semester/Fachpraktikum/EtherCAT_CiA402/1_Workspace/workspace_selfmade_ssc/1_V2.x/EtherCAT_SSC_CiA402/project/sflash/RZ_T_sflash/../../../inc" -I"C:/Users/josch/OneDrive/Studium/Semester/6. Semester/Fachpraktikum/EtherCAT_CiA402/1_Workspace/workspace_selfmade_ssc/1_V2.x/EtherCAT_SSC_CiA402/project/sflash/RZ_T_sflash/../../../src/sample/src/Src" -DDOUBLE_HAS_64_BITS -MMD -MP -MF"src/drv/r_ecm.d" -MT"src/drv/r_ecm.d" -c -o "$@" "$<"'

	@arm-none-eabi-gcc @"$@.in"
src/drv/r_icu_init.o: C:/Users/josch/OneDrive/Studium/Semester/6.\ Semester/Fachpraktikum/EtherCAT_CiA402/1_Workspace/workspace_selfmade_ssc/1_V2.x/EtherCAT_SSC_CiA402/src/drv/r_icu_init.c
	$(file > $@.in,-mcpu=cortex-r4f -march=armv7-r -marm -mthumb-interwork -mlittle-endian -mfloat-abi=softfp -mfpu=vfp -O0 -ffunction-sections -fdata-sections -Wnull-dereference -g3 -I"C:/Users/josch/OneDrive/Studium/Semester/6. Semester/Fachpraktikum/EtherCAT_CiA402/1_Workspace/workspace_selfmade_ssc/1_V2.x/EtherCAT_SSC_CiA402/project/sflash/RZ_T_sflash/../../../inc" -I"C:/Users/josch/OneDrive/Studium/Semester/6. Semester/Fachpraktikum/EtherCAT_CiA402/1_Workspace/workspace_selfmade_ssc/1_V2.x/EtherCAT_SSC_CiA402/project/sflash/RZ_T_sflash/../../../src/sample/src/Src" -DDOUBLE_HAS_64_BITS -MMD -MP -MF"src/drv/r_icu_init.d" -MT"src/drv/r_icu_init.d" -c -o "$@" "$<")
	@echo 'arm-none-eabi-gcc -mcpu=cortex-r4f -march=armv7-r -marm -mthumb-interwork -mlittle-endian -mfloat-abi=softfp -mfpu=vfp -O0 -ffunction-sections -fdata-sections -Wnull-dereference -g3 -I"C:/Users/josch/OneDrive/Studium/Semester/6. Semester/Fachpraktikum/EtherCAT_CiA402/1_Workspace/workspace_selfmade_ssc/1_V2.x/EtherCAT_SSC_CiA402/project/sflash/RZ_T_sflash/../../../inc" -I"C:/Users/josch/OneDrive/Studium/Semester/6. Semester/Fachpraktikum/EtherCAT_CiA402/1_Workspace/workspace_selfmade_ssc/1_V2.x/EtherCAT_SSC_CiA402/project/sflash/RZ_T_sflash/../../../src/sample/src/Src" -DDOUBLE_HAS_64_BITS -MMD -MP -MF"src/drv/r_icu_init.d" -MT"src/drv/r_icu_init.d" -c -o "$@" "$<"'

	@arm-none-eabi-gcc @"$@.in"
src/drv/r_mpc2.o: C:/Users/josch/OneDrive/Studium/Semester/6.\ Semester/Fachpraktikum/EtherCAT_CiA402/1_Workspace/workspace_selfmade_ssc/1_V2.x/EtherCAT_SSC_CiA402/src/drv/r_mpc2.c
	$(file > $@.in,-mcpu=cortex-r4f -march=armv7-r -marm -mthumb-interwork -mlittle-endian -mfloat-abi=softfp -mfpu=vfp -O0 -ffunction-sections -fdata-sections -Wnull-dereference -g3 -I"C:/Users/josch/OneDrive/Studium/Semester/6. Semester/Fachpraktikum/EtherCAT_CiA402/1_Workspace/workspace_selfmade_ssc/1_V2.x/EtherCAT_SSC_CiA402/project/sflash/RZ_T_sflash/../../../inc" -I"C:/Users/josch/OneDrive/Studium/Semester/6. Semester/Fachpraktikum/EtherCAT_CiA402/1_Workspace/workspace_selfmade_ssc/1_V2.x/EtherCAT_SSC_CiA402/project/sflash/RZ_T_sflash/../../../src/sample/src/Src" -DDOUBLE_HAS_64_BITS -MMD -MP -MF"src/drv/r_mpc2.d" -MT"src/drv/r_mpc2.d" -c -o "$@" "$<")
	@echo 'arm-none-eabi-gcc -mcpu=cortex-r4f -march=armv7-r -marm -mthumb-interwork -mlittle-endian -mfloat-abi=softfp -mfpu=vfp -O0 -ffunction-sections -fdata-sections -Wnull-dereference -g3 -I"C:/Users/josch/OneDrive/Studium/Semester/6. Semester/Fachpraktikum/EtherCAT_CiA402/1_Workspace/workspace_selfmade_ssc/1_V2.x/EtherCAT_SSC_CiA402/project/sflash/RZ_T_sflash/../../../inc" -I"C:/Users/josch/OneDrive/Studium/Semester/6. Semester/Fachpraktikum/EtherCAT_CiA402/1_Workspace/workspace_selfmade_ssc/1_V2.x/EtherCAT_SSC_CiA402/project/sflash/RZ_T_sflash/../../../src/sample/src/Src" -DDOUBLE_HAS_64_BITS -MMD -MP -MF"src/drv/r_mpc2.d" -MT"src/drv/r_mpc2.d" -c -o "$@" "$<"'

	@arm-none-eabi-gcc @"$@.in"
src/drv/r_ram_init.o: C:/Users/josch/OneDrive/Studium/Semester/6.\ Semester/Fachpraktikum/EtherCAT_CiA402/1_Workspace/workspace_selfmade_ssc/1_V2.x/EtherCAT_SSC_CiA402/src/drv/r_ram_init.c
	$(file > $@.in,-mcpu=cortex-r4f -march=armv7-r -marm -mthumb-interwork -mlittle-endian -mfloat-abi=softfp -mfpu=vfp -O0 -ffunction-sections -fdata-sections -Wnull-dereference -g3 -I"C:/Users/josch/OneDrive/Studium/Semester/6. Semester/Fachpraktikum/EtherCAT_CiA402/1_Workspace/workspace_selfmade_ssc/1_V2.x/EtherCAT_SSC_CiA402/project/sflash/RZ_T_sflash/../../../inc" -I"C:/Users/josch/OneDrive/Studium/Semester/6. Semester/Fachpraktikum/EtherCAT_CiA402/1_Workspace/workspace_selfmade_ssc/1_V2.x/EtherCAT_SSC_CiA402/project/sflash/RZ_T_sflash/../../../src/sample/src/Src" -DDOUBLE_HAS_64_BITS -MMD -MP -MF"src/drv/r_ram_init.d" -MT"src/drv/r_ram_init.d" -c -o "$@" "$<")
	@echo 'arm-none-eabi-gcc -mcpu=cortex-r4f -march=armv7-r -marm -mthumb-interwork -mlittle-endian -mfloat-abi=softfp -mfpu=vfp -O0 -ffunction-sections -fdata-sections -Wnull-dereference -g3 -I"C:/Users/josch/OneDrive/Studium/Semester/6. Semester/Fachpraktikum/EtherCAT_CiA402/1_Workspace/workspace_selfmade_ssc/1_V2.x/EtherCAT_SSC_CiA402/project/sflash/RZ_T_sflash/../../../inc" -I"C:/Users/josch/OneDrive/Studium/Semester/6. Semester/Fachpraktikum/EtherCAT_CiA402/1_Workspace/workspace_selfmade_ssc/1_V2.x/EtherCAT_SSC_CiA402/project/sflash/RZ_T_sflash/../../../src/sample/src/Src" -DDOUBLE_HAS_64_BITS -MMD -MP -MF"src/drv/r_ram_init.d" -MT"src/drv/r_ram_init.d" -c -o "$@" "$<"'

	@arm-none-eabi-gcc @"$@.in"
src/drv/r_reset2.o: C:/Users/josch/OneDrive/Studium/Semester/6.\ Semester/Fachpraktikum/EtherCAT_CiA402/1_Workspace/workspace_selfmade_ssc/1_V2.x/EtherCAT_SSC_CiA402/src/drv/r_reset2.c
	$(file > $@.in,-mcpu=cortex-r4f -march=armv7-r -marm -mthumb-interwork -mlittle-endian -mfloat-abi=softfp -mfpu=vfp -O0 -ffunction-sections -fdata-sections -Wnull-dereference -g3 -I"C:/Users/josch/OneDrive/Studium/Semester/6. Semester/Fachpraktikum/EtherCAT_CiA402/1_Workspace/workspace_selfmade_ssc/1_V2.x/EtherCAT_SSC_CiA402/project/sflash/RZ_T_sflash/../../../inc" -I"C:/Users/josch/OneDrive/Studium/Semester/6. Semester/Fachpraktikum/EtherCAT_CiA402/1_Workspace/workspace_selfmade_ssc/1_V2.x/EtherCAT_SSC_CiA402/project/sflash/RZ_T_sflash/../../../src/sample/src/Src" -DDOUBLE_HAS_64_BITS -MMD -MP -MF"src/drv/r_reset2.d" -MT"src/drv/r_reset2.d" -c -o "$@" "$<")
	@echo 'arm-none-eabi-gcc -mcpu=cortex-r4f -march=armv7-r -marm -mthumb-interwork -mlittle-endian -mfloat-abi=softfp -mfpu=vfp -O0 -ffunction-sections -fdata-sections -Wnull-dereference -g3 -I"C:/Users/josch/OneDrive/Studium/Semester/6. Semester/Fachpraktikum/EtherCAT_CiA402/1_Workspace/workspace_selfmade_ssc/1_V2.x/EtherCAT_SSC_CiA402/project/sflash/RZ_T_sflash/../../../inc" -I"C:/Users/josch/OneDrive/Studium/Semester/6. Semester/Fachpraktikum/EtherCAT_CiA402/1_Workspace/workspace_selfmade_ssc/1_V2.x/EtherCAT_SSC_CiA402/project/sflash/RZ_T_sflash/../../../src/sample/src/Src" -DDOUBLE_HAS_64_BITS -MMD -MP -MF"src/drv/r_reset2.d" -MT"src/drv/r_reset2.d" -c -o "$@" "$<"'

	@arm-none-eabi-gcc @"$@.in"

