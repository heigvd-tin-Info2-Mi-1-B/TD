/**
 * \file matrix.h
 * \version 1.0
 * \date 27/02/2020 - 15:33:28
 * \brief header to matrix
 */

#pragma once

#include <stdint.h>
#include <stdio.h>

// preprocessor symbols
//#define MATRIX (1)

// preprocessor macros

// enumerated types

// structured types
typedef struct {
    uint32_t numRows;
    uint32_t numCols;
    double *m;
} sMatrix;
// unions types

// functions prototypes

// externals

// end of matrix.h
