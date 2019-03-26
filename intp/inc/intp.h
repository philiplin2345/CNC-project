#ifndef _INTP_H_
#define _INTP_H_

#include "../../link/inc/link.h"
#include "..\INC\slope.h"
#include "..\INC\trafo.h"

#define HOME_X_POSITION  75
#define HOME_Y_POSITION  75
#define HOME_Z_POSITION  0
#define HOME_U_POSITION  0
#define HOME_V_POSITION  90
#define HOME_W_POSITION  0

enum INTP_ST8 
{
	INTP_NULL = 0,
	INTP_IDLE,//motion
	INTP_PRE,//motion
	INTP_EXE,//motion
	INTP_CLOSE,//motion
	INTP_DWELL_TIME,//function
	INTP_PROGRAM_END,//function
	INTP_RESET,
	INTP_WAIT_PGM_END,
	INTP_ERROR
};
struct  AXIS_DATA
{
	double  rActValue;
	double	mSetValue;			// setting value in mm	(or degree)
	double	mActValue;			// actual value in mm	(or degree)
	double  remainValue;          // Remainder, in mm (or degree) 
	double  resolution;          //resolution, mm/inc
	double  relInc;             // relative increment
};
struct INTP_DATA
{
	SLOPE_DATA slopeData;
	SLOPE_DATA *slopeDataPtr;

	AXIS_DATA axisData[3];

	double startMkPos[3];    //mk machine coordinates rk relative coordinates
	double endMkPos[3];
	double newMkPos[3];

	double startRkPos[3];
	double endRkPos[3];
	double newRkPos[3];

	double relMkPos[3];
	double relRkPos[3];
	
	double centerPos[3];
	double arcLength;
	double radius;
	double startAngle;
	double endAngle;
	double relAngle;
	double newAngle;

	bool   mThirty;
	bool   mzero;
	bool   feedhold;

	DEC_TO_INTP_FIFO decToIntpData;
	INTP_ST8 intpState;
	int      errorState;
};

int intpInit(INTP_DATA *intpDataPtr);
int intpCtl(INTP_DATA *intpDataPtr);
int intpMain(INTP_DATA *intpDataPtr);
int intpIdle(INTP_DATA *intpDataPtr);
int intpPre(INTP_DATA *intpDataPtr);
int intpExe(INTP_DATA *intpDataPtr);
int intpClose(INTP_DATA *intpDataPtr);
int intpDwellTime(INTP_DATA *intpDataPtr);
int intpProgramEnd(INTP_DATA *intpDataPtr);
int intpReset(INTP_DATA *intpDataPtr);
int realKnl(INTP_DATA *intpDataPtr);
void intpCorrAngle(INTP_DATA *intpDataPtr);
void bubbleSort(double * angleForMk );
#endif