# SolarMax Battery Charger


### Build instructions
To build for the MCU, run: 
```
mkdir build
make clean
make HARDWARE=1
```
The `main` binary will then appear in build directory.

For testing logic, run `make` without the `HARDWARE=1` flag. This will compile with gcc and ignore all the HARDWARE macro blocks in the code 

### Build dependencies 
```
sudo apt update 
sudo apt upgrade
sudo apt install cmake g{cc,++}-aarch64-linux-gnu gcc-avr binutils-avr avr-libc avrdude git-all
```