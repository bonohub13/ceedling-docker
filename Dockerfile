FROM ubuntu:jammy

RUN apt update
RUN apt upgrade -y

RUN DEBIAN_FRONEND=noninteractive apt install -y \
    ruby \
    gdb \
    gcovr

RUN gem install ceedling
