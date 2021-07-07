################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

-include makefile.init

RM := rm -rf *.lst *.lis *.lpp *.map

# All of the sources participating in the build are defined here
-include sources.mk
-include src/sample/src/Src/subdir.mk
-include src/sample/subdir.mk
-include src/drv/ether/subdir.mk
-include src/drv/cmt/subdir.mk
-include src/drv/subdir.mk
-include src/common/sflash_boot/subdir.mk
-include src/common/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(JMP_DEPS)),)
-include $(JMP_DEPS)
endif
ifneq ($(strip $(FSY_DEPS)),)
-include $(FSY_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
ifneq ($(strip $(SRC_UPPER_DEPS)),)
-include $(SRC_UPPER_DEPS)
endif
ifneq ($(strip $(P_UPPER_DEPS)),)
-include $(P_UPPER_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(PP_UPPER_DEPS)),)
-include $(PP_UPPER_DEPS)
endif
ifneq ($(strip $(P_DEPS)),)
-include $(P_DEPS)
endif
ifneq ($(strip $(FSY_UPPER_DEPS)),)
-include $(FSY_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(SRC_DEPS)),)
-include $(SRC_DEPS)
endif
ifneq ($(strip $(JMP_UPPER_DEPS)),)
-include $(JMP_UPPER_DEPS)
endif
ifneq ($(strip $(PP_DEPS)),)
-include $(PP_DEPS)
endif
ifneq ($(strip $(ASM_UPPER_DEPS)),)
-include $(ASM_UPPER_DEPS)
endif
ifneq ($(strip $(SX_DEPS)),)
-include $(SX_DEPS)
endif
ifneq ($(strip $(SX_UPPER_DEPS)),)
-include $(SX_UPPER_DEPS)
endif
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
SECONDARY_FLASH += \
RZ_T_sflash_sample.hex \

SECONDARY_SIZE += \
RZ_T_sflash_sample.siz \

LIBRARY_GENERATOR_OUTPUTTYPE_OUTPUTS += \
libRZ_T_sflash_sample.a \


# All Target
all: RZ_T_sflash_sample.x secondary-outputs

# Tool invocations
RZ_T_sflash_sample.x: $(OBJS) $(USER_OBJS) $(LIBRARY_GENERATOR_OUTPUTTYPE_OUTPUTS)
	@	$(file > RZ_T_sflash_sample.x.in,-mcpu=cortex-r4f -march=armv7-r -marm -mthumb-interwork -mlittle-endian -mfloat-abi=softfp -mfpu=vfp -O0 -ffunction-sections -fdata-sections -Wnull-dereference -g3 -o "RZ_T_sflash_sample.x" $(OBJS) $(USER_OBJS) -T "C:/Users/josch/OneDrive/Studium/Semester/6. Semester/Fachpraktikum/EtherCAT_CiA402/1_Workspace/workspace_selfmade_ssc/1_V2.x/EtherCAT_SSC_CiA402/project/sflash/RZ_T_sflash/../../../linker_script/sflash_boot.ld" -L "C:\\\\Users\\\\josch\\\\OneDrive\\\\Studium\\\\Semester\\\\6. Semester\\\\Fachpraktikum\\\\EtherCAT_CiA402\\\\1_Workspace\\\\workspace_selfmade_ssc\\\\1_V2.x\\\\EtherCAT_SSC_CiA402\\\\project\\\\sflash\\\\RZ_T_sflash\\\\HardwareDebug" -Wl,--start-group -lRZ_T_sflash_sample -lgcc -lgcc -Wl,--end-group -nostartfiles -Xlinker --gc-sections -Wl,-Map,"RZ_T_sflash_sample.map" -Wl,-e_PowerON_Reset --specs=rdimon.specs)
	@echo 'arm-none-eabi-gcc -mcpu=cortex-r4f -march=armv7-r -marm -mthumb-interwork -mlittle-endian -mfloat-abi=softfp -mfpu=vfp -O0 -ffunction-sections -fdata-sections -Wnull-dereference -g3 -o "RZ_T_sflash_sample.x" $(OBJS) $(USER_OBJS) -T "C:/Users/josch/OneDrive/Studium/Semester/6. Semester/Fachpraktikum/EtherCAT_CiA402/1_Workspace/workspace_selfmade_ssc/1_V2.x/EtherCAT_SSC_CiA402/project/sflash/RZ_T_sflash/../../../linker_script/sflash_boot.ld" -L "C:\\\\Users\\\\josch\\\\OneDrive\\\\Studium\\\\Semester\\\\6. Semester\\\\Fachpraktikum\\\\EtherCAT_CiA402\\\\1_Workspace\\\\workspace_selfmade_ssc\\\\1_V2.x\\\\EtherCAT_SSC_CiA402\\\\project\\\\sflash\\\\RZ_T_sflash\\\\HardwareDebug" -Wl,--start-group -lRZ_T_sflash_sample -lgcc -lgcc -Wl,--end-group -nostartfiles -Xlinker --gc-sections -Wl,-Map,"RZ_T_sflash_sample.map" -Wl,-e_PowerON_Reset --specs=rdimon.specs'

	arm-none-eabi-gcc @"RZ_T_sflash_sample.x.in"
