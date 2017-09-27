################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../encodings/solutionType/ArrayRealSolutionType.cpp \
../encodings/solutionType/BinaryRealSolutionType.cpp \
../encodings/solutionType/BinarySolutionType.cpp \
../encodings/solutionType/RealSolutionType.cpp 

OBJS += \
./encodings/solutionType/ArrayRealSolutionType.o \
./encodings/solutionType/BinaryRealSolutionType.o \
./encodings/solutionType/BinarySolutionType.o \
./encodings/solutionType/RealSolutionType.o 

CPP_DEPS += \
./encodings/solutionType/ArrayRealSolutionType.d \
./encodings/solutionType/BinaryRealSolutionType.d \
./encodings/solutionType/BinarySolutionType.d \
./encodings/solutionType/RealSolutionType.d 


# Each subdirectory must supply rules for building sources it contributes
encodings/solutionType/%.o: ../encodings/solutionType/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


