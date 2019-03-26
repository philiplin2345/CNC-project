#include "stdafx.h"
#include "..\INC\slope.h"
#include <math.h>

int slopeMain(SLOPE_DATA *slopeDataPtr)
{
	switch (slopeDataPtr->slopeState)
	{
	case SLOPE_PRE:
		slopePre(slopeDataPtr);
		break;
	case SLOPE_ACC:
		slopeAcc(slopeDataPtr);
		break;
	case SLOPE_CONST:
		slopeConst(slopeDataPtr);
		break;
	case SLOPE_DEC:
		slopeDec(slopeDataPtr);
		break;
	}
	return 1;
}
int slopePre(SLOPE_DATA *slopeDataPtr)
{
	slopeDataPtr->intpEnd = false;
	slopeDataPtr->instSpeed = 0;
	slopeDataPtr->stepDistance = slopeDataPtr->vStep*REAL_SAMPLING_TIME*0.001;
	if (slopeDataPtr->circular == false)
	{	
	slopeDataPtr->totalDistance = sqrt( slopeDataPtr->axisVector[0]*slopeDataPtr->axisVector[0]
									   +slopeDataPtr->axisVector[1]*slopeDataPtr->axisVector[1]
									   +slopeDataPtr->axisVector[2]*slopeDataPtr->axisVector[2]);
	}
	else
	{
		slopeDataPtr->totalDistance = slopeDataPtr->axisVector[0];
	}
	slopeDataPtr->accCount = (int)(slopeDataPtr->feedSpeed/slopeDataPtr->vStep);
	slopeDataPtr->decCount = slopeDataPtr->accCount;
	slopeDataPtr->accDistance = 0.5 * (slopeDataPtr->stepDistance * (slopeDataPtr->accCount + 1) * slopeDataPtr->accCount);
	slopeDataPtr->decDistance = slopeDataPtr->accDistance;
	slopeDataPtr->constDistance = slopeDataPtr->totalDistance - 2*slopeDataPtr->accDistance;
	slopeDataPtr->constCount = (int)(slopeDataPtr->constDistance/(slopeDataPtr->accCount*slopeDataPtr->stepDistance)); //s/v=t
	slopeDataPtr->residualLength = slopeDataPtr->constDistance - slopeDataPtr->stepDistance*slopeDataPtr->accCount*slopeDataPtr->constCount;
	slopeDataPtr->residualSpeed = slopeDataPtr->residualLength / (REAL_SAMPLING_TIME *1000);

	slopeDataPtr->slopeState = SLOPE_ACC;
	return 1;
}
int slopeAcc(SLOPE_DATA *slopeDataPtr)
{
	slopeDataPtr->instSpeed += slopeDataPtr->vStep;
	slopeDataPtr->accCount--;
	double x = slopeDataPtr->sumLength + slopeDataPtr->instSpeed*REAL_SAMPLING_TIME*0.001;
	if (x >= slopeDataPtr->totalDistance)
	{
		slopeDataPtr->intpEnd = true;
		slopeDataPtr->instSpeed = 0;
		slopeDataPtr->slopeState = SLOPE_PRE;
	}
	if (slopeDataPtr->sumLength >= (0.5*slopeDataPtr->totalDistance))
	{
		slopeDataPtr->instSpeed -= (2* slopeDataPtr->vStep); // an increment was added at the start of the function but we found out half of the length has passed so we subtract it back
		slopeDataPtr->decCount = slopeDataPtr->decCount - slopeDataPtr->accCount - 2;
		slopeDataPtr->residualSpeed = 0;
		slopeDataPtr->slopeState = SLOPE_DEC;
	}
	else if ( slopeDataPtr->accCount <= 0)
	{
		slopeDataPtr->slopeState = SLOPE_CONST;
	}
	return 1;
}

int slopeConst(SLOPE_DATA *slopeDataPtr)
{
	slopeDataPtr->constCount--;
	if (slopeDataPtr->constCount<=0)
	{
		slopeDataPtr->slopeState = SLOPE_DEC;
	}
	return 1;
}

int slopeDec(SLOPE_DATA *slopeDataPtr)
{
	if ((slopeDataPtr->residualSpeed - slopeDataPtr->instSpeed)<= slopeDataPtr->vStep && (slopeDataPtr->residualSpeed - slopeDataPtr->instSpeed)>0)
	{
		slopeDataPtr->instSpeed = slopeDataPtr->residualSpeed;
		slopeDataPtr->residualSpeed = 0;
	}
	else
	{
		slopeDataPtr->instSpeed = slopeDataPtr->decCount * slopeDataPtr->vStep;
		slopeDataPtr->decCount--;
	}
	double x = slopeDataPtr->sumLength + slopeDataPtr->instSpeed*REAL_SAMPLING_TIME*0.001;
	if (x >= slopeDataPtr->totalDistance)
	{
		slopeDataPtr->intpEnd = true;
		slopeDataPtr->instSpeed = 0;
		slopeDataPtr->slopeState = SLOPE_PRE;
	}
	if (slopeDataPtr->decCount <=0)
	{
		slopeDataPtr->intpEnd = true;
		slopeDataPtr->slopeState = SLOPE_PRE;
	}
	return 1;
}

