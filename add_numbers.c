// This file is part of the HPC workshop 2019 at Durham University 
// Author: Christian Arnold
#include <stdlib.h>
#include <stdio.h>
#include "proto.h"
#include <time.h>
#include <math.h>
#ifdef _OPENMP
#include <omp.h>  /* use OpenMP only if needed */
#endif


/* This function the numbers and prints the result. */
void add_numbers(int n_numbers, float *numbers)
{
  printf("Adding %i numbers ...\n", n_numbers);

  float result = 0;
#ifdef _OPENMP
  double start = omp_get_wtime();
#else 
  clock_t start = clock(); 
#endif

  /* do the actual calculation */
  for(int i = 0; i < n_numbers; i++)
    {
      result += fabs(log(pow(fabs(numbers[i]), 2.1))) + log(pow(fabs(numbers[i]), 1.9)) 
        + log(pow(fabs(numbers[i]), -1.97)) + fabs(log(pow(fabs(numbers[i]), -1.005)));
    }

  /* time the calculation */  
#ifdef _OPENMP
  double end = omp_get_wtime();
  double time = end-start;
#else
  clock_t end = clock();
  double time = ((double)end - start)/CLOCKS_PER_SEC;
#endif

  printf("The result is: %g\n", result);
  printf("Doing %i calculations took %g s\n", n_numbers, time);
}

