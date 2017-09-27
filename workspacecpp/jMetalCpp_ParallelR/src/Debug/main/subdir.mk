################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../main/DE_main.cpp \
../main/GDE3_main.cpp \
../main/MOEAD_main.cpp \
../main/NSGAII_main.cpp \
../main/NSGAIIbin_main.cpp \
../main/PAES_main.cpp \
../main/PSO_main.cpp \
../main/SMPSO_main.cpp \
../main/gGA_main.cpp \
../main/gGAbin_main.cpp \
../main/main.cpp \
../main/ssGA_main.cpp 

OBJS += \
./main/DE_main.o \
./main/GDE3_main.o \
./main/MOEAD_main.o \
./main/NSGAII_main.o \
./main/NSGAIIbin_main.o \
./main/PAES_main.o \
./main/PSO_main.o \
./main/SMPSO_main.o \
./main/gGA_main.o \
./main/gGAbin_main.o \
./main/main.o \
./main/ssGA_main.o 

CPP_DEPS += \
./main/DE_main.d \
./main/GDE3_main.d \
./main/MOEAD_main.d \
./main/NSGAII_main.d \
./main/NSGAIIbin_main.d \
./main/PAES_main.d \
./main/PSO_main.d \
./main/SMPSO_main.d \
./main/gGA_main.d \
./main/gGAbin_main.d \
./main/main.d \
./main/ssGA_main.d 


# Each subdirectory must supply rules for building sources it contributes
main/%.o: ../main/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


