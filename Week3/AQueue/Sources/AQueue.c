#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include"AQueue.h"

//初始化队列
void InitAQueue(AQueue *Q){
    Q->length=0;
    Q->front=0;
    Q->rear=0;
    printf("初始化成功！\n");
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

//判断是否已满
Status IsFullAQueue(const AQueue *Q){
    if(Q->length==MAXQUEUE){
        return TRUE;
    }
    else {
        return FALSE;
    }
}

//判断是否为空
Status IsEmptyAQueue(const AQueue *Q){
    if(Q->length==0){
        return TRUE;
    }
    else {
        return FALSE;
    }
}

//获取队列长度
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
    printf("入队成功！\n");
    return TRUE;
}

Status DeAQueue(AQueue *Q){
    int k;
    if(Q->front==Q->rear) {
        printf("队列为空，无元素可出\n");
        return FALSE;
    }
    Q->front=(Q->front+1)%MAXQUEUE;
    for(k=0;k<Q->length-1;k++){
        datatype[k]=datatype[k+1];
    }
    Q->length--;

    printf("出队成功\n");
    return TRUE;
}

//获取队头元素
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
    printf("队列已清空\n");
}
