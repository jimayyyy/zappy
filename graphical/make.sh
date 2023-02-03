#!/bin/bash

mkdir build
cd build
cmake ..
cmake --build .
mv zappy_gui ..
# cd ..
# ./zappy_gui