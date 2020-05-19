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
#include <string.h>

// preprocessor symbols
#define MAX_LIST_SIZE (100)

// preprocessor macros

// enumerated types

// structured types

typedef double elem; // generic type

typedef struct {

    elem element[MAX_LIST_SIZE];
    uint32_t numElem;

} sList;
// unions types

// functions prototypes
void initList(sList *l);
bool isListFull(sList *l);
bool isListEmpty(sList *l);
void insertList(sList *l, elem e, int32_t pos);
// externals

// end of list.h
