CC = gcc
CFLAGS = -g -Wall -Os -Wextra -Wno-strict-aliasing -v#-mmcu=atmega644a
OBJS = main.o adc.o pwm.o mppt.o controller.o types.o
ODIR = ../build/src
OBJS_ = $(addprefix $(ODIR)/,$(OBJS))

all : $(ODIR) $(OBJS_) 

$(ODIR) : 
	echo $(OBJS_)
	mkdir $(ODIR)

$(ODIR)/main.o : main.c
	$(CC) -c $< -o $@

$(ODIR)/adc.o : adc/*.c adc/*.h
	$(CC) -c $< -o $@

$(ODIR)/pwm.o : pwm/*.c adc/*.h
	$(CC) -c $< -o $@

$(ODIR)/mppt.o : mppt/*.c mppt/*.h
	$(CC) -c $< -o $@

$(ODIR)/controller.o : controller/*.c controller/*.h
	$(CC) -c $< -o $@

$(ODIR)/types.o : types/*.c types/*.h
	$(CC) -c $< -o $@

.PHONY : clean
clean : 
	-rm $(ODIR)/*.o

