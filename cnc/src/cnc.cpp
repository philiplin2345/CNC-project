#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>


#include "..\..\CNC\INC\cnc.h"


int cncInit(CNC_DATA *cncDataPtr)
{
	mmiInit(&cncDataPtr->mmiData);
	sysInit(&cncDataPtr->sysData);    //empty for now
	intpInit(&cncDataPtr->intpData);
	decInit(&cncDataPtr->decData); 	

	return 1;
}

int cncNrtCtl(CNC_DATA *cncDataPtr)
{
	
    mmiCtl(&cncDataPtr->mmiData);
	sysCtl(&cncDataPtr->sysData);
	decCtl(&cncDataPtr->decData);

	return 1;
}
int  cncRtCtl(CNC_DATA *cncDataPtr)
{
	intpCtl(&cncDataPtr->intpData);
	return 1;
} 
int  cncReset(CNC_DATA *cncDataPtr)
{
	mmiReset(&cncDataPtr->mmiData);
	sysReset(&cncDataPtr->sysData);
	decReset(&cncDataPtr->decData);
	intpReset(&cncDataPtr->intpData);

	return 1;
}