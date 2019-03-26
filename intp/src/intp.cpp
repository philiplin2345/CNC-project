#include <stdafx.h>
#include <windows.h>
#include "..\..\INTP\INC\intp.h"
#include "..\..\LINK\INC\link.h"

#include <math.h>


extern LINK_DATA *linkDataPtr;

int intpInit(INTP_DATA *intpDataPtr)
{	
	if (!intpDataPtr)
	{
		return 0;
	}
	intpDataPtr->intpState = INTP_IDLE;
	intpDataPtr->errorState = 0;

	intpDataPtr->startRkPos[0] = HOME_X_POSITION;
	intpDataPtr->startRkPos[1] = HOME_Y_POSITION;
	intpDataPtr->startRkPos[2] = HOME_Z_POSITION;

	intpDataPtr->endRkPos[0] = HOME_X_POSITION;
	intpDataPtr->endRkPos[0] = HOME_Y_POSITION;
	intpDataPtr->endRkPos[0] = HOME_Z_POSITION;

	intpDataPtr->startMkPos[0] = HOME_U_POSITION;
	intpDataPtr->startMkPos[1] = HOME_V_POSITION;
	intpDataPtr->startMkPos[2] = HOME_W_POSITION;

	intpDataPtr->endMkPos[0] = HOME_U_POSITION;
	intpDataPtr->endMkPos[1] = HOME_V_POSITION;
	intpDataPtr->endMkPos[2] = HOME_W_POSITION;

	intpDataPtr->slopeDataPtr = &intpDataPtr->slopeData;

	// resolution of U axis
	intpDataPtr->axisData[0].resolution = 0.0018;		// 360(degree) / 200000(increment)
	// resolution of V axis
	intpDataPtr->axisData[1].resolution = 0.0018;
	// resolution of W axis
	intpDataPtr->axisData[2].resolution = 0.0025;		// 200(mm) / 80000(increment)
	intpDataPtr->axisData[0].mSetValue = HOME_U_POSITION;
	intpDataPtr->axisData[1].mSetValue = HOME_V_POSITION;
	intpDataPtr->axisData[2].mSetValue = HOME_W_POSITION;


	intpDataPtr->axisData[0].mActValue = HOME_U_POSITION;
	intpDataPtr->axisData[1].mActValue = HOME_V_POSITION;
	intpDataPtr->axisData[2].mActValue = HOME_W_POSITION;

	intpDataPtr->axisData[0].rActValue = HOME_X_POSITION;
	intpDataPtr->axisData[1].rActValue = HOME_Y_POSITION;
	intpDataPtr->axisData[2].rActValue = HOME_Z_POSITION;

	intpDataPtr->arcLength = 0 ;
	intpDataPtr->radius    = 0 ;
	intpDataPtr->startAngle= 0 ;
	intpDataPtr->endAngle  = 0 ;
	intpDataPtr->relAngle  = 0 ;
	intpDataPtr->newAngle  = 0 ;
	intpDataPtr->mzero     = false;
	intpDataPtr->feedhold  = false;

	for(int i=0 ; i<3 ; i++)
	{
		intpDataPtr->axisData[i].relInc = 0;
		intpDataPtr->axisData[i].remainValue = 0.00;
#if HD_TIMER
		putAxisValue(i, intpDataPtr->axisData[i].relInc);
#endif
		intpDataPtr->axisData[i].mActValue = intpDataPtr->axisData[i].mSetValue;
		intpDataPtr->centerPos[i] = 0;
	}
	return 1;
}//intpInit()

int intpCtl(INTP_DATA *intpDataPtr)
{
	intpMain(intpDataPtr);
	return 1;
}//intpCtl()
int intpMain(INTP_DATA *intpDataPtr)
{
	switch(intpDataPtr->intpState)
	{
	case INTP_IDLE:
		intpIdle(intpDataPtr);
		break;
	case INTP_PRE:
		intpPre(intpDataPtr);
		break;
	case INTP_EXE:
		intpExe(intpDataPtr);
		break;
	case INTP_CLOSE:
		intpClose(intpDataPtr);
		break;
	case INTP_DWELL_TIME:
		intpDwellTime(intpDataPtr);
		break;
	case INTP_PROGRAM_END:
		intpProgramEnd(intpDataPtr);
		break;
	case INTP_RESET:
		intpReset(intpDataPtr);
		break;
	case INTP_ERROR:
		break;

	}
	return 1;
}//intpMain()

