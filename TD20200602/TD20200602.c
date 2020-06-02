/**
  \file      TD20200602.c
  \brief     table list dynamic size
  \author    Pierre BRESSY
  \version   1.0
  \date      2020-04-21 13:41:24
  \details
    
**/

#include "TD20200602.h"

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
  insertElem(&l, 2, -1);
  insertElem(&l, 3, -1);
  insertElem(&l, 4, -1);
  insertElem(&l, 5, -1);
  insertElem(&l, 6, -1);
  insertElem(&l, 7, -1);
  insertElem(&l, 8, -1);
  insertElem(&l, 9, -1);
  insertElem(&l, 10, -1);
  insertElem(&l, 11, -1);
  insertElem(&l, 12, -1);
  insertElem(&l, 13, -1);
  insertElem(&l, 14, -1);
  displayList(&l);


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

  elem e;
  e = getElem(&l, -1);
  displayElem(e);
#endif

  puts("");
  return 0;
}
