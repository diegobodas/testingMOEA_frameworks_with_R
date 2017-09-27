################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../core/Algorithm.cpp \
../core/Operator.cpp \
../core/Problem.cpp \
../core/Solution.cpp \
../core/SolutionSet.cpp \
../core/SolutionType.cpp \
../core/Variable.cpp 

OBJS += \
./core/Algorithm.o \
./core/Operator.o \
./core/Problem.o \
./core/Solution.o \
./core/SolutionSet.o \
./core/SolutionType.o \
./core/Variable.o 

CPP_DEPS += \
./core/Algorithm.d \
./core/Operator.d \
./core/Problem.d \
./core/Solution.d \
./core/SolutionSet.d \
./core/SolutionType.d \
./core/Variable.d 


# Each subdirectory must supply rules for building sources it contributes
core/%.o: ../core/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


