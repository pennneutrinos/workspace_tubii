/*
 * tubiiClocks.h
 *
 *  Created on: Mar 20, 2015
 *      Author: Ian
 */
#include "tubiiUtil.h"

#ifndef CLOCKS_H_
#define CLOCKS_H_

void *MappedClocksBaseAddress;

int clockReset(int clk_choice)
{
  if(clk_choice==1 || clk_choice==0){
	mWriteReg(MappedClocksBaseAddress, RegOffset0, clk_choice);
  }
  else{
    Log(DEBUG, "TUBii: Invalid clock choice. Choose 0 or 1.");
	sprintf(tubii_err, "TUBii: Invalid clock choice. Choose 0 or 1.");
	return -1;
  }

  return 0;
}

int clockStatus()
{
  return mReadReg(MappedClocksBaseAddress, RegOffset1);
}

// DELETE THIS FUNCTION
int clockDebug()
{
  u32 BaseAddress= COUNTDEBUG_BASEADDR;
  u32 HighAddress= COUNTDEBUG_HIGHADDR;
  void *MappedBaseAddress= MemoryMapping(BaseAddress,HighAddress);

  printf("%x\n",mReadReg(MappedBaseAddress, RegOffset0));

  munmap((void*)MappedBaseAddress, (HighAddress-BaseAddress));
  return 0;
}

#endif /* CLOCKS_H_ */
