//Stack.c
#include "Stack.h"

////////////////////////////////////////////////////////////////
//函数名称：PopStack
//作    者：赵  政
//输    入：ZStack* p_stack 栈指针
//输    出：无
//返    回：int 原栈顶元素
//影响结果：弹出栈顶元素，改变栈的高度height
////////////////////////////////////////////////////////////////
int   PopStack(ZStack* p_stack)
{
    if(!IsEmpty(p_stack))
	{
	    return p_stack->stack[--p_stack->height];
	}
	else
	{
        return -1; //此处不作特殊处理，出栈前自行检查是否为空栈
	}
}

////////////////////////////////////////////////////////////////
//函数名称：PushStack
//作    者：赵  政
//输    入：ZStack* p_stack 栈指针
//          int     p_num   要入栈的元素
//输    出：无
//返    回：BOOL 操作是否成功，如果栈满则重新分配内存，若超过上界
//          则返回FALSE
//影响结果：将元素压入栈中，改变栈的高度height
////////////////////////////////////////////////////////////////
BOOL  PushStack(ZStack* p_stack, int p_num)
{
    if(IsFull(p_stack))
	{
	    if(!EnlargeStack(p_stack))
		{
		    return FALSE;
		}
	}

	p_stack->stack[p_stack->height++] = p_num;
	return TRUE;
}

////////////////////////////////////////////////////////////////
//函数名称：IsEmpty
//作    者：赵  政
//输    入：ZStack* p_stack 栈指针
//输    出：无
//返    回：BOOL 判断栈是否为空，若为空，则返回TRUE，否则返回FALSE
//影响结果：无
////////////////////////////////////////////////////////////////
BOOL  IsEmpty(ZStack* p_stack)
{
    if(p_stack->height <= 0)
	{
	    p_stack->height = 0;
		return TRUE;
	}
	else
	{
	    return FALSE;
	}
}

////////////////////////////////////////////////////////////////
//函数名称：IsFull
//作    者：赵  政
//输    入：ZStack* p_stack 栈指针
//输    出：无
//返    回：BOOL 判断栈是否满，若满，则返回TRUE，否则返回FALSE
//影响结果：无
////////////////////////////////////////////////////////////////
BOOL  IsFull(ZStack* p_stack)
{
    if(p_stack->height >= p_stack->size)
	{
	    p_stack->height = p_stack->size;
	    return TRUE;
	}
	else
	{
	    return FALSE;
	}
}

////////////////////////////////////////////////////////////////
//函数名称：EnlargeStack
//作    者：赵  政
//输    入：ZStack* p_stack 栈指针
//输    出：无
//返    回：BOOL 操作是否成功，若成功，则返回TRUE，否则返回FALSE
//影响结果：入栈时若栈存储空间不够，申请原内存2倍大小的内存空间，
//          并修改size，将栈拷贝到新内存空间，并free原内存空间。
////////////////////////////////////////////////////////////////
BOOL  EnlargeStack(ZStack* p_stack)
{
    int   i = 0;
    int*  l_stack ;
	int   size;

	size = (STACK_MAX/2 < p_stack->size) ? STACK_MAX : 2*p_stack->size ;

	if(l_stack = (int*) malloc(size * sizeof(int)))
	{
	    for(i=0;i<p_stack->size;i++)
		{
		    l_stack[i] = p_stack->stack[i];
		}

		free(p_stack->stack);

		p_stack->size   = size;
		p_stack->stack  = l_stack;
		return TRUE;
	}
	else
	{
	    return FALSE;
	}

}

////////////////////////////////////////////////////////////////
//函数名称：InitStack
//作    者：赵  政
//输    入：ZStack* p_stack 栈指针
//          int     p_size  初始栈大小，若小于MIN，则按MIN分配大小
//输    出：无
//返    回：BOOL 操作是否成功，若成功，则返回TRUE，否则返回FALSE
//影响结果：新定义一个栈时，首先调用此函数，用于初始化栈空间，分配
//          栈初始内存，及初始化
////////////////////////////////////////////////////////////////
BOOL  InitStack(ZStack* p_stack,int p_size)
{
    int  l_size = 0;

	if(STACK_MAX < p_size)
	{
	    p_stack->size   = 0;
		p_stack->height = 0;
		p_stack->stack  ;

	    return FALSE;
	}
    else if(p_size < STACK_MIN)
	{
	    l_size = STACK_MIN;
	}
	else
	{
	    l_size = p_size;
	}
	if(p_stack->stack = (int*)malloc(l_size * sizeof(int)) )
	{
        p_stack->size   = l_size;
		p_stack->height = 0;

		return TRUE;
	}
	else
	{
	    return FALSE;
	}

}

////////////////////////////////////////////////////////////////
//函数名称：DeleteStack
//作    者：赵  政
//输    入：ZStack* p_stack 栈指针
//输    出：无
//返    回：void
//影响结果：删除一个栈，并将分配的内存free掉
////////////////////////////////////////////////////////////////
void  DeleteStack(ZStack* p_stack)
{
    if( p_stack->stack)
	{
	    free(p_stack->stack);
	}

	p_stack->size   = 0;
	p_stack->height = 0;
}

////////////////////////////////////////////////////////////////
//函数名称：GetStackSize
//作    者：赵  政
//输    入：ZStack* p_stack 栈指针
//输    出：无
//返    回：int 返回栈的尺寸size
//影响结果：返回栈的尺寸
////////////////////////////////////////////////////////////////
int  GetStackSize(ZStack* p_stack)
{
    return p_stack->size;
}

////////////////////////////////////////////////////////////////
//函数名称：GetStackHeight
//作    者：赵  政
//输    入：ZStack* p_stack 栈指针
//输    出：无
//返    回：int 返回栈的高度
//影响结果：返回栈的高度
////////////////////////////////////////////////////////////////
int  GetStackHeight(ZStack* p_stack)
{
    return p_stack->height;
}

////////////////////////////////////////////////////////////////
//函数名称：GetStackTop
//作    者：赵  政
//输    入：ZStack* p_stack 栈指针
//输    出：无
//返    回：int 返回栈顶元素
//影响结果：返回栈的高度
////////////////////////////////////////////////////////////////
int  GetStackTop(ZStack* p_stack)
{
    if(p_stack->height >0)
    {
        return p_stack->stack[p_stack->height-1];
    }
    else
    {
        return ERROR;
    }
}