RZ_T_sflash_sample.hex: RZ_T_sflash_sample.x
	arm-none-eabi-objcopy -O ihex "RZ_T_sflash_sample.x"  "RZ_T_sflash_sample.hex"
RZ_T_sflash_sample.siz: RZ_T_sflash_sample.x
	arm-none-eabi-size --format=berkeley "RZ_T_sflash_sample.x"
libRZ_T_sflash_sample.a: 
	arm-none-eabi-libgen  --header-files=all --select-lib=optlib --compiler-options=-O0,-ffunction-sections,-fdata-sections,-mcpu=cortex-r4f,-march=armv7-r,-mthumb-interwork,-mlittle-endian,-mfloat-abi=softfp,-mfpu=vfp --assembler-options=-mcpu=cortex-r4f,-march=armv7-r,-mthumb-interwork,-mlittle-endian,-mfloat-abi=softfp,-mfpu=vfp -o "libRZ_T_sflash_sample.a"
# Other Targets
clean:
ifneq ($(strip $(JMP_DEPS)),)
	-$(file > clean_JMP_DEPS.tmp, $(JMP_DEPS))
	-@ xargs -s 6000 -t -a clean_JMP_DEPS.tmp $(RM)
	-@$(RM) clean_JMP_DEPS.tmp
endif
ifneq ($(strip $(FSY_DEPS)),)
	-$(file > clean_FSY_DEPS.tmp, $(FSY_DEPS))
	-@ xargs -s 6000 -t -a clean_FSY_DEPS.tmp $(RM)
	-@$(RM) clean_FSY_DEPS.tmp
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
	-$(file > clean_C_UPPER_DEPS.tmp, $(C_UPPER_DEPS))
	-@ xargs -s 6000 -t -a clean_C_UPPER_DEPS.tmp $(RM)
	-@$(RM) clean_C_UPPER_DEPS.tmp
endif
ifneq ($(strip $(SECONDARY_SIZE)),)
	-$(file > clean_SECONDARY_SIZE.tmp, $(SECONDARY_SIZE))
	-@ xargs -s 6000 -t -a clean_SECONDARY_SIZE.tmp $(RM)
	-@$(RM) clean_SECONDARY_SIZE.tmp
endif
ifneq ($(strip $(SRC_UPPER_DEPS)),)
	-$(file > clean_SRC_UPPER_DEPS.tmp, $(SRC_UPPER_DEPS))
	-@ xargs -s 6000 -t -a clean_SRC_UPPER_DEPS.tmp $(RM)
	-@$(RM) clean_SRC_UPPER_DEPS.tmp
endif
ifneq ($(strip $(P_UPPER_DEPS)),)
	-$(file > clean_P_UPPER_DEPS.tmp, $(P_UPPER_DEPS))
	-@ xargs -s 6000 -t -a clean_P_UPPER_DEPS.tmp $(RM)
	-@$(RM) clean_P_UPPER_DEPS.tmp
endif
ifneq ($(strip $(S_DEPS)),)
	-$(file > clean_S_DEPS.tmp, $(S_DEPS))
	-@ xargs -s 6000 -t -a clean_S_DEPS.tmp $(RM)
	-@$(RM) clean_S_DEPS.tmp
endif
ifneq ($(strip $(PP_UPPER_DEPS)),)
	-$(file > clean_PP_UPPER_DEPS.tmp, $(PP_UPPER_DEPS))
	-@ xargs -s 6000 -t -a clean_PP_UPPER_DEPS.tmp $(RM)
	-@$(RM) clean_PP_UPPER_DEPS.tmp
endif
ifneq ($(strip $(P_DEPS)),)
	-$(file > clean_P_DEPS.tmp, $(P_DEPS))
	-@ xargs -s 6000 -t -a clean_P_DEPS.tmp $(RM)
	-@$(RM) clean_P_DEPS.tmp
