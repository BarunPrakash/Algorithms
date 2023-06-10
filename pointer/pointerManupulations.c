/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/


#include <stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include<string.h>

typedef struct CanFrame
{
    uint32_t CANframe_ID;
    unsigned char mess[32];
    uint32_t Ref;
    uint32_t (*splitFrame)(struct CanFrame*);
    struct CanFrame *nodeConnect;
}CanFrame;

typedef struct CANBUS
{
    uint32_t bus_1;
    uint32_t bus_2;
    union
    {
        uint8_t signal1;
        uint8_t signal2;
        uint8_t signal3;
        uint8_t signal4;
    }sig;
    struct
    {
        uint8_t BitControlsa;
        uint8_t BitControlsb;
    }bits;
    uint8_t keptForfutureuse;
}CANBUS;
#if 0
CanFrame CanFrame_1 ,CanFrame_2[5];

CanFrame **CanFrameDPtr=NULL;
CanFrame (*canfd)[5];
CanFrame  *canayp[5];
#endif
//canfd =&CanFrame_2;


void loadSwap( CanFrame *cfptr ,uint32_t FD ,uint32_t  Ref_input )
{
    cfptr->CANframe_ID = FD;
    cfptr->Ref =Ref_input;
    printf("%d\n",cfptr->CANframe_ID);
    printf("%d\n",cfptr->Ref);
    strcpy(cfptr->mess,"TakenCanID");
}

uint32_t bitsExchange(CanFrame *cfptr)
{ uint32_t tempCanFrame;
    tempCanFrame =(cfptr->CANframe_ID ^cfptr->Ref);
    return(tempCanFrame);
}

void store_Inheap(void)
{
    CanFrame *CanFramePtr=NULL;
    CanFramePtr =(CanFrame*)malloc(sizeof(CanFrame));
    CanFramePtr->CANframe_ID =128;
    printf("heap:-%d\n",CanFramePtr->CANframe_ID);
    free(CanFramePtr);
}

void ArryAllocation_2d(void)
{
    int row=2, col=2;
    int *ptr =(int*)malloc(row*col*sizeof(int));
    for(uint8_t count= 0; count<row*col;count++)
    {
        ptr[count]=count;
    }
    for(uint8_t rw=0 ;rw<row ;rw++)
    {
        for(uint8_t cw=0 ;cw<col ;cw++)
        {
            printf(" app2d:-%d",ptr[rw*col+ cw]);
        }
        printf("\n");
    }
}
void ArryAllocation_2d_arryp(void)
{
    int row=2, col=2 ;
    int count=0;
    int *arp[row];
    
    for(uint8_t rw=0 ;rw<row ;rw++)
    {
        arp[rw]=(int*)malloc(col*sizeof(int));
    }
    for(uint8_t rw=0 ;rw<row ;rw++)
    {
        for(uint8_t cw=0 ;cw<col ;cw++)
        {
          arp[rw][col]=++count;
        }
        printf("\n");
    }
      for(uint8_t rw=0 ;rw<row ;rw++)
    {
        for(uint8_t cw=0 ;cw<col ;cw++)
        {
          printf ("arrp:-%d\t",arp[rw][col]);
        }
        printf("\n");
    }
    for(uint8_t rw=0 ;rw<row ;rw++)
    {
        free(arp[rw]);
    }
}

void memoryAlocationUsingDP(void)
{
    int **dptr=NULL;
    int row=2, col=2 ;
    int count=0;
  
     dptr =(int**)malloc(row*sizeof(int));
      for(uint8_t cw=0 ;cw<col ;cw++)
      {
          dptr[cw]=malloc(col*sizeof(int));
      }
     for(uint8_t rw=0 ;rw<row ;rw++)
    {
        for(uint8_t cw=0 ;cw<col ;cw++)
        {
          dptr[rw][col]=++count;
        }
        printf("\n");
    }
     for(uint8_t rw=0 ;rw<row ;rw++)
    {
        for(uint8_t cw=0 ;cw<col ;cw++)
        {
          printf ( "DP-%d",dptr[rw][col]);
        }
        printf("\n");
    }
    for(uint8_t rw=0 ;rw<row ;rw++)
    {
        free(dptr[rw]);
    }
    free( dptr);
}
//void sumof2dArray(uint32_t (*apa)[2] )
//void sumof2dArray(uint32_t apa[][2] )
void sumof2dArray(uint32_t apa[2][2] )
{   
    int row=2, col=2 ;
    uint8_t rw,cw;
     for( rw=0 ;rw<row ;rw++)
    {
        for( cw=0 ;cw<col ;cw++)
        {
          printf ( "apa-%d",apa[rw][cw]);
        }
        printf("\n");
    }
}

void funcTostructManup(void)
{
    int row=2, col=2 ;
    CanFrame CanFrame_1 ,CanFrame_2[5];
    CanFrame *strptr=(CanFrame*)malloc(sizeof(CanFrame));
    CanFrame **CanFrameDPtr=malloc(2*sizeof(CanFrame));
    CanFrame (*canfd)[5];
    CanFrame  *canayp[5];
    strptr->CANframe_ID=1;
    printf("heapStruc:-%d\n",strptr->CANframe_ID);
    for(uint8_t cw=0 ;cw<col ;cw++)
     {
          CanFrameDPtr[cw]=malloc(col*sizeof(CanFrame));
     }
     CanFrameDPtr[0][0].CANframe_ID =5;
     printf("heapStrucDP:-%d\n",CanFrameDPtr[0][0].CANframe_ID);
     
      for(uint8_t rw=0 ;rw<row ;rw++)
    {
        free(CanFrameDPtr[rw]);
    }
    free( CanFrameDPtr);


}
int main()
{
    CanFrame CanFrame_a;
    store_Inheap();
    loadSwap(&CanFrame_a, 102,77);
    CanFrame_a.splitFrame= &bitsExchange;
    CANBUS c1;
    c1.sig.signal4=123;
    printf("sigsignsl:-%d",c1.sig.signal4);
   printf("%d", CanFrame_a.splitFrame(&CanFrame_a));
   
    
    uint32_t arr[5]={1,2,3,4,5};
    uint32_t darr[2][2]={{1,2},{3,4}};
    uint32_t  *ptr =arr;
    unsigned  **ptrD=&ptr;
    unsigned int (*arr1)[5];
    arr1=&arr;
    // ArryAllocation_2d();
   // ArryAllocation_2d_arryp();
    //memoryAlocationUsingDP();
    sumof2dArray(darr);
    funcTostructManup();
    printf("%d",(*arr1)[4]);
    
    #if 0
    printf("%p and %p and %p and %p\n",&arr,arr,ptr,&ptr);
    printf("val:-%d,Add:-%p ,Add&ptr:-%p\n",*ptr,ptr,&ptr);
    printf("Addptr:-%p and %p\n",*ptrD, ptrD);
    printf("sizeof:-%d\n",sizeof(ptr));
    #endif
    //printf("%x",ptr);

    return 0;
}
