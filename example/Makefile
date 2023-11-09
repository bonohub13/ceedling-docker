CC := $(shell which gcc)
INCLUDE := $(shell find src -type d -name "include" | sed "s;src;-I&;g")
DOCKER := $(shell which docker)
DOCKER_IMAGE_NAME := ceedling
TAG := example

test:
	cd test \
		&& ceedling clean \
		&& ceedling gcov:all utils:gcov

build: prepare
	$(CC) -c -o build/src/main.o src/main.c ${INCLUDE}
	$(CC) -o build/example $(shell find build -type f -name "*.o" -printf "%p ") ${INCLUDE}

prepare:
	[ -d build/src/add/include ] || mkdir -p build/src/add/include
	$(CC) -c -o build/src/add/include/add.o src/add/src/add.c ${INCLUDE}

compiledb:
	$(DOCKER) run --rm -it -v $(shell pwd):/app ${DOCKER_IMAGE_NAME}:${TAG} /bin/sh -c 'compiledb -n make build'

docker-test:
	$(DOCKER) run --rm -it -v $(shell pwd):/app ${DOCKER_IMAGE_NAME}:${TAG} /bin/sh -c 'make -j test'

docker-build:
	$(DOCKER) run --rm -it -v $(shell pwd):/app ${DOCKER_IMAGE_NAME}:${TAG} /bin/sh -c 'make -j build'

docker-debug:
	$(DOCKER) run --rm -it -v $(shell pwd):/app ${DOCKER_IMAGE_NAME}:${TAG} /bin/bash

build-docker:
	$(DOCKER) build . -t ${DOCKER_IMAGE_NAME}:${TAG}

.PHONY: build test
