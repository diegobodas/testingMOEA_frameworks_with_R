################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../util/archive/AdaptiveGridArchive.cpp \
../util/archive/Archive.cpp \
../util/archive/CrowdingArchive.cpp 

OBJS += \
./util/archive/AdaptiveGridArchive.o \
./util/archive/Archive.o \
./util/archive/CrowdingArchive.o 

CPP_DEPS += \
./util/archive/AdaptiveGridArchive.d \
./util/archive/Archive.d \
./util/archive/CrowdingArchive.d 


# Each subdirectory must supply rules for building sources it contributes
util/archive/%.o: ../util/archive/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


