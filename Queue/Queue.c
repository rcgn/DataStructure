#include "Queue.h"


///////////////////////////////////////////////////////////////////////////
// 函数名称：InitQueue
// 函数输入：p_queue 初始化队列的指针，i_size 初始化队列的初始空间大小
// 函数输出：无
// 函数返回：是否成功，BOOL类型
// 函数作用：初始化队列，将所有参数初始化，并为队列数据分配存储空间，最小分
//           配大小为256
///////////////////////////////////////////////////////////////////////////
BOOL InitQueue(ZQueue* p_queue,int i_size)
{
    int size;
    if(i_size > QUEUE_MAX)
    {
        return FALSE;
    }

    p_queue->count    = 0;
    p_queue->readside = 0;
    p_queue->writeside= 0;
    p_queue->size     = 0;

    size = i_size > QUEUE_MIN ? i_size : QUEUE_MIN ;

    if(p_queue->data = (int*)malloc(size * sizeof(int)))
    {
        p_queue->size = size;
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}


///////////////////////////////////////////////////////////////////////////
// 函数名称：InQueue
// 函数输入：p_queue 队列指针，p_num 进入队列的元素
// 函数输出：无
// 函数返回：是否成功，BOOL类型
// 函数作用：将元素入队，若数据区不够则扩容，若超过上限，则报错
///////////////////////////////////////////////////////////////////////////
BOOL InQueue(ZQueue* p_queue,int p_num)
{
    //若队列已满则返回失败
    if(QueueIsFull(p_queue))
    {
        if(!QueueEnlarge(p_queue))
        {
            return FALSE;
        }
    }

    //入队，写指针加1
    p_queue->data[p_queue->writeside++]  = p_num;
    p_queue->writeside %= p_queue->size;
    p_queue->count ++;

    return TRUE;
}


///////////////////////////////////////////////////////////////////////////
// 函数名称：OutQueue
// 函数输入：p_queue 队列指针
// 函数输出：无
// 函数返回：返回出队元素
// 函数作用：队首元素出队，并返回出队元素
///////////////////////////////////////////////////////////////////////////
int OutQueue(ZQueue* p_queue)
{
    int tempdata = 0;
    if(QueueIsEmpty(p_queue))
    {
        return ERROR;
    }

    tempdata = p_queue->data[p_queue->readside++];
    p_queue->readside %= p_queue->size;
    p_queue->count--;

    return tempdata;
}


///////////////////////////////////////////////////////////////////////////
// 函数名称：QueueIsEmpty
// 函数输入：p_queue 队列指针
// 函数输出：无
// 函数返回：返回队列是否为空，若为空则返回TRUE，若非空则返回FALSE
// 函数作用：判断队列是否为空
///////////////////////////////////////////////////////////////////////////
BOOL QueueIsEmpty(ZQueue* p_queue)
{
    if(p_queue->writeside == p_queue->readside)
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}


///////////////////////////////////////////////////////////////////////////
// 函数名称：QueueIsFull
// 函数输入：p_queue 队列指针
// 函数输出：无
// 函数返回：返回队列是否满，若当前队列已满，则返回TRUE，否则返回FALSE
// 函数作用：判断队列是否满
///////////////////////////////////////////////////////////////////////////
BOOL QueueIsFull(ZQueue* p_queue)
{
    if(p_queue->count == p_queue->size)
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}


///////////////////////////////////////////////////////////////////////////
// 函数名称：QueueEnlarge
// 函数输入：p_queue 队列指针
// 函数输出：无
// 函数返回：队列扩大一倍，若成功，返回TRUE，否则返回FALSE
// 函数作用：将队列空间扩大一倍，并将原队列中元素拷贝入新空间
///////////////////////////////////////////////////////////////////////////
BOOL QueueEnlarge(ZQueue* p_queue)
{
    int  i;
    int* tempdata;
    int  size=0;

    size = (QUEUE_MAX/2 < p_queue->size ) ? QUEUE_MAX : 2*p_queue->size ;

    if(tempdata = (int*) malloc(size * sizeof(int)))
    {
        for(i=0; i<p_queue->count; i++,p_queue->writeside+=1, p_queue->writeside %= p_queue->size)
        {
            tempdata[i] = p_queue->data[p_queue->writeside];
        }

        free(p_queue->data);
        p_queue->data = tempdata;
        p_queue->size = size;
        p_queue->readside = 0 ;
        p_queue->writeside = p_queue->count;

        return TRUE;
    }
    else
    {
        return FALSE;
    }
}


///////////////////////////////////////////////////////////////////////////
// 函数名称：GetQueueHead
// 函数输入：p_queue 队列指针
// 函数输出：无
// 函数返回：返回队列首元素
// 函数作用：获取队列首元素
///////////////////////////////////////////////////////////////////////////
int GetQueueHead(ZQueue* p_queue)
{
    if(QueueIsEmpty(p_queue))
    {
        return ERROR;
    }
    return p_queue->data[p_queue->writeside];
}


///////////////////////////////////////////////////////////////////////////
// 函数名称：GetQueueSize
// 函数输入：p_queue 队列指针
// 函数输出：无
// 函数返回：返回队列当前空间大小
// 函数作用：获取队列当前空间大小
///////////////////////////////////////////////////////////////////////////
int GetQueueSize(ZQueue* p_queue)
{
    return p_queue->size;
}


///////////////////////////////////////////////////////////////////////////
// 函数名称：GetQueueCount
// 函数输入：p_queue 队列指针
// 函数输出：无
// 函数返回：返回队列当前元素个数
// 函数作用：获取队列当前元素个数
///////////////////////////////////////////////////////////////////////////
int GetQueueCount(ZQueue* p_queue)
{
    return p_queue->count;
}


///////////////////////////////////////////////////////////////////////////
// 函数名称：DelQueue
// 函数输入：p_queue 队列指针
// 函数输出：无
// 函数返回：无
// 函数作用：删除当前队列
///////////////////////////////////////////////////////////////////////////
void DelQueue(ZQueue* p_queue)
{
    free(p_queue->data);
    p_queue->count = 0;
    p_queue->size  = 0;
    p_queue->writeside = 0;
    p_queue->readside  = 0;
}
