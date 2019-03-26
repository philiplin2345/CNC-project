#ifndef _LINK_H_
#define _LINK_H_

#include "..\..\fifo\inc\fifo.h"



enum OP_MODE
{
	IDLE_MODE,
	MEM_MODE ,
	MDI_MODE ,
	JOG_MODE ,
	WHEEL_MODE ,
	TEACH_MODE ,
	HOME_MODE
};

struct MMI2SYS
{
	bool fileValid;
	bool jogValid;
	bool wheelValid;
	bool homeValid;
	bool feedModify;
	int feedOverride;
	OP_MODE opMode;

};//mmi2sys

struct SYS2MMI
{
	bool fileValid;
	bool jogValid;
	bool wheelValid;
	bool decError;
	int  decErrorState;
};//sys2mmi

struct SYS2DEC
{
	bool fileValid;
	bool jogValid;
	bool wheelValid;
	bool homeValid;
};//sys2dec

struct DEC2SYS
{
	int errorState;
	bool decError;
};//dec2sys

struct INTP2SYS
{
	int tba;
};//intp2mmi

struct SYS2INTP
{
	int feedOverride;
};//sys2intp

struct DEC2INTP
{
DEC_TO_INTP_FIFO decToIntpFifo;
};

struct LINK_DATA
{
	MMI2SYS mmiToSys;
	SYS2MMI sysToMmi;
	DEC2SYS decToSys;
	SYS2DEC sysToDec;
	INTP2SYS intpToSys;
	SYS2INTP sysToIntp;
	DEC2INTP decToIntp;
};


int linkInit(LINK_DATA* linkDataPtr);
int linkCtl(LINK_DATA *linkDataPtr);
int linkClose(LINK_DATA *linkDataPtr);
int linkMain(LINK_DATA* linkDataPtr);
int linkReset(LINK_DATA* linkDataPtr);

#endif