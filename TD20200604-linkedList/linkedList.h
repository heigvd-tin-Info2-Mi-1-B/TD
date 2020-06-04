/**
 * \file linkedList.h
 * \version 1.0
 * \date 27/02/2020 - 15:33:28
 * \brief header to linkedList
 */

#pragma once

#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// preprocessor symbols

// preprocessor macros

// enumerated types

// structured types
typedef struct
{
    int32_t row;
    int32_t col;
} payload;

typedef struct elem {
    struct elem *prev;
    struct elem *next;
    payload p;
} elem;

typedef struct {
    elem *first;
    elem *last;
    uint32_t numElem;
} linkedList;

// unions types

// functions prototypes
void
initList(linkedList *l);
elem *createElem(payload p);
void displayElem(elem e);

// externals

// end of linkedList.h
