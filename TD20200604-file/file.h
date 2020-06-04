/**
 * \file file.h
 * \version 1.0
 * \date 27/02/2020 - 15:33:28
 * \brief header to file
 */

#pragma once

#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "list.h"

// preprocessor symbols

// preprocessor macros

// enumerated types

// structured types

// unions types

// functions prototypes
void initFile(sList *l);
void terminateFile(sList *l);
void push(sList *l, elem e);
elem pop(sList *l);

// externals

// end of list.h
