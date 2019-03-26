#include "stdAfx.h"
#include <stdio.h>
#include <stdlib.h>

#include "..\..\fifo\inc\fifo.h"
#include "..\..\DEC\INC\dec.h"
#include "..\..\LINK\INC\link.h"


extern LINK_DATA *linkDataPtr;



int decCtl(DEC_DATA *decDataPtr)
{
	decMain(decDataPtr);
	return 1;
}//decCtl()
int decInit(DEC_DATA  *decDataPtr)
{
	if (!decDataPtr)
	{
		return 0;
	}
	delByteSpace((char *)decDataPtr, sizeof(DEC_DATA));
	decDataPtr ->decState = DEC_IDLE;
	decDataPtr ->errorState = 0;
	decDataPtr ->feedSpeed = FEED;
	return 1;
	
}//decInit()
int decMain(DEC_DATA  *decDataPtr)
{
	switch (decDataPtr->decState)
	{
	case DEC_IDLE:
		decIdle(decDataPtr);
		break;
	case DEC_OPEN_FILE:
		decOpenFile(decDataPtr);
		break;
	case DEC_LOOP:
		decLoop(decDataPtr);
		break;
	case DEC_PRE:
		decPre(decDataPtr);
		break;
	case DEC_ERROR:
		decError(decDataPtr);
		break;
	case DEC_FIFO_FULL:
		endOfLine(decDataPtr);
		break;	
	case DEC_AFTER_WRITE:
		decAfterWrite(decDataPtr);
		break;
	case DEC_RESET:
		decReset(decDataPtr);
		break;
	}

	return 1;
}//decMain()
int decReset(DEC_DATA *decDataPtr)
{
	decDataPtr ->errorState = 0;
	decDataPtr ->feedSpeed = FEED;
	decAfterWrite(decDataPtr);
	for (int a = 0 ; a < FILE_BUFFER_LENGTH ; a++)
	{
		decDataPtr->ncFileBuffer[a] = 0;
	}
	decDataPtr ->decState = DEC_IDLE;
	return 1;
}
//***********************************************************************
// DEC STATE FUNCTIONS
//***********************************************************************
void decIdle(DEC_DATA *decDataPtr)
{ 
	if (linkDataPtr->sysToDec.fileValid == true)
	{
		decDataPtr->fileValid = true;
		decDataPtr->decState =DEC_OPEN_FILE;
		linkDataPtr->sysToDec.fileValid = false;
	}
	if (linkDataPtr->sysToDec.jogValid == true)
	{
		decDataPtr->jogValid = true;
		decDataPtr->decState = DEC_OPEN_FILE;
		linkDataPtr->sysToDec.jogValid = false;
	}
	if (linkDataPtr->sysToDec.homeValid == true)
	{
		decDataPtr->homeValid = true;
		decDataPtr->decState = DEC_OPEN_FILE;
		linkDataPtr->sysToDec.homeValid = false;
	}
	if (linkDataPtr->sysToDec.wheelValid == true)
	{
		decDataPtr->wheelValid = true;
		decDataPtr->decState = DEC_OPEN_FILE;
		linkDataPtr->sysToDec.wheelValid = false;
	}

	return ;
}//decIdle()
void decOpenFile(DEC_DATA  *decDataPtr)
{  
	if((decDataPtr->fileValid == true)||(decDataPtr->jogValid == true)
		||(decDataPtr->homeValid == true)||(decDataPtr->wheelValid == true))
	{
		decDataPtr->filePtr = fopen("../TempNcCode/ncfile.txt", "r");
		decDataPtr->fileValid = false;
		decDataPtr->jogValid = false;
		decDataPtr->homeValid = false;
		decDataPtr->wheelValid = false;
	}
	if (decDataPtr->filePtr == NULL)
	{
		decDataPtr->errorState = 2;
		decDataPtr->decState = DEC_ERROR;
	}
	else
	{ 
		for (int i=0;i<FILE_BUFFER_LENGTH;i++)
		{
			fscanf(decDataPtr->filePtr,"%c", &decDataPtr->ncFileBuffer[i]);
			if(decDataPtr->ncFileBuffer[i] == 0)
				break;
		}
		fclose(decDataPtr->filePtr);
		decDataPtr->decState = DEC_PRE;// data exchange finish, cleared for next exchange
	}

	return ;
}//decOpenFile

void decPre(DEC_DATA  *decDataPtr)
{
	decDataPtr->asciiPtr = decDataPtr->ncFileBuffer;
	decDataPtr->decState = DEC_LOOP;	
	return ;
}//decPre()




void decAfterWrite(DEC_DATA *decDataPtr)
{
	decDataPtr->asciiLinePtr = nullptr;
	decDataPtr->lineNumber   = 0;
	for (int a = 0 ; a<3 ; a++)
	{
		decDataPtr->xyzInput[a] = false;
		decDataPtr->uvwInput[a] = false;
		decDataPtr->ijkInput[a] = false;
		decDataPtr->xyzValue[a] = 0;
		decDataPtr->uvwValue[a] = 0;
		decDataPtr->ijkValue[a] = 0;
	}
	for (int a = 0 ; a < FILE_LINE_LENGTH ; a++)
	{
		decDataPtr->ncLine[a] = 0;
	}
	decDataPtr->radius         = 0;
	decDataPtr->angle          = 0;
	decDataPtr->dwellTime      = 0;
	decDataPtr->oneTimeLineCmd = false;
	decDataPtr->rel            = false;
	decDataPtr->oneTimeStopCmd = false;
	decDataPtr->stopCmd        = STOP_NULL;
	decDataPtr->lineCmd        = NULL_CMD;
	decDataPtr->decState = DEC_LOOP;
	return;
}//decAfterWrite

void decError(DEC_DATA *decDataPtr)
{
	linkDataPtr->decToSys.errorState = decDataPtr->errorState;
	linkDataPtr->decToSys.decError = true;
	decDataPtr->decState = DEC_IDLE;
	//dectommiptr
	return ;
}