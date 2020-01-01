#!/bin/bash

cd build && cmake ../ && make && cd ../ && time ./build/Main
