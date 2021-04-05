#include <iostream>
#include "DoubleList.h"
using namespace std;

//初始化
Status InitList_DuL(DuLinkedList *L) {
    *L = new DuLNode;
    (*L)->next = NULL;    //初始化指针域
    (*L)->prior = NULL;
    cout << "初始化成功" << endl;
    return SUCCESS;
}

//添加元素
Status AddList_DuL(DuLinkedList *L, ElemType e) {
    DuLinkedList point;
    point = new DuLNode;   //创建新结点
    point->data = e;    //给新结点赋值
    point->next = (*L)->next;
    if ((*L)->next != NULL) {    //(*L)->next的指针域不为空
        (*L)->next->prior = point;    //改变后继指针的指针域，而(*L)->next的指针域为空时，无需改变
    }
    (*L)->next = point;
    point->prior = (*L);
    return SUCCESS;
}

//寻找结点的位置
Status FindNode(DuLinkedList *L, int location, DuLinkedList *p) {
    int count_num;
    DuLinkedList temp_point = *L;
    for (count_num = 1; count_num < location && temp_point; count_num++)    //遍历寻找
        temp_point = temp_point->next;
    if (!temp_point || count_num > location) {   //该结点不存在
        return ERROR;
    } else
        *p = temp_point->next;    //temp_point是指定结点的前一个，故指定的结点为其next指针指向的内容
    return SUCCESS;
}

//在p结点前插入q结点
Status InsertBeforeList_DuL(DuLNode *p, DuLNode *q) {
    q->prior = p->prior;
    q->next = p;
    p->prior->next = q;
    p->prior = q;
    cout << "插入成功" << endl;
    return SUCCESS;
}

//在p结点后插入q结点
Status InsertAfterList_DuL(DuLNode *p, DuLNode *q) {
    q->next = p->next;
    if (p->next != NULL) {    //p->next的指针域不为空，要调整后继结点的prior指针域
        p->next->prior = q;
    }
    p->next = q;    //p->next的指针域为空
    q->prior = p;
    cout << "插入成功" << endl;
    return SUCCESS;
}

//输出结点的数据
void visit(ElemType c) {
    cout << c << '\t';
}

//遍历链表，显示数据
Status TraverseList_DuL(DuLinkedList L, void (*visit)(ElemType c)) {     //函数指针作为形参
    DuLinkedList point;
    point = L->next;
    while (point) {
        visit(point->data);    //迭代：调用visit函数
        point = point->next;
    }
    cout << endl;
    return SUCCESS;
}

//删除指定结点的下一个结点
Status DeleteList_DuL(DuLNode *p, ElemType *e) {
    if (p->next == NULL) {  //判断指定的结点是否为尾结点，尾结点无后继
        e = NULL;
        return ERROR;
    }
    else {
        DuLinkedList point;
        point = p->next;
        p->next = point->next;
        *e = point->data;
        if (p->next != NULL)   //判断要删除的结点是否为尾结点
            p->next->prior = p;    //不是，则要调整其后继结点的prior指针域
        delete point;
        return SUCCESS;
    }
}

//销毁该双向链表
void DestroyList_DuL(DuLinkedList *L) {
    DuLinkedList point;
    while (*L) {    //从头结点开始逐一释放内存
        point = *L;
        *L = (*L)->next;
        delete point;
    }
    cout << "已销毁";
}
