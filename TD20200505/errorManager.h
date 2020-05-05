/**
 * \file errorManager.h
 * \version 1.0
 * \date 27/02/2020 - 15:33:28
 * \brief header to errorManager
 */

#pragma once

#include <stdint.h>
#include <stdio.h>

// preprocessor symbols

// preprocessor macros

// enumerated types
typedef enum
{
    E_NO_ERROR=0,
    E_ALLOC_MEM_ERROR,
    E_FILE_ERROR
} eError;

// structured types
// unions types

// functions prototypes
void displayError(eError e);

// externals

// end of errorManager.h
