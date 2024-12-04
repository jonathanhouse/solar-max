MCU=atmega324p
F_CPU=1000000UL
AVR_CC=avr-gcc
AVR_CFLAGS = -g -Wall -O0 -Wextra -Wno-strict-aliasing -mmcu=$(MCU) -DF_CPU=$(F_CPU) # -arch arm64#

GCC_CC=gcc
GCC_CFLAGS= -g -Wall -O0 -Wextra -Wno-strict-aliasing #-arch=arm64

ifdef HARDWARE 
CC=$(AVR_CC)
CFLAGS = $(AVR_CFLAGS)
CFLAGS+=-DHARDWARE
else 
CC = $(GCC_CC)
CFLAGS = $(GCC_CFLAGS)
endif

BDIR = build
SDIR = src
OBJS = $(BDIR)/$(SDIR)/*.o

install : $(BDIR) source 
	$(CC) $(CFLAGS) -o $(BDIR)/main.o $(OBJS)
	avr-gcc -g -Wall -Os -Werror -Wextra -Wno-strict-aliasing -o $(BDIR)/main.elf $(BDIR)/main.o
	echo "Compiling main.elf to main.flash.hex"
	avr-objcopy -j .text -j .data -O ihex $(BDIR)/main.elf $(BDIR)/main.flash.hex

$(BDIR) :
	echo "ERROR: Make a build directory"
	exit 1

source :
	cd src && $(MAKE) 

.PHONY : clean 
clean : 
	-rm $(OBJS) $(BDIR)/main.o