################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../metaheuristics/nsgaII/NSGAII.cpp 

OBJS += \
./metaheuristics/nsgaII/NSGAII.o 

CPP_DEPS += \
./metaheuristics/nsgaII/NSGAII.d 


# Each subdirectory must supply rules for building sources it contributes
metaheuristics/nsgaII/%.o: ../metaheuristics/nsgaII/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


