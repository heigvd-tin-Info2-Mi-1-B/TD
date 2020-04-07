/**
  \file      TD20200407.c
  \brief     preprocessing
  \author    Pierre BRESSY
  \version   1.0
  \date      2020-03-03 13:41:24
  \details
    
**/

#include "TD20200407.h"

int main(int argc, char *argv[])
{
    eErrorCode returnCode = E_NO_ERROR;

    int x = 3 * M;
    printf("x=%d \n", x);

    int k = -32;
    int sk = SIGN(k);
    printf("k=%d    sign=%d\n", k, sk);
    char c = -65;
    int sc = SIGN(c);
    printf("c=%d    sign=%d\n", c, sc);

    //int m = MAX2(48, 27);
    //printf("MAX2 m=%d\n", m);
    //m = MAX3(48, 27, 300);
    //printf("MAX3 m=%d\n", m);
    return returnCode;
}