int intpIdle(INTP_DATA *intpDataPtr)
{
	if (decToIntpFifoRead(&intpDataPtr->decToIntpData, &linkDataPtr->decToIntp.decToIntpFifo))
	{
		if(intpDataPtr->decToIntpData.decToIntpBlock->lineCmd == G04_DWELL)
		{
			Sleep(intpDataPtr->decToIntpData.decToIntpBlock->dwellTime);
		}
		else if (intpDataPtr->decToIntpData.decToIntpBlock->stopCmd == MUST_STOP_CMD)
		{
			intpDataPtr->intpState = INTP_DWELL_TIME;
		}
		else if (intpDataPtr->decToIntpData.decToIntpBlock->stopCmd == ARBITARY_STOP_CMD)
		{
			if (intpDataPtr->mzero == true)
			{
				intpDataPtr->intpState = INTP_DWELL_TIME;
			}
		}
		else
		{		
			intpDataPtr->intpState = INTP_PRE;
			intpDataPtr->mThirty = false;
			if (intpDataPtr->decToIntpData.decToIntpBlock->stopCmd == PROGRAM_END_CMD)
			{
				intpDataPtr->mThirty = true;
				intpDataPtr->intpState = INTP_RESET;
			}
		}
	} 
	else
	{
		intpDataPtr->intpState = INTP_IDLE;
	}
	return 1;
}//intpIdle()

