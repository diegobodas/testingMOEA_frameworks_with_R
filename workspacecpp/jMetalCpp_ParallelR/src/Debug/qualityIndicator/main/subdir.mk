################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../qualityIndicator/main/Epsilon_main.cpp \
../qualityIndicator/main/GenerationalDistance_main.cpp \
../qualityIndicator/main/Hypervolume_main.cpp \
../qualityIndicator/main/InvertedGenerationalDistance_main.cpp \
../qualityIndicator/main/Spread_main.cpp 

OBJS += \
./qualityIndicator/main/Epsilon_main.o \
./qualityIndicator/main/GenerationalDistance_main.o \
./qualityIndicator/main/Hypervolume_main.o \
./qualityIndicator/main/InvertedGenerationalDistance_main.o \
./qualityIndicator/main/Spread_main.o 

CPP_DEPS += \
./qualityIndicator/main/Epsilon_main.d \
./qualityIndicator/main/GenerationalDistance_main.d \
./qualityIndicator/main/Hypervolume_main.d \
./qualityIndicator/main/InvertedGenerationalDistance_main.d \
./qualityIndicator/main/Spread_main.d 


# Each subdirectory must supply rules for building sources it contributes
qualityIndicator/main/%.o: ../qualityIndicator/main/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


