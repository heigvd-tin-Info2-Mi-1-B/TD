/**
  \file      errorManager.c
  \brief     multiple file compilation
  \author    Pierre BRESSY
  \version   1.0
  \date      2020-04-21 13:41:24
  \details   error management module
    
**/

#include "errorManager.h"


void displayError(eError e)
{
    printf("[errorManager.c | display] e=%d\n",e);
    switch(e) {
        case E_NO_ERROR:
            puts("NO ERROR");
            break;
        case E_ALLOC_MEM_ERROR:
            puts("ERROR memory allocation");
            break;
        case E_FILE_ERROR:
            puts("ERROR file");
            break;
        default:
            puts("UNKNONW ERROR");
            break;
        }
    return;
}

