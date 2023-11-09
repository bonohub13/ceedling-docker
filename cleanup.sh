#!/usr/bin/env sh
set -eu

IMAGE_NAME="$1"

docker images \
    | grep "${IMAGE_NAME}" \
    | awk '{print$3}' \
    | while read image
do
    docker image rm "${image}"
done
