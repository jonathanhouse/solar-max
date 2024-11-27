FROM ubuntu:latest

RUN apt-get update && apt-get install -y \
    qemu-system-avr \
    gcc-avr \
    binutils-avr \
    avr-libc \
    make \
    git \
    build-essential \
    gdb-avr \
    simavr \
    apt-get clean \ 
    && avrdude

WORKDIR /workspace

RUN git clone https://github.com/jonathanhouse/solar-max.git 

CMD ["bash"]
