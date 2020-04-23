/**
 * \file TD20200423.h
 * \version 1.0
 * \date 27/02/2020 - 15:33:28
 * \brief header to TD20200423
 */

#pragma once
#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

// preprocessor symbols
#define VERSION_LENGTH (10)

// preprocessor macros

// enumerated types
typedef enum
{
    E_POS = 1,
    E_GPS,
    E_STATUS,
} eTypeMsg;

// structured types
typedef struct
{
    double x;
    double y;
    double z;
} sPosition;

typedef struct
{
    uint32_t numSat;
    double dop;
} sGPS;

typedef struct
{
    bool error;
    char version[VERSION_LENGTH];
} sStatus;

// unions types
typedef union {
    sPosition pos;
    sGPS gps;
    sStatus status;
} uData;


// compound structured types
typedef struct {

    eTypeMsg type;
    uData data;

} sMsg;

// functions prototypes

// externals
