#include <stdio.h>
#include <stdlib.h>
#include<string.h>

#include"LQueue.h"

void InitLQueue(LQueue *Q){
    Node* point=(Node*)malloc(sizeof(Node));    //创建头结点
    if(!point)
        printf("内存分配失败！\n");
    else{
        point->next=NULL;
        Q->front=point;
        Q->rear=point;
        Q->length=0;
        count=0;
        printf("初始化成功!\n");
    }
}

Status GetHeadLQueue(LQueue *Q, void *e){
    memcpy(e,Q->front->next->data,datatype[0]);
    return TRUE;
}

Status IsEmptyLQueue(const LQueue *Q){
    if(Q->length==0)
        return TRUE;
    else
        return FALSE;
}


int LengthLQueue(LQueue *Q){
    return Q->length;
}

void DestoryLQueue(LQueue *Q){
    ClearLQueue(Q);
    free(Q->front);
    free(Q->rear);
}

void ClearLQueue(LQueue *Q){
    Node*p,*q;
    Q->rear = Q->front;
    p=Q->front->next;
    while(p){
        q=p;
        p=p->next;
        free(q);
    }
    free(p);
    Q->length=0;
    count=0;
}

Status EnLQueue(LQueue *Q, void *data){
    Node*point=(Node*)malloc(sizeof(Node));
    if(!point){
        printf("内存分配失败！\n");
        return FALSE;
    }
    point->data=(void*)malloc(datatype[count]-'0');
    memcpy(point->data,data,datatype[count]-'0');
    point->next=NULL;
    Q->rear->next=point;
    Q->rear=point;
    Q->length++;
    count++;
    printf("入队成功！\n");
    return TRUE;
}


Status DeLQueue(LQueue *Q){
    Node*point;
    point=Q->front->next;
    Q->front->next=point->next;
    if(point->next==NULL)
        Q->rear=Q->front;
    free(point);
    int k;
    for(k=0;k<count-1;k++){
        datatype[k]=datatype[k+1];
    }
    count--;
    Q->length--;
    printf("出队成功\n");
    return TRUE;
}

Status TraverseLQueue(const LQueue *Q, void (*foo)(void *q)){
    Node * point;
    point=Q->front->next;
    for(outNum=0;outNum<Q->length;outNum++){
        foo(point->data);
        point=point->next;
    }
    printf("\n");
    return TRUE;
}

void LPrint(void *q){
    if(datatype[outNum]=='4'){
        printf("%d",*(int*)q);
    }
    if(datatype[outNum]=='1'){
        printf("%c",*(char*)q);
    }
    if(datatype[outNum]=='8'){
        printf("%lf",*(double*)q);
    }
    printf(" ");
}
