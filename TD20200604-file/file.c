/**
  \file      file.c
  \brief     file
  \author    Pierre BRESSY
  \version   1.0
  \date      2020-04-21 13:41:24
  \details   implementation
    
**/

#include "file.h"

void initFile(sList *l)
{
  initList(l);
}

void terminateFile(sList *l)
{
  terminateList(l);
}

void push(sList *l, elem e)
{
  insertElem(l, e, 0);
}

elem pop(sList *l)
{
  elem e;
  e = getElem(l, -1);
  removeElem(l, -1);
  return e;
}
