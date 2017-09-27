################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../encodings/variable/ArrayReal.cpp \
../encodings/variable/Binary.cpp \
../encodings/variable/BinaryReal.cpp \
../encodings/variable/Real.cpp 

OBJS += \
./encodings/variable/ArrayReal.o \
./encodings/variable/Binary.o \
./encodings/variable/BinaryReal.o \
./encodings/variable/Real.o 

CPP_DEPS += \
./encodings/variable/ArrayReal.d \
./encodings/variable/Binary.d \
./encodings/variable/BinaryReal.d \
./encodings/variable/Real.d 


# Each subdirectory must supply rules for building sources it contributes
encodings/variable/%.o: ../encodings/variable/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


