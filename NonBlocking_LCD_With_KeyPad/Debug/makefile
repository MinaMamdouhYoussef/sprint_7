################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include MCAL/TIMERS/subdir.mk
-include MCAL/DIO/subdir.mk
-include ECUAL/LED/subdir.mk
-include ECUAL/LCD/subdir.mk
-include ECUAL/KEYPAD_non_blocking/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
NonBlocking_LCD_With_KeyPad.lss \

FLASH_IMAGE += \
NonBlocking_LCD_With_KeyPad.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: NonBlocking_LCD_With_KeyPad.elf secondary-outputs

# Tool invocations
NonBlocking_LCD_With_KeyPad.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,NonBlocking_LCD_With_KeyPad.map -mmcu=atmega32 -o "NonBlocking_LCD_With_KeyPad.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

NonBlocking_LCD_With_KeyPad.lss: NonBlocking_LCD_With_KeyPad.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S NonBlocking_LCD_With_KeyPad.elf  >"NonBlocking_LCD_With_KeyPad.lss"
	@echo 'Finished building: $@'
	@echo ' '

NonBlocking_LCD_With_KeyPad.hex: NonBlocking_LCD_With_KeyPad.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex NonBlocking_LCD_With_KeyPad.elf  "NonBlocking_LCD_With_KeyPad.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: NonBlocking_LCD_With_KeyPad.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 NonBlocking_LCD_With_KeyPad.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) NonBlocking_LCD_With_KeyPad.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
