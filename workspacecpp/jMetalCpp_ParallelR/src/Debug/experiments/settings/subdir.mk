################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../experiments/settings/DE_Settings.cpp \
../experiments/settings/GDE3_Settings.cpp \
../experiments/settings/NSGAII_Settings.cpp \
../experiments/settings/PSO_Settings.cpp \
../experiments/settings/SMPSO_Settings.cpp \
../experiments/settings/gGA_Settings.cpp \
../experiments/settings/ssGA_Settings.cpp 

OBJS += \
./experiments/settings/DE_Settings.o \
./experiments/settings/GDE3_Settings.o \
./experiments/settings/NSGAII_Settings.o \
./experiments/settings/PSO_Settings.o \
./experiments/settings/SMPSO_Settings.o \
./experiments/settings/gGA_Settings.o \
./experiments/settings/ssGA_Settings.o 

CPP_DEPS += \
./experiments/settings/DE_Settings.d \
./experiments/settings/GDE3_Settings.d \
./experiments/settings/NSGAII_Settings.d \
./experiments/settings/PSO_Settings.d \
./experiments/settings/SMPSO_Settings.d \
./experiments/settings/gGA_Settings.d \
./experiments/settings/ssGA_Settings.d 


# Each subdirectory must supply rules for building sources it contributes
experiments/settings/%.o: ../experiments/settings/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


