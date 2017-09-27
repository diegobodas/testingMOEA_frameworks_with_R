################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../util/iniFile/iniFile.cpp 

OBJS += \
./util/iniFile/iniFile.o 

CPP_DEPS += \
./util/iniFile/iniFile.d 


# Each subdirectory must supply rules for building sources it contributes
util/iniFile/%.o: ../util/iniFile/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


