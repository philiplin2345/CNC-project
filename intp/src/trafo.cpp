#include "StdAfx.h"
#include "..\INC\trafo.h"

#define LENGTH 75 //arm length in mm



int FromMkToRk(double MkPos[3],double* RkPos)
{
	RkPos[0] = LENGTH * cos(MkPos[0] * DEGREE_TO_RADIANS) + LENGTH * cos(MkPos[1] * DEGREE_TO_RADIANS);
	RkPos[1] = LENGTH * sin(MkPos[0] * DEGREE_TO_RADIANS) + LENGTH * sin(MkPos[1] * DEGREE_TO_RADIANS);
	RkPos[2] = MkPos[2];

	return 1;
}

int FromRkToMk(double RkPos[3],double* MkPos)
{
	double theta = atan2(RkPos[1] , RkPos[0]); //angle between the abscissa and the line connecting the origin and the end of the second bar
	double theta1 = (acos((sqrt(RkPos[0] * RkPos[0] + RkPos[1] * RkPos[1])) / (2 * LENGTH)) + atan2(RkPos[1] , RkPos[0]));
	double theta2 = 2 * theta - theta1;
	MkPos[0] = RADIANS_TO_DEGREE * theta2;
	MkPos[1] = RADIANS_TO_DEGREE * theta1;
	MkPos[2] = RkPos[2];
	return 1;
}