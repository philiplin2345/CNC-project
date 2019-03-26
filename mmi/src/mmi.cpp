#include <stdafx.h>
#include <string.h>
#include <stdio.h>



#include "..\..\MMI\INC\mmi.h"


extern LINK_DATA *linkDataPtr;


void mmiCtl(MMI_DATA* mmiDataPtr)
{
	mmiMain(mmiDataPtr);
	return;
}

//**********************************************************//
//                                                          //
//**********************************************************//
int mmiInit(MMI_DATA *mmiDataPtr)
{
	if(!mmiDataPtr)
	return 0;
	int i;
	for (i=0;i<3;i++)
	{
		mmiDataPtr->jogDirection[i]=0;
	}
	mmiDataPtr->feedModify = false;
	mmiDataPtr->feedOverride = 100;
	mmiDataPtr->jogCartesian = true;
	mmiDataPtr->fileValid = false;
	mmiDataPtr->homeValid = false;
	mmiDataPtr->jogValid = false;
	mmiDataPtr->wheelValid = false;
	mmiDataPtr->commence = false;
	mmiDataPtr->homeValid = false;
	mmiDataPtr->decError = false;
	mmiDataPtr->mOne = false;
	return 1;
} //mmiInit()
void mmiMain(MMI_DATA* mmiDataPtr)
{
	switch(mmiDataPtr->opMode)
	{
		case MEM_MODE:
			mmiMemMode(mmiDataPtr);
			break;
		case JOG_MODE:
			mmiJogMode(mmiDataPtr);
			break;
		case HOME_MODE:
			mmiHomeMode(mmiDataPtr);
			break;
		case WHEEL_MODE:
			mmiWheelMode(mmiDataPtr);
			break;
	}
	if (mmiDataPtr->feedModify == true)
	{
		linkDataPtr->mmiToSys.feedModify = true;
		linkDataPtr->mmiToSys.feedOverride = mmiDataPtr->feedOverride;
		mmiDataPtr->feedModify = false;
	}
	if (linkDataPtr->sysToMmi.decError == true)
	{
		mmiDataPtr->decError = true;
		mmiDataPtr->decErrorState = linkDataPtr->sysToMmi.decErrorState;
		linkDataPtr->sysToMmi.decError =false;
	}

	return;
}//mmiMain()
void mmiReset(MMI_DATA* mmiDataPtr)
{
	if(!mmiDataPtr)
		return;
	int i;
	for (i=0;i<3;i++)
	{
		mmiDataPtr->jogDirection[i]=0;
	}
	mmiDataPtr->feedModify = false;
	mmiDataPtr->feedOverride = 100;
	mmiDataPtr->jogCartesian = true;
	mmiDataPtr->fileValid = false;
	mmiDataPtr->homeValid = false;
	mmiDataPtr->jogValid = false;
	mmiDataPtr->wheelValid = false;
	mmiDataPtr->commence = false;
	mmiDataPtr->homeValid = false;
	mmiDataPtr->decError = false;
	mmiDataPtr->mOne = false;
	return;
}//mmiReset()
void mmiClose(MMI_DATA* mmiDataPtr)
{
	return;
}//mmiClose()
//**********************************************************//
//                                                          //
//**********************************************************//
void mmiIdle(MMI_DATA *mmiDataPtr)
{
	return;
}//mmiIdle()
void mmiMemMode(MMI_DATA *mmiDataPtr)
{	
	if(mmiDataPtr->fileValid == true)
	{
		linkDataPtr->mmiToSys.fileValid = mmiDataPtr->fileValid;
		linkDataPtr->mmiToSys.opMode=MEM_MODE;
		mmiDataPtr->fileValid = false;
	}
	return;
}
void mmiJogMode(MMI_DATA *mmiDataPtr)
{
	linkDataPtr->mmiToSys.opMode=JOG_MODE;
	if (mmiDataPtr->jogValid == true)
	{
		linkDataPtr->mmiToSys.jogValid = true;
		mmiDataPtr->jogValid = false;
	}
	return;
}
void mmiHomeMode(MMI_DATA *mmiDataPtr)
{
	linkDataPtr->mmiToSys.opMode = HOME_MODE;
	if (mmiDataPtr->homeValid == true)
	{
		linkDataPtr->mmiToSys.homeValid = true;
		mmiDataPtr->homeValid = false;
	}
	return;
}
void mmiWheelMode(MMI_DATA *mmiDataPtr)
{
	linkDataPtr->mmiToSys.opMode = WHEEL_MODE;
	if (mmiDataPtr->wheelValid == true)
	{
		linkDataPtr->mmiToSys.wheelValid = true;
		mmiDataPtr->wheelValid = false;
	}
	return;
}