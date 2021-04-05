#include "LinkedList.h"
#include <iostream>
using namespace std;

//添加元素
Status AddList(LinkedList * L, ElemType e) {
    int count_num;     //用作计数的变量
    LinkedList temp_point = *L;
    for (count_num = 1; count_num < 1 && temp_point; count_num++)   //寻找该结点
        temp_point = temp_point->next;
    if (!temp_point || count_num > 1)   //该结点不存在
        return ERROR;
    LinkedList point;
    point = new LNode;     //创建新结点
    point->data = e;
    point->next = temp_point->next;
    temp_point->next = point;
    return SUCCESS;
}

//初始化
Status InitList(LinkedList* L) {
    *L = new LNode;
    (*L)->next = NULL;   //头结点的指针域为空
    cout<<"初始化成功"<<endl;
    return SUCCESS;
}

//寻找结点的位置
Status FindNode(LinkedList *L, int location, LinkedList *p) {
    int count_num;
    LinkedList temp_point = *L;
    for (count_num = 1; count_num < location && temp_point; count_num++)    //遍历寻找
        temp_point = temp_point->next;
    if (!temp_point || count_num > location) {   //该结点不存在
        return ERROR;
    }
    else
        *p = temp_point->next;    //temp_point是指定结点的前一个，故指定的结点为其next指针指向的内容
    return SUCCESS;
}

//在指定结点的后面插入
Status InsertList(LNode *p, LNode *q){
    q->next = p->next;
    p->next = q;
    cout << "插入成功" << endl;
    return SUCCESS;
}

//删除指定结点的下一个结点
Status DeleteList(LNode *p, ElemType *e){
    if(p->next==NULL){     //判断指定结点是否具有后继结点
        e=NULL;
        return ERROR;
    }
    LNode *q;
    q=p->next;
    p->next=q->next;
    *e = q->data;
    delete q;
    return SUCCESS;
}

//销毁链表
Status DestroyList(LinkedList* L){
    LinkedList point;
    while(*L) {    //从头结点开始逐一释放内存
        point = *L;
        *L=(*L)->next;
        delete point;
    }
    cout<<"已销毁";
    return SUCCESS;
}

//打印结点中存放的数据
void visit(ElemType e)
{
    cout<<e<<'\t';
}

//遍历链表，并输出各结点的数据值
void TraverseList(LinkedList L,void (*visit)(ElemType e)){
    LinkedList point;
    point=L->next;
    while(point){   //遍历链表，循环条件为当链表不为空
        visit(point->data);    //迭代：调用visit函数
        point=point->next;
    }
    cout<<endl;
}

//根据所给元素在表中找到第一个符合的结点
Status SearchList(LinkedList L,ElemType e){
    LinkedList point=L;
    int i;
    for(i=0;point;i++){    //遍历链表
        if(point->data==e) {
            cout << "符合该数值的第一个结点为第" << i << "个" << endl;
            break;     //找到后退出循环
        }
        point=point->next;
    }
    return SUCCESS;
}

//判断链表是否为空
Status EmptyList(LinkedList head){
    if(!head)
        cout << "此为空"<<endl;
    else
        cout<<"此不为空"<<endl;
    return SUCCESS;
}
