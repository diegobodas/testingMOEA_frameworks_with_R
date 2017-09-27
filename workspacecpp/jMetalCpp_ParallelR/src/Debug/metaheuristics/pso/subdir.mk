################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../metaheuristics/pso/PSO.cpp 

OBJS += \
./metaheuristics/pso/PSO.o 

CPP_DEPS += \
./metaheuristics/pso/PSO.d 


# Each subdirectory must supply rules for building sources it contributes
metaheuristics/pso/%.o: ../metaheuristics/pso/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


