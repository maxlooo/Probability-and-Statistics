#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SAMPLESIZE 1000

double random(); 

int main(void) {
  int count, a=0, b=0, c=0, d=0, e=0, f=0, g=0, h=0, i=0, j=0;
  double x[SAMPLESIZE]={}, y[SAMPLESIZE]={}, test;
  srand(time(0)); 
  
  // generate samples of two 1000 times from uniform distribution
  for (count = 0; count < SAMPLESIZE; count++) {
  	x[count]=random();
  	y[count]=random();
  }

  /*
  for (count = 0; count < SAMPLESIZE; count++) {
    printf("x = %0.5f, y = %0.5f,\n", x[count], y[count]);
  }
  */
  
  // distribute sum of pair for each sampled pair
  for (count = 0; count < SAMPLESIZE; count++) {
  	test = x[count]+y[count];
  	if (test>=.0 && test<=.2) a++;
  	else if (test>.2 && test<=.4) b++;
  	else if (test>.4 && test<=.6) c++;
  	else if (test>.6 && test<=.8) d++;
  	else if (test>.8 && test<=1.0) e++;
  	else if (test>1.0 && test<=1.2) f++;
  	else if (test>1.2 && test<=1.4) g++;
  	else if (test>1.4 && test<=1.6) h++;
  	else if (test>1.6 && test<=1.8) i++;
  	else if (test>1.8 && test<=2.0) j++;
  }

  // print relative frequency histogram
  printf("%d, %d, %d, %d, %d, %d, %d, %d, %d, %d\n", 
  	a, b, c, d, e, f, g, h, i, j);

	return 0;
}

double random() {
	return rand()/(double)RAND_MAX;
}