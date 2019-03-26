#include "stdafx.h"
#include "..\INC\fifo.h"
#include "..\..\link\inc\link.h"



int decToIntpFifoWrite (DEC_TO_INTP_FIFO *Fifo , DEC_TO_INTP_FIFO *Decoder)
{
	int wrindex;
	wrindex = Fifo->fifoHead.wrindex;
	if (Fifo->vaild[wrindex] == false)
	{
		Fifo->decToIntpBlock[wrindex].lineNumber = Decoder->decToIntpBlock->lineNumber;
		Fifo->decToIntpBlock[wrindex].lineCmd = Decoder->decToIntpBlock->lineCmd;
		Fifo->decToIntpBlock[wrindex].plane = Decoder->decToIntpBlock->plane;
		Fifo->decToIntpBlock[wrindex].rel = Decoder->decToIntpBlock->rel;
		Fifo->decToIntpBlock[wrindex].feedSpeed = Decoder->decToIntpBlock->feedSpeed;
		Fifo->decToIntpBlock[wrindex].stopCmd = Decoder->decToIntpBlock->stopCmd;
		Fifo->decToIntpBlock[wrindex].dwellTime = Decoder->decToIntpBlock->dwellTime;
		Fifo->decToIntpBlock[wrindex].radius = Decoder->decToIntpBlock->radius;
		Fifo->decToIntpBlock[wrindex].angle = Decoder->decToIntpBlock->angle;
		for (int a=0 ; a<3 ; a++)
		{
			Fifo->decToIntpBlock[wrindex].xyzValue[a] = Decoder->decToIntpBlock->xyzValue[a];
			Fifo->decToIntpBlock[wrindex].xyzInput[a] = Decoder->decToIntpBlock->xyzInput[a];
			Fifo->decToIntpBlock[wrindex].uvwValue[a] = Decoder->decToIntpBlock->uvwValue[a];
			Fifo->decToIntpBlock[wrindex].uvwInput[a] = Decoder->decToIntpBlock->uvwInput[a];
			Fifo->decToIntpBlock[wrindex].ijkValue[a] = Decoder->decToIntpBlock->ijkValue[a];
			Fifo->decToIntpBlock[wrindex].ijkInput[a] = Decoder->decToIntpBlock->ijkInput[a];
		}
		Fifo->vaild[wrindex] = true;
		if (Fifo->fifoHead.wrindex < DEC_TO_INTP_FIFO_SPACE - 1)//0~99 and 1~100
		{
			Fifo->fifoHead.wrindex++;
		}
		else
		{
			Fifo->fifoHead.wrindex = 0;
		}
		return 1;
	} 
	else
	{
		return 0;
	}
}//decToIntpFifoWrite()

int decToIntpFifoRead (DEC_TO_INTP_FIFO *Intp , DEC_TO_INTP_FIFO *Fifo)
{
	int rdindex;
	rdindex = Fifo->fifoHead.rdindex;
	if (Fifo->vaild[rdindex] == true)
	{
		Intp->decToIntpBlock->lineNumber = Fifo->decToIntpBlock[rdindex].lineNumber;
		Intp->decToIntpBlock->lineCmd = Fifo->decToIntpBlock[rdindex].lineCmd;
		Intp->decToIntpBlock->plane = Fifo->decToIntpBlock[rdindex].plane;
		Intp->decToIntpBlock->rel = Fifo->decToIntpBlock[rdindex].rel;
		Intp->decToIntpBlock->feedSpeed = Fifo->decToIntpBlock[rdindex].feedSpeed;
		Intp->decToIntpBlock->stopCmd = Fifo->decToIntpBlock[rdindex].stopCmd;
		Intp->decToIntpBlock->dwellTime = Fifo->decToIntpBlock[rdindex].dwellTime;
		Intp->decToIntpBlock->radius = Fifo->decToIntpBlock[rdindex].radius;
		Intp->decToIntpBlock->angle = Fifo->decToIntpBlock[rdindex].angle;
		for (int a=0 ; a<3 ; a++)
		{
			Intp->decToIntpBlock->xyzValue[a] = Fifo->decToIntpBlock[rdindex].xyzValue[a];
			Intp->decToIntpBlock->xyzInput[a] = Fifo->decToIntpBlock[rdindex].xyzInput[a];
			Intp->decToIntpBlock->uvwValue[a] = Fifo->decToIntpBlock[rdindex].uvwValue[a];
			Intp->decToIntpBlock->uvwInput[a] = Fifo->decToIntpBlock[rdindex].uvwInput[a];
			Intp->decToIntpBlock->ijkValue[a] = Fifo->decToIntpBlock[rdindex].ijkValue[a];
			Intp->decToIntpBlock->ijkInput[a] = Fifo->decToIntpBlock[rdindex].ijkInput[a];
		}
		Fifo->vaild[rdindex] = false;
		if (Fifo->fifoHead.rdindex < DEC_TO_INTP_FIFO_SPACE - 1)
		{
			Fifo->fifoHead.rdindex++;
		}
		else
		{
			Fifo->fifoHead.rdindex = 0;
		}
		return 1;
	} 
	else
	{
		return 0;
	}
}//decToIntpFifoRead()

int decToIntpFifoReset (DEC_TO_INTP_FIFO *Fifo)
{
	for (int i=0 ; i<DEC_TO_INTP_FIFO_SPACE ; i++)
	{
		Fifo->vaild[i] = false;
	}
	Fifo->fifoHead.rdindex = 0;
	Fifo->fifoHead.wrindex = 0;
	return 1;
}//dec to intp fifo reset
