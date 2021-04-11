#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include"AQueue.h"

//��ʼ������
void InitAQueue(AQueue *Q){
    Q->length=0;
    Q->front=0;
    Q->rear=0;
    printf("��ʼ���ɹ���\n");
}

void DestoryAQueue(AQueue *Q){
    int i;
    for(i=Q->front;i<=Q->rear;i++){
        free(Q->data[i]);
    }
}

Status TraverseAQueue(const AQueue *Q, void (*foo)(void *q)){
    for(count=Q->front+1;count<=(MAXQUEUE-Q->front+Q->rear)%MAXQUEUE;count=(count+1)%MAXQUEUE){
        foo(Q->data[count]);
    }
    return TRUE;
}

void APrint(void *q){
    if(datatype[count]=='4'){
        printf("%d",*(int*)q);
    }
    if(datatype[count]=='1'){
        printf("%c",*(char*)q);
    }
    if(datatype[count]=='8'){
        printf("%lf",*(double*)q);
    }
    printf(" ");
}

//�ж��Ƿ�����
Status IsFullAQueue(const AQueue *Q){
    if(Q->length==MAXQUEUE){
        return TRUE;
    }
    else {
        return FALSE;
    }
}

//�ж��Ƿ�Ϊ��
Status IsEmptyAQueue(const AQueue *Q){
    if(Q->length==0){
        return TRUE;
    }
    else {
        return FALSE;
    }
}

//��ȡ���г���
int LengthAQueue(AQueue *Q){
    return Q->length;
}

Status EnAQueue(AQueue *Q, void *data){
    if(IsFullAQueue(Q))
        return FALSE;
    Q->rear=(Q->rear+1)%MAXQUEUE;
    Q->data[Q->rear]=(void*)malloc(datatype[Q->rear]-'0');

    memcpy(Q->data[Q->rear],data,datatype[Q->rear]-'0');
    Q->length++;
    Q->rear++;
    printf("��ӳɹ���\n");
    return TRUE;
}

Status DeAQueue(AQueue *Q){
    int k;
    if(Q->front==Q->rear) {
        printf("����Ϊ�գ���Ԫ�ؿɳ�\n");
        return FALSE;
    }
    Q->front=(Q->front+1)%MAXQUEUE;
    for(k=0;k<Q->length-1;k++){
        datatype[k]=datatype[k+1];
    }
    Q->length--;

    printf("���ӳɹ�\n");
    return TRUE;
}

//��ȡ��ͷԪ��
Status GetHeadAQueue(AQueue *Q, void *e){
    int i;
    i=Q->front;
    i=(i+1)%MAXQUEUE;
    e=(void*)malloc(datatype[i]-'0');
    memcpy(e,Q->data[i],datatype[i]-'0');
    return TRUE;
}

void ClearAQueue(AQueue *Q){
    Q->front=0;
    Q->rear=0;
    Q->length=0;
    printf("���������\n");
}
