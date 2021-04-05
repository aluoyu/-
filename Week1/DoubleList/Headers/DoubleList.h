#ifndef DOUBLELIST_H_INCLUDED
#define DOUBLELIST_H_INCLUDED



#endif // DOUBLELIST_H_INCLUDED
typedef int ElemType;
typedef enum Status {
    ERROR,
    SUCCESS,
} Status;

typedef struct DuLNode {    //结点的结构体
    ElemType data;
    DuLNode *prior;
    DuLNode *next;
} DuLNode, *DuLinkedList;
typedef struct DuLNode *DuLinkedList;

Status InitList_DuL(DuLinkedList *L);//初始化
Status AddList_DuL(DuLinkedList *L, ElemType e);//添加元素
Status FindNode(DuLinkedList *L, int location, DuLinkedList *p);//寻找结点的位置
Status InsertBeforeList_DuL(DuLNode *p, DuLNode *q);//在p结点前插入q结点
Status InsertAfterList_DuL(DuLNode *p, DuLNode *q);//在p结点后插入q结点
void visit(ElemType c);//输出结点的数据
Status TraverseList_DuL(DuLinkedList L, void (*visit)(ElemType c));//遍历链表，显示数据
Status DeleteList_DuL(DuLNode *p, ElemType *e);//删除指定结点的下一个结点
void DestroyList_DuL(DuLinkedList *L);//销毁该双向链表