int intpPre(INTP_DATA *intpDataPtr)
{
	for(int i = 0 ; i<3 ; i++)
	{
		intpDataPtr->startMkPos[i] = intpDataPtr->axisData[i].mActValue;
		intpDataPtr->startRkPos[i] = intpDataPtr->axisData[i].rActValue;
	}
	
	if (intpDataPtr->decToIntpData.decToIntpBlock->ijkInput[1] == true||
		intpDataPtr->decToIntpData.decToIntpBlock->ijkInput[2] == true||
		intpDataPtr->decToIntpData.decToIntpBlock->ijkInput[3] == true)
	{
		if (intpDataPtr->feedhold == false)
		{
			for (int i=0 ; i<3 ;i ++ )
			{
				
					intpDataPtr->centerPos[i] = intpDataPtr->decToIntpData.decToIntpBlock->ijkValue[i] + intpDataPtr->startRkPos[i];
				
			}
		}//gets the center position
		intpDataPtr->radius = sqrt(intpDataPtr->decToIntpData.decToIntpBlock->ijkValue[0]*intpDataPtr->decToIntpData.decToIntpBlock->ijkValue[0]
								  +intpDataPtr->decToIntpData.decToIntpBlock->ijkValue[1]*intpDataPtr->decToIntpData.decToIntpBlock->ijkValue[1]
								  +intpDataPtr->decToIntpData.decToIntpBlock->ijkValue[2]*intpDataPtr->decToIntpData.decToIntpBlock->ijkValue[2]);//gets radius			
		switch (intpDataPtr->decToIntpData.decToIntpBlock->plane)
		{		
		case XY_PLANE:
			intpDataPtr->startAngle = atan2(intpDataPtr->startRkPos[1]-intpDataPtr->centerPos[1],intpDataPtr->startRkPos[0]-intpDataPtr->centerPos[0]);
			break;
		case ZX_PLANE:
			intpDataPtr->startAngle = atan2(intpDataPtr->startRkPos[0]-intpDataPtr->centerPos[0],intpDataPtr->startRkPos[2]-intpDataPtr->centerPos[2]);
			break;
		case YZ_PLANE:
			intpDataPtr->startAngle = atan2(intpDataPtr->startRkPos[2]-intpDataPtr->centerPos[2],intpDataPtr->startRkPos[0]-intpDataPtr->centerPos[0]);
			break;
		}//gets the start angle with respect to the center
		if (intpDataPtr->feedhold == false)
		{
			if (intpDataPtr->decToIntpData.decToIntpBlock->rel == true)
			{
				switch (intpDataPtr->decToIntpData.decToIntpBlock->lineCmd)
				{
				case G02_CIRCULARINTPCLOCKWISE:
					intpDataPtr->endAngle = intpDataPtr->startAngle - intpDataPtr->decToIntpData.decToIntpBlock->angle * DEGREE_TO_RADIANS;
					break;
				case G03_CIRCULARINTPCOUNTERCLOCKWISE:
					intpDataPtr->endAngle = intpDataPtr->startAngle + intpDataPtr->decToIntpData.decToIntpBlock->angle * DEGREE_TO_RADIANS;
					break;
				}
			}
			else
			{
				intpDataPtr->endAngle = intpDataPtr->decToIntpData.decToIntpBlock->angle * DEGREE_TO_RADIANS;
			}//gets the absolute end angle

			switch (intpDataPtr->decToIntpData.decToIntpBlock->plane)
			{
			case XY_PLANE:
				intpDataPtr->endRkPos[0] = intpDataPtr->centerPos[0] + intpDataPtr->radius * cos(intpDataPtr->endAngle);
				intpDataPtr->endRkPos[1] = intpDataPtr->centerPos[1] + intpDataPtr->radius * sin(intpDataPtr->endAngle);
				intpDataPtr->endRkPos[2] = intpDataPtr->startRkPos[2] + intpDataPtr->decToIntpData.decToIntpBlock->xyzValue[2];
				break;
			case ZX_PLANE:
				intpDataPtr->endRkPos[0] = intpDataPtr->centerPos[0] + intpDataPtr->radius * sin(intpDataPtr->endAngle);
				intpDataPtr->endRkPos[1] = intpDataPtr->startRkPos[1] + intpDataPtr->decToIntpData.decToIntpBlock->xyzValue[1];
				intpDataPtr->endRkPos[2] = intpDataPtr->centerPos[2] + intpDataPtr->radius * cos(intpDataPtr->endAngle);
				break;
			case YZ_PLANE:
				intpDataPtr->endRkPos[0] = intpDataPtr->startRkPos[0] + intpDataPtr->decToIntpData.decToIntpBlock->xyzValue[0];
				intpDataPtr->endRkPos[1] = intpDataPtr->centerPos[1] + intpDataPtr->radius * cos(intpDataPtr->endAngle);
				intpDataPtr->endRkPos[2] = intpDataPtr->centerPos[2] + intpDataPtr->radius * sin(intpDataPtr->endAngle);
				break;
			}//gets the end rk position
		}// gets end rk end angle
		intpDataPtr->relAngle = intpDataPtr->endAngle - intpDataPtr->startAngle;
		switch (intpDataPtr->decToIntpData.decToIntpBlock->plane)
		{		
		case XY_PLANE:
			intpDataPtr->arcLength = sqrt(intpDataPtr->radius * intpDataPtr->relAngle  *intpDataPtr->radius * intpDataPtr->relAngle
				                         +(intpDataPtr->endRkPos[2] - intpDataPtr->startRkPos[2])*(intpDataPtr->endRkPos[2] - intpDataPtr->startRkPos[2]));
			break;
		case ZX_PLANE:
			intpDataPtr->arcLength = sqrt(intpDataPtr->radius * intpDataPtr->relAngle *intpDataPtr->radius * intpDataPtr->relAngle 
										 +(intpDataPtr->endRkPos[1] - intpDataPtr->startRkPos[1])*(intpDataPtr->endRkPos[1] - intpDataPtr->startRkPos[1]));
			break;
		case YZ_PLANE:
			intpDataPtr->arcLength = sqrt(intpDataPtr->radius * intpDataPtr->relAngle *intpDataPtr->radius * intpDataPtr->relAngle 
										 +(intpDataPtr->endRkPos[0] - intpDataPtr->startRkPos[0])*(intpDataPtr->endRkPos[0] - intpDataPtr->startRkPos[0]));
			break;
		}//gets the absolute start angle

	}//ijk input
	else if ((intpDataPtr->decToIntpData.decToIntpBlock->xyzInput[0] == true)||
			 (intpDataPtr->decToIntpData.decToIntpBlock->xyzInput[1] == true)||
			 (intpDataPtr->decToIntpData.decToIntpBlock->xyzInput[2] == true))
	{
		if (intpDataPtr->decToIntpData.decToIntpBlock->rel == true)
		{
			for (int i = 0; i<3 ; i++)
			{
				if (intpDataPtr->decToIntpData.decToIntpBlock->xyzInput[i] == true)
				{
					intpDataPtr->relRkPos[i] = intpDataPtr->decToIntpData.decToIntpBlock->xyzValue[i];
					intpDataPtr->endRkPos[i] = intpDataPtr->startRkPos[i] + intpDataPtr->relRkPos[i];
				} 
				else
				{
					intpDataPtr->endRkPos[i] = intpDataPtr->startRkPos[i];
					intpDataPtr->relRkPos[i] = 0;
				}
			}
		}//relative xyz input
		else//abs xyz input
		{
			for (int i = 0; i<3; i++)
			{
				if (intpDataPtr->decToIntpData.decToIntpBlock->xyzInput[i] == true)
				{
					intpDataPtr->endRkPos[i] = intpDataPtr->decToIntpData.decToIntpBlock->xyzValue[i];
					intpDataPtr->relRkPos[i] = intpDataPtr->endRkPos[i] - intpDataPtr->startRkPos[i];
				} 
				else
				{
					intpDataPtr->endRkPos[i] = intpDataPtr->startRkPos[i];
					intpDataPtr->relRkPos[i] = 0;
				}
			}
		}//absolute xyz input
		FromRkToMk(intpDataPtr->endRkPos,intpDataPtr->endMkPos);
		for (int i = 0 ; i <3 ; i ++)
		{
			intpDataPtr->relMkPos[i] = intpDataPtr->endMkPos-intpDataPtr->startMkPos;
		}
	}//xyzinput
	else if ((intpDataPtr->decToIntpData.decToIntpBlock->uvwInput[0] == true)||
			 (intpDataPtr->decToIntpData.decToIntpBlock->uvwInput[1] == true)||
			 (intpDataPtr->decToIntpData.decToIntpBlock->uvwInput[2] == true))
	{
		if (intpDataPtr->decToIntpData.decToIntpBlock->rel == true)
		{
			for (int i = 0; i<3 ; i++)
			{
				if (intpDataPtr->decToIntpData.decToIntpBlock->uvwInput[i] == true)
				{
					intpDataPtr->relMkPos[i] = intpDataPtr->decToIntpData.decToIntpBlock->uvwValue[i];
					intpDataPtr->endMkPos[i] = intpDataPtr->startMkPos[i] + intpDataPtr->relMkPos[i];
				} 
				else
				{
					intpDataPtr->endMkPos[i] = intpDataPtr->startMkPos[i];
					intpDataPtr->relMkPos[i] = 0;
				}
			}
		}//relative uvw input
		else//abs input
		{
			for (int i = 0; i<3; i++)
			{
				if (intpDataPtr->decToIntpData.decToIntpBlock->uvwInput[i] == true)
				{
					intpDataPtr->endMkPos[i] = intpDataPtr->decToIntpData.decToIntpBlock->uvwValue[i];
					intpDataPtr->relMkPos[i] = intpDataPtr->endMkPos[i] - intpDataPtr->startMkPos[i];
				} 
				else
				{
					intpDataPtr->endMkPos[i] = intpDataPtr->startMkPos[i];
					intpDataPtr->relMkPos[i] = 0;
				}
			}
		}//absolute uvw input		
		FromMkToRk(intpDataPtr->endMkPos,intpDataPtr->endRkPos);
		for (int i=0 ; i<3 ; i++)
		{
			intpDataPtr->relRkPos[i]= intpDataPtr->endRkPos[i] - intpDataPtr->startRkPos[i];
		}
	}//uvw input
	switch(intpDataPtr->decToIntpData.decToIntpBlock->lineCmd)
	{
	case G00_RAPIDPOSITIONING:
		intpDataPtr->slopeDataPtr->circular = false;
		intpDataPtr->slopeDataPtr->feedSpeed = GZEROSPEED; //10
		for (int i = 0; i < 3 ; i++)
		{
			intpDataPtr->slopeDataPtr->axisVector[i] = intpDataPtr->relMkPos[i];
		}
		intpDataPtr->slopeDataPtr->vStep = ANGACC; //1
		break;
	case G01_LINEARINTP:
		intpDataPtr->slopeDataPtr->circular = false;
		intpDataPtr->slopeDataPtr->feedSpeed = intpDataPtr->decToIntpData.decToIntpBlock->feedSpeed*linkDataPtr->sysToIntp.feedOverride* 0.01;
		for (int i=0; i<3 ; i ++)
		{
			intpDataPtr->slopeDataPtr->axisVector[i] = intpDataPtr->relRkPos[i];
		}
		intpDataPtr->slopeDataPtr->vStep = REAL_SAMPLING_TIME * ACCELERATION * 0.001; //0.001 for transferring ms to s
		if (intpDataPtr->slopeDataPtr->feedSpeed <= intpDataPtr->slopeDataPtr->vStep)//vstep indicates the minimum acceleration in 1 step
		{
			intpDataPtr->slopeDataPtr->vStep = intpDataPtr->slopeDataPtr->feedSpeed;
		}
		break;
	case G02_CIRCULARINTPCLOCKWISE:
	case G03_CIRCULARINTPCOUNTERCLOCKWISE:
		intpDataPtr->slopeDataPtr->circular = true;
		intpDataPtr->slopeDataPtr->feedSpeed = intpDataPtr->decToIntpData.decToIntpBlock->feedSpeed*linkDataPtr->sysToIntp.feedOverride* 0.01;

		intpDataPtr->slopeDataPtr->axisVector[0] = intpDataPtr->arcLength;
		

		if (intpDataPtr->slopeDataPtr->feedSpeed <= intpDataPtr->slopeDataPtr->vStep)//vstep indicates the minimum acceleration in 1 step
		{
			intpDataPtr->slopeDataPtr->vStep = intpDataPtr->slopeDataPtr->feedSpeed;
		}
		intpDataPtr->slopeDataPtr->vStep = ANGACC; //1
		break;
	}//intp pre gives feedspeed and (angular)acceleration per step to the slope module	
	intpDataPtr->slopeDataPtr->sumLength = 0;
	slopeMain(intpDataPtr->slopeDataPtr);
	intpDataPtr->intpState = INTP_EXE;	

	return 1;
}//intpPre()

int intpExe(INTP_DATA *intpDataPtr)
{
	slopeMain(intpDataPtr->slopeDataPtr);
	intpDataPtr->slopeDataPtr->deltaL = intpDataPtr->slopeDataPtr->instSpeed*REAL_SAMPLING_TIME*0.001;
	intpDataPtr->slopeDataPtr->sumLength += intpDataPtr->slopeDataPtr->deltaL;
	switch(intpDataPtr->decToIntpData.decToIntpBlock->lineCmd)
	{
	case G00_RAPIDPOSITIONING:
		for ( int i = 0 ; i < 3 ; i ++)
		{
			intpDataPtr->newMkPos[i] = intpDataPtr->startMkPos[i] + intpDataPtr->relMkPos[i] * intpDataPtr->slopeDataPtr->sumLength/intpDataPtr->slopeDataPtr->totalDistance;
		}
		FromMkToRk(intpDataPtr->newMkPos,intpDataPtr->newRkPos);
		if ((intpDataPtr->newRkPos[0] * intpDataPtr->newRkPos[0] + intpDataPtr->newRkPos[1] * intpDataPtr->newRkPos[1]) >= (150*150))
		{
			intpDataPtr->intpState = INTP_ERROR;
		}
		else
		{		
		realKnl(intpDataPtr);
		}
		break;
	case G01_LINEARINTP:
		for (int i = 0 ; i < 3 ; i ++)
		{
			intpDataPtr->newRkPos[i] = intpDataPtr->startRkPos[i] + intpDataPtr->relRkPos[i] * intpDataPtr->slopeDataPtr->sumLength/intpDataPtr->slopeDataPtr->totalDistance;
		}
		FromRkToMk(intpDataPtr->newRkPos,intpDataPtr->newMkPos);
		if ((intpDataPtr->newRkPos[0] * intpDataPtr->newRkPos[0] + intpDataPtr->newRkPos[1] * intpDataPtr->newRkPos[1]) >= (150*150))
		{
			intpDataPtr->intpState = INTP_ERROR;
		}
		else
		{
			intpCorrAngle(intpDataPtr);
			realKnl(intpDataPtr);
		}
		break;
	case G02_CIRCULARINTPCLOCKWISE:
	case G03_CIRCULARINTPCOUNTERCLOCKWISE:
		intpDataPtr->newAngle = intpDataPtr->startAngle + intpDataPtr->relAngle*intpDataPtr->slopeDataPtr->sumLength/intpDataPtr->slopeDataPtr->totalDistance;
		switch (intpDataPtr->decToIntpData.decToIntpBlock->plane)
		{
		case XY_PLANE:
			intpDataPtr->newRkPos[0] = intpDataPtr->centerPos[0]+ intpDataPtr->radius * cos(intpDataPtr->newAngle);
			intpDataPtr->newRkPos[1] = intpDataPtr->centerPos[1]+ intpDataPtr->radius * sin(intpDataPtr->newAngle);
			intpDataPtr->newRkPos[2] = intpDataPtr->startRkPos[2]+ intpDataPtr->decToIntpData.decToIntpBlock->xyzValue[2]* intpDataPtr->slopeDataPtr->sumLength/intpDataPtr->slopeDataPtr->totalDistance;
			break;
		case ZX_PLANE:
			intpDataPtr->newRkPos[2] = intpDataPtr->centerPos[2]+ intpDataPtr->radius * cos(intpDataPtr->newAngle);
			intpDataPtr->newRkPos[0] = intpDataPtr->centerPos[0]+ intpDataPtr->radius * sin(intpDataPtr->newAngle);
			intpDataPtr->newRkPos[1] = intpDataPtr->startRkPos[1]+ intpDataPtr->decToIntpData.decToIntpBlock->xyzValue[1]* intpDataPtr->slopeDataPtr->sumLength/intpDataPtr->slopeDataPtr->totalDistance;	
			break;
		case YZ_PLANE:
			intpDataPtr->newRkPos[1] = intpDataPtr->centerPos[1]+ intpDataPtr->radius * cos(intpDataPtr->newAngle);
			intpDataPtr->newRkPos[2] = intpDataPtr->centerPos[2]+ intpDataPtr->radius * sin(intpDataPtr->newAngle);
			intpDataPtr->newRkPos[0] = intpDataPtr->startRkPos[0]+ intpDataPtr->decToIntpData.decToIntpBlock->xyzValue[0]* intpDataPtr->slopeDataPtr->sumLength/intpDataPtr->slopeDataPtr->totalDistance;	
			break;
		}
		FromRkToMk(intpDataPtr->newRkPos,intpDataPtr->newMkPos);
		if ((intpDataPtr->newRkPos[0] * intpDataPtr->newRkPos[0] + intpDataPtr->newRkPos[1] * intpDataPtr->newRkPos[1]) >= (150*150))
		{
			intpDataPtr->intpState = INTP_ERROR;
		}
		else
		{
			intpCorrAngle(intpDataPtr);
			realKnl(intpDataPtr);
		}
		break;
	}//slope outputs the instantaneous speed for 0.02sec, for g01 the new coordinates must be transformed into machine coordinates then corrected for the corresponding angles
	if (intpDataPtr->slopeDataPtr->intpEnd == true)
	{
		intpDataPtr->intpState = INTP_CLOSE;
	}
	return 1;
}//intpExe()

int intpClose(INTP_DATA *intpDataPtr)
{
	switch(intpDataPtr->decToIntpData.decToIntpBlock->lineCmd)
	{
	case G00_RAPIDPOSITIONING:
		for (int i = 0 ; i<3 ; i++)
		{
			intpDataPtr->newMkPos[i] = intpDataPtr->endMkPos[i];
		}
		realKnl(intpDataPtr);
		break;
	case G01_LINEARINTP:
	case G02_CIRCULARINTPCLOCKWISE:
	case G03_CIRCULARINTPCOUNTERCLOCKWISE:
		for (int i = 0 ; i<3 ; i++)
		{
			intpDataPtr->newRkPos[i] = intpDataPtr->endRkPos[i];
		}
		FromRkToMk(intpDataPtr->newRkPos, intpDataPtr->newMkPos);
		intpCorrAngle(intpDataPtr);
		realKnl(intpDataPtr);
		break;
	}//when interpolation ends the remainder is given out as a last command
	intpDataPtr->slopeDataPtr->instSpeed = 0;
	intpDataPtr->intpState = INTP_IDLE;
	return 1;
}//intpClose()

int intpDwellTime(INTP_DATA *intpDataPtr)
{
	return 1;
}//intpDwellTime()

int intpProgramEnd(INTP_DATA *intpDataPtr)
{
	return 1;
}//intpProgramEnd()

int intpReset(INTP_DATA *intpDataPtr)
{
	if (!intpDataPtr)
	{
		return 0;
	}
	decToIntpFifoReset(&linkDataPtr->decToIntp.decToIntpFifo);
	if (intpDataPtr->slopeDataPtr->instSpeed >= 0)
	{
		intpDataPtr->slopeDataPtr->slopeState = SLOPE_DEC;
		intpDataPtr->slopeDataPtr->decCount = intpDataPtr->slopeDataPtr->decCount - intpDataPtr->slopeDataPtr->accCount;
		for (;intpDataPtr->slopeDataPtr->instSpeed > 0;)
		{
			slopeMain(intpDataPtr->slopeDataPtr);
			intpDataPtr->slopeDataPtr->deltaL = intpDataPtr->slopeDataPtr->instSpeed*REAL_SAMPLING_TIME*0.001;
			intpDataPtr->slopeDataPtr->sumLength += intpDataPtr->slopeDataPtr->deltaL;
			switch (intpDataPtr->decToIntpData.decToIntpBlock->lineCmd)
			{
			case G00_RAPIDPOSITIONING:
				for ( int i = 0 ; i < 3 ; i ++)
				{
					intpDataPtr->newMkPos[i] = intpDataPtr->startMkPos[i] + intpDataPtr->relMkPos[i] * intpDataPtr->slopeDataPtr->sumLength/intpDataPtr->slopeDataPtr->totalDistance;
				}
					intpCorrAngle(intpDataPtr);
					realKnl(intpDataPtr);
				break;
			case G01_LINEARINTP:
				for (int i = 0 ; i < 3 ; i ++)
				{
					intpDataPtr->newRkPos[i] = intpDataPtr->startRkPos[i] + intpDataPtr->relRkPos[i] * intpDataPtr->slopeDataPtr->sumLength/intpDataPtr->slopeDataPtr->totalDistance;
				}
				FromRkToMk(intpDataPtr->newRkPos,intpDataPtr->newMkPos);
				if ((intpDataPtr->newRkPos[0] * intpDataPtr->newRkPos[0] + intpDataPtr->newRkPos[1] * intpDataPtr->newRkPos[1]) >= (150*150))
				{
					intpDataPtr->intpState = INTP_ERROR;
				}
				else
				{
					intpCorrAngle(intpDataPtr);
					realKnl(intpDataPtr);
				}
				break;
			case G02_CIRCULARINTPCLOCKWISE:
			case G03_CIRCULARINTPCOUNTERCLOCKWISE:
				intpDataPtr->newAngle = intpDataPtr->startAngle + intpDataPtr->relAngle*intpDataPtr->slopeDataPtr->sumLength/intpDataPtr->slopeDataPtr->totalDistance;
				switch (intpDataPtr->decToIntpData.decToIntpBlock->plane)
				{
				case XY_PLANE:
					intpDataPtr->newRkPos[0] = intpDataPtr->centerPos[0]+ intpDataPtr->radius * cos(intpDataPtr->newAngle);
					intpDataPtr->newRkPos[1] = intpDataPtr->centerPos[1]+ intpDataPtr->radius * sin(intpDataPtr->newAngle);
					intpDataPtr->newRkPos[2] = intpDataPtr->startRkPos[2]+ intpDataPtr->decToIntpData.decToIntpBlock->xyzValue[2]* intpDataPtr->slopeDataPtr->sumLength/intpDataPtr->slopeDataPtr->totalDistance;
					break;
				case ZX_PLANE:
					intpDataPtr->newRkPos[2] = intpDataPtr->centerPos[2]+ intpDataPtr->radius * cos(intpDataPtr->newAngle);
					intpDataPtr->newRkPos[0] = intpDataPtr->centerPos[0]+ intpDataPtr->radius * sin(intpDataPtr->newAngle);
					intpDataPtr->newRkPos[1] = intpDataPtr->startRkPos[1]+ intpDataPtr->decToIntpData.decToIntpBlock->xyzValue[1]* intpDataPtr->slopeDataPtr->sumLength/intpDataPtr->slopeDataPtr->totalDistance;	
					break;
				case YZ_PLANE:
					intpDataPtr->newRkPos[1] = intpDataPtr->centerPos[1]+ intpDataPtr->radius * cos(intpDataPtr->newAngle);
					intpDataPtr->newRkPos[2] = intpDataPtr->centerPos[2]+ intpDataPtr->radius * sin(intpDataPtr->newAngle);
					intpDataPtr->newRkPos[0] = intpDataPtr->startRkPos[0]+ intpDataPtr->decToIntpData.decToIntpBlock->xyzValue[0]* intpDataPtr->slopeDataPtr->sumLength/intpDataPtr->slopeDataPtr->totalDistance;	
					break;
				}
				FromRkToMk(intpDataPtr->newRkPos,intpDataPtr->newMkPos);
				if ((intpDataPtr->newRkPos[0] * intpDataPtr->newRkPos[0] + intpDataPtr->newRkPos[1] * intpDataPtr->newRkPos[1]) >= (150*150))
				{
					intpDataPtr->intpState = INTP_ERROR;
				}
				else
				{
					intpCorrAngle(intpDataPtr);
					realKnl(intpDataPtr);
				}
				break;
			}
		}
	}

	intpDataPtr->slopeDataPtr->slopeState = SLOPE_PRE;
	intpDataPtr->intpState = INTP_IDLE;
	intpDataPtr->errorState = 0;
	intpDataPtr->mzero = false;
	intpDataPtr->arcLength = 0 ;
	intpDataPtr->radius    = 0 ;
	intpDataPtr->startAngle= 0 ;
	intpDataPtr->endAngle  = 0 ;
	intpDataPtr->relAngle  = 0 ;
	intpDataPtr->newAngle  = 0 ;
	intpDataPtr->feedhold  = false;

	for (int a = 0 ; a < 3 ; a ++)
	{
		intpDataPtr->startRkPos[a] = intpDataPtr->axisData[a].rActValue;
		intpDataPtr->endRkPos[a] = intpDataPtr->axisData[a].rActValue;
		intpDataPtr->newRkPos[a] = intpDataPtr->axisData[a].rActValue;
		intpDataPtr->startMkPos[a] = intpDataPtr->axisData[a].mActValue;
		intpDataPtr->endMkPos[a] = intpDataPtr->axisData[a].mActValue;
		intpDataPtr->newMkPos[a] = intpDataPtr->axisData[a].mActValue;
		intpDataPtr->relRkPos[a] = 0;
		intpDataPtr->relMkPos[a] = 0;
		intpDataPtr->centerPos[a]= 0;
	}
	return 1;
}//intpReset()

