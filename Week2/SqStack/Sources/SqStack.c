#include "SqStack.h"
#include <stdio.h>
#include <stdlib.h>

//初始化栈
Status initStack(SqStack *s, int sizes) {
    s->size=sizes;
    s->top=-1;
    s->elem=(ElemType*)malloc(sizes*sizeof(int));   //分配内存空间
    if(!s->elem) {
        printf("内存分配失败！\n");
        return ERROR;
    }
    printf("内存分配成功！\n");
    return SUCCESS;
}

//入栈
Status pushStack(SqStack *s,ElemType data){
    if(s->top==s->size-1){
        printf("栈已满！\n");
        return ERROR;
    }
    else{
        s->top++;
        s->elem[s->top]=data;
        printf("入栈成功！\n");
        return SUCCESS;
    }
}

//出栈
Status popStack(SqStack *s,ElemType *data){
    *data=s->elem[s->top];
    s->top--;
    return SUCCESS;
}

//检测栈长度
Status stackLength(SqStack *s,int *length){
    if(s->elem==NULL) {
        printf("未初始化栈，栈不存在！\n");
        return ERROR;
    }
    *length=(s->top)+1;
    printf("栈的长度为：%d\n",*length);
    return SUCCESS;
}

//判断栈是否为空
Status isEmptyStack(SqStack *s){
    if(s->top==-1){
        return ERROR;
    }
    else
        return SUCCESS;
}

//得到栈顶元素
Status getTopStack(SqStack *s,ElemType *e){
    if(s->top!=-1){
        *e=s->elem[s->top];
        return SUCCESS;
    }
    else{
        printf("此为空栈\n");
        return SUCCESS;
    }
}

//清空栈
Status clearStack(SqStack *s){
    s->top=-1;
    printf("栈已清空\n");
    return SUCCESS;
}

//销毁栈
Status destroyStack(SqStack *s){
    free(s->elem);
    printf("栈已销毁\n");
    return SUCCESS;
}
