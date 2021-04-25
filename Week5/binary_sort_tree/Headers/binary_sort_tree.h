#ifndef BINARY_SORT_TREE_H_INCLUDED
#define BINARY_SORT_TREE_H_INCLUDED

#define true 1
#define false 0
#define succeed 1
#define failed 0
#define Status int

typedef int ElemType;

typedef struct Node{
    ElemType value;
    struct Node *left, *right;
}Node, *NodePtr;

typedef struct BinarySortTree{
    NodePtr root ;
} BinarySortTree, *BinarySortTreePtr;

NodePtr temp_point;  //�������һ���ڵ㣬��������

typedef struct LQueue
{
    int front;                   //��ͷ
    int rear;                    //��β
    struct Node* num[50];
} LQueue;

void show(NodePtr p);
Status BST_init(BinarySortTreePtr);     //��ʼ������������
Status BST_insert(BinarySortTreePtr, ElemType);     //��������������
Status BST_delete(BinarySortTreePtr, ElemType);     //ɾ��
Status BST_search(BinarySortTreePtr, ElemType);     //����
Status BST_preorderI(BinarySortTreePtr, void (*visit)(NodePtr));    //ǰ�� ����
Status BST_preorderR(NodePtr p, void (*visit)(NodePtr));    //ǰ�� �ݹ�
Status BST_inorderI(BinarySortTreePtr, void (*visit)(NodePtr));
Status BST_inorderR(NodePtr p, void (*visit)(NodePtr));
Status BST_postorderI(BinarySortTreePtr, void (*visit)(NodePtr));
Status BST_postorderR(NodePtr p, void (*visit)(NodePtr));
Status BST_levelOrder(BinarySortTreePtr, void (*visit)(NodePtr));


#endif // BINARY_SORT_TREE_H_INCLUDED
