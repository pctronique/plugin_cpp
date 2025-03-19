#/////////////////////////////////////
#//    DEVELOPPEUR : PCTRONIQUE     //
#/////////////////////////////////////

#!/bin/sh

cd ${0%/*}

rm -rf dist
mkdir dist

cd pctrplugin
chmod 777 comp.sh
./comp.sh
cd ../testplugin
chmod 777 comp.sh
./comp.sh
