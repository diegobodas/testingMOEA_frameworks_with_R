################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../operators/mutation/BitFlipMutation.cpp \
../operators/mutation/Mutation.cpp \
../operators/mutation/PolynomialMutation.cpp 

OBJS += \
./operators/mutation/BitFlipMutation.o \
./operators/mutation/Mutation.o \
./operators/mutation/PolynomialMutation.o 

CPP_DEPS += \
./operators/mutation/BitFlipMutation.d \
./operators/mutation/Mutation.d \
./operators/mutation/PolynomialMutation.d 


# Each subdirectory must supply rules for building sources it contributes
operators/mutation/%.o: ../operators/mutation/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


