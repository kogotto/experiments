#!/bin/bash

mkdir -p build;
cmake -B build/ -S .;
mkdir out/;

cd build;
make;
