/**
 * \file TD20200303.c
 * \version 1.0
 * \date 25/02/2020 - 15:33:28
 * \brief text file basics
 */

#include "TD20200303.h"

int main(int argc, char *argv[])
{
    const char *fileName = "data.txt";
    FILE *f = NULL;

    double x = 0.;
    int returnCode = 0;
    int ret = 0;
    long int fileSize;

    char s[MAX_LINE_SIZE];

    f = fopen(fileName, "r");
    if (f == NULL)
    {
        printf("Error while opening the file %s.\n", fileName);
        returnCode = 1;
    }

    if (!returnCode)
    {
        printf("File %s opened successfuly.\n", fileName);

        // read text file with fscanf
        do
        {
            ret = fscanf(f, "%lf", &x);
            if (!feof(f))
            {
                printf("%lf\n", x);
            }
        } while (!feof(f));

        // back to the begining ot the file
        rewind(f);

        // read text file with fgets
        do
        {
            fgets(s, MAX_LINE_SIZE, f);

            // remove the \n if any
            s[strlen(s) - 1] = s[strlen(s) - 1] == '\n' ? 0 : s[strlen(s) - 1];

            if (!feof(f))
            {
                printf("%s\n", s);
            }
        } while (!feof(f));

        // get file size
        fseek(f, 0, SEEK_END);
        fileSize = ftell(f);
        printf("File size: %ld bytes.\n", fileSize);

        if (0 != fclose(f))
        {
            printf("Error while closing the file %s.\n", fileName);
            returnCode = 2;
        }
    }
    return returnCode;
}
