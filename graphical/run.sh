#!/bin/bash

mkdir build
cd build
cmake ..
cmake --build . -j8
mv zappy_gui ..
cd ..
./zappy_gui