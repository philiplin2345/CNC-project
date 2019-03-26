#include "stdAfx.h"

#include "..\..\fifo\inc\fifo.h"
#include "..\..\DEC\INC\dec.h"
#include "..\..\LINK\INC\link.h"
#include <stdio.h>
#include <stdlib.h>

extern LINK_DATA *linkDataPtr;


//***********************************************************************
//N G F¡@ENDOFLINEFUNCTIONS
//***********************************************************************
int nFunction(DEC_DATA *decDataPtr)
{
	bool nResult;
	int  nTempData;
	decDataPtr->asciiLinePtr++; //was at N ++ to the digits
	while (isSpace(decDataPtr->asciiLinePtr))
	{
		decDataPtr->asciiLinePtr++;
	}
	nResult = isDigit(decDataPtr->asciiLinePtr);

	if (nResult == true)
	{
		nTempData = atoi(decDataPtr->asciiLinePtr);
		while (isDigit(decDataPtr->asciiLinePtr))
		{
			decDataPtr->asciiLinePtr++;
		}
		decDataPtr->lineNumber = nTempData;
	}
	else
	{
		decDataPtr->errorState = 1;
		decDataPtr->decState = DEC_ERROR;
	}
	return 1;

}//nFunction

int gFunction(DEC_DATA *decDataPtr)
{
	bool    gResult;
	int     gTempData;
	decDataPtr->asciiLinePtr++;                              //pass the first char 'G'
	while (isSpace(decDataPtr->asciiLinePtr))
	{
		decDataPtr->asciiLinePtr++;
	}
	gResult = isDigit(decDataPtr->asciiLinePtr);

	if (gResult == true)
	{
		gTempData = atoi(decDataPtr->asciiLinePtr);
		while (isDigit(decDataPtr->asciiLinePtr))
		{
			decDataPtr->asciiLinePtr++;
		}

		switch(gTempData)
		{
		case 0:
			if (decDataPtr->oneTimeLineCmd == false)
			{
				decDataPtr->lineCmd        = G00_RAPIDPOSITIONING;
				decDataPtr->oneTimeLineCmd = true;
			}
			else
			{
				decDataPtr->errorState     = 3;
				decDataPtr->decState = DEC_ERROR;
			}
			break;
		case 1:
			if (decDataPtr->oneTimeLineCmd == false)
			{
				decDataPtr->lineCmd        = G01_LINEARINTP;
				decDataPtr->oneTimeLineCmd = true;
			}
			else
			{
				decDataPtr->errorState     = 3;
				decDataPtr->decState = DEC_ERROR;
			}
			break;
		case 2:
			if (decDataPtr->oneTimeLineCmd == false)
			{
				decDataPtr->lineCmd        = G02_CIRCULARINTPCLOCKWISE;
				decDataPtr->oneTimeLineCmd = true;
			}
			else
			{
				decDataPtr->errorState     = 3;
				decDataPtr->decState = DEC_ERROR;
			}
			break;
		case 3:
			if (decDataPtr->oneTimeLineCmd == false)
			{
				decDataPtr->lineCmd        = G03_CIRCULARINTPCOUNTERCLOCKWISE;
				decDataPtr->oneTimeLineCmd = true;
			}
			else
			{
				decDataPtr->errorState     = 3;
				decDataPtr->decState = DEC_ERROR;
			}
			break;
		case 4:
			if (decDataPtr->oneTimeLineCmd == false)
			{
				decDataPtr->lineCmd        = G04_DWELL;
				decDataPtr->oneTimeLineCmd = true;
				while (isSpace(decDataPtr->asciiLinePtr))
				{
					decDataPtr->asciiLinePtr++;
				}
				if (isDigit(decDataPtr->asciiLinePtr)==false)
				{
					decDataPtr->dwellTime = 5000;
				}
				else
				{
					decDataPtr->dwellTime = atof(decDataPtr->asciiLinePtr);
					while (isDigit(decDataPtr->asciiLinePtr))
					{
						decDataPtr->asciiLinePtr++;
					}
				}
			}
			else
			{
				decDataPtr->errorState     = 3;
				decDataPtr->decState = DEC_ERROR;
			}
			break;
		case 17:
			decDataPtr->plane          = XY_PLANE;
			break;
		case 18:
			decDataPtr->plane          = ZX_PLANE;
			break;
		case 19:
			decDataPtr->plane          = YZ_PLANE;
			break;
		case 90:
			decDataPtr->rel            = false;
			break;
		case 91:
			decDataPtr->rel            = true;
			break;
		default:
			break;
		}
	}
	else
	{
		decDataPtr->errorState = 3;
		decDataPtr->decState   = DEC_ERROR;
	}

	return 1;
}//gFunction()
int mFunction(DEC_DATA* decDataPtr)
{
	bool mResult;
	int  mTempData;
	decDataPtr->asciiLinePtr++;
	while (isSpace(decDataPtr->asciiLinePtr))
	{
		decDataPtr->asciiLinePtr++;
	}
	mResult = isDigit(decDataPtr->asciiLinePtr);

	if (mResult == true)
	{
		mTempData = atoi(decDataPtr->asciiLinePtr);
		while(isDigit(decDataPtr->asciiLinePtr))
		{
			decDataPtr->asciiLinePtr++;
		}
		switch (mTempData)
		{
		case 0:
			decDataPtr->stopCmd        = MUST_STOP_CMD;
			decDataPtr->oneTimeStopCmd = true;
			break;
		case 1:
			decDataPtr->stopCmd        = ARBITARY_STOP_CMD;
			decDataPtr->oneTimeStopCmd = true;
			break;
		case 30:
			decDataPtr->stopCmd        = PROGRAM_END_CMD;
			decDataPtr->oneTimeStopCmd = true;
			break;
		default:
			decDataPtr->errorState     = 4;
			decDataPtr->decState       = DEC_ERROR;
			break;
		}
	}
	else
	{
		decDataPtr->errorState = 4;
		decDataPtr->decState   = DEC_ERROR;
	}
	return 1;
}//mFunction()

