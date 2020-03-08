#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define POPSIZE 1000
#define SAMPLESIZE5 5
#define SAMPLESIZE10 10

double random(void); 

int main(void) {
  int count1, count2;
  int value[2][20]={};
  double sample1[POPSIZE][SAMPLESIZE5]={}, sample2[POPSIZE][SAMPLESIZE10]={}, test;
  srand(time(0)); 

  // generate samples of five 1000 times from uniform distribution
  for (count1 = 0; count1 < POPSIZE; ++count1) {
    for (count2 = 0; count2 < SAMPLESIZE5; ++count2) {
      sample1[count1][count2]=random();
    }
  }
  // generate samples of ten 1000 times from uniform distribution
  for (count1 = 0; count1 < POPSIZE; ++count1) {
    for (count2 = 0; count2 < SAMPLESIZE10; ++count2) {
      sample2[count1][count2]=random();
    }
  }
  
  // distribute average for each sample size 5
  for (count1 = 0; count1 < POPSIZE; ++count1) {
    test = 0;
    for (count2 = 0; count2 < SAMPLESIZE5; ++count2) { 
      test += sample1[count1][count2];
    }
    test/=SAMPLESIZE5;
    if (test>=.0 && test<=.05) value[0][0]++;
    else if (test>.05 && test<=.1) value[0][1]++;
    else if (test>.1 && test<=.15) value[0][2]++;
    else if (test>.15 && test<=.2) value[0][3]++;
    else if (test>.2 && test<=.25) value[0][4]++;
    else if (test>.25 && test<=.3) value[0][5]++;
    else if (test>.3 && test<=.35) value[0][6]++;
    else if (test>.35 && test<=.4) value[0][7]++;
    else if (test>.4 && test<=.45) value[0][8]++;
    else if (test>.45 && test<=.5) value[0][9]++;
    else if (test>.5 && test<=.55) value[0][10]++;
    else if (test>.55 && test<=.6) value[0][11]++;
    else if (test>.6 && test<=.65) value[0][12]++;
    else if (test>.65 && test<=.7) value[0][13]++;
    else if (test>.7 && test<=.75) value[0][14]++;
    else if (test>.75 && test<=.8) value[0][15]++;
    else if (test>.8 && test<=.85) value[0][16]++;
    else if (test>.85 && test<=.9) value[0][17]++;
    else if (test>.9 && test<=.95) value[0][18]++;
    else if (test>.95 && test<=1.0) value[0][19]++;
  }

  // print relative frequency histogram
  printf("\n*****Relative Frequency Histogram of Sample Size Five 1000 times*****\n");
  printf("From 0 to 1.0, segmented into 20 parts\n");
  printf("\n");
  for (int i=0; i<20; ++i) {
    printf("%d, ", value[0][i]);
  }
  printf("\n");

  // distribute average for each sample size 10
  for (count1 = 0; count1 < POPSIZE; ++count1) {
    test = 0;
    for (count2 = 0; count2 < SAMPLESIZE10; ++count2) { 
      test += sample2[count1][count2];
    }
    test/=SAMPLESIZE10;
    if (test>=.0 && test<=.05) value[1][0]++;
    else if (test>.05 && test<=.1) value[1][1]++;
    else if (test>.1 && test<=.15) value[1][2]++;
    else if (test>.15 && test<=.2) value[1][3]++;
    else if (test>.2 && test<=.25) value[1][4]++;
    else if (test>.25 && test<=.3) value[1][5]++;
    else if (test>.3 && test<=.35) value[1][6]++;
    else if (test>.35 && test<=.4) value[1][7]++;
    else if (test>.4 && test<=.45) value[1][8]++;
    else if (test>.45 && test<=.5) value[1][9]++;
    else if (test>.5 && test<=.55) value[1][10]++;
    else if (test>.55 && test<=.6) value[1][11]++;
    else if (test>.6 && test<=.65) value[1][12]++;
    else if (test>.65 && test<=.7) value[1][13]++;
    else if (test>.7 && test<=.75) value[1][14]++;
    else if (test>.75 && test<=.8) value[1][15]++;
    else if (test>.8 && test<=.85) value[1][16]++;
    else if (test>.85 && test<=.9) value[1][17]++;
    else if (test>.9 && test<=.95) value[1][18]++;
    else if (test>.95 && test<=1.0) value[1][19]++;
  }

  // print relative frequency histogram
  printf("\n*****Relative Frequency Histogram of Sample Size Ten 1000 times*****\n");
  printf("From 0 to 1.0, segmented into 20 parts\n");
  printf("\n");
  for (int i=0; i<20; ++i) {
    printf("%d, ", value[1][i]);
  }
  printf("\n");

  return 0;
}

double random(void) {
  return rand()/(double)RAND_MAX;
}
