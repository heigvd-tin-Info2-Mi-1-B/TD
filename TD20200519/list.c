/**
  \file      list.c
  \brief     table list
  \author    Pierre BRESSY
  \version   1.0
  \date      2020-04-21 13:41:24
  \details   implementation
    
**/

#include "list.h"

void initList(sList *l)
{

    l->numElem = 0;
    return;
}

bool isListFull(sList *l)
{

    return (l->numElem == MAX_LIST_SIZE);
}

bool isListEmpty(sList *l)
{

    return (l->numElem == 0);
}

uint32_t insertElem(sList *l, elem e, int32_t pos)
{
    int32_t k = 0;

    if (!isListFull(l))
    {
        if(pos==-1) {
            l->element[l->numElem] = e;
            l->numElem++;
        }
        else if(0<=pos && pos<l->numElem) {
            for (k = l->numElem; k > pos; k--) {
                l->element[k] = l->element[k - 1];
            }
            l->element[pos] = e;
            l->numElem++;
        }
        else {
            puts("[insertElem] bad position for insertion.");
        }
    }

    else {
        puts("[insertElem] list is full.");
    }
    return l->numElem;
}

void displayElem(elem e) {
#ifdef LIST_OF_DOUBLE
        printf("%+6.3lf ", e);
#endif
#ifdef LIST_OF_INT32
        printf("%d ", e);
#endif
#ifdef LIST_OF_POINT2D
        printf("(%3d,%3d) ", e.col, e.row);
#endif
}

void displayList(sList *l) {

    uint32_t k = 0;
    
    printf("n=%u\t", l->numElem);
    for (k = 0; k < l->numElem;k++) {
        displayElem(l->element[k]);
    }
    puts("");
    return;
}

int32_t searchElem(sList *l, elem e)
{
    int32_t pos = -1;
    bool found = false;
    uint32_t k = 0;

    while( k<l->numElem && !found) {

        if(e==l->element[k])
        {
            found = true;
            pos = k;
        }

        k++;
    }

    return pos;
}
