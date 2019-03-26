#ifndef  _TRAFO_H_
#define  _TRAFO_H_
#include <math.h>

#define RADIANS_TO_DEGREE 57.29577951
#define DEGREE_TO_RADIANS 0.01745329252

int FromMkToRk(double MkPos[3],double RkPos[3]);
int FromRkToMk(double RkPos[3],double MkPos[3]);
#endif