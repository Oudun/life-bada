################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/AboutForm.cpp \
../src/AbstractForm.cpp \
../src/AbstractSettingsForm.cpp \
../src/ColorModel.cpp \
../src/Constants.cpp \
../src/Evolution.cpp \
../src/Generation.cpp \
../src/Life.cpp \
../src/LifeEntry.cpp \
../src/LifeForm.cpp \
../src/RulesForm.cpp \
../src/SettingsForm.cpp \
../src/SpeedForm.cpp \
../src/SurfaceForm.cpp 

OBJS += \
./src/AboutForm.o \
./src/AbstractForm.o \
./src/AbstractSettingsForm.o \
./src/ColorModel.o \
./src/Constants.o \
./src/Evolution.o \
./src/Generation.o \
./src/Life.o \
./src/LifeEntry.o \
./src/LifeForm.o \
./src/RulesForm.o \
./src/SettingsForm.o \
./src/SpeedForm.o \
./src/SurfaceForm.o 

CPP_DEPS += \
./src/AboutForm.d \
./src/AbstractForm.d \
./src/AbstractSettingsForm.d \
./src/ColorModel.d \
./src/Constants.d \
./src/Evolution.d \
./src/Generation.d \
./src/Life.d \
./src/LifeEntry.d \
./src/LifeForm.d \
./src/RulesForm.d \
./src/SettingsForm.d \
./src/SpeedForm.d \
./src/SurfaceForm.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: bada C++ Compiler'
	arm-samsung-nucleuseabi-g++ -D_DEBUG -DSHP -I"D:/bada/2.0.3/include" -I"D:/bada/2.0.3/IDE/workspace/Life/inc" -O0 -g -Wall -c -fpic -fshort-wchar -march=armv5te -mlittle-endian -mthumb -mthumb-interwork -mfloat-abi=soft -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	arm-samsung-nucleuseabi-g++ -D_DEBUG -DSHP -I"D:/bada/2.0.3/include" -I"D:/bada/2.0.3/IDE/workspace/Life/inc" -O0 -g -Wall -E -fpic -fshort-wchar -march=armv5te -mlittle-endian -mthumb -mthumb-interwork -mfloat-abi=soft -o"D:/bada/2.0.3/IDE/workspace/repository/Life/Target-Debug/$(notdir $(basename $@).i)" "$<"
	@echo 'Finished building: $<'
	@echo ' '


