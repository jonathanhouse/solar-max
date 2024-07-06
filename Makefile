#CC = gcc
MCU=atmega64
F_CPU=16000000UL
CC=avr-gcc
CFLAGS = -g -Wall -Os -Wextra -Wno-strict-aliasing -mmcu=$(MCU) -DF_CPU=$(F_CPU) # -arch arm64#
BDIR = build

SDIR = src
OBJS = $(BDIR)/$(SDIR)/*.o

install : $(BDIR) source 
	$(CC) $(CFLAGS) -o $(BDIR)/main $(OBJS)

$(BDIR) :
	echo "ERROR: Make a build directory"
	exit 1

source :
	cd src && $(MAKE) 

.PHONY : clean 
clean : 
	-rm $(OBJS) $(BDIR)/main
