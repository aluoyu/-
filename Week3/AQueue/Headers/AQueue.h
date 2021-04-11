#ifndef AQUEUE_H_INCLUDED
#define AQUEUE_H_INCLUDED

#define MAXQUEUE 10
int count;

typedef struct Aqueue
{
    void *data[MAXQUEUE];      //数据域(指针数组，每个数组元素是泛型的)
    int front;
    int rear;
    size_t length;        //队列长度
} AQueue;

typedef enum
{
    FALSE=0, TRUE=1
} Status;
char type;
char datatype[MAXQUEUE];

void InitAQueue(AQueue *Q);
void DestoryAQueue(AQueue *Q);
Status IsFullAQueue(const AQueue *Q);    //判断是否已满
Status IsEmptyAQueue(const AQueue *Q);    //判断是否为空
Status GetHeadAQueue(AQueue *Q, void *e);
int LengthAQueue(AQueue *Q);    //获取队列长度
Status EnAQueue(AQueue *Q, void *data);    //进队
Status DeAQueue(AQueue *Q);    //出队
void ClearAQueue(AQueue *Q);    //清空队列
Status TraverseAQueue(const AQueue *Q, void (*foo)(void *q));
void APrint(void *q);


#endif // AQUEUE_H_INCLUDED