int fFunction(DEC_DATA *decDataPtr)
{
	bool fResult;
	double  fTempData;
	decDataPtr->asciiLinePtr++;
	while (isSpace(decDataPtr->asciiLinePtr))
	{
		decDataPtr->asciiLinePtr++;
	}
	fResult = isAtofFormat(decDataPtr->asciiLinePtr);

	if (fResult == true)
	{
		fTempData = atof(decDataPtr->asciiLinePtr);
		while (isAtofFormat(decDataPtr->asciiLinePtr))
		{
			decDataPtr->asciiLinePtr++;
		}
		decDataPtr->feedSpeed = fTempData;
	}
	else
	{
		decDataPtr->errorState = 5;
		decDataPtr->decState   = DEC_ERROR;
	}
	return 1;
}//fFunction

int rFunction(DEC_DATA *decDataPtr)
{
	bool rResult;
	double  rTempData;
	decDataPtr->asciiLinePtr++;
	while (isSpace(decDataPtr->asciiLinePtr))
	{
		decDataPtr->asciiLinePtr++;
	}
	rResult = isAtofFormat(decDataPtr->asciiLinePtr);

	if (rResult == true)
	{
		rTempData = atof(decDataPtr->asciiLinePtr);
		while (isAtofFormat(decDataPtr->asciiLinePtr))
		{
			decDataPtr->asciiLinePtr++;
		}
		decDataPtr->radius = rTempData;
	}
	else
	{
		decDataPtr->errorState = 9;
		decDataPtr->decState   = DEC_ERROR;
	}
	return 1;
}//rFunction

int aFunction(DEC_DATA *decDataPtr)
{
	bool aResult;
	double  aTempData;
	decDataPtr->asciiLinePtr++;
	while (isSpace(decDataPtr->asciiLinePtr))
	{
		decDataPtr->asciiLinePtr++;
	}
	aResult = isAtofFormat(decDataPtr->asciiLinePtr);

	if (aResult == true)
	{
		aTempData = atof(decDataPtr->asciiLinePtr);
		while (isAtofFormat(decDataPtr->asciiLinePtr))
		{
			decDataPtr->asciiLinePtr++;
		}
		decDataPtr->angle = aTempData;
	}
	else
	{
		decDataPtr->errorState = 10;
		decDataPtr->decState   = DEC_ERROR;
	}
	return 1;
}//aFunction

int xyzCoordFunction(DEC_DATA *decDataPtr)
{
	bool xyzResult;
	int  xyzTempData;

	switch (*decDataPtr->asciiLinePtr)
	{
	case 'x':
	case 'X':
		decDataPtr->xyzInput[0] = true;
		xyzTempData = 0;
		break;
	case 'y':
	case 'Y':
		decDataPtr->xyzInput[1] = true;
		xyzTempData = 1;
		break;
	case 'z':
	case 'Z':
		decDataPtr->xyzInput[2] = true;
		xyzTempData = 2;
		break;
	default:
		break;
	}
	decDataPtr->asciiLinePtr++;
	while (isSpace(decDataPtr->asciiLinePtr))
	{
		decDataPtr->asciiLinePtr++;
	}
	xyzResult = isAtofFormat(decDataPtr->asciiLinePtr);
	if(xyzResult == true)
	{
		decDataPtr->xyzValue[xyzTempData] = atof(decDataPtr->asciiLinePtr);
		while(isAtofFormat(decDataPtr->asciiLinePtr))
		{
			decDataPtr->asciiLinePtr++;
		}
	}
	else
	{
		decDataPtr ->errorState	= 6;
		decDataPtr ->decState	= DEC_ERROR;
	}
	return 1;
}//xyzCoordFunction()

int uvwCoordFunction(DEC_DATA *decDataPtr)
{
	bool uvwResult;
	int  uvwTempData;

	switch (*decDataPtr->asciiLinePtr)
	{
	case 'u':
	case 'U':
		decDataPtr->uvwInput[0] = true;
		uvwTempData = 0;
		break;
	case 'v':
	case 'V':
		decDataPtr->uvwInput[1] = true;
		uvwTempData = 1;
		break;
	case 'w':
	case 'W':
		decDataPtr->uvwInput[2] = true;
		uvwTempData = 2;
		break;
	default:
		break;
	}
	decDataPtr->asciiLinePtr++;
	while (isSpace(decDataPtr->asciiLinePtr))
	{
		decDataPtr->asciiLinePtr++;
	}
	uvwResult = isAtofFormat(decDataPtr->asciiLinePtr);
	if(uvwResult == true)
	{
		decDataPtr->uvwValue[uvwTempData] = atof(decDataPtr->asciiLinePtr);
		while(isAtofFormat(decDataPtr->asciiLinePtr))
		{
			decDataPtr->asciiLinePtr++;
		}
	}
	else
	{
		decDataPtr ->errorState	= 7;
		decDataPtr ->decState	= DEC_ERROR;
	}
	return 1;
}//uvwCoordFunction()

int ijkCoordFunction(DEC_DATA *decDataPtr)
{
	bool ijkResult;
	int  ijkTempData;

	switch (*decDataPtr->asciiLinePtr)
	{
	case 'i':
	case 'I':
		decDataPtr->ijkInput[0] = true;
		ijkTempData = 0;
		break;
	case 'j':
	case 'J':
		decDataPtr->ijkInput[1] = true;
		ijkTempData = 1;
		break;
	case 'k':
	case 'K':
		decDataPtr->ijkInput[2] = true;
		ijkTempData = 2;
		break;
	default:
		break;
	}
	decDataPtr->asciiLinePtr++;
	while (isSpace(decDataPtr->asciiLinePtr))
	{
		decDataPtr->asciiLinePtr++;
	}
	ijkResult = isAtofFormat(decDataPtr->asciiLinePtr);
	if(ijkResult == true)
	{
		decDataPtr->ijkValue[ijkTempData] = atof(decDataPtr->asciiLinePtr);
		while(isAtofFormat(decDataPtr->asciiLinePtr))
		{
			decDataPtr->asciiLinePtr++;
		}
	}
	else
	{
		decDataPtr ->errorState	= 8;
		decDataPtr ->decState	= DEC_ERROR;
	}
	return 1;
}//ijkCoordFunction()

int endOfLine(DEC_DATA *decDataPtr)
{
	if (decDataPtr->decState == DEC_ERROR)
	{
		return 1;
	}
	DEC_TO_INTP_FIFO decToIntpLocal;
	decToIntpLocal.decToIntpBlock->lineCmd = decDataPtr->lineCmd;
	decToIntpLocal.decToIntpBlock->plane = decDataPtr->plane;
	decToIntpLocal.decToIntpBlock->rel = decDataPtr->rel;
	decToIntpLocal.decToIntpBlock->feedSpeed = decDataPtr->feedSpeed;
	decToIntpLocal.decToIntpBlock->stopCmd = decDataPtr->stopCmd;
	decToIntpLocal.decToIntpBlock->dwellTime = decDataPtr->dwellTime;
	decToIntpLocal.decToIntpBlock->radius = decDataPtr->radius;
	decToIntpLocal.decToIntpBlock->angle  = decDataPtr->angle;
	for (int a=0 ; a<3 ; a++)
	{
		decToIntpLocal.decToIntpBlock->xyzValue[a] = decDataPtr->xyzValue[a];
		decToIntpLocal.decToIntpBlock->xyzInput[a] = decDataPtr->xyzInput[a];
		decToIntpLocal.decToIntpBlock->uvwValue[a] = decDataPtr->uvwValue[a];
		decToIntpLocal.decToIntpBlock->uvwInput[a] = decDataPtr->uvwInput[a];
		decToIntpLocal.decToIntpBlock->ijkValue[a] = decDataPtr->ijkValue[a];
		decToIntpLocal.decToIntpBlock->ijkInput[a] = decDataPtr->ijkInput[a];
	}
	if (decToIntpFifoWrite(&linkDataPtr->decToIntp.decToIntpFifo, &decToIntpLocal))
	{
		decDataPtr->decState = DEC_AFTER_WRITE;
	} 
	else
	{
		decDataPtr->decState = DEC_FIFO_FULL;
	}
	return 1;

} //endOfLine()

void decLoop(DEC_DATA *decDataPtr)
{
	for (int i = 0;; i++)
	{
		decDataPtr->ncLine[i] = *decDataPtr->asciiPtr;
		decDataPtr->asciiPtr++;
		if (decDataPtr->ncLine[i] == 10 || decDataPtr->ncLine[i] == 0)
		{
			break;
		}

	}
	if (decDataPtr->ncLine[0] == 0)
	{
		decDataPtr->decState = DEC_RESET;
		return;
	}
	decDataPtr->asciiLinePtr = decDataPtr->ncLine;
	for(int i = 0;;i++)
	{
		switch(*decDataPtr->asciiLinePtr)
		{
		case' ':
			decDataPtr->asciiLinePtr++; //++ to move the pointer to the next variable in code
			break;
		case'N':
		case'n':
			nFunction(decDataPtr);
			break;
		case'G':
		case'g':
			gFunction(decDataPtr);
			break;
		case'M':
		case'm':
			mFunction(decDataPtr);
			break;
		case'F':
		case'f':
			fFunction(decDataPtr);
			break;
		case'R':
		case'r':
			rFunction(decDataPtr);
			break;
		case'A':
		case'a':
			aFunction(decDataPtr);
			break;
		case'X':
		case'x':
		case'Y':
		case'y':
		case'Z':
		case'z':
			xyzCoordFunction(decDataPtr);
			break;
		case'u':
		case'U':
		case'v':
		case'V':
		case'w':
		case'W':
			uvwCoordFunction(decDataPtr);
			break;
		case'i':
		case'I':
		case'j':
		case'J':
		case'k':
		case'K':
			ijkCoordFunction(decDataPtr);
			break;
		case'\0': //end of file
		case'\n': //new line
			endOfLine(decDataPtr);
			return;
		default:
			decDataPtr->asciiLinePtr++; //++ to move the pointer to the next variable in code		
		}
	}
	return ;
}//decLoop()
//***********************************************************************
//UTILITY FUNCTIONS
//***********************************************************************
int delByteSpace(char  *bytePtr, int size)
{
	int i;

	for(i =0; i< size; i++)
	{
		*bytePtr = 0;  //byte to byte to clear memory
		bytePtr++;
	}

	return 1;
}//decInitdelByteSpace()
bool isDigit(char* asciiPtr)
{
	if (*asciiPtr >= '0' && *asciiPtr <= '9')
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool isSpace(char* asciiPtr)
{
	if (*asciiPtr == ' ')
{
	return true;
}
else
{
	return false;
}
}
bool isAtofFormat(char* asciiPtr)
{
	if ((*asciiPtr >= '0' && *asciiPtr <= '9')
		|| (*asciiPtr == '+') || (*asciiPtr == '-') 
		|| (*asciiPtr == '.') || (*asciiPtr == 'E') 
		|| (*asciiPtr == 'e'))
	{
		return true;
	}
	else
	{
		return false;
	}
}