int intpRefresh(INTP_DATA *intpDataPtr)
{
	return 1;
}//intpRefresh

int realKnl(INTP_DATA *intpDataPtr)
{
	for (int i = 0 ; i <3 ; i ++)
	{
		intpDataPtr->axisData[i].mSetValue = intpDataPtr->newMkPos[i];
		// relInc = (set - oldSet) / resolution
		double relDistance = intpDataPtr->axisData[i].mSetValue - intpDataPtr->axisData[i].mActValue;
		// 	calculate relative increment
		if (relDistance != 0)
		{
			intpDataPtr->axisData[i].relInc = (int)(relDistance / intpDataPtr->axisData[i].resolution);

			// ================== remain value ================== //
			intpDataPtr->axisData[i].remainValue += ( relDistance - intpDataPtr->axisData[i].relInc * intpDataPtr->axisData[i].resolution);
			// remainValue > 0 && resolution <= remainValue
			if( intpDataPtr->axisData[i].resolution <= intpDataPtr->axisData[i].remainValue  )
			{
				intpDataPtr->axisData[i].relInc++;
				intpDataPtr->axisData[i].remainValue -= intpDataPtr->axisData[i].resolution;
			}
			// remainValue < 0 && resolution <= (-1)*remainValue
			else if( intpDataPtr->axisData[i].resolution <= (-1)*intpDataPtr->axisData[i].remainValue )
			{
				intpDataPtr->axisData[i].relInc--;
				intpDataPtr->axisData[i].remainValue += intpDataPtr->axisData[i].resolution;
			}
			// ================================================== //
		}
		else 
			intpDataPtr->axisData[i].relInc = 0;
	}
	for (int i = 0 ; i<3 ; i++)
	{
#if HD_TIMER
		putAxisValue(i, intpDataPtr->axisData[i].relInc);
#endif
		intpDataPtr->axisData[i].mActValue = intpDataPtr->axisData[i].mSetValue;
	}
	double axisDataMk[3];
	axisDataMk[0] = intpDataPtr->axisData[0].mActValue;
	axisDataMk[1] = intpDataPtr->axisData[1].mActValue;
	axisDataMk[2] = intpDataPtr->axisData[2].mActValue;
	double axisDataRk[3];
	FromMkToRk(axisDataMk,axisDataRk);
	for ( int i = 0 ; i < 3 ; i ++)
	{	
		intpDataPtr->axisData[i].rActValue = axisDataRk[i];
	}
	return 1;
}

