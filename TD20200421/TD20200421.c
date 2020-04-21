/**
  \file      TD20200421.c
  \brief     recursivity
  \author    Pierre BRESSY
  \version   1.0
  \date      2020-03-03 13:41:24
  \details
    
**/

#include "TD20200421.h"

uint32_t tp(uint32_t l, uint32_t c)
{
  //printf("l=%u   c=%u\n", l, c);

  return l == c || c == 0 ? 1 : tp(l - 1, c - 1) + tp(l - 1, c);

  /*  if (l == c || c == 0)
    return 1;
  else
    return (tp(l - 1, c - 1) + tp(l - 1, c));*/
}

/*
Triangle de Pascal ligne : 0 à 12 inclus
1
1 1
1 2 1
1 3 3 1
1 4 6 4 1
1 5 10 10 5 1
...
*/
int main(int argc, char *argv[])
{
  uint32_t l = 8;
  uint32_t c = 5;
#if 0
  printf("tp(%u,%u)=%u\n", l, c, tp(l, c));
#else

  for (l = 0; l <= 12; l++)
  {
    for (c = 0; c <= l; c++)
    {
      printf("%4u", tp(l, c));
    }
    puts("");
  }

#endif
  return 0;
}
