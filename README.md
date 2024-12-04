# SolarMax Battery Charger

### MCU Flashing attempts
Set fuses to default for ATmega324pb
```
avrdude -p atmega324p -c avrispv2 -vvvv -P usb -U lfuse:w:0x62:m -U hfuse:w:0x99:m -B 4
```
SPI clock is set by master (programmer) so whatever -B is is what the interface should be 
Check that ~Reset on MCU is high w MM
MOSI to MOSI, MISO to MISO, SCK to SCK, reset output of programmer to RESET pin of target, Vcc and Ground (well, Vcc if you power from the programmer, otherwise not).


### Docker instructions 
First, install the Docker application off Chrome. Then, inside of the repo run: 
```
docker build -t avr-ubuntu .
docker run -it avr-ubuntu
```

### Build instructions
To build for the MCU, run: 
```
mkdir build
make clean
make HARDWARE=1
```
The `main.*` binaries will then appear in build directory.

### Flash instructions 
After building the code, to flash to the MCU, run: 
```
./mcu_flash.sh
```


For testing logic, run `make` without the `HARDWARE=1` flag. This will compile with gcc and ignore all the HARDWARE macro blocks in the code 

### Build dependencies 
```
sudo apt update 
sudo apt upgrade
sudo apt install cmake g{cc,++}-aarch64-linux-gnu gcc-avr binutils-avr avr-libc avrdude git-all
```