void intpCorrAngle(INTP_DATA *intpDataPtr)
{
	double minAxisDisplacement[2];
	int multiple[4];
	double angleForMk[3];
	multiple[0] = (int)(intpDataPtr->axisData[0].mActValue/360);
	angleForMk[0] = abs(intpDataPtr->newMkPos[0] + 360 - (intpDataPtr->axisData[0].mActValue - 360 * multiple[0]));
	angleForMk[1] = abs(intpDataPtr->newMkPos[0] - (intpDataPtr->axisData[0].mActValue - 360 * multiple[0]));
	angleForMk[2] = abs(intpDataPtr->newMkPos[0] - 360 - (intpDataPtr->axisData[0].mActValue - 360 * multiple[0]));
	bubbleSort(angleForMk);

	minAxisDisplacement[0] = angleForMk[2];
	multiple[1] = (int)(intpDataPtr->axisData[1].mActValue/360);
	angleForMk[0] = abs(intpDataPtr->newMkPos[0] + 360 - (intpDataPtr->axisData[1].mActValue - 360 * multiple[1]));
	angleForMk[1] = abs(intpDataPtr->newMkPos[0] - (intpDataPtr->axisData[1].mActValue - 360 * multiple[1]));
	angleForMk[2] = abs(intpDataPtr->newMkPos[0] - 360 - (intpDataPtr->axisData[1].mActValue - 360 * multiple[1]));
	bubbleSort(angleForMk);
	minAxisDisplacement[1] = angleForMk[2];

	if(minAxisDisplacement[1] < minAxisDisplacement[0])
	{
		double temp;
		temp = intpDataPtr->newMkPos[0];
		intpDataPtr->newMkPos[0] = intpDataPtr->newMkPos[1];
		intpDataPtr->newMkPos[1] = temp;
	}
	multiple[2] = (int) ((abs(intpDataPtr->newMkPos[0] - intpDataPtr->axisData[0].mActValue) - 300)/360);
	multiple[3] = (int) ((abs(intpDataPtr->newMkPos[1] - intpDataPtr->axisData[1].mActValue) - 300)/360);
	//u axis
	if (intpDataPtr->newMkPos[0] - intpDataPtr->axisData[0].mActValue >= 300)
	{
		intpDataPtr->newMkPos[0] -= 360 * (1 + multiple[2] );
	}
	else if (intpDataPtr->newMkPos[0] - intpDataPtr->axisData[0].mActValue <= -300)
	{
		intpDataPtr->newMkPos[0] += 360 * (1 + multiple[2] );
	}
	//v axis
	if (intpDataPtr->newMkPos[1] - intpDataPtr->axisData[1].mActValue >= 300)
	{
		intpDataPtr->newMkPos[1] -= 360 * (1 + multiple[3] );
	}
	else if (intpDataPtr->newMkPos[1] - intpDataPtr->axisData[1].mActValue <= -300)
	{
		intpDataPtr->newMkPos[1] += 360 * (1 + multiple[3] );
	}

	return;
}//intpCorrAngle

void bubbleSort(double * angleForMk )
{
	for (int i = 0 ; i < 2 ; i ++)
	{
		for (int j= i + 1 ; j < 3 ; j++)
		{
			if (angleForMk[i] < angleForMk[j])
			{
				double temp;
				temp = angleForMk[i];
				angleForMk[i] = angleForMk[j];
				angleForMk[j] = temp;
			}
		}
	}
}//bubble sort for sorting the angle