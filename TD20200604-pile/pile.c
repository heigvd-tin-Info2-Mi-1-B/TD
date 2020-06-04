/**
  \file      pile.c
  \brief     pile
  \author    Pierre BRESSY
  \version   1.0
  \date      2020-04-21 13:41:24
  \details   implementation
    
**/

#include "pile.h"

void initPile(sList *l) {
  initList(l);
}

void terminatePile(sList *l) {
  terminateList(l);
}

void push(sList *l, elem e) {
  insertElem(l, e, -1);
}

elem pop(sList *l) {
  elem e;
  e = getElem(l, -1);
  removeElem(l,-1);
  return e;
}
