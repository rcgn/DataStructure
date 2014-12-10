#include <stdio.h>
#include "Stack.h"


///////////////////////////////////Test code by zzheng/////////////////////
int main()
{
    ZStack zzstack;
    int i = 0;

    //初始化测试
    InitStack(&zzstack,256) ;

    printf("IsEmpty:");
    printf("%d\n",IsEmpty(&zzstack));

    //入栈测试
    for(i=0;i<1000;i++)
    {
        if(i == 256)
        {
            printf("IsFull:%d\n",IsFull(&zzstack));
        }
        if(i == 400)
        {
            printf("GetSize:%d\n",GetStackSize(&zzstack));
        }
        PushStack(&zzstack,i) ;
    }

    printf("IsEmpty:");
    printf("%d\n",IsEmpty(&zzstack));

    printf("GetStackTop:");
    printf("%d\n",GetStackTop(&zzstack));

    printf("GetStackSize:");
    printf("%d\n",GetStackSize(&zzstack));


    for(i=0;i<1000;i++)
    {
      printf("%d\t",PopStack(&zzstack));
      if(i%10 == 9)
      {
        printf("\n");
      }
    }

    DeleteStack(&zzstack);
    printf("DeleteStack:");
    printf("%d\n",zzstack.stack == NULL);

    return 0;
}

///////////////////////////////////Test code end by zzheng/////////////////////
