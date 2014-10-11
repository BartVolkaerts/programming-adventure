#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

static long num_steps = 100000;
double step;

int main(void)
{
  int i, nthreads; 
  double x, pi, sum = 0.0;
  double time_start, time_stop;

  step = 1.0/(double) num_steps;

  time_start = omp_get_wtime();

  for (i=0;i<num_steps;i++) {
    x = (i+0.5)*step;
    sum = sum + 4.0/(1.0+x*x);
  }

  pi = step * sum;
  time_stop = omp_get_wtime();

  printf("Pi: %lf\n", pi);
  printf("and it only took me: %lf\n", time_stop-time_start);

  return EXIT_SUCCESS;
}
