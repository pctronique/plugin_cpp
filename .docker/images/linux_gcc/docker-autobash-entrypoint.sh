#!/bin/bash

if [ -z ${GCC_FOLDER_PROJECT} ]
then
    GCC_FOLDER_PROJECT=/home/project/
fi

if [ -z ${PHP_FOLDER_LOG} ]
then
    GCC_FOLDER_LOG=/var/log/docker/gcc/
fi

touch ${GCC_FOLDER_LOG}/error.log
service startautobash start && tail -F ${GCC_FOLDER_LOG}/error.log &

exec "$@"