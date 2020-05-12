/**
  \file      TD20200505.c
  \brief     multiple file compilation
  \author    Pierre BRESSY
  \version   1.0
  \date      2020-04-21 13:41:24
  \details
    
**/

#include "TD20200505.h"

static int gA;

int main(int argc, char const *argv[])
{
  //displayError(E_ALLOC_MEM_ERROR);

  sPoint p1 = {1., 1.};
  sPoint p2 = {0., 0.};

  p2 = rotate(p1, -45);
  gA = 3;
  pointDisplay("P1", p1);
  pointDisplay("P2", p2);
  return 0;
}
