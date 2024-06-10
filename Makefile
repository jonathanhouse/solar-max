CC = gcc
CFLAGS = -g -Wall -Os -Wextra -Wno-strict-aliasing -v#-mmcu=atmega644a
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