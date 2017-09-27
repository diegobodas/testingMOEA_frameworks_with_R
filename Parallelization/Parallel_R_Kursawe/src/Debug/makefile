################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include util/wrapper/subdir.mk
-include util/iniFile/subdir.mk
-include util/comparators/subdir.mk
-include util/archive/subdir.mk
-include util/subdir.mk
-include qualityIndicator/util/subdir.mk
-include qualityIndicator/main/subdir.mk
-include qualityIndicator/subdir.mk
-include problems/subdir.mk
-include operators/selection/subdir.mk
-include operators/mutation/subdir.mk
-include operators/crossover/subdir.mk
-include metaheuristics/ssGA/subdir.mk
-include metaheuristics/smpso/subdir.mk
-include metaheuristics/pso/subdir.mk
-include metaheuristics/paes/subdir.mk
-include metaheuristics/nsgaII/subdir.mk
-include metaheuristics/moead/subdir.mk
-include metaheuristics/gde3/subdir.mk
-include metaheuristics/gGA/subdir.mk
-include metaheuristics/de/subdir.mk
-include main/subdir.mk
-include experiments/util/subdir.mk
-include experiments/settings/subdir.mk
-include experiments/subdir.mk
-include encodings/variable/subdir.mk
-include encodings/solutionType/subdir.mk
-include core/subdir.mk
-include subdir.mk
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
all: JMetalCpp_RInside

# Tool invocations
JMetalCpp_RInside: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: Cross G++ Linker'
	g++  -o "JMetalCpp_RInside" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(C++_DEPS)$(OBJS)$(C_DEPS)$(CC_DEPS)$(CPP_DEPS)$(EXECUTABLES)$(CXX_DEPS)$(C_UPPER_DEPS) JMetalCpp_RInside
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
