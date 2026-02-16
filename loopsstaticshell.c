//PLACE YOUR INCLUDE STATEMENTS HERE
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main(int argc, char **argv) {
  int i,j;
  int n = (argc > 1) ? atoi(argv[1]) : 128; // read from the command line; default is 128
  double sum;
  clock_t end, start;
  double arr[n][n];
  printf("n: %d\n", n);

// THIS FILLS THE MATRIX WITH NUMBERS
  for (i=0; i<n; i++)
    for (j=0; j<n; j++)
      arr[i][j] = (double) rand()/RAND_MAX;

  sum = 0;

// ROW MAJOR WORK
// YOU'LL NEED TO TIME IT
start = clock();
for (i = 0; i<n; i++) // iterate over rows 
  for (j = 0; j<n; j++) // iterate over columns 
    sum += arr[i][j];
end = clock();

printf("Row Major: sum = %lf and Clock Ticks are %ld\n",sum,end-start);

//ADD YOUR COLUMN MAJOR WORK
start = clock();
for (j = 0; j<n; j++) // iterate over columns 
  for (i = 0; i<n; i++) // iterate over rows 
    sum += arr[i][j];
end = clock();

printf("Column Major: sum = %lf and Clock Ticks are %ld\n",sum,end-start);

  return 0;
}

