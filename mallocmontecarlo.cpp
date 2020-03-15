#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define POPSIZE 1000

double random(void); 
void allocateSample(int sampleSize, double *sample[POPSIZE]);
void distributeSampleMean(int sampleSize, double *sample[POPSIZE], int x, int value[][20]);

int main(void) {
  const int sampleSize5=5;
  const int sampleSize10=10;
  int count1, count2;
  int value[2][20]={};
  double *sample1[POPSIZE], *sample2[POPSIZE], test;
  srand(time(0)); 
  
  // generate samples of five 1000 times 
  allocateSample(sampleSize5, sample1);
  // generate samples of ten 1000 times 
  allocateSample(sampleSize10, sample2);  
  // distribute sample mean for each sample size 5
  distributeSampleMean(sampleSize5, sample1, 0, value);
  // distribute sample mean for each sample size 10
  distributeSampleMean(sampleSize10, sample2, 1, value);

  // print relative frequency histogram
  printf("\n*****Relative Frequency Histogram of Sample Means of Sample Size Five 1000 times*****\n");
  printf("From 0 to 1.0, segmented into 20 parts\n\n");
  for (int i=0; i<20; ++i) {
    printf("%d, ", value[0][i]);
  }
  printf("\n");

  // print relative frequency histogram
  printf("\n*****Relative Frequency Histogram of Sample Means of Sample Size Ten 1000 times*****\n");
  printf("From 0 to 1.0, segmented into 20 parts\n\n");
  for (int i=0; i<20; ++i) {
    printf("%d, ", value[1][i]);
  }
  printf("\n");

  for (count1 = 0; count1 < POPSIZE; ++count1) {  
    free(sample1[count1]);
    sample1[count1] = NULL;
    free(sample2[count1]);
    sample2[count1] = NULL;
  }

  return 0;
}

// random numbers taken from uniform distribution
double random(void) {
  return rand()/(double)RAND_MAX;
}

// generate samples 1000 times from uniform distribution
void allocateSample(int sampleSize, double *sample[POPSIZE]) {
  int count1, count2;

  for (count1 = 0; count1 < POPSIZE; ++count1) {  
    sample[count1] = (double *) malloc (sampleSize * sizeof(double));
  }

  for (count1 = 0; count1 < POPSIZE; ++count1) {
  	for (count2 = 0; count2 < sampleSize; ++count2) {
  		sample[count1][count2]=random();
  	}
  }
}

// distribute average for each sample size 
void distributeSampleMean(int sampleSize, double *sample[POPSIZE], int x, int value[][20]) {
  int count1, count2;
  double test;

  for (count1 = 0; count1 < POPSIZE; ++count1) {
    test = 0;
    for (count2 = 0; count2 < sampleSize; ++count2) { 
      test += sample[count1][count2];
    }
    test/=sampleSize;
    if (test>=.0 && test<=.05) value[x][0]++;
    else if (test>.05 && test<=.1) value[x][1]++;
    else if (test>.1 && test<=.15) value[x][2]++;
    else if (test>.15 && test<=.2) value[x][3]++;
    else if (test>.2 && test<=.25) value[x][4]++;
    else if (test>.25 && test<=.3) value[x][5]++;
    else if (test>.3 && test<=.35) value[x][6]++;
    else if (test>.35 && test<=.4) value[x][7]++;
    else if (test>.4 && test<=.45) value[x][8]++;
    else if (test>.45 && test<=.5) value[x][9]++;
    else if (test>.5 && test<=.55) value[x][10]++;
    else if (test>.55 && test<=.6) value[x][11]++;
    else if (test>.6 && test<=.65) value[x][12]++;
    else if (test>.65 && test<=.7) value[x][13]++;
    else if (test>.7 && test<=.75) value[x][14]++;
    else if (test>.75 && test<=.8) value[x][15]++;
    else if (test>.8 && test<=.85) value[x][16]++;
    else if (test>.85 && test<=.9) value[x][17]++;
    else if (test>.9 && test<=.95) value[x][18]++;
    else if (test>.95 && test<=1.0) value[x][19]++;
  }
}
