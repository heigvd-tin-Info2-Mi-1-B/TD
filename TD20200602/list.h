/**
 * \file list.h
 * \version 1.0
 * \date 27/02/2020 - 15:33:28
 * \brief header to list
 */

#pragma once

#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// preprocessor symbols
//#define LIST_OF_DOUBLE
#define LIST_OF_INT32
//#define LIST_OF_POINT2D

#define DEFAULT_LIST_SIZE (10)
#define EXTENSION_LIST_SIZE (5)

// preprocessor macros

// enumerated types

// structured types
typedef struct
{
    int32_t row;
    int32_t col;
} sPoint2D;

#ifdef LIST_OF_DOUBLE
typedef double elem; // generic type
#endif
#ifdef LIST_OF_INT32
typedef int32_t elem; // generic type
#endif
#ifdef LIST_OF_POINT2D
typedef sPoint2D elem; // generic type
#endif

typedef struct
{
    uint32_t capacity;
    uint32_t numElem;
    elem *element;

} sList;
// unions types

// functions prototypes
void initList(sList *l);
bool isListFull(sList *l);
bool isListEmpty(sList *l);
uint32_t insertElem(sList *l, elem e, int32_t pos);
void displayElem(elem e);
void displayList(sList *l);
int32_t searchElem(sList *l, elem e);
elem getElem(sList *l, int32_t pos);

// externals

// end of list.h
