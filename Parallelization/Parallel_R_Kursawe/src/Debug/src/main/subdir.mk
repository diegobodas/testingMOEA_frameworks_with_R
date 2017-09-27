################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/main/DE_main.cpp \
../src/main/GDE3_main.cpp \
../src/main/MOEAD_main.cpp \
../src/main/NSGAII_main.cpp \
../src/main/NSGAIIbin_main.cpp \
../src/main/PAES_main.cpp \
../src/main/PSO_main.cpp \
../src/main/SMPSO_main.cpp \
../src/main/gGA_main.cpp \
../src/main/gGAbin_main.cpp \
../src/main/main.cpp \
../src/main/ssGA_main.cpp 

OBJS += \
./src/main/DE_main.o \
./src/main/GDE3_main.o \
./src/main/MOEAD_main.o \
./src/main/NSGAII_main.o \
./src/main/NSGAIIbin_main.o \
./src/main/PAES_main.o \
./src/main/PSO_main.o \
./src/main/SMPSO_main.o \
./src/main/gGA_main.o \
./src/main/gGAbin_main.o \
./src/main/main.o \
./src/main/ssGA_main.o 

CPP_DEPS += \
./src/main/DE_main.d \
./src/main/GDE3_main.d \
./src/main/MOEAD_main.d \
./src/main/NSGAII_main.d \
./src/main/NSGAIIbin_main.d \
./src/main/PAES_main.d \
./src/main/PSO_main.d \
./src/main/SMPSO_main.d \
./src/main/gGA_main.d \
./src/main/gGAbin_main.d \
./src/main/main.d \
./src/main/ssGA_main.d 


# Each subdirectory must supply rules for building sources it contributes
src/main/%.o: ../src/main/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -I"/home/Diego/workspace/JMetalCpp_RInside/src/core" -I"/home/Diego/workspace/JMetalCpp_RInside/src/util" -I"/home/Diego/workspace/JMetalCpp_RInside/src/util/wrapper" -I"/home/Diego/workspace/JMetalCpp_RInside/src/util/archive" -I"/home/Diego/workspace/JMetalCpp_RInside/src/util/comparators" -I"/home/Diego/workspace/JMetalCpp_RInside/src/util/iniFile" -I"/home/Diego/workspace/JMetalCpp_RInside/src/problems" -I"/home/Diego/workspace/JMetalCpp_RInside/src/operators/crossover" -I"/home/Diego/workspace/JMetalCpp_RInside/src/operators/mutation" -I"/home/Diego/workspace/JMetalCpp_RInside/src/operators/selection" -I"/home/Diego/workspace/JMetalCpp_RInside/src/metaheuristics/de" -I"/home/Diego/workspace/JMetalCpp_RInside/src/metaheuristics/gde3" -I"/home/Diego/workspace/JMetalCpp_RInside/src/metaheuristics/gGA" -I"/home/Diego/workspace/JMetalCpp_RInside/src/metaheuristics/moead" -I"/home/Diego/workspace/JMetalCpp_RInside/src/metaheuristics/paes" -I"/home/Diego/workspace/JMetalCpp_RInside/src/metaheuristics/pso" -I"/home/Diego/workspace/JMetalCpp_RInside/src/metaheuristics/smpso" -I"/home/Diego/workspace/JMetalCpp_RInside/src/metaheuristics/nsgaII" -I"/home/Diego/workspace/JMetalCpp_RInside/src/metaheuristics/ssGA" -I"/home/Diego/workspace/JMetalCpp_RInside/src/qualityIndicator" -I"/home/Diego/workspace/JMetalCpp_RInside/src/qualityIndicator/main" -I"/home/Diego/workspace/JMetalCpp_RInside/src/qualityIndicator/util" -I"/home/Diego/workspace/JMetalCpp_RInside/src/experiments" -I"/home/Diego/workspace/JMetalCpp_RInside/src/experiments/settings" -I"/home/Diego/workspace/JMetalCpp_RInside/src/experiments/util" -I"/home/Diego/workspace/JMetalCpp_RInside/src/encodings/solutionType" -I"/home/Diego/workspace/JMetalCpp_RInside/src/encodings/variable" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


