################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../metaheuristics/smpso/SMPSO.cpp 

OBJS += \
./metaheuristics/smpso/SMPSO.o 

CPP_DEPS += \
./metaheuristics/smpso/SMPSO.d 


# Each subdirectory must supply rules for building sources it contributes
metaheuristics/smpso/%.o: ../metaheuristics/smpso/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


