#!/bin/bash

cd $(dirname ${0})

touch "src/${1}.cpp" "test/${1}_test.cpp"
