#!/bin/bash

leetcode=${1}
if [ -z "${leetcode}" ]; then
    leetcode="ALL"
fi

program=leetcode
if [ ! -d build ]; then
    echo "-- Build directory not exists"
fi
if [ -f ./build/${program} ]; then
    rm ./build/${program}
fi

cmake --log-level=DEBUG -Wdev -DCMAKE_BUILD_TYPE=Debug -DLEETCODE_PROBLEM="${leetcode}" -S . -B build
if [ $? != 0 ]; then
    exit $?
fi

if [ $(uname) == "Linux" ]; then
    cpu_core=$(nproc)
elif [ $(uname) == "Darwin" ]; then
    cpu_core=$(sysctl -n hw.physicalcpu)
else
    echo "Unsupported platform"
    exit 1
fi
echo "-- CPU core: $cpu_core"

make -j${cpu_core} -C build

otool -L build/${program}

if [ -x ./build/${program} ]; then
    echo "-- Run tests"
    ./build/${program}
fi
