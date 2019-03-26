#ifndef DEC_H	                  //to prevent redefinition 
#define DEC_H

#include "../../link/inc/link.h"
#include <stdio.h>

#define FILENAME_LENGTH		200
#define FILE_LINE_LENGTH	200
#define FILE_BUFFER_LENGTH	20000
#define FEED				20

enum DEC_STATE  //不具有儲存空間 部佔有記憶體 限定只有這些狀態
{
	DEC_IDLE,
	DEC_OPEN_FILE,
	DEC_PRE,
	DEC_LOOP,
	DEC_ERROR,
	DEC_AFTER_WRITE,
	DEC_FIFO_FULL,
	DEC_RESET
};

struct DEC_DATA
{

	DEC_STATE         decState;


	FILE              *filePtr;
	char              ncLine[FILE_LINE_LENGTH];
	char              *asciiPtr;
	char              ncFileBuffer[FILE_BUFFER_LENGTH];
	char              *asciiLinePtr;
	bool              fileValid;
	bool              jogValid;
	bool              homeValid;
	bool              wheelValid;
	PLANE_OF_MOTION   plane;
	int               lineNumber;  // N
	LINE_CMD          lineCmd;     //G00, G06, G07, G04, M30
	STOP_CMD          stopCmd;
	bool              oneTimeLineCmd;
	bool              oneTimeStopCmd;
	bool              rel;     // G91 true: rel, G90 false: abs relative or absolute coordinates


	double		      xyzValue[3];
	bool		      xyzInput[3];

	double		      uvwValue[3];
	bool		      uvwInput[3];

	double		      ijkValue[3];
	bool		      ijkInput[3];
	
	double            radius;
	double            angle;

	double            feedSpeed;  // Feedspeed
	double            dwellTime;

	int			errorState;	//1 = Read File ERROR ;2 = N ERROR; 3 = G ERROR ;4 = M ERROR; 5=F ERROR 6=xyz ERROR 7=uvw ERROR 


};


// DECODER must exclude any syntax error!
// double input, contradictory input,
// unfinished input () check at line end, ...



//********************
//  function define
//********************
int  nfunction       (DEC_DATA *decDataPtr);
int  gFunction       (DEC_DATA *decDataPtr);
int  mFunction       (DEC_DATA* decDataPtr);
int  fFunction       (DEC_DATA *decDataPtr);
int  rFunction       (DEC_DATA *decDataPtr);
int  aFunction       (DEC_DATA *decDataPtr);
int  xyzCoordFunction   (DEC_DATA *decDataPtr);
int  uvwCoordFunction   (DEC_DATA *decDataPtr);
int  ijkCoordFunction   (DEC_DATA *decDataPtr);
int  endOfLine          (DEC_DATA *decDataPtr);

int      decCtl          (DEC_DATA *decDataPtr);
int      decMain         (DEC_DATA *decDataPtr);
int		 decInit         (DEC_DATA *decDataPtr);
void	 decIdle         (DEC_DATA *decDataPtr);
void	 decOpenFile     (DEC_DATA *decDataPtr);
void     decLoop         (DEC_DATA *decDataPtr);
void     decPre          (DEC_DATA *decDataPtr);
void     decError        (DEC_DATA *decDataPtr);
void     decAfterWrite   (DEC_DATA *decDataPtr);
int      decReset        (DEC_DATA *decDataPtr);

bool isDigit(char* asciiPtr);
bool isSpace(char* asciiPtr);
bool isAtofFormat(char* asciiPtr);
int delByteSpace(char  *bytePtr, int size);



#endif
