#ifndef AQUEUE_H_INCLUDED
#define AQUEUE_H_INCLUDED

#define MAXQUEUE 10
int count;

typedef struct Aqueue
{
    void *data[MAXQUEUE];      //������(ָ�����飬ÿ������Ԫ���Ƿ��͵�)
    int front;
    int rear;
    size_t length;        //���г���
} AQueue;

typedef enum
{
    FALSE=0, TRUE=1
} Status;
char type;
char datatype[MAXQUEUE];

void InitAQueue(AQueue *Q);
void DestoryAQueue(AQueue *Q);
Status IsFullAQueue(const AQueue *Q);    //�ж��Ƿ�����
Status IsEmptyAQueue(const AQueue *Q);    //�ж��Ƿ�Ϊ��
Status GetHeadAQueue(AQueue *Q, void *e);
int LengthAQueue(AQueue *Q);    //��ȡ���г���
Status EnAQueue(AQueue *Q, void *data);    //����
Status DeAQueue(AQueue *Q);    //����
void ClearAQueue(AQueue *Q);    //��ն���
Status TraverseAQueue(const AQueue *Q, void (*foo)(void *q));
void APrint(void *q);


#endif // AQUEUE_H_INCLUDED
