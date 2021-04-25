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

NodePtr temp_point;  //树的最后一个节点，用作插入

typedef struct LQueue
{
    int front;                   //队头
    int rear;                    //队尾
    struct Node* num[50];
} LQueue;

void show(NodePtr p);
Status BST_init(BinarySortTreePtr);     //初始化二叉排序树
Status BST_insert(BinarySortTreePtr, ElemType);     //二叉排序树插入
Status BST_delete(BinarySortTreePtr, ElemType);     //删除
Status BST_search(BinarySortTreePtr, ElemType);     //搜索
Status BST_preorderI(BinarySortTreePtr, void (*visit)(NodePtr));    //前序 迭代
Status BST_preorderR(NodePtr p, void (*visit)(NodePtr));    //前序 递归
Status BST_inorderI(BinarySortTreePtr, void (*visit)(NodePtr));
Status BST_inorderR(NodePtr p, void (*visit)(NodePtr));
Status BST_postorderI(BinarySortTreePtr, void (*visit)(NodePtr));
Status BST_postorderR(NodePtr p, void (*visit)(NodePtr));
Status BST_levelOrder(BinarySortTreePtr, void (*visit)(NodePtr));


#endif // BINARY_SORT_TREE_H_INCLUDED
