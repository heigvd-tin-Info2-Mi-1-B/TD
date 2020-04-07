/**
 * \file TD20200407.h
 * \version 1.0
 * \date 27/02/2020 - 15:33:28
 * \brief header to TD20200324
 */

#pragma once
#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// preprocessor symbols
#define M (80 + 20)

// preprocessor macros
#define SIGN(x) ((x) >= 0 ? (1) : (-1))

// enumerated types
typedef enum
{
    E_NO_ERROR = 0,
    E_FILE_OPEN,
    E_FILE_CLOSE,
    E_FILE_WRITE,
    E_FILE_READ,
    E_MALLOC
} eErrorCode;

// structured types

// unions types

// functions prototypes

// externals
