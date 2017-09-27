################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../qualityIndicator/Epsilon.cpp \
../qualityIndicator/Fitness.cpp \
../qualityIndicator/GenerationalDistance.cpp \
../qualityIndicator/Hypervolume.cpp \
../qualityIndicator/InvertedGenerationalDistance.cpp \
../qualityIndicator/QualityIndicator.cpp \
../qualityIndicator/Spread.cpp 

OBJS += \
./qualityIndicator/Epsilon.o \
./qualityIndicator/Fitness.o \
./qualityIndicator/GenerationalDistance.o \
./qualityIndicator/Hypervolume.o \
./qualityIndicator/InvertedGenerationalDistance.o \
./qualityIndicator/QualityIndicator.o \
./qualityIndicator/Spread.o 

CPP_DEPS += \
./qualityIndicator/Epsilon.d \
./qualityIndicator/Fitness.d \
./qualityIndicator/GenerationalDistance.d \
./qualityIndicator/Hypervolume.d \
./qualityIndicator/InvertedGenerationalDistance.d \
./qualityIndicator/QualityIndicator.d \
./qualityIndicator/Spread.d 


# Each subdirectory must supply rules for building sources it contributes
qualityIndicator/%.o: ../qualityIndicator/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


