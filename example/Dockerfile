FROM ceedling:base

RUN apt install -y \
    python3-pip \
    build-essential

RUN python3 -m pip install -U pip
RUN python3 -m pip install compiledb

RUN mkdir -p /app

WORKDIR /app
