/**
 \file	TD20200220.c
 \brief	argc argv
 \author	Pierre BRESSY
 \version	1.0
 \date	20.02.2010, 13:45:01
 \details
    - basic usage of argc and argv
 **/

#include <stdint.h>
#include <stdio.h>


int main(int argc, const char *argv[]) {

  uint32_t k=0;
    
  printf("argc=%d\n",argc);
  
  for(k=0;k<argc;k++) {
    printf("%s\n",argv[k]);
  }

  return 0;
}




