# SolarMax Battery Charger

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