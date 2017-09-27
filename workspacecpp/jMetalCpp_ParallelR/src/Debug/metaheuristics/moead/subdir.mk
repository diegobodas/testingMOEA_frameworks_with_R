################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../metaheuristics/moead/MOEAD.cpp \
../metaheuristics/moead/UtilsMOEAD.cpp 

OBJS += \
./metaheuristics/moead/MOEAD.o \
./metaheuristics/moead/UtilsMOEAD.o 

CPP_DEPS += \
./metaheuristics/moead/MOEAD.d \
./metaheuristics/moead/UtilsMOEAD.d 


# Each subdirectory must supply rules for building sources it contributes
metaheuristics/moead/%.o: ../metaheuristics/moead/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


