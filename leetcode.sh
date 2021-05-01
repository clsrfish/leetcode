#!/bin/bash

problem=${1}
if [ -z "${problem}" ]; then
    problem="ALL"
fi

program=leetcode
if [ ! -d build ]; then
    echo "-- Build directory not exists"
fi
if [ -f ./build/${program} ]; then
    rm ./build/${program}
fi

cmake --log-level=DEBUG -Wdev -DCMAKE_BUILD_TYPE=Debug -DLEETCODE_PROBLEM="${problem}" -S . -B build
if [ $? != 0 ]; then
    exit $?
fi

cmake --build build
if [ $? != 0 ]; then
    exit $?
fi

if [ -x ./build/${program} ]; then
    otool -L build/${program}
    echo "-- Run leetcode"
    ./build/${program}
fi
