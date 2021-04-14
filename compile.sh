#!/usr/bin/bash

cd $(dirname $0)

g++ -Wall -std=c++17 -Os -g0 ./wizcheat.cpp -o wizcheat
strip -s ./wizcheat.exe

