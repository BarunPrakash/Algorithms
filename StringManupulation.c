/**************************************************
impliment 
strcmp done
strlen done
strstr ,stchr
memcopy ,memmove,strcpy ,strncpy done 

reverse done
pelidrom
swape
printf
strtok







*******************************************************/

int selfDefined_strcmp(char *strA ,char *strB)
{
	
	uint8_t indexA;
	uint8_t indexB;
	
		for(;strA[indexA]&&strB[indexB];indexA++,indexB++)
		{
			
			if(strA[indexA]==strB[indexB] || strA[indexA]==strB[indexB]^32)
				continue;
			else
			break;	
		}
		
	
		if(strA[indexA]==strB[indexB])
		{
		
	    	return 0;
	    	
	    }
		
		else
		{
			if(strA[indexA]<strB[indexB])
			return 1;
			else
			return -1;
			
			
		
		}
	
	
		
}
/**************************************************************************/

int selfDefined_strcmp2(char *strA ,char *strB)
{
	
	//uint8_t indexA;
	//uint8_t indexB;
	
		for(;*strA&&*strB;)
		{
			
			if((*strA==*strB )|| (*strA==*strB^32))
			{
			
				strA+=1;
				strA+=1;
				continue;
			}
			else
			break;	
		}
		
	
		if(*strA==*strB)
		{
		
	    	return 0;
	    	
	    }
		
		else
		{
			if(*strA<*strB)
			return 1;
			else
			return -1;
			
			
		
		}
	
	
		
}
/************************************************************/

int countLeng(char *str )
{
	uint8_t count=0;
	for(;*str;count++,str++);
	return (count);
	
}
/******************************************/

int findPos(char *str )
{
	uint8_t count=0;
	for(;*str;count++,str++)
	{
      if(*str=='r')	
      	break;
    }
	return (count+1);
	
}
/*************************************************/
int selfDefined_strstr(const char *strArr,const char *strSearch)
{
		
	uint8_t indexA=0;
	uint8_t indexB=0;
//	for(;)
	
	
}
/**********************************************/
void  selfDefined_strcpy( char *strA, char *strB,const uint8_t strBsize)
{
		
	uint8_t indexA=0;
	uint8_t indexB=0;
//	printf("%s\n",strB);
	for(;*strB && indexA<strBsize;)
	{
		
	//	printf("Hi\n");
	//	strA[indexB] =strB[indexB];
			*strA =*strB;
	//	printf("%c",strA[indexA]);
		strA+=1;
		strB+=1;
		indexA++;
	}
//	strA[strBsize] ='\0';
	//	printf("%s\n",strA);
	
	
}
/********************************************/
void selfDefined_memcpy(void *dest ,void *source ,uint32_t size )
{
	uint32_t index=0;
	char *ldest =(char*)dest;
	char *lsource=(char*)source;
	for(;index<size;index++)
	{
		ldest[index]=lsource[index];
		
	}
}
/****************************************/

void selfDefined_memmove(void *dest ,void *source ,uint32_t size )
{
	uint32_t index=0;
	char *ldest =(char*)dest;
	char *lsource=(char*)source;
	char *cptr= new char[size];
	for(;index<size;index++)
	{
		cptr[index]=lsource[index];
		
	}
		for(index=0;index<size;index++)
	{
		ldest[index]=cptr[index];
		
	}
	delete []cptr;
}
/*******************************************/

void reverseString(char *str)
{
	if(*str)
	reverseString(str+1);
	printf("%c",*str+32);
}
/******************************/
bool isItPelidrom(char *str, uint8_t intsize,uint8_t lastIndex )
{
	
	if((str[intsize]==str[lastIndex])&&lastIndex/2<lastIndex+1)
		return true;
	isItPelidrom(str,intsize+1, lastIndex-1 );
}
/****************************************************************/
void swapeString(char **strA, char **strB)
{
	char *cTemp =*strA;
	*strA =*strB;
	*strB=cTemp;
	
}
/*****************************************************************/
int SelfDefined_strcmp(char *a, char *b) 
{ 
  return (*a == *b && *b == '\0')? 0 : (*a == *b)? my_strcmp(++a, ++b): 1; 
}  
/***********************************************************************/
void selfDefined_strcat(char *dest, char *src) 
{ 
  //(*dest)? my_strcat(++dest, src): (*dest++ = *src++)? my_strcat(dest, src): 0 ; 
} 
/********************************************************************************/
char *removeDefinedSpaces(char *str) 
{ 
    int i = 0, j = 0; 
    while (str[i]) 
    { 
        if (str[i] != ' ') 
           str[j++] = str[i]; 
        i++; 
    } 
    str[j] = '\0'; 
    return str; 
}
/******************************************************************/
void Paternsearch(char* pat, char* txt) 
{ 
    int M = strlen(pat); 
    int N = strlen(txt); 
  
    
    for (int i = 0; i <= N - M; i++) { 
        int j; 
  
        /* For current index i, check for pattern match */
        for (j = 0; j < M; j++) 
            if (txt[i + j] != pat[j]) 
                break; 
  
        if (j == M) // if pat[0...M-1] = txt[i, i+1, ...i+M-1] 
            cout << "Pattern found at index "
                 << i << endl; 
    } 
}
