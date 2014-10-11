#include <stdio.h>
#include <omp.h>

#define NUM_THREADS 4 
#define PAD 32

static long num_steps = 100000000;
double step;

int main(int argc, char **argv)
{
  int i, nthreads;
  double pi, sum[NUM_THREADS][PAD];

  double time_start, time_stop;
  time_start = omp_get_wtime();

  step = 1.0/(double)num_steps;

  omp_set_num_threads(NUM_THREADS);
  #pragma omp parallel
  {
    int i, id, nthrds;
    double x;
    id = omp_get_thread_num();
    nthrds = omp_get_num_threads();
    if (id == 0)
      nthreads = nthrds;

    for (i = id, sum[id][0] = 0.0; i < num_steps; i=i+nthrds)
    {
      x = (i+0.5)*step;
      sum[id][0] += 4.0/(1.0 + x*x);
    }
  }
  for (i = 0; i < nthreads; i++)
  {
    pi += sum[i][0] * step; 
  }

  time_stop = omp_get_wtime();

  printf("Pi: %lf\n", pi);
  printf("Calculated with %d threads and it only took me: %lf\n", NUM_THREADS, time_stop-time_start);
  return 0;
}
