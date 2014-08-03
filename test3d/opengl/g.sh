#!/bin/sh
if [ $# -eq 1 ]; then
echo complite $1
infile=$1
outfile=${infile%%.*}
g++ -o $outfile $infile  -lglut -lGL -lGLU -lm
fi
