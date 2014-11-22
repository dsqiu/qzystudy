#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <math.h>
#include "fix_fft.h"

int main(int argc, char *argv[])
{
	int i = 0,j = 1000;
	int tt;
	int val;
	char im[128];
	char data[128];
	srand( (unsigned)time(NULL));
	do {
		if (i < 128){
			val =  rand() % 256;  //audio data
			data[i] = val - 128;
			im[i] = 0;
			i++;
		}
		else{
			//this could be done with the fix_fftr function without the im array.
			fix_fft(data,im,7,0);
			//fix_fftr(data,7,0);
			// I am only interessted in the absolute value of the transformation
			for (i=0; i< 64;i++){
				data[i] = sqrt(data[i] * data[i] + im[i] * im[i]);
				printf("%3d\t",data[i]);
			}
			printf("\n");
		}
	}while(--j);
	return 0;
}
