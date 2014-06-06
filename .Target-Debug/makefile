################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

REPOSITORY_ROOT := D:/bada/2.0.3/IDE/workspace/repository/Life/Target-Debug

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir.mk
-include src/forms/subdir.mk
-include src/subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: Life.exe

# Tool invocations
Life.exe: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: bada C++ Linker'
	@echo 'ldflags: -nostartfiles -Wl,-u__gnu_thumb1_case_si,-u__gnu_thumb1_case_sqi,-u__gnu_thumb1_case_uqi,-u__gnu_thumb1_case_shi,-u__gnu_thumb1_case_uhi -lgcc_sa -L"D:/bada/2.0.3/Model/WaveWQVGA/Target" -L"D:/bada/2.0.3/IDE/workspace/Life/lib" -shared -o"Life.exe" ./src/forms/NewCellSizeForm.o ./src/forms/NewColorForm.o ./src/forms/NewSpeedForm.o ./src/forms/NewSurfaceForm.o ./src/AboutForm.o ./src/AbstractForm.o ./src/AbstractSettingsForm.o ./src/ColorModel.o ./src/Constants.o ./src/DemoForm.o ./src/Evolution.o ./src/Generation.o ./src/Life.o ./src/LifeEntry.o ./src/LifeForm.o ./src/RulesForm.o ./src/SettingsForm.o ./src/SpeedForm.o ./src/SurfaceForm.o '
	arm-samsung-nucleuseabi-g++ @ldflags @ldobjs  $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(OBJS)$(C++_DEPS)$(C_DEPS)$(CC_DEPS)$(CPP_DEPS)$(CXX_DEPS)$(C_UPPER_DEPS) Life.exe $(REPOSITORY_ROOT)/temp/*  $(REPOSITORY_ROOT)/*
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
