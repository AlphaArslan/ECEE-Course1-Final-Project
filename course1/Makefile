#******************************************************************************
# Copyright (C) 2017 by Alex Fosdick - University of Colorado
#
# Redistribution, modification or use of this software in source or binary
# forms is permitted as long as the files maintain this copyright. Users are
# permitted to modify this and use it to learn about the field of embedded
# software. Alex Fosdick and the University of Colorado are not liable for any
# misuse of this material.
#
#*****************************************************************************

#------------------------------------------------------------------------------
# A build system to generate :
#		%.i   : preprocessed output of all c-program implementation files
#		%.asm : assembly output of c-program implementation files and the final output executable
#		%.o   : object file for all c-source files
# For to PLATFORMs :
#		HOST  : native compilation for linux
#		MSP432: cross compilation for ARM architecture target
#
# Use: make [TARGET] [PLATFORM-OVERRIDES]
#
# Build Targets:
#	<FILE>.i   - Builds <FILE>.o preprocessed file
#	<FILE>.asm - Builds <FILE>.o assembly file
#	<FILE>.o   - Builds <FILE>.o object file
#      	compile-all- Compile all object files, but DO NOT link
#	Build	   - Compile all object files and link into a final executable
#	Clean	   - Remove all generated files
#
# Platform Overrides:
#	PLATFORM   - the platform for which we build (HOST / MSP432 )
#
#------------------------------------------------------------------------------
include sources.mk

# Platform Overrides
PLATFORM = MSP432

ifeq ($(PLATFORM),HOST)
	# for HOST
	# Compiler Flags and Defines
	CC = 		gcc
	CFLAGS = 	-g -O0 -std=c99 -Wall -Werror -DHOST $(INCLUDES) -DCOURSE1 -DVERBOSE
	#excluding MSP$#@ source files
	SOURCES := $(filter-out src/interrupts_msp432p401r_gcc.c	, $(SOURCES))
	SOURCES := $(filter-out src/startup_msp432p401r_gcc.c	, $(SOURCES))
	SOURCES := $(filter-out src/system_msp432p401r.c		, $(SOURCES))
else
	# for MSP432
	# Architectures Specific Flags
	LINKER_FILE = 	../msp432p401r.lds
	CPU = 		cortex-m4
	ARCH = 		thumb
	SPECS = 	nosys.specs
	# Compiler Flags and Defines
	CC = 		arm-none-eabi-gcc
	LD =		arm-none-eabi-ld
	LDFLAGS = 	-Wl,-Map=$(TARGET).map -T $(LINKER_FILE)
	CFLAGS = 	-mcpu=$(CPU) -m$(ARCH) -march=armv7e-m -mfloat-abi=hard -mfpu=fpv4-sp-d16 --specs=$(SPECS) -g -O0 -std=c99 -Wall -Werror -DMSP432 $(INCLUDES) -DCOURSE1
endif


CPPS = $(SOURCES:.c=.i)
ASMS = $(SOURCES:.c=.asm)
OBJS = $(SOURCES:.c=.o)
TARGET = c1

# build targets
%.i : %.c
	$(CC) -E $< $(CFLAGS) -o $@


%.asm : %.c
	$(CC) -S $< $(CFLAGS) -o $@


%.o : %.c
	$(CC) -c $< $(CFLAGS) -o $@


.PHONY: compile-all
compile-all: $(OBJS)


.PHONY: build
build: all
.PHONY: all
all: $(TARGET).out
$(TARGET).out: $(OBJS)
	$(CC) $(OBJS) $(CFLAGS) $(LDFLAGS) -o $@

.PHONY: clean
clean:
	rm -f $(CPPS) $(ASMS) $(OBJS) $(TARGET).out $(TARGET).map
