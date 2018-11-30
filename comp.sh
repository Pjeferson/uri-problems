#!/bin/bash

# Compiling the current solution based on its number

FOLDER=$(pwd)
QUESTION="${FOLDER##*/}"
BINARY="${QUESTION}-bin"

g++ "${QUESTION}.cpp" -o $BINARY

if [ $? -ne 1 ]; then
    echo "Arquivo ${BINARY} gerado"
else
    echo "Falha na compilação de ${BINARY}"
fi
