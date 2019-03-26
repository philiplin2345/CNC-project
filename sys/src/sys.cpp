#include "stdafx.h"



#include "..\..\SYS\INC\sys.h"



extern LINK_DATA *linkDataPtr;

void sysInit(SYS_DATA* sysDataPtr)
{
	linkDataPtr->sysToIntp.feedOverride = 100;
	sysDataPtr->mmiToSys.feedModify = false;
	sysDataPtr->mmiToSys.fileValid = false;
	sysDataPtr->mmiToSys.homeValid = false;
	sysDataPtr->mmiToSys.jogValid = false;
	sysDataPtr->mmiToSys.wheelValid = false;
	return;
}
void sysCtl(SYS_DATA* sysDataPtr)
{
	sysMain(sysDataPtr);
	return;
}
void sysReset(SYS_DATA* sysDataPtr)
{
	sysDataPtr->mmiToSys.feedModify = false;
	sysDataPtr->mmiToSys.fileValid = false;
	sysDataPtr->mmiToSys.homeValid = false;
	sysDataPtr->mmiToSys.jogValid = false;
	sysDataPtr->mmiToSys.wheelValid = false;
	return;
}
int sysMain(SYS_DATA *sysDataPtr)
{
	sysInput(sysDataPtr);

	switch(sysDataPtr->sysState)
	{
	case SYS_INIT:
		sysInit(sysDataPtr);
		break;
	case SYS_MEM:
		sysMem(sysDataPtr);
		break;
	case SYS_JOG:
		sysJog(sysDataPtr);
		break;
	case SYS_MDI:
		sysMdi(sysDataPtr);
		break;
	case SYS_WHEEL:
		sysWheel(sysDataPtr);
		break;
	case SYS_HOME:
		sysHome(sysDataPtr);
		break;
	case SYS_RESET:
		sysReset(sysDataPtr);
		break;

	}

	return 1;
}
int sysInput(SYS_DATA *sysDataPtr)
{
	if(linkDataPtr->mmiToSys.fileValid == true)
    {
		sysDataPtr->mmiToSys.fileValid=linkDataPtr->mmiToSys.fileValid;
		linkDataPtr->mmiToSys.fileValid = false;
	}
	if (linkDataPtr->mmiToSys.feedModify == true)
	{
		sysDataPtr->mmiToSys.feedOverride = linkDataPtr->mmiToSys.feedOverride;
		linkDataPtr->sysToIntp.feedOverride = sysDataPtr->mmiToSys.feedOverride;
		linkDataPtr->mmiToSys.feedModify = false;
	}
	if (linkDataPtr->decToSys.decError == true)
	{
		linkDataPtr->sysToMmi.decError = true;
		linkDataPtr->sysToMmi.decErrorState = linkDataPtr->decToSys.errorState;
		linkDataPtr->decToSys.decError = false;
	}
	if (linkDataPtr->mmiToSys.jogValid == true)
	{
		sysDataPtr->mmiToSys.jogValid = true;
		linkDataPtr->mmiToSys.jogValid = false;
	}
	if (linkDataPtr->mmiToSys.homeValid == true)
	{
		sysDataPtr->mmiToSys.homeValid = true;
		linkDataPtr->mmiToSys.homeValid = false;
	}
	if (linkDataPtr->mmiToSys.wheelValid == true)
	{
		sysDataPtr->mmiToSys.wheelValid = true;
		linkDataPtr->mmiToSys.wheelValid = false;
	}
	sysDataPtr->mmiToSys.opMode = linkDataPtr->mmiToSys.opMode;
	switch (sysDataPtr->mmiToSys.opMode)
	{
		case MEM_MODE:
			sysDataPtr->sysState = SYS_MEM;			
			break;
		case MDI_MODE:
			sysDataPtr->sysState = SYS_MDI;
			break;
		case JOG_MODE:
			sysDataPtr->sysState = SYS_JOG;
			break;
		case HOME_MODE:
			sysDataPtr->sysState = SYS_HOME;
			break;
		case WHEEL_MODE:
			sysDataPtr->sysState = SYS_WHEEL;
			break;
	}
	return 1;
}//sysInput()
int sysMem(SYS_DATA *sysDataPtr)
{
	if (sysDataPtr->mmiToSys.fileValid == true)
	{
		linkDataPtr->sysToDec.fileValid = true;
		sysDataPtr->mmiToSys.fileValid = false;
	}
	return 1;
}//sysMem()
int sysMdi(SYS_DATA *sysDataPtr)
{
	if (sysDataPtr->mmiToSys.fileValid == true)
	{
		linkDataPtr->sysToDec.fileValid = true;
		sysDataPtr->mmiToSys.fileValid = false;
	}
	return 1;
}
int sysJog(SYS_DATA *sysDataPtr)
{
	if (sysDataPtr->mmiToSys.jogValid == true)
	{
		linkDataPtr->sysToDec.jogValid = true;
		sysDataPtr->mmiToSys.jogValid = false;
	}
	return 1;
}//sysJog
int sysWaitAllReset(SYS_DATA *sysDataPtr)
{
	return 1;
}//sysw8AllReset()
int sysResetStart(SYS_DATA *sysDataPtr)
{
	return 1;
}//sysResetStart
int sysRestart(SYS_DATA *sysDataPtr)
{
	return 1;
}//sysRestart
int sysWheel(SYS_DATA *sysDataPtr)
{
	if (sysDataPtr->mmiToSys.wheelValid == true)
	{
		linkDataPtr->sysToDec.wheelValid = true;
		sysDataPtr->mmiToSys.wheelValid = false;
	}
	return 1;
}//sysWheel
int sysHome(SYS_DATA *sysDataPtr)
{
	if (sysDataPtr->mmiToSys.homeValid == true)
	{
		linkDataPtr->sysToDec.homeValid = true;
		sysDataPtr->mmiToSys.homeValid = false;
	}
	return 1;
}//sysHome