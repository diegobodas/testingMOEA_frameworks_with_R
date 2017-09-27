################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir.mk
-include src/util/wrapper/subdir.mk
-include src/util/iniFile/subdir.mk
-include src/util/comparators/subdir.mk
-include src/util/archive/subdir.mk
-include src/util/subdir.mk
-include src/r_problems/subdir.mk
-include src/problems/subdir.mk
-include src/operators/selection/subdir.mk
-include src/operators/mutation/subdir.mk
-include src/operators/crossover/subdir.mk
-include src/metaheuristics/ssGA/subdir.mk
-include src/metaheuristics/smpso/subdir.mk
-include src/metaheuristics/pso/subdir.mk
-include src/metaheuristics/paes/subdir.mk
-include src/metaheuristics/nsgaII/subdir.mk
-include src/metaheuristics/moead/subdir.mk
-include src/metaheuristics/gde3/subdir.mk
-include src/metaheuristics/gGA/subdir.mk
-include src/metaheuristics/de/subdir.mk
-include src/main_files/subdir.mk
-include src/subdir.mk
-include src/encodings/variable/subdir.mk
-include src/encodings/solutionType/subdir.mk
-include src/core/subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: libjMetalCpp_FromR_Final.so

# Tool invocations
libjMetalCpp_FromR_Final.so: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: GCC C++ Linker'
	g++ -L/usr/lib64/R/lib/ -L"/home/cloudera/workspacecpp/jMetalCpp_FromR_Final/include/RInside/lib" -L"/home/cloudera/workspacecpp/jMetalCpp_FromR_Final/include/RInside/libs" -shared -o"libjMetalCpp_FromR_Final.so" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(OBJS)$(C++_DEPS)$(C_DEPS)$(CC_DEPS)$(LIBRARIES)$(CPP_DEPS)$(CXX_DEPS)$(C_UPPER_DEPS) libjMetalCpp_FromR_Final.so
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
