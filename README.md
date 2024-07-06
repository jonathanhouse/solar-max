# SolarMax Battery Charger


### Build instructions
From the root repo, run: 
```
mkdir build
make clean
make
```
The `main` binary will then appear in build directory.

### Build dependencies 
```
sudo apt update 
sudo apt upgrade
sudo apt install cmake g{cc,++}-aarch64-linux-gnu gcc-avr binutils-avr avr-libc avrdude git-all
```