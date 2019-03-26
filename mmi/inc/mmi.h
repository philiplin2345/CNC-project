#ifndef	MMI_H
#define MMI_H

#include "../../link/inc/link.h"


struct MMI_DATA
{
	OP_MODE opMode;
	int     jogDirection[3];	//Axis Button X=[0] , Y=[1] , Z=[2]
	bool    feedModify;
	int     feedOverride;	//0~200 (%)
	bool	fileValid;			//fileName valid or not
	bool    commence;
	bool    jogValid;
	bool    homeValid;
	bool    wheelValid;
	bool    jogCartesian;
	bool    feedHold;
	bool    mOne;
	double  wheelMultiple;


	bool    decError;
	int     decErrorState;
} ;
///////////////////////////////////////////////////////////////////////////////////////////
//                           FUNCTION DEFINE
///////////////////////////////////////////////////////////////////////////////////////////


void mmiCtl(MMI_DATA* mmiDataPtr);
int  mmiInit(MMI_DATA* mmiDataPtr);
void mmiMain(MMI_DATA* mmiDataPtr);
void mmiReset(MMI_DATA* mmiDataPtr);
void mmiClose(MMI_DATA* mmiDataPtr);
void mmiIdle(MMI_DATA *mmiDataPtr);
void mmiMemMode(MMI_DATA *mmiDataPtr);
void mmiJogMode(MMI_DATA *mmiDataPtr);
void mmiHomeMode(MMI_DATA *mmiDataPtr);
void mmiWheelMode(MMI_DATA *mmiDataPtr);


#endif