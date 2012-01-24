#XCODE 4

AVRDUDE_DIR = $(ARDUINO_APP_PATH)/Contents/Resources/Java/hardware/tools/avr/bin
AVRDUDE_CONF= $(ARDUINO_APP_PATH)/Contents/Resources/Java/hardware/tools/avr/etc/avrdude.conf
SIZE = $(AVRDUDE_DIR)/avr-size
SOURCES = $(wildcard src/*.cpp)

# add arduino app path to the paths..
ARD_LIBRARIES = $(ARDUINO_LIBRARIES)
ARD_LIBRARIES_PATH = $(ARDUINO_APP_PATH)$(ARDUINO_LIBRARIES_PATH)
ARD_PATH = $(ARDUINO_APP_PATH)$(ARDUINO_PATH)

# make the correct paths for the libraries
INCLUDE_LIBRARIES = $(addprefix -I$(ARD_LIBRARIES_PATH)/,$(ARD_LIBRARIES)) \
$(addprefix -I, $(wildcard $(LIBRARY_PATHS)))

# find .cpp files in libraries
CPP_LIBRARIES = $(foreach lib,$(ARD_LIBRARIES),$(wildcard $(ARD_LIBRARIES_PATH)$(lib)/*.cpp))
CPP_LIBRARIES += $(foreach item, $(LIBRARY_PATHS), $(wildcard $(item)/*.cpp))


BOARDS_TXT = $(ARDUINO_APP_PATH)$(BOARDS_TXT_PATH)

# result = $(call READ_BOARD_TXT, 'boardname.parameter', 'pathfileboards.txt')
nullstring  :=
spacestring := $(nullstring) # end of the line
equalstring := $(nullstring)=# end of the line
#READ_BOARD_TXT = $(lastword $(subst $(equalstring),$(spacestring),$(shell grep -e$(1) $(2)))) 
READ_BOARD_TXT = $(subst $(1)=,, $(shell grep -e$(1) $(2)))

parameter = build.f_cpu
F_CPU = $(call READ_BOARD_TXT, $(BOARDNAME).build.f_cpu, $(BOARDS_TXT))
DESCRIPTION = $(call READ_BOARD_TXT, $(BOARDNAME).name, $(BOARDS_TXT))
MCU = $(call READ_BOARD_TXT, $(BOARDNAME).build.mcu, $(BOARDS_TXT))
UPLOAD_RATE = $(call READ_BOARD_TXT, $(BOARDNAME).upload.speed, $(BOARDS_TXT))
FORMAT = ihex




# main file
TARGET = main

# find .c files in arduino directory
SRC = $(wildcard $(ARD_PATH)/*.c)

# .cpp files from libraries and arduino directory
CXXSRC = $(SOURCES) $(wildcard $(ARD_PATH)/*.cpp) $(CPP_LIBRARIES) 


# Name of this Makefile (used for "make depend").
MAKEFILE = Makefile

# Debugging format.
# Native formats for AVR-GCC's -g are stabs [default], or dwarf-2.
# AVR (extended) COFF requires stabs, plus an avr-objcopy run.
DEBUG = stabs

OPT = s

# Place -D or -U options here
CDEFS = -DF_CPU=$(F_CPU)
CXXDEFS = -DF_CPU=$(F_CPU)

# Place -I options here : include libraries
CINCS = -I$(ARD_PATH) $(INCLUDE_LIBRARIES)
CXXINCS = -I$(ARD_PATH) $(INCLUDE_LIBRARIES)

# Compiler flag to set the C Standard level.
# c89   - "ANSI" C
# gnu89 - c89 plus GCC extensions
# c99   - ISO C99 standard (not yet fully implemented)
# gnu99 - c99 plus GCC extensions
CSTANDARD = -std=gnu99
CDEBUG = -g$(DEBUG)
CWARN = -Wall -Wstrict-prototypes
CTUNING = -funsigned-char -funsigned-bitfields -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -Wl,-gc-sections

CFLAGS = $(CDEBUG) $(CDEFS) $(CINCS) -O$(OPT) $(CWARN) $(CSTANDARD) $(CEXTRA) $(CTUNING)
CXXFLAGS = $(CDEFS) $(CXXINCS) -O$(OPT) $(CTUNING)
LDFLAGS = -lm -Wl,-gc-sections -mmcu=$(MCU)

# Programming support using avrdude. Settings and variables.
AVRDUDE_PROGRAMMER = stk500v1
AVRDUDE_PORT = $(PORT)
AVRDUDE_WRITE_FLASH = -U flash:w:bin/$(TARGET).hex
AVRDUDE_FLAGS = -F -p $(MCU) -P $(AVRDUDE_PORT) -c $(AVRDUDE_PROGRAMMER) \
  -b $(UPLOAD_RATE) -D
  

# Program settings
CC = $(AVRDUDE_DIR)/avr-gcc
CXX = $(AVRDUDE_DIR)/avr-g++
OBJCOPY = $(AVRDUDE_DIR)/avr-objcopy
OBJDUMP = $(AVRDUDE_DIR)/avr-objdump
AR  = $(AVRDUDE_DIR)/avr-ar
SIZE = $(AVRDUDE_DIR)/avr-size
NM = $(AVRDUDE_DIR)/avr-nm
AVRDUDE = $(AVRDUDE_DIR)/avrdude
REMOVE = rm -f
MV = mv -f

# Define all object files.
OBJ = $(SRC:.c=.o) $(CXXSRC:.cpp=.o) $(ASRC:.S=.o)

# Define all listing files.
LST = $(ASRC:.S=.lst) $(CXXSRC:.cpp=.lst) $(SRC:.c=.lst)

# Combine all necessary flags and optional flags.
# Add target processor to flags.
ALL_CFLAGS = -mmcu=$(MCU) -I. $(CFLAGS)
ALL_CXXFLAGS = -mmcu=$(MCU) -I. $(CXXFLAGS)
ALL_ASFLAGS = -mmcu=$(MCU) -I. -x assembler-with-cpp $(ASFLAGS)


# Default target.
all: clean build sizeafter upload
	@echo "action = all";


build: info folder elf hex
	@echo "action = build";

		

elf: bin/$(TARGET).elf
hex: bin/$(TARGET).hex
eep: bin/$(TARGET).eep
lss: bin/$(TARGET).lss 
sym: bin/$(TARGET).sym


# print info
info:
	@echo "------------------------ some info for debugging ------------------";
	@echo "board name: \t" $(BOARDNAME);
	@echo "description: \t" $(DESCRIPTION);
	@echo "cpu: \t\t\t" $(F_CPU); 
	@echo "mcu: \t\t" $(MCU);
	@echo "upload speed: \t" $(UPLOAD_RATE);
	@echo "port: \t\t" $(PORT);
	
	@echo " ";

	@echo "Library paths: \n\t" $(LIBRARY_PATHS);
	@echo "Library cpp files: \n\t" $(foreach item,$(LIBRARY_PATHS), $(wildcard $(item)/*.cpp));
	@echo "Compiling sources: \n\t" $(CXXSRC);
	@echo "Compiling libraries sources: \n\t" $(CPP_LIBRARIES);
	@echo "Included libraries: \n\t" $(INCLUDE_LIBRARIES);
	@echo "------------------------ end of debugging info --------------------";
	@echo " ";
	
# create the bin folder if it doesn't exist
folder:
	mkdir -p bin

# Program the device.  
upload: bin/$(TARGET).hex
	$(AVRDUDE) -C$(AVRDUDE_CONF) $(AVRDUDE_FLAGS) $(AVRDUDE_WRITE_FLASH)

# Display size of file.
HEXSIZE = $(SIZE) --target=$(FORMAT) bin/$(TARGET).hex
ELFSIZE = $(SIZE)  bin/$(TARGET).elf

sizebefore:
	@echo "size before: ";
	@if [ -f bin/$(TARGET).elf ]; then echo; echo $(MSG_SIZE_BEFORE); $(HEXSIZE); echo; fi

sizeafter:
	@echo "size after:";
	@if [ -f bin/$(TARGET).elf ]; then echo; echo $(MSG_SIZE_AFTER); $(HEXSIZE); echo; fi



# Convert ELF to COFF for use in debugging / simulating in AVR Studio or VMLAB.
COFFCONVERT=$(OBJCOPY) --debugging \
--change-section-address .data-0x800000 \
--change-section-address .bss-0x800000 \
--change-section-address .noinit-0x800000 \
--change-section-address .eeprom-0x810000 


coff: bin/$(TARGET).elf
	$(COFFCONVERT) -O coff-avr bin/$(TARGET).elf $(TARGET).cof


extcoff: $(TARGET).elf
	$(COFFCONVERT) -O coff-ext-avr bin/$(TARGET).elf $(TARGET).cof


.SUFFIXES: .elf .hex .eep .lss .sym

.elf.hex:
	$(OBJCOPY) -O $(FORMAT) -R .eeprom $< $@

.elf.eep:
	-$(OBJCOPY) -j .eeprom --set-section-flags=.eeprom="alloc,load" \
	--change-section-lma .eeprom=0 -O $(FORMAT) $< $@

# Create extended listing file from ELF output file.
.elf.lss:
	$(OBJDUMP) -h -S $< > $@

# Create a symbol table from ELF output file.
.elf.sym:
	$(NM) -n $< > $@


bin/core.a: $(OBJ)
	@for i in $(OBJ); do echo $(AR) rcs bin/core.a $$i; $(AR) rcs bin/core.a $$i; done

# Link: create ELF output file from library.
bin/$(TARGET).elf: bin/core.a
	$(CC) $(ALL_CFLAGS) -o $@ src/$(TARGET).cpp -L. bin/core.a $(LDFLAGS)

# Compile: create object files from C++ source files.
.cpp.o:
	$(CXX) -c $(ALL_CXXFLAGS) $< -o $@ 

# Compile: create object files from C source files.
.c.o:
	$(CC) -c $(ALL_CFLAGS) $< -o $@ 


# Compile: create assembler files from C source files.
.c.s:
	$(CC) -S $(ALL_CFLAGS) $< -o $@


# Assemble: create object files from assembler source files.
.S.o:
	$(CC) -c $(ALL_ASFLAGS) $< -o $@



# Target: clean project.
clean:
	$(REMOVE) bin/*.o bin/*.a bin/$(TARGET).hex bin/$(TARGET).eep bin/$(TARGET).cof bin/$(TARGET).elf \
	bin/$(TARGET).map bin/$(TARGET).sym bin/$(TARGET).lss bin/core.a \
	$(OBJ) $(LST) $(SRC:.c=.s) $(SRC:.c=.d) $(CXXSRC:.cpp=.s) $(CXXSRC:.cpp=.d)

depend:
	if grep '^# DO NOT DELETE' $(MAKEFILE) >/dev/null; \
	then \
		sed -e '/^# DO NOT DELETE/,$$d' $(MAKEFILE) > \
			$(MAKEFILE).$$$$ && \
		$(MV) $(MAKEFILE).$$$$ $(MAKEFILE); \
	fi
	echo '# DO NOT DELETE THIS LINE -- make depend depends on it.' \
		>> $(MAKEFILE); \
	$(CC) -M -mmcu=$(MCU) $(CDEFS) $(CINCS) $(SRC) $(ASRC) >> $(MAKEFILE)

.PHONY:	all build elf hex eep lss sym program coff extcoff clean depend info sizeafter sizebefore folder
