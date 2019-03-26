#ifndef _SLOPE_H_
#define _SLOPE_H_
#include "..\..\DRV\INC\stepMotorDRV.h"

#define   HD_TIMER			0	// motion card timer
								// Form timer interrupt		= 0 (debug)

#define   REAL_SAMPLING_TIME  20      //in milliseconds
#define   ACCELERATION  50     //in mm/s^2
#define   ANGACC 1   // in deg/s^2
#define   GZEROSPEED 30


enum SLOPE_ST8 
{
SLOPE_PRE,
SLOPE_ACC, 
SLOPE_CONST, 
SLOPE_DEC
};

//********************
//  motion card parameters
//********************


//********************
//  acceleration, deceleration planning
//********************
struct SLOPE_DATA
{
	SLOPE_ST8    slopeState; 
	double       sumLength;
	double       residualLength;
	double       instSpeed;   //instantaneous speed
	bool         intpEnd;
	int          accCount;	 // acceleration count
	int          decCount;	 // deceleration count
	int          constCount; // constant count
	double       residualSpeed;  // random rest speed 
	double       vStep;      // acc/dec step
	double       stepDistance; // total acc(dec) distance in a step mm/0.02s
	double       totalDistance;
	double       feedSpeed;
	double       axisVector[3];
	double       accDistance,decDistance,constDistance;
	double       deltaL;
	bool         circular;
};
int slopeMain(SLOPE_DATA *slopeDataPtr);
int slopePre(SLOPE_DATA *slopeDataPtr);
int slopeAcc(SLOPE_DATA *slopeDataPtr);
int slopeConst(SLOPE_DATA *slopeDataPtr);
int slopeDec(SLOPE_DATA *slopeDataPtr);
#endif