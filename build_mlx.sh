#!/bin/bash

cd mlx
make clean
make
cp libmlx.dylib ..
cd ..