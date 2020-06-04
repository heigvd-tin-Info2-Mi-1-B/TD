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
    l->capacity = 0;
    l->element = (elem *)calloc(DEFAULT_LIST_SIZE, sizeof(elem));
    if (l->element)
    {
        l->capacity = DEFAULT_LIST_SIZE;
    }
    return;
}

bool isListFull(sList *l)
{

    return (l->numElem == l->capacity);
}

bool isListEmpty(sList *l)
{

    return (l->numElem == 0);
}

uint32_t insertElem(sList *l, elem e, int32_t pos)
{
    int32_t k = 0;
    elem *newArea = NULL;

    if (isListFull(l))
    {
        newArea = (elem *)realloc(l->element, (l->capacity + EXTENSION_LIST_SIZE) * sizeof(elem));
        if (newArea)
        {
            l->element = newArea;
            l->capacity += EXTENSION_LIST_SIZE;
            printf("new capacity=%u\n", l->capacity);
        }
    }

    if (!isListFull(l))
    {
        if (pos == -1)
        {
            l->element[l->numElem] = e;
            l->numElem++;
        }
        else if (0 <= pos && pos < l->numElem)
        {
            for (k = l->numElem; k > pos; k--)
            {
                l->element[k] = l->element[k - 1];
            }
            l->element[pos] = e;
            l->numElem++;
        }
        else
        {
            puts("[insertElem] bad position for insertion.");
        }
    }

    else
    {
        puts("[insertElem] list is full.");
    }
    return l->numElem;
}

void displayElem(elem e)
{
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

void displayList(sList *l)
{

    uint32_t k = 0;

    printf("n=%u\t", l->numElem);
    for (k = 0; k < l->numElem; k++)
    {
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

    while (k < l->numElem && !found)
    {

        if (0 == memcmp(&e, &l->element[k], sizeof(elem)))
        {
            found = true;
            pos = k;
        }

        k++;
    }

    return pos;
}
int32_t searchElemBasic(sList *l, elem e)
{
    int32_t pos = -1;
    bool found = false;
    uint32_t k = 0;

    while (k < l->numElem && !found)
    {

        if (e == l->element[k]) // not for compound types like structures and unions    :(
        {
            found = true;
            pos = k;
        }

        k++;
    }

    return pos;
}

elem getElem(sList *l, int32_t pos)
{

    elem e;
    if (pos == -1)
    {
        pos = l->numElem - 1;
    }
    if (0 <= pos && pos < l->numElem)
    {

        // e=l->element[pos]      ok for int32_t double...  not for structures nor unions.

        memcpy(&e, &(l->element[pos]), sizeof(elem));
    }
    else
    {
        puts("[insertElem] bad position for getting element.");
    }
    return e;
}

void terminateList(sList *l)
{

    if (l->element)
    {
        free(l->element);
        l->element = NULL;
        l->capacity = 0;
        l->numElem = 0;
    }
    return;
}

void removeElem(sList *l, int32_t pos)
{
    if (pos == -1)
    {
        pos = l->numElem - 1;
    }
    if (0 <= pos && pos < l->numElem)
    {
        l->numElem--;
    }
    else
    {
        puts("[removeElem] bad position for removing element.");
    }
    return;
}