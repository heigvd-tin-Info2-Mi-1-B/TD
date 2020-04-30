/**
  \file      TD20200428.c
  \brief     getoptions
  \author    Pierre BRESSY
  \version   1.0
  \date      2020-04-21 13:41:24
  \details
    
**/

#include "TD20200428.h"


eArgCode processArg(int argc, char *argv[])
{

  eArgCode arg = 0;
  int o = 0;
  int optIndex = 0;

  struct option long_options[] =
      {
          /* These options set a flag. */
          {"file", required_argument, 0, 'f'},
          {"gravity", required_argument, 0, 'g'},
          {"help", no_argument, 0, 'h'},
          {0, 0, 0, 0}};
  do
  {
    o = getopt_long(argc, argv, "f:g:h", long_options, &optIndex);
    printf("o=%d [%c]\n", o, o);

    // from o, update arg using switch/case
    switch (o)
    {
    case 'h':
      arg |= E_ARG_HELP + E_ARG_OK;
      break;
    case 'f':
      arg |= E_ARG_FILE + E_ARG_OK;
      // recover the filename
      break;
    case 'g':
      arg |= E_ARG_GRAVITY + E_ARG_OK;
      // recover the gravity value
      break;
    case -1: // end of processing
      break;
    default: // '?'
      puts("unknown / missing parameter.");
      arg |= E_ARG_BAD_ARG;
      break;
    }

  } while (o != -1);

  return arg;
}

int main(int argc, char *argv[])
{
  uint32_t k = 0;
  eArgCode arg = 0;

  // display args
  printf("num args=%u\n", argc);
  for (k = 0; k < argc; k++)
  {
    printf("Arg n°%u : [%s]\n", k, argv[k]);
  }
  puts("-----------\n");

  arg = processArg(argc, argv);
  printf("\narg=%04X\n", arg);
  return 0;
}

