################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../qualityIndicator/util/LexicoGraphicalComparator.cpp \
../qualityIndicator/util/MetricsUtil.cpp 

OBJS += \
./qualityIndicator/util/LexicoGraphicalComparator.o \
./qualityIndicator/util/MetricsUtil.o 

CPP_DEPS += \
./qualityIndicator/util/LexicoGraphicalComparator.d \
./qualityIndicator/util/MetricsUtil.d 


# Each subdirectory must supply rules for building sources it contributes
qualityIndicator/util/%.o: ../qualityIndicator/util/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


