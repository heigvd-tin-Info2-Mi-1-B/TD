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
  linkedList l;
  elem *e;

  initList(&l);
  
  e = createElem((payload){.row = 1, .col = 2});
  
  displayElem(*e);
  puts("");
  return 0;
}
