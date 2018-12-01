#!/bin/bash

# Compiling the current solution based on its number

FOLDER=$(pwd)
QUESTION="${FOLDER##*/}"
BINARY="${QUESTION}-bin"

g++ "${QUESTION}.cpp" -o $BINARY

if [ $? -ne 1 ]; then
    echo "File ${BINARY} generated"
else
    echo "Failed to compile ${BINARY}"
fi
