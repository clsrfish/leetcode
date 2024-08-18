#!/bin/sh

cmake --log-level=DEBUG -Wdev -DCMAKE_BUILD_TYPE=Debug -S . -B build &&
    cmake --build build &&
    ./build/tests/leetcode/tests_leetcode
