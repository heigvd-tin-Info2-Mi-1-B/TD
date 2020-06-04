/**
  \file      TD20200604.c
  \brief     pile
  \author    Pierre BRESSY
  \version   1.0
  \date      2020-04-21 13:41:24
  \details
    
**/

#include "TD20200604.h"

int main(int argc, char const *argv[])
{
  sList l;
  elem e;

  initPile(&l);
  displayList(&l);

  push(&l, 1);
  displayList(&l);
  push(&l, 2);
  displayList(&l);
  push(&l, 3);
  displayList(&l);
  push(&l, 4);
  displayList(&l);

  push(&l, 5);
  push(&l, 6);
  push(&l, 7);
  push(&l, 8);
  push(&l, 9);
  push(&l, 10);
  push(&l, 11);
  push(&l, 12);

  e = pop(&l);
  displayElem(e);
  puts("");
  displayList(&l);
  terminatePile(&l);
  return 0;
}
