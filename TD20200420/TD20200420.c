/**
  \file      TD20200407.c
  \brief     preprocessing
  \author    Pierre BRESSY
  \version   1.0
  \date      2020-03-03 13:41:24
  \details
    
**/

#include "TD20200420.h"

int main(int argc, char *argv[])
{
  uint32_t k = 0;

  srand((unsigned int)time(NULL));

  for (k = 0; k < 10; k++)
    printf("%.6lf\n", rand() / (double)RAND_MAX);

  puts("");

  return 0;
}
