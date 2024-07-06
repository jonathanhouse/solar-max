
#CC = gcc
MCU=atmega64
F_CPU=16000000UL
CC=avr-gcc
CFLAGS = -g -Wall -Os -Wextra -Wno-strict-aliasing -mmcu=$(MCU) -DF_CPU=$(F_CPU) # -arch arm64#
BDIR = build

OBJS = main.o adc.o pwm.o mppt.o controller.o types.o
ODIR = ../build/src
OBJS_ = $(addprefix $(ODIR)/,$(OBJS))

all : $(ODIR) $(OBJS_) 

$(ODIR) : 
	echo $(OBJS_)
	mkdir $(ODIR)

$(ODIR)/main.o : main.c
	$(CC) $(CFLAGS) -c $< -o $@

$(ODIR)/adc.o : adc/*.c adc/*.h
	$(CC) $(CFLAGS) -c $< -o $@

$(ODIR)/pwm.o : pwm/*.c adc/*.h
	$(CC) $(CFLAGS) -c $< -o $@

$(ODIR)/mppt.o : mppt/*.c mppt/*.h
	$(CC) $(CFLAGS) -c $< -o $@

$(ODIR)/controller.o : controller/*.c controller/*.h
	$(CC) $(CFLAGS) -c $< -o $@

$(ODIR)/types.o : types/*.c types/*.h
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY : clean
clean : 
	-rm $(ODIR)/*.o

