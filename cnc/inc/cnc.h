#ifndef _CNC_H_
#define _CNC_H_
#include "..\..\DEC\INC\dec.h"
#include "..\..\fifo\inc\fifo.h"
#include "..\..\MMI\INC\mmi.h"
#include "..\..\INTP\INC\intp.h"
#include "..\..\SYS\INC\sys.h"
#include "..\..\LINK\INC\link.h"



struct CNC_DATA
{
	SYS_DATA sysData;
	MMI_DATA mmiData;
	DEC_DATA decData;
	LINK_DATA linkData;
	INTP_DATA intpData;
};

int cncRtCtl(CNC_DATA *cncDataPtr);
int cncNrtCtl(CNC_DATA *cncDataPtr);
int cncInit(CNC_DATA *cncDataPtr);
int cncReset(CNC_DATA *cncDataPtr);
#endif