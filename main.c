
// This file is part of the HPC workshop 2019 at Durham University 
// Author: Christian Arnold

/* 
 * This program reads a set of numbers from a file and adds them (in serial).
 * Your task is to identify the hotspots of the programm and to parallelise 
 * them using OpenMP.
 * 
 * Note that the result of your calculation will suffer from floating point 
 * roundoff errors, it might thus differ depending how you add the numbers.
 */

#ifdef _OPENMP
#include <omp.h>
#endif

#include <stdlib.h>
#include <stdio.h>
#include "proto.h"
#include <time.h>


/*
 * The program takes one argument: the name of the file containing the 
 * numbers in binary format.
 */
void main(int argc, char *argv[])
{
  int n_threads;
  double cpu_time;
  clock_t start, end;

  int n_numbers; /* the count of numbers in the file */

#ifdef _OPENMP
#pragma omp parallel
  {
    n_threads = omp_get_num_threads();
  }
  printf("number of threads=%d \n", n_threads);
#else
  printf("Serial version\n");
#endif

  if(argc > 2)
    {
      n_numbers = 10000000;
      create_and_write_numbers(argv[1], n_numbers);
    }
  else
    {
      float *numbers; /* the array holding the individual numbers */

      /* read the numbers from the file */
      read_numbers(argv[1], &n_numbers, &numbers);

      for(int i = 5; i< n_numbers; i+=n_numbers/10)
        printf("numbers[%i] = %g\n", i, numbers[i]);

      /* now add the numbers */
      add_numbers(n_numbers, numbers);

      free(numbers);
    }
}
