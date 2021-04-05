#ifndef LINKEDLIST_H_INCLUDED
#define LINKEDLIST_H_INCLUDED



#endif // LINKEDLIST_H_INCLUDED

typedef int ElemType;

typedef struct LNode {
    ElemType data;
    struct LNode *next;
} LNode, *LinkedList;

typedef enum Status {
    ERROR,
    SUCCESS
} Status;

Status AddList(LinkedList * L, ElemType e);//添加元素
Status InitList(LinkedList* L);//初始化
Status FindNode(LinkedList *L, int location, LinkedList *p);//寻找结点的位置
Status InsertList(LNode *p, LNode *q);//在指定结点的后面插入
Status DeleteList(LNode *p, ElemType *e);//删除指定结点的下一个结点
Status DestroyList(LinkedList* L);//销毁链表
void visit(ElemType e);//打印结点中存放的数据
void TraverseList(LinkedList L,void (*visit)(ElemType e));//遍历链表，并输出各结点的数据值
Status SearchList(LinkedList L,ElemType e);//根据所给元素在表中找到第一个符合的结点
Status EmptyList(LinkedList head);//判断链表是否为空
