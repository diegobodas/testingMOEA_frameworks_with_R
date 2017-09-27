################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../problems/AutoDock.cpp \
../problems/DTLZ1.cpp \
../problems/DTLZ2.cpp \
../problems/DTLZ3.cpp \
../problems/DTLZ4.cpp \
../problems/DTLZ5.cpp \
../problems/DTLZ6.cpp \
../problems/DTLZ7.cpp \
../problems/Fonseca.cpp \
../problems/Griewank.cpp \
../problems/Kursawe.cpp \
../problems/LZ09.cpp \
../problems/LZ09_F1.cpp \
../problems/LZ09_F2.cpp \
../problems/LZ09_F3.cpp \
../problems/LZ09_F4.cpp \
../problems/LZ09_F5.cpp \
../problems/LZ09_F6.cpp \
../problems/LZ09_F7.cpp \
../problems/LZ09_F8.cpp \
../problems/LZ09_F9.cpp \
../problems/OneMax.cpp \
../problems/ProblemFactory.cpp \
../problems/Schaffer.cpp \
../problems/Sphere.cpp \
../problems/ZDT1.cpp \
../problems/ZDT2.cpp \
../problems/ZDT3.cpp \
../problems/ZDT4.cpp \
../problems/ZDT5.cpp \
../problems/ZDT6.cpp 

OBJS += \
./problems/AutoDock.o \
./problems/DTLZ1.o \
./problems/DTLZ2.o \
./problems/DTLZ3.o \
./problems/DTLZ4.o \
./problems/DTLZ5.o \
./problems/DTLZ6.o \
./problems/DTLZ7.o \
./problems/Fonseca.o \
./problems/Griewank.o \
./problems/Kursawe.o \
./problems/LZ09.o \
./problems/LZ09_F1.o \
./problems/LZ09_F2.o \
./problems/LZ09_F3.o \
./problems/LZ09_F4.o \
./problems/LZ09_F5.o \
./problems/LZ09_F6.o \
./problems/LZ09_F7.o \
./problems/LZ09_F8.o \
./problems/LZ09_F9.o \
./problems/OneMax.o \
./problems/ProblemFactory.o \
./problems/Schaffer.o \
./problems/Sphere.o \
./problems/ZDT1.o \
./problems/ZDT2.o \
./problems/ZDT3.o \
./problems/ZDT4.o \
./problems/ZDT5.o \
./problems/ZDT6.o 

CPP_DEPS += \
./problems/AutoDock.d \
./problems/DTLZ1.d \
./problems/DTLZ2.d \
./problems/DTLZ3.d \
./problems/DTLZ4.d \
./problems/DTLZ5.d \
./problems/DTLZ6.d \
./problems/DTLZ7.d \
./problems/Fonseca.d \
./problems/Griewank.d \
./problems/Kursawe.d \
./problems/LZ09.d \
./problems/LZ09_F1.d \
./problems/LZ09_F2.d \
./problems/LZ09_F3.d \
./problems/LZ09_F4.d \
./problems/LZ09_F5.d \
./problems/LZ09_F6.d \
./problems/LZ09_F7.d \
./problems/LZ09_F8.d \
./problems/LZ09_F9.d \
./problems/OneMax.d \
./problems/ProblemFactory.d \
./problems/Schaffer.d \
./problems/Sphere.d \
./problems/ZDT1.d \
./problems/ZDT2.d \
./problems/ZDT3.d \
./problems/ZDT4.d \
./problems/ZDT5.d \
./problems/ZDT6.d 


# Each subdirectory must supply rules for building sources it contributes
problems/%.o: ../problems/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


