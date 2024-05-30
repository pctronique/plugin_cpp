#/////////////////////////////////////
#//    DEVELOPPEUR : PCTRONIQUE     //
#/////////////////////////////////////

#!/bin/sh

cd ${0%/*}

cd static
chmod 777 comp.sh
./comp.sh
cd ../testplugin
chmod 777 comp.sh
./comp.sh
