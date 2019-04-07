bool isItendian(void)
{
	uint32_t iVal=1;
	unsigned char *cPtr=(unsigned char*)&iVal;
	if(*cPtr)
		return true;
		
	return false;	
}
 void  readFloatData(void *Vptr ,uint8_t size) 
  {
  	unsigned char *lVtr =(unsigned char*)Vptr;
 	for (uint32_t index=0;index<size;index++)
 	{
 		printf("%x",lVtr[index]);	
	}
 	
 }
  
  **********************************************************/

bool isItendian(void)
{
	uint32_t iVal=1;
	unsigned char *cPtr=(unsigned char*)&iVal;
	if(*cPtr)
		return true;
		
	return false;	
}
/**************************************************************/
 void  readFloatData(void *Vptr ,uint8_t size) 
  {
  	unsigned char *lVtr =(unsigned char*)Vptr;
 	for (uint32_t index=0;index<size;index++)
 	{
 		printf("%x",lVtr[index]);	
	}
 	
 }
 /**************************************************************/
  uint8_t swapeBytes(uint8_t lVal)
  {
  	return((lVal&0x0F<<4)|(lVal&0xF0>>4));
  }
  /************************************************************/
bool isPowOFtwo(uint32_t iNum)
{
	return(iNum&&(!(iNum&iNum-1)));
}
/*****************************************************************/
bool isPowOfFour(uint32_t iNum)
{
	uint8_t count=false;
	if((iNum&&(!(iNum&iNum-1))))
	{
		while(iNum>1)
		{
			iNum>>=1;
			count+=1;
		}
		return(count%2==0)? 1:0;
		
	}
}
/********************************************************/
uint8_t addByone(uint8_t iNum)
{
	return(-(~iNum));	
}

/***************************************************/
uint8_t subByone(uint8_t iNum)
{
	return(~iNum+(iNum<<1));	
}
/****************************************************************/
uint32_t addTwoNum(uint32_t iNumA,uint32_t iNumB)
{
	if(iNumB)
		return iNumA;
	
	addTwoNum(iNumA&iNumB<<1,iNumA^iNumB);	
	
}
/*****************************************************************/
bool isItSame(uint32_t iNumA,uint32_t iNumB)
{
	return (iNumA^iNumB)? false :true;
	
}
