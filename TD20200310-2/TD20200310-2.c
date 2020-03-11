/**
 * \file TD20200310-2.c
 * \version 1.0
 * \date 25/02/2020 - 15:33:28
 * \brief structured data and binary wave file header
 */

#include "TD20200310-2.h"

int main(int argc, char *argv[])
{
    eErrorCode returnCode = 0;
    FILE *f = NULL;
    const char *filename = "61s.wav";
    sWavHeader header = {0};
    int ret = 0;

    f = fopen(filename, "rb");
    if (NULL == f)
    {
        printf("Error while opening file %s.\n", filename);
        returnCode = E_FILE_OPEN;
    }
    if (!returnCode)
    {
        ret = fread(&header, sizeof(sWavHeader), 1, f);
        if (ret != 1)
        {
            printf("Error while reading file %s.\n", filename);
            returnCode = E_FILE_READ;
        }
        else
        {
            printf("%hu channels.\n", header.format.channel_number);
            printf("%u [Hz].\n", header.format.sample_rate);
        }
    }
    if (!returnCode)
    {
        if (0 != fclose(f))
        {
            printf("Error while closing file %s.\n", filename);
            returnCode = E_FILE_CLOSE;
        }
    }

    return returnCode;
}
