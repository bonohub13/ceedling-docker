DOCKER := $(shell which docker)
CLEANUP_SCRIPT := cleanup.sh

DOCKER_IMAGE_NAME := ceedling
TAG := base

build:
	$(DOCKER) build . -t ${DOCKER_IMAGE_NAME}:${TAG}

test:
	$(DOCKER) --rm -it ${DOCKER_IMAGE_NAME}:${TAG} /bin/bash

clean:
	./${CLEANUP_SCRIPT} ${DOCKER_IMAGE_NAME}
