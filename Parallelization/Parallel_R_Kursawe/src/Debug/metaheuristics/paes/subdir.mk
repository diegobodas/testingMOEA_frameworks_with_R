################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../metaheuristics/paes/paes.cpp 

OBJS += \
./metaheuristics/paes/paes.o 

CPP_DEPS += \
./metaheuristics/paes/paes.d 


# Each subdirectory must supply rules for building sources it contributes
metaheuristics/paes/%.o: ../metaheuristics/paes/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


