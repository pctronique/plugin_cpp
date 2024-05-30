#/////////////////////////////////////
#//    DEVELOPPEUR : PCTRONIQUE     //
#/////////////////////////////////////

#!/bin/sh

cd ${0%/*}

cd plugin1
chmod 777 comp.sh
./comp.sh
cd ../plugin2
chmod 777 comp.sh
./comp.sh
cd ../plugin3
chmod 777 comp.sh
./comp.sh
