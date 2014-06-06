################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../inc/CellSizeForm.cpp \
../inc/ColorForm.cpp \
../inc/RulesForm.cpp \
../inc/SpeedForm.cpp 

OBJS += \
./inc/CellSizeForm.o \
./inc/ColorForm.o \
./inc/RulesForm.o \
./inc/SpeedForm.o 

CPP_DEPS += \
./inc/CellSizeForm.d \
./inc/ColorForm.d \
./inc/RulesForm.d \
./inc/SpeedForm.d 


# Each subdirectory must supply rules for building sources it contributes
inc/%.o: ../inc/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: bada C++ Compiler'
	arm-samsung-nucleuseabi-g++ -D_DEBUG -DSHP -I"D:/bada/2.0.3/include" -I"D:/bada/2.0.3/IDE/workspace/Life/inc" -O0 -g -Wall -c -fpic -fshort-wchar -march=armv5te -mlittle-endian -mthumb -mthumb-interwork -mfloat-abi=soft -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	arm-samsung-nucleuseabi-g++ -D_DEBUG -DSHP -I"D:/bada/2.0.3/include" -I"D:/bada/2.0.3/IDE/workspace/Life/inc" -O0 -g -Wall -E -fpic -fshort-wchar -march=armv5te -mlittle-endian -mthumb -mthumb-interwork -mfloat-abi=soft -o"D:/bada/2.0.3/IDE/workspace/repository/Life/Target-Debug/$(notdir $(basename $@).i)" "$<"
	@echo 'Finished building: $<'
	@echo ' '


