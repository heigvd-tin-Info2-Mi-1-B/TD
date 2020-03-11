/**
 * \file TD20200310-1.c
 * \version 1.0
 * \date 25/02/2020 - 15:33:28
 * \brief structured data
 */

#include "TD20200310-1.h"

int main(int argc, char *argv[])
{
    eErrorCode returnCode = 0;
    sData1 d1 = {0};
    uint8_t *ptr = NULL;
    uint32_t k = 0;

    printf("Size of sData1 : %lu bytes.\n", sizeof(sData1));

    d1.a = 0x55;
    d1.b = 0x11223344;
    d1.c = 0xAA;

    ptr = &d1;

    for (k = 0; k < sizeof(sData1); k++, ptr++)
    {
        printf("%02X ", *ptr);
    }

    puts("");

    return returnCode;
}
