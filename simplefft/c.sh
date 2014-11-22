#!/bin/bash
gcc -o l lines.c fix_fft.c `pkg-config --cflags gtk+-3.0` `pkg-config --libs gtk+-3.0` -lm
