/**
 * \file trigo.h
 * \version 1.0
 * \date 27/02/2020 - 15:33:28
 * \brief header to trigo
 */

#pragma once

#include <stdint.h>
#include <stdio.h>
#include <math.h>

// preprocessor symbols
#define PI (3.141592654)

// preprocessor macros

// enumerated types

// structured types
typedef struct
{
    double x;
    double y;
} sPoint;

// unions types

// functions prototypes
sPoint rotate(const sPoint p1, const double angle);
void pointDisplay(const char *name, const sPoint p);

// externals

// end of errorManager.h
