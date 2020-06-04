/**
  \file      linkedList.c
  \brief     table list
  \author    Pierre BRESSY
  \version   1.0
  \date      2020-04-21 13:41:24
  \details   implementation
    
**/

#include "linkedList.h"

void initList(linkedList *l)
{
    l->numElem = 0;
    l->first = NULL;
    l->last = NULL;
    return;
}

elem *createElem(payload p) {

    elem *e;
    e = (elem *)calloc(1, sizeof(elem));
    if(e) {
        memcpy(&(e->p), &p, sizeof(payload));
    }
    else {
        fprintf(stderr, "[createElem] error while allocating memory for elem.\n");
    }
    return e;
}

void displayElem(elem e) {

    printf("(%3d,%3d)", e.p.col, e.p.row);
    return;
}
