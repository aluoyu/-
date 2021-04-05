#include "SqStack.h"
#include <stdio.h>
#include <stdlib.h>

//��ʼ��ջ
Status initStack(SqStack *s, int sizes) {
    s->size=sizes;
    s->top=-1;
    s->elem=(ElemType*)malloc(sizes*sizeof(int));   //�����ڴ�ռ�
    if(!s->elem) {
        printf("�ڴ����ʧ�ܣ�\n");
        return ERROR;
    }
    printf("�ڴ����ɹ���\n");
    return SUCCESS;
}

//��ջ
Status pushStack(SqStack *s,ElemType data){
    if(s->top==s->size-1){
        printf("ջ������\n");
        return ERROR;
    }
    else{
        s->top++;
        s->elem[s->top]=data;
        printf("��ջ�ɹ���\n");
        return SUCCESS;
    }
}

//��ջ
Status popStack(SqStack *s,ElemType *data){
    *data=s->elem[s->top];
    s->top--;
    return SUCCESS;
}

//���ջ����
Status stackLength(SqStack *s,int *length){
    if(s->elem==NULL) {
        printf("δ��ʼ��ջ��ջ�����ڣ�\n");
        return ERROR;
    }
    *length=(s->top)+1;
    printf("ջ�ĳ���Ϊ��%d\n",*length);
    return SUCCESS;
}

//�ж�ջ�Ƿ�Ϊ��
Status isEmptyStack(SqStack *s){
    if(s->top==-1){
        return ERROR;
    }
    else
        return SUCCESS;
}

//�õ�ջ��Ԫ��
Status getTopStack(SqStack *s,ElemType *e){
    if(s->top!=-1){
        *e=s->elem[s->top];
        return SUCCESS;
    }
    else{
        printf("��Ϊ��ջ\n");
        return SUCCESS;
    }
}

//���ջ
Status clearStack(SqStack *s){
    s->top=-1;
    printf("ջ�����\n");
    return SUCCESS;
}

//����ջ
Status destroyStack(SqStack *s){
    free(s->elem);
    printf("ջ������\n");
    return SUCCESS;
}