endif
ifneq ($(strip $(FSY_UPPER_DEPS)),)
	-$(file > clean_FSY_UPPER_DEPS.tmp, $(FSY_UPPER_DEPS))
	-@ xargs -s 6000 -t -a clean_FSY_UPPER_DEPS.tmp $(RM)
	-@$(RM) clean_FSY_UPPER_DEPS.tmp
endif
ifneq ($(strip $(C_DEPS)),)
	-$(file > clean_C_DEPS.tmp, $(C_DEPS))
	-@ xargs -s 6000 -t -a clean_C_DEPS.tmp $(RM)
	-@$(RM) clean_C_DEPS.tmp
endif
ifneq ($(strip $(SRC_DEPS)),)
	-$(file > clean_SRC_DEPS.tmp, $(SRC_DEPS))
	-@ xargs -s 6000 -t -a clean_SRC_DEPS.tmp $(RM)
	-@$(RM) clean_SRC_DEPS.tmp
endif
ifneq ($(strip $(JMP_UPPER_DEPS)),)
	-$(file > clean_JMP_UPPER_DEPS.tmp, $(JMP_UPPER_DEPS))
	-@ xargs -s 6000 -t -a clean_JMP_UPPER_DEPS.tmp $(RM)
	-@$(RM) clean_JMP_UPPER_DEPS.tmp
endif
ifneq ($(strip $(PP_DEPS)),)
	-$(file > clean_PP_DEPS.tmp, $(PP_DEPS))
	-@ xargs -s 6000 -t -a clean_PP_DEPS.tmp $(RM)
	-@$(RM) clean_PP_DEPS.tmp
endif
ifneq ($(strip $(ASM_UPPER_DEPS)),)
	-$(file > clean_ASM_UPPER_DEPS.tmp, $(ASM_UPPER_DEPS))
	-@ xargs -s 6000 -t -a clean_ASM_UPPER_DEPS.tmp $(RM)
	-@$(RM) clean_ASM_UPPER_DEPS.tmp
endif
ifneq ($(strip $(SX_DEPS)),)
	-$(file > clean_SX_DEPS.tmp, $(SX_DEPS))
	-@ xargs -s 6000 -t -a clean_SX_DEPS.tmp $(RM)
	-@$(RM) clean_SX_DEPS.tmp
endif
ifneq ($(strip $(SX_UPPER_DEPS)),)
	-$(file > clean_SX_UPPER_DEPS.tmp, $(SX_UPPER_DEPS))
	-@ xargs -s 6000 -t -a clean_SX_UPPER_DEPS.tmp $(RM)
	-@$(RM) clean_SX_UPPER_DEPS.tmp
endif
ifneq ($(strip $(OBJS)),)
	-$(file > clean_OBJS.tmp, $(OBJS))
	-@ xargs -s 6000 -t -a clean_OBJS.tmp $(RM)
	-@$(RM) clean_OBJS.tmp
endif
ifneq ($(strip $(SECONDARY_FLASH)),)
	-$(file > clean_SECONDARY_FLASH.tmp, $(SECONDARY_FLASH))
	-@ xargs -s 6000 -t -a clean_SECONDARY_FLASH.tmp $(RM)
	-@$(RM) clean_SECONDARY_FLASH.tmp
endif
ifneq ($(strip $(ASM_DEPS)),)
	-$(file > clean_ASM_DEPS.tmp, $(ASM_DEPS))
	-@ xargs -s 6000 -t -a clean_ASM_DEPS.tmp $(RM)
	-@$(RM) clean_ASM_DEPS.tmp
endif
ifneq ($(strip $(LIBRARY_GENERATOR_OUTPUTTYPE_OUTPUTS)),)
	-$(file > clean_LIBRARY_GENERATOR_OUTPUTTYPE_OUTPUTS.tmp, $(LIBRARY_GENERATOR_OUTPUTTYPE_OUTPUTS))
	-@ xargs -s 6000 -t -a clean_LIBRARY_GENERATOR_OUTPUTTYPE_OUTPUTS.tmp $(RM)
	-@$(RM) clean_LIBRARY_GENERATOR_OUTPUTTYPE_OUTPUTS.tmp
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
	-$(file > clean_S_UPPER_DEPS.tmp, $(S_UPPER_DEPS))
	-@ xargs -s 6000 -t -a clean_S_UPPER_DEPS.tmp $(RM)
	-@$(RM) clean_S_UPPER_DEPS.tmp
endif
	-$(RM)  RZ_T_sflash_sample.x
	-@echo ' '

secondary-outputs: $(SECONDARY_FLASH) $(SECONDARY_SIZE)

.PHONY: all clean dependents 

-include ../makefile.targets
