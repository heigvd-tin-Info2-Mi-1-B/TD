/**
  \file      trigo.c
  \brief     multiple file compilation
  \author    Pierre BRESSY
  \version   1.0
  \date      2020-04-21 13:41:24
  \details   trigonometric computation module
    
**/

#include "trigo.h"

sPoint rotate(const sPoint p1, const double angle)
{

    sPoint p2 = {0., 0.};
    double alpha = angle * PI / 180.;

    p2.x = p1.x * cos(alpha) - p1.y * sin(alpha);
    p2.y = p1.x * sin(alpha) + p1.y * cos(alpha);

    return p2;
}

void pointDisplay(const char *name, const sPoint p)
{
    printf("%s: (%+6.3lf,%+6.3lf)\n", name, p.x, p.y);

    return;
}