#!/bin/bash

# TODO
# Generating files for a new problem solution

QUESTION=$1

mkdir "problems/${QUESTION}"
touch "problems/${QUESTION}/${QUESTION}.cpp"
touch "problems/${QUESTION}/in"
touch "problems/${QUESTION}/out"
touch "problems/${QUESTION}/comp"

echo -e "Created structure:"
echo -e "  problems/${QUESTION}"
echo -e "  problems/${QUESTION}/${QUESTION}.cpp"
echo -e "  problems/${QUESTION}/in"
echo -e "  problems/${QUESTION}/out"
echo -e "  problems/${QUESTION}/comp"