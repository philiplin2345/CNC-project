#ifndef SYS_H	
#define SYS_H

#include "../../link/inc/link.h"

enum SYS_ST8 
{ 
	SYS_INIT = 0, 
	SYS_MEM, 
	SYS_JOG, 
	SYS_MDI, 
	SYS_WHEEL, 
	SYS_HOME,
	SYS_RESET
};//enum sysst8


struct SYS_DATA
{
	SYS_ST8    sysState;
	MMI2SYS mmiToSys;	
};

void sysInit(SYS_DATA* sysDataPtr);
void sysCtl(SYS_DATA* sysDataPtr);
void sysReset(SYS_DATA* sysDataPtr);
int sysMain(SYS_DATA *sysDataPtr);
int sysInput(SYS_DATA *sysDataPtr);
int sysMem(SYS_DATA *sysDataPtr);
int sysMdi(SYS_DATA *sysDataPtr);
int sysJog(SYS_DATA *sysDataPtr);
int sysWaitAllReset(SYS_DATA *sysDataPtr);
int sysResetStart(SYS_DATA *sysDataPtr);
int sysRestart(SYS_DATA *sysDataPtr);
int sysWheel(SYS_DATA *sysDataPtr);
int sysHome(SYS_DATA *sysDataPtr);


#endif







