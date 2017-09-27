################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../metaheuristics/gGA/gGA.cpp 

OBJS += \
./metaheuristics/gGA/gGA.o 

CPP_DEPS += \
./metaheuristics/gGA/gGA.d 


# Each subdirectory must supply rules for building sources it contributes
metaheuristics/gGA/%.o: ../metaheuristics/gGA/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


