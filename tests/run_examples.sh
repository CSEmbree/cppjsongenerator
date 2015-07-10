#!/bin/bash

export CPPJSONGENERATOR=../src

g++ -g $CPPJSONGENERATOR/json_generator.cpp examples.cpp -o run_example
./run_example
