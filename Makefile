#CC = gcc
CC = avr-gcc
CFLAGS = -g -Wall -Os -Wextra -Wno-strict-aliasing -mmcu=atmega644a # -arch arm64#
BDIR = build

SDIR = src
OBJS = $(BDIR)/$(SDIR)/*.o

install : $(BDIR) source 
	$(CC) -o $(BDIR)/main $(OBJS)

$(BDIR) :
	echo "ERROR: Make a build directory"
	exit 1

source :
	cd src && $(MAKE) 

.PHONY : clean 
clean : 
	-rm $(OBJS) $(BDIR)/main