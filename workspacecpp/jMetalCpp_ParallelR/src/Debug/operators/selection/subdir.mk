################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../operators/selection/BestSolutionSelection.cpp \
../operators/selection/BinaryTournament.cpp \
../operators/selection/BinaryTournament2.cpp \
../operators/selection/DifferentialEvolutionSelection.cpp \
../operators/selection/Selection.cpp \
../operators/selection/WorstSolutionSelection.cpp 

OBJS += \
./operators/selection/BestSolutionSelection.o \
./operators/selection/BinaryTournament.o \
./operators/selection/BinaryTournament2.o \
./operators/selection/DifferentialEvolutionSelection.o \
./operators/selection/Selection.o \
./operators/selection/WorstSolutionSelection.o 

CPP_DEPS += \
./operators/selection/BestSolutionSelection.d \
./operators/selection/BinaryTournament.d \
./operators/selection/BinaryTournament2.d \
./operators/selection/DifferentialEvolutionSelection.d \
./operators/selection/Selection.d \
./operators/selection/WorstSolutionSelection.d 


# Each subdirectory must supply rules for building sources it contributes
operators/selection/%.o: ../operators/selection/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


