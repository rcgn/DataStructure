#include "Queue.h"


///////////////////////////////////////////////////////////////////////////
// �������ƣ�InitQueue
// �������룺p_queue ��ʼ�����е�ָ�룬i_size ��ʼ�����еĳ�ʼ�ռ��С
// �����������
// �������أ��Ƿ�ɹ���BOOL����
// �������ã���ʼ�����У������в�����ʼ������Ϊ�������ݷ���洢�ռ䣬��С��
//           ���СΪ256
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
// �������ƣ�InQueue
// �������룺p_queue ����ָ�룬p_num ������е�Ԫ��
// �����������
// �������أ��Ƿ�ɹ���BOOL����
// �������ã���Ԫ����ӣ������������������ݣ����������ޣ��򱨴�
///////////////////////////////////////////////////////////////////////////
BOOL InQueue(ZQueue* p_queue,int p_num)
{
    //�����������򷵻�ʧ��
    if(QueueIsFull(p_queue))
    {
        if(!QueueEnlarge(p_queue))
        {
            return FALSE;
        }
    }

    //��ӣ�дָ���1
    p_queue->data[p_queue->writeside++]  = p_num;
    p_queue->writeside %= p_queue->size;
    p_queue->count ++;

    return TRUE;
}


///////////////////////////////////////////////////////////////////////////
// �������ƣ�OutQueue
// �������룺p_queue ����ָ��
// �����������
// �������أ����س���Ԫ��
// �������ã�����Ԫ�س��ӣ������س���Ԫ��
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
// �������ƣ�QueueIsEmpty
// �������룺p_queue ����ָ��
// �����������
// �������أ����ض����Ƿ�Ϊ�գ���Ϊ���򷵻�TRUE�����ǿ��򷵻�FALSE
// �������ã��ж϶����Ƿ�Ϊ��
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
// �������ƣ�QueueIsFull
// �������룺p_queue ����ָ��
// �����������
// �������أ����ض����Ƿ���������ǰ�����������򷵻�TRUE�����򷵻�FALSE
// �������ã��ж϶����Ƿ���
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
// �������ƣ�QueueEnlarge
// �������룺p_queue ����ָ��
// �����������
// �������أ���������һ�������ɹ�������TRUE�����򷵻�FALSE
// �������ã������пռ�����һ��������ԭ������Ԫ�ؿ������¿ռ�
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
// �������ƣ�GetQueueHead
// �������룺p_queue ����ָ��
// �����������
// �������أ����ض�����Ԫ��
// �������ã���ȡ������Ԫ��
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
// �������ƣ�GetQueueSize
// �������룺p_queue ����ָ��
// �����������
// �������أ����ض��е�ǰ�ռ��С
// �������ã���ȡ���е�ǰ�ռ��С
///////////////////////////////////////////////////////////////////////////
int GetQueueSize(ZQueue* p_queue)
{
    return p_queue->size;
}


///////////////////////////////////////////////////////////////////////////
// �������ƣ�GetQueueCount
// �������룺p_queue ����ָ��
// �����������
// �������أ����ض��е�ǰԪ�ظ���
// �������ã���ȡ���е�ǰԪ�ظ���
///////////////////////////////////////////////////////////////////////////
int GetQueueCount(ZQueue* p_queue)
{
    return p_queue->count;
}


///////////////////////////////////////////////////////////////////////////
// �������ƣ�DelQueue
// �������룺p_queue ����ָ��
// �����������
// �������أ���
// �������ã�ɾ����ǰ����
///////////////////////////////////////////////////////////////////////////
void DelQueue(ZQueue* p_queue)
{
    free(p_queue->data);
    p_queue->count = 0;
    p_queue->size  = 0;
    p_queue->writeside = 0;
    p_queue->readside  = 0;
}
