#include <stdio.h>
#include "Queue.h"


///////////////////////////////////Test code by zzheng/////////////////////
int main()
{
    ZQueue zzqueue;
    unsigned int i = 0;

    //Test 1
    InitQueue(&zzqueue,10) ;
    printf("InitQueue(&zzqueue,10) \n");
    printf("count:%3d   size:%3d   writeside:%3d   readside:%3d\n",zzqueue.count,zzqueue.size,zzqueue.writeside,zzqueue.readside);

 /*   //Test 2
    InitQueue(&zzqueue,300) ;
    printf("InitQueue(&zzqueue,300) \n");
    printf("count:%3d   size:%3d   writeside:%3d   readside:%3d\n",zzqueue.count,zzqueue.size,zzqueue.writeside,zzqueue.readside);
*/
    //Test 3
    for(i=0;i<0x80000000;i++)
    {
        InQueue(&zzqueue,i);
 //       OutQueue(&zzqueue);
        if(!i%0x80000)
        {
            printf("%d\n",i);
        }
    }
    printf("count:%3d   size:%3d   writeside:%3d   readside:%3d\n",zzqueue.count,zzqueue.size,zzqueue.writeside,zzqueue.readside);
/*
    for(i=0;i<1000;i++)
    {
        printf("%5d",zzqueue.data[i]);
    }
*/
/*
    for(i=0;i<1001;i++)
    {
        printf("%5d",OutQueue(&zzqueue));
    }
*/
    return 0;
}

///////////////////////////////////Test code end by zzheng/////////////////////
