################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/forms/NewCellSizeForm.cpp \
../src/forms/NewColorForm.cpp \
../src/forms/NewSpeedForm.cpp \
../src/forms/NewSurfaceForm.cpp 

OBJS += \
./src/forms/NewCellSizeForm.o \
./src/forms/NewColorForm.o \
./src/forms/NewSpeedForm.o \
./src/forms/NewSurfaceForm.o 

CPP_DEPS += \
./src/forms/NewCellSizeForm.d \
./src/forms/NewColorForm.d \
./src/forms/NewSpeedForm.d \
./src/forms/NewSurfaceForm.d 


# Each subdirectory must supply rules for building sources it contributes
src/forms/%.o: ../src/forms/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: bada C++ Compiler'
	arm-samsung-nucleuseabi-g++ -D_DEBUG -DSHP -I"D:/bada/2.0.3/include" -I"D:/bada/2.0.3/IDE/workspace/Life/inc" -O0 -g -Wall -c -fpic -fshort-wchar -march=armv5te -mlittle-endian -mthumb -mthumb-interwork -mfloat-abi=soft -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	arm-samsung-nucleuseabi-g++ -D_DEBUG -DSHP -I"D:/bada/2.0.3/include" -I"D:/bada/2.0.3/IDE/workspace/Life/inc" -O0 -g -Wall -E -fpic -fshort-wchar -march=armv5te -mlittle-endian -mthumb -mthumb-interwork -mfloat-abi=soft -o"D:/bada/2.0.3/IDE/workspace/repository/Life/Target-Debug/$(notdir $(basename $@).i)" "$<"
	@echo 'Finished building: $<'
	@echo ' '


