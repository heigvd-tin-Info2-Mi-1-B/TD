/**
 * \file TD20200305.h
 * \version 1.0
 * \date 25/02/2020 - 15:33:28
 * \brief header to TD20200305
 */

#pragma once
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// preprocessor symbols
#define PI 3.141592654
#define ANGLE (PI / 10.)
#define N 2020

// preprocessor macros

// enumerated types
typedef enum
{
    E_NO_ERROR = 0,
    E_FILE_OPEN,
    E_FILE_CLOSE,
    E_FILE_WRITE,
    E_FILE_READ
} eErrorCode;

// structured types

// unions types

// functions prototypes
eErrorCode saveToTextFile(void);
eErrorCode readFromTextFile(void);
eErrorCode saveToBinaryFile(void);
eErrorCode readFromBinaryFile(void);
eErrorCode saveTable(void);

// externals
