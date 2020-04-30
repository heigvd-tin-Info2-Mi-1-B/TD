/**
 * \file TD20200428.h
 * \version 1.0
 * \date 27/02/2020 - 15:33:28
 * \brief header to TD20200428
 */

#pragma once
#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <getopt.h>

// preprocessor symbols

// preprocessor macros

// enumerated types
typedef enum { // binary code for each option
    E_NO_ARG=1<<0,       // binaire : 00000000000000000000000000000001
    E_ARG_HELP=1<<1,     // binaire : 00000000000000000000000000000010
    E_ARG_FILE=1<<2,     // binaire : 00000000000000000000000000000100
    E_ARG_GRAVITY=1<<3,  // binaire : 00000000000000000000000000001000
    E_ARG_BAD_ARG=1<<30, // binaire : 01000000000000000000000000000000
    E_ARG_OK=1<<31,      // binaire : 10000000000000000000000000000000
} eArgCode;

// structured types

// unions types

// functions prototypes
eArgCode processArg(int argc, char *argv[]);

// externals
