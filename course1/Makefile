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

ifndef PLATFORM
$(info PLATFORM not set. Default PLATFORM = MSP432 will be used)
PLATFORM=MSP432
endif

include sources.mk

# check on platform

ifeq ($(PLATFORM),HOST)

# defines for HOST

# Compiler Defines
CC = 		  gcc				#Compiler
LD =		  ld				#Linker
SIZE =	  size 			#size
OBJDUMP = objdump 	#objdump

# Compiler Flags
LDFLAGS 	= -Wl,-Map=$(TARGET).map -lm
ARM_FLAGS =

#excluding MSP432 source files
SOURCES := $(filter-out src/interrupts_msp432p401r_gcc.c	, $(SOURCES))
SOURCES := $(filter-out src/startup_msp432p401r_gcc.c	, $(SOURCES))
SOURCES := $(filter-out src/system_msp432p401r.c		, $(SOURCES))

else

# defines for MSP432

# Architectures Specific Flags
LINKER_FILE = 	msp432p401r.lds
CPU   = cortex-m4
ARCH1 = thumb
ARCH2 = armv7e-m
SPECS = nosys.specs
FLOAT = hard
FPU = fpv4-sp-d16

# Compiler Defines
CC = 			arm-none-eabi-gcc			#Compiler
LD =			arm-none-eabi-ld			#Linker
SIZE = 		arm-none-eabi-size 		#size
OBJDUMP = arm-none-eabi-objdump	#objdump

# Compiler Flags
LDFLAGS 	= -Wl,-Map=$(TARGET).map -T $(LINKER_FILE) -lm
ARM_FLAGS = -mcpu=$(CPU) -m$(ARCH1) -march=$(ARCH2) -mfloat-abi=$(FLOAT) -mfpu=$(FPU) --specs=$(SPECS)

endif

# defines for Common

# target file name
TARGET = c1

# Common Compiler Flags
CFLAGS = -g -O0 -std=c99 -Wall -Werror -DCOURSE1 -DVERBOSE -D$(PLATFORM) $(INCLUDES) $(ARM_FLAGS)

# output file types
PPCS = $(SOURCES:.c=.i)
ASMS = $(SOURCES:.c=.asm)
OBJS = $(SOURCES:.c=.o)
DEPS = $(SOURCES:.c=.d)


#-------------------------------#
#--------- build target --------#
#-------------------------------#

# generate preprocessed files
%.i : %.c
	$(CC) -E $< $(CFLAGS) -o $@

# generate assembly files
# individual source files
%.asm : %.c
	$(CC) -S $< $(CFLAGS) -o $@
# target output file
$(TARGET).asm : $(TARGET).out
	$(OBJDUMP) --syms $(TARGET).out >> $@

# generate object files
%.o : %.c
	$(CC) -c $< $(CFLAGS) -o $@

# generate dependent files
%.d : %.c
	$(CC) -M $< $(CFLAGS) -o $@

# generate object files for all files but doesn't link
.PHONY: compile-all
compile-all: $(OBJS)

# generate object files for all files ,link ,generate output file and info
$(TARGET).out: $(OBJS)
	$(CC) $(OBJS) $(CFLAGS) $(LDFLAGS) -o $@
	$(SIZE) --format=Berkeley $(TARGET).out

# phonies
.PHONY: all
all: $(TARGET).out $(TARGET).asm

.PHONY: build
build: all

.PHONY: clean
clean:
	rm -f $(PPCS) $(ASMS) $(OBJS) $(DEPS) $(TARGET).*
