#!/usr/bin/env bash
mkdir build 
c++ -std=c++17 -c ./src/subtract.cpp -I./include -o build/subtract.o 
c++ -std=c++17 -c ./src/sum.cpp -I./include -o build/sum.o
c++ -std=c++17 -c ./src/main.cpp -I./include -o build/main.o
ar rcs build/libipb_arithmetic.a build/subtract.o build/sum.o 
c++ -std=c++17 ./src/main.cpp -I./include -L./build -lipb_arithmetic -o test_ipb_arithmetic
mkdir -p results/{bin,lib}
cp test_ipb_arithmetic results/bin
cp build/libipb_arithmetic.a results/lib
./cmake_build.sh start
