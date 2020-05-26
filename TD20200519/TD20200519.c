/**
  \file      TD20200519.c
  \brief     table list
  \author    Pierre BRESSY
  \version   1.0
  \date      2020-04-21 13:41:24
  \details
    
**/

#include "TD20200519.h"

int main(int argc, char const *argv[])
{
  sList l;
  int32_t pos = 0;

  initList(&l);

#ifdef LIST_OF_DOUBLE
  insertElem(&l, 1., -1);
  displayList(&l);
  insertElem(&l, 2., -1);
  displayList(&l);
  insertElem(&l, 3., -1);
  displayList(&l);
  insertElem(&l, 4., 1);
  displayList(&l);
#endif
#ifdef LIST_OF_INT32
  insertElem(&l, 1, -1);
  displayList(&l);
  insertElem(&l, 2, -1);
  displayList(&l);
  insertElem(&l, 3, -1);
  displayList(&l);
  insertElem(&l, 4, 1);
  displayList(&l);

  pos = searchElem(&l, 2);
  printf("pos=%d\n", pos);
#endif
#ifdef LIST_OF_POINT2D
  //sPoint2D p1 = {10, 20};
  //insertElem(&l, p1, -1);

  insertElem(&l, (sPoint2D){.row = 0, .col = 0}, -1);
  displayList(&l);
  insertElem(&l, (sPoint2D){.row=1, .col=0}, -1);
  displayList(&l);
  insertElem(&l, (sPoint2D){.row=2, .col=0}, -1);
  displayList(&l);
  insertElem(&l, (sPoint2D){.row=3, .col=0}, -1);
  displayList(&l);
  insertElem(&l, (sPoint2D){.row=4, .col=0}, 0);
  displayList(&l);
#endif


  return 0;
}
