#!/bin/bash

# Compilation script for examples
# This script should create and connect all "things" needed to generate the example

export CPPJSONGENERATOR=../src
export EXEC_NAME=run_examples

g++ -g $CPPJSONGENERATOR/json_generator.cpp examples.cpp -o $EXEC_NAME
./$EXEC_NAME
