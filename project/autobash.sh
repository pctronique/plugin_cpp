#!/bin/bash

cd ${0%/*}

chmod 777 comp.sh
./comp.sh
cd plugins
chmod 777 comp.sh
./comp.sh
