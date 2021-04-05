#include <stdio.h>
#include <stdlib.h>
#include "LinkStack.h"
Status initLStack(LinkStack *s){
    s->top=(LinkStackPtr)malloc(sizeof(StackNode));    //为结点分配内存空间
    if(!s->top){    //指针为空指针
        printf("内存分配失败！\n");
        return ERROR;
    }
    s->top->next=NULL;
    s->count=0;

    printf("初始化成功！\n");
    return SUCCESS;
}

Status pushLStack(LinkStack *s,ElemType data){
    LinkStackPtr point;
    point=(LinkStackPtr)malloc(sizeof(StackNode));
    if(point==NULL) {

        printf("内存分配失败！\n");
        return ERROR;
    }
    else {

        point->data = data;
        point->next = s->top;
        s->top = point;
        s->count++;    //长度加一
        return SUCCESS;
    }
}

Status popLStack(LinkStack *s,ElemType *data){
    LinkStackPtr point;
    *data=s->top->data;
    point=s->top;
    s->top=point->next;
    free(point);
    s->count--;    //长度减一
    return SUCCESS;
}
Status isEmptyLStack(LinkStack *s){
    if(s->count==0){
        return ERROR;
    }
    else
        return SUCCESS;
}

Status clearLStack(LinkStack *s){
    LinkStackPtr p,q;
    p=s->top;
    while(p->next){
        q=p;
        p=p->next;
        free(q);
    }
    s->count=0;
    return SUCCESS;
}

Status destroyLStack(LinkStack *s){
    LinkStackPtr p,q;
    p=s->top;
    printf("OK1\n");
    while(p->next){
        q=p;
        p=p->next;
        free(q);
        printf("OK2\n");
    }
    free(p);
    printf("OK3\n");
    s->count=0;
    return SUCCESS;
}

Status LStackLength(LinkStack *s,int *length){
    *length=s->count;
    return SUCCESS;
}

Status getTopLStack(LinkStack *s,ElemType *e){
    *e=s->top->data;
    return SUCCESS;
}
