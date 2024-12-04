echo "Flashing main.flash.hex to an avr atmega644 with tool avrisp2"

avrdude -p atmega324p -c avrisp2 -v -U flash:w:build/main.flash.hex:i 

echo "Done with flash. Hopefully it was succesful"

echo "removing .0, .elf, and .flash.hex files"

#rm build/main.o build/main.elf build/main.flash.hex