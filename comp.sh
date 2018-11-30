#!/bin/bash

# Compiling the current solution based on its number

FOLDER=$(pwd)
QUESTION="${FOLDER##*/}"

g++ "${QUESTION}.cpp" -o "${QUESTION}"

if [ $? -ne 1 ]; then
    echo "Arquivo ${QUESTION} gerado"
else
    echo "Falha na compilação de ${QUESTION}"
fi
