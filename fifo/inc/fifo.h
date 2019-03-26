#ifndef _FIFO_H_
#define _FIFO_H_

#include <stdio.h>
#include <stdlib.h>

#include"..\..\link\inc\mutual.h"

#define DEC_TO_INTP_FIFO_SPACE 100

struct FIFO_HEAD
{
	int wrindex;
	int rdindex;
};

struct DEC_TO_INTP_BLOCK
{
	int               lineNumber;  // N
	LINE_CMD          lineCmd;     //G00, M30

	bool              rel;     // G91 true: rel, G90 false: abs relative or absolute coordinates
	PLANE_OF_MOTION   plane;
	STOP_CMD          stopCmd;
	double            feedSpeed;  // Feedspeed

	double		      xyzValue[3];
	bool		      xyzInput[3];

	double		      uvwValue[3];
	bool		      uvwInput[3];

	double		      ijkValue[3];
	bool		      ijkInput[3];

	double            radius;
	double            angle;

	double            dwellTime;
};

struct DEC_TO_INTP_FIFO
{
	FIFO_HEAD			fifoHead;
	bool				vaild[DEC_TO_INTP_FIFO_SPACE];
	DEC_TO_INTP_BLOCK	decToIntpBlock[DEC_TO_INTP_FIFO_SPACE];
};

//********************
//  Declaration of functions
//********************
int decToIntpFifoReset(DEC_TO_INTP_FIFO* decToIntpFifo);
int decToIntpFifoWrite (DEC_TO_INTP_FIFO* Fifo , DEC_TO_INTP_FIFO* Decoder);
int decToIntpFifoRead (DEC_TO_INTP_FIFO* Intp , DEC_TO_INTP_FIFO* Fifo);
#endif