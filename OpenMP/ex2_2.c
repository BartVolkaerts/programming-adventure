#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

#define NUM_THREADS 4

static long num_steps = 100000000;
double step;

int main(void)
{
  int nthreads; 
  double pi=0.0;
  double time_start, time_stop;

  step = 1.0/(double) num_steps;

  time_start = omp_get_wtime();
  omp_set_num_threads(NUM_THREADS);
  #pragma omp parallel
  {
    int i, nthrds;
    int ID = omp_get_thread_num();
    double x, sum;
    
    nthrds = omp_get_num_threads();
    if (ID == 0)
      nthreads = nthrds;

    for (i=ID, sum = 0.0; i<num_steps; i+=nthrds) 
    {
      x = (i+0.5)*step;
      sum+= 4.0/(1.0+x*x);
    }
      sum = sum * step;
      #pragma omp atomic
      pi += sum;
  }
  time_stop = omp_get_wtime();

  printf("Pi: %lf\n", pi);
  printf("Calculated with %d threads and it only took me: %lf\n", nthreads, time_stop-time_start);

  return EXIT_SUCCESS;
}
