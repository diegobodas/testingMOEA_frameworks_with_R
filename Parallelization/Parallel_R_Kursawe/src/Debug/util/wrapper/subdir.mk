################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../util/wrapper/XReal.cpp 

OBJS += \
./util/wrapper/XReal.o 

CPP_DEPS += \
./util/wrapper/XReal.d 


# Each subdirectory must supply rules for building sources it contributes
util/wrapper/%.o: ../util/wrapper/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


