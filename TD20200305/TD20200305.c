/**
 * \file TD20200305.c
 * \version 1.0
 * \date 25/02/2020 - 15:33:28
 * \brief text file versus binary file
 */

#include "TD20200305.h"

int main(int argc, char *argv[])
{
    eErrorCode returnCode = 0;
#if 0
    returnCode = saveToTextFile();
    returnCode = readFromTextFile();

    returnCode = saveToBinaryFile();
    returnCode = readFromBinaryFile();
#endif

    returnCode = saveTable();
    return returnCode;
}

eErrorCode saveTable(void)
{
    eErrorCode returnCode = 0;
    const char *fileName = "suite.bin";
    FILE *f = NULL;

    int16_t suite[N];
    int ret = 0;
    uint32_t k = 0;

    k = 0;
    suite[k++] = 1;
    suite[k++] = 1;
    for (; k < N; k++)
    {
        suite[k] = suite[k - 1] + suite[k - 2];
        printf("%hd\n", suite[k]);
    }

    f = fopen(fileName, "wb");
    if (f == NULL)
    {
        printf("Error while creating the file %s.\n", fileName);
        returnCode = E_FILE_OPEN;
    }
    if (!returnCode)
    {
        ret = fwrite(suite, sizeof(int16_t), N, f);
        if (ret != N)
        {
            printf("Error while writing data to the file %s.\n", fileName);
            returnCode = E_FILE_WRITE;
        }
    }
    if (0 != fclose(f))
    {
        printf("Error while closing the file %s.\n", fileName);
        returnCode = E_FILE_CLOSE;
    }
    return returnCode;
}
eErrorCode saveToTextFile(void)
{
    eErrorCode returnCode = 0;
    const char *fileName = "data.txt";
    FILE *f = NULL;

    double x = ANGLE;
    double s = sin(x);

    f = fopen(fileName, "w");
    if (f == NULL)
    {
        printf("Error while creating the file %s.\n", fileName);
        returnCode = E_FILE_OPEN;
    }
    if (!returnCode)
    {
        fprintf(f, "%+.3lf\n", x);
        fprintf(f, "%+.3lf\n", s);
    }
    if (0 != fclose(f))
    {
        printf("Error while closing the file %s.\n", fileName);
        returnCode = E_FILE_CLOSE;
    }
    return returnCode;
}

eErrorCode readFromTextFile(void)
{
    eErrorCode returnCode = 0;
    const char *fileName = "data.txt";
    FILE *f = NULL;

    double x = PI / 10.;
    double s = sin(x);
    int ret = 0;

    f = fopen(fileName, "r");
    if (f == NULL)
    {
        printf("Error while opening the file %s.\n", fileName);
        returnCode = E_FILE_OPEN;
    }
    if (!returnCode)
    {
        ret = fscanf(f, "%lf", &x);
        ret += fscanf(f, "%lf", &s);
        if (ret != 2)
        {
            printf("Error while read the file %s.\n", fileName);
            returnCode = E_FILE_READ;
        }
        else
        {
            printf("diff angle=%e\n", x - (ANGLE));
            printf("diff sinus=%e\n", s - sin(ANGLE));
        }
    }
    if (0 != fclose(f))
    {
        printf("Error while closing the file %s.\n", fileName);
        returnCode = E_FILE_CLOSE;
    }
    return returnCode;
}

eErrorCode saveToBinaryFile(void)
{
    eErrorCode returnCode = 0;
    const char *fileName = "data.bin";
    FILE *f = NULL;

    double x = ANGLE;
    double s = sin(x);
    int ret = 0;

    f = fopen(fileName, "wb");
    if (f == NULL)
    {
        printf("Error while creating the file %s.\n", fileName);
        returnCode = E_FILE_OPEN;
    }
    if (!returnCode)
    {
        ret = fwrite(&x, sizeof(double), 1, f);
        ret += fwrite(&s, sizeof(double), 1, f);
        if (ret != 2)
        {
            printf("Error while writing data to the file %s.\n", fileName);
            returnCode = E_FILE_WRITE;
        }
    }
    if (0 != fclose(f))
    {
        printf("Error while closing the file %s.\n", fileName);
        returnCode = E_FILE_CLOSE;
    }
    return returnCode;
}

eErrorCode readFromBinaryFile(void)
{
    eErrorCode returnCode = 0;
    const char *fileName = "data.bin";
    FILE *f = NULL;

    double x = ANGLE;
    double s = sin(x);
    int ret = 0;

    f = fopen(fileName, "rb");
    if (f == NULL)
    {
        printf("Error while opening the file %s.\n", fileName);
        returnCode = E_FILE_OPEN;
    }
    if (!returnCode)
    {
        ret = fread(&x, sizeof(double), 1, f);
        ret += fread(&s, sizeof(double), 1, f);
        if (ret != 2)
        {
            printf("Error while writing data to the file %s.\n", fileName);
            returnCode = E_FILE_WRITE;
        }
        else
        {
            printf("diff angle=%e\n", x - (ANGLE));
            printf("diff sinus=%e\n", s - sin(ANGLE));
        }
    }
    if (0 != fclose(f))
    {
        printf("Error while closing the file %s.\n", fileName);
        returnCode = E_FILE_CLOSE;
    }
    return returnCode;
}
