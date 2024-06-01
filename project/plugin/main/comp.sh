#/////////////////////////////////////
#//    DEVELOPPEUR : PCTRONIQUE     //
#/////////////////////////////////////

#!/bin/sh

cd ${0%/*}

mkdir build
cd build
cmake ../
make
cd ..
rm -r build