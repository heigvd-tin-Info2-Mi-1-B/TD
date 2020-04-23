/**
  \file      TD20200423.c
  \brief     unions
  \author    Pierre BRESSY
  \version   1.0
  \date      2020-03-03 13:41:24
  \details
    
**/

#include "TD20200423.h"

void createMsg(eTypeMsg type, sMsg *m)
{
  switch (type)
  {
  case E_POS:
    m->type = type;
    m->data.pos.x = 1.;
    m->data.pos.y = 2.;
    m->data.pos.z = 3.;
    break;
  case E_GPS:
    m->type = type;
    m->data.gps.numSat = 15;
    m->data.gps.dop = .5;
    break;
  case E_STATUS:
    m->type = type;
    m->data.status.error = true;
    //m->data.status.version = "1.0b"; // NO !!!
    strcpy(m->data.status.version, "1.0b");
    break;
  default:
    puts("Unknonw type");
    break;
  }
}

void displayMsg(sMsg msg)
{
  switch (msg.type)
  {
  case E_POS:
    printf("Message type POSITION\n");
    printf("\tx=%lf\n", msg.data.pos.x);
    printf("\ty=%lf\n", msg.data.pos.y);
    printf("\tz=%lf\n", msg.data.pos.z);
    break;
  case E_GPS:
    printf("Message type GPS\n");
    printf("\tnumSat=%u\n", msg.data.gps.numSat);
    printf("\tdop=%lf\n", msg.data.gps.dop);
    break;
  case E_STATUS:
    printf("Message type STATUS\n");
    printf("\terror=%d\n", msg.data.status.error);
    printf("\tversion=%s\n", msg.data.status.version);
    break;
  default:
    puts("Unknonw type");
    break;
  }
}

int main(int argc, char *argv[])
{
  sMsg m;
  //printf("Size of uData : %lu\n", sizeof(uData));
  //printf("Size of sMsg : %lu\n", sizeof(sMsg));
  createMsg(E_STATUS, &m);
  displayMsg(m);
  return 0;
}
