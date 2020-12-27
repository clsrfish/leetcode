#!/bin/bash

program=main
if [ ! -d build ]; then
    echo "-- Build directory not exists"
fi
if [ -f ./build/${program} ]; then
    rm ./build/${program}
fi

cmake --log-level=VERBOSE -Wdev -DCMAKE_BUILD_TYPE=Debug -S . -B build

if [ $(uname) == "Linux" ]; then
    cpu_core=$(nproc)
elif [ $(uname) == "Darwin" ]; then
    cpu_core=$(sysctl -n hw.physicalcpu)
else
    echo "Unsupported platform"
    exit 1
fi
echo "-- CPU core: $cpu_core"

make -d -j${cpu_core} -C build

otool -L build/${program}

echo "-- Launching main"

./build/${program}
