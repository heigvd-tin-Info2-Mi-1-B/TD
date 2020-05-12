/**
  \file      graph.c
  \brief     graph
  \author    Pierre BRESSY
  \version   1.0
  \date      2020-04-21 13:41:24
  \details
    
**/

#include "graph.h"

int gGraph = 0;

void graph(void)
{
  puts("graph module");
  test();
  gGraph = 1;
  return;
}

static void test(void) {

  printf("[graph.c] - test\n");
  return;
}

void stest(void) {
  test();
}