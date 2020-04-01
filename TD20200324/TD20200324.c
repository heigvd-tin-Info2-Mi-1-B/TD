/**
  \file      TD20200324.c
  \brief     txt file / dynamic alloc / workd processing
  \author    Pierre BRESSY
  \version   1.0
  \date      2020-03-03 13:41:24
  \details
    
**/

#include "TD20200324.h"

uint32_t wc(char *s)
{

    bool inWord = false;
    uint32_t count = 0;
    uint32_t index = 0;

    while (s[index])
    {
        if (!inWord && !(s[index] == ' ' || s[index] == ',' || s[index] == '.' || s[index] == '\0'))
        {
            count++;
            inWord = true;
        }
        else if (inWord && (s[index] == ' ' || s[index] == ',' || s[index] == '.' || s[index] == '\0'))
        {
            inWord = false;
        }
        index++;
    }
    return count;
}

void ws(char *s)
{

    bool inWord = false;
    uint32_t index = 0;
    char *start = NULL;
    char *stop = NULL;
    char *p = NULL;
    char **word = NULL;

    // allocate a table of string (char*). the number of cells is the number of words in 's' : wc(s)
    word = (char **)calloc(wc(s), sizeof(char *));


    while (s[index])
    {
        if (!inWord && !(s[index] == ' ' || s[index] == ',' || s[index] == '.' || s[index] == '\0'))
        {                      // detect begining of word
            start = s + index; // &s[index];
            inWord = true;
        }
        else if (inWord && (s[index] == ' ' || s[index] == ',' || s[index] == '.' || s[index] == '\0'))
        {
            // detect one char after the end of word
            // ex: "pipo" : start point on 'p', stop point on 'o'
            stop = s + index - 1;
            inWord = false;

            for (p = start; p <= stop; p++)
            {
                putchar(*p);
            }
            puts("");
        }
        index++;
    }
    return;
}

int main(int argc, char *argv[])
{
    eErrorCode returnCode = E_NO_ERROR;
    const char *filename = "text.txt";
    FILE *f = NULL;
    uint32_t fileSize = 0;
    char *text = NULL; // pointer to the dynamic area

    // open the file as a text file
    f = fopen(filename, "r");
    if (NULL == f)
    {
        returnCode = E_FILE_OPEN;
        printf("Error while opening %s\n", filename);
    }
    if (!returnCode)
    {

        // example: 10ème octet depuis le début
        // fseek(f, 10, SEEK_SET);

        // example15ème octet depuis la position courante
        // fseek(f, 15, SEEK_CUR);

        fseek(f, 0, SEEK_END); // set the read pointer to the end
        fileSize = ftell(f);   // read the current position = size of the file
        printf("File size=%u bytes\n", fileSize);

        text = (char *)calloc(fileSize + 1, sizeof(char)); // dynamic allocation
        if (text == NULL)
        {
            printf("Error while allocating %u bytes.\n", fileSize + 1);
            returnCode = E_MALLOC;
        }
        else
        {
            puts("alloc ok");
        }
    }
    if (!returnCode)
    {
        // transfer the text file content to the memory
        rewind(f);
        fgets(text, 1 + fileSize, f);
        printf("[%s]\n", text);
        printf("%lu bytes.\n", strlen(text)); // 1336

        printf("%u words.\n", wc(text)); // 200

        ws(text);
    }

    if (!returnCode)
    {
        if (0 != fclose(f))
        {
            returnCode = E_FILE_CLOSE;
            printf("Error while closing %s\n", filename);
        }
    }

    if (text != NULL)
    {
        free(text);
        text = NULL;
    }
    return returnCode;
}
