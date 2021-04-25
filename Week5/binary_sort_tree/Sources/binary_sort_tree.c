#include <stdio.h>
#include <stdlib.h>
#include "binary_sort_tree.h"

//初始化
Status BST_init(BinarySortTreePtr BST){
    BST->root=NULL;
    return succeed;
}

//插入
Status BST_insert(BinarySortTreePtr BST, ElemType data){
    NodePtr point=(NodePtr)malloc(sizeof(Node));
    if(point!=NULL) {
        point->value = data;
        point->right = NULL;
        point->left = NULL;

        //空树的时候，直接把数据放在根节点上
        if(BST->root==NULL){
            BST->root=point;
            printf("插入成功\n");
            return succeed;
        }

        //树不为空
        else {
            //搜索查看树中是否已经存在该值，存在为1，不存在为0
            if (BST_search(BST, data) == 1) {
                printf("该值已存在！\n\n");
                return failed;
            }
            //不存在
            if(data<temp_point->value){
                temp_point->left=point;
            }
            else
                temp_point->right=point;
	    printf("插入成功\n\n");
            return succeed;
        }
    }
    else {
        printf("内存分配失败！\n\n");
        return failed;
    }
}

Status search(Node*p,int data,Node*parent){
    //若传入的节点为空
    if(p==NULL) {
        temp_point = parent;
        return false;
    }
    if(data==p->value){
        temp_point=p;
        return true;
    }
    else if(data<p->value){
        return search(p->left,data,p);
    }
    else{
        return search(p->right,data,p);
    }
}


//搜索,返回存在的值
Status BST_search(BinarySortTreePtr BST, ElemType data){
    if(BST->root==NULL)     //树为空
        return false;
    //等于根节点，直接返回
    if(data==BST->root->value)
        return true;
    //小于根节点，在左子树查找
    else if(data<BST->root->value){
        if(search(BST->root->left,data,BST->root))
            return true;
        else
            return false;
    }
    //大于根节点，在右子树查找
    else{
        if(search(BST->root->right,data,BST->root))
            return true;
        else
            return false;
    }
}

Node* Find_Parent(Node*p,Node*child){
    if(p==NULL)
        return NULL;
    if(p->left==child||p->right==child)
        return p;
    else if(child->value<p->value){
        return Find_Parent(p->left,child);
    }
    else
        return Find_Parent(p->right,child);
}

Status BST_delete(BinarySortTreePtr BST, ElemType data){
    //树为空
    if(BST->root==NULL){
        printf("树为空\n");
        return failed;
    }
    //搜索看，该值是否存在
    if(BST_search(BST,data)){
        NodePtr q,parent;
        //只有左孩子
        if(temp_point->right==NULL&temp_point->left!=NULL){
            q=temp_point->left;
            temp_point->value=q->value;
            temp_point->left=q->left;
            temp_point->right=q->right;
            free(q);
        }
        //只有右孩子
        else if(temp_point->left==NULL&temp_point->right!=NULL){
            q=temp_point->right;
            temp_point->value=q->value;
            temp_point->left=q->left;
            temp_point->right=q->right;
            free(q);
        }

        //有左右孩子
        else if(temp_point->right!=NULL&&temp_point->left!=NULL){
            parent=temp_point;
            q=temp_point->left;
            while(q->right){
                parent=q;
                q=q->right;
            }
            temp_point->value=q->value;
            if(parent==temp_point)
                parent->left=q->left;
            else
                parent->right=q->left;
            free(q);
        }

        //没有孩子
        else{
            //只有一个根节点
            if(BST->root==temp_point){
                free(BST->root);
                BST->root=NULL;
                return succeed;
            }
            parent=Find_Parent(BST->root,temp_point);
            if(parent->left==temp_point)
                parent->left=NULL;
            else
                parent->right=NULL;
            free(temp_point);
        }
        return succeed;
    }
}

void show(NodePtr p){
    printf("%d ", p->value);
}

//前序 递归 根 左 右
Status BST_preorderR(NodePtr p, void (*visit)(NodePtr)){
    if(p==NULL)
        return failed;
    visit(p);
    BST_preorderR(p->left,visit);
    BST_preorderR(p->right,visit);

    return succeed;
}

//中序 递归
Status BST_inorderR(NodePtr p, void (*visit)(NodePtr)){
    if(p==NULL)
        return failed;
    else{
        BST_inorderR(p->left,visit);
        visit(p);
        BST_inorderR(p->right,visit);
        return succeed;
    }
}

//后序 递归
Status BST_postorderR(NodePtr p, void (*visit)(NodePtr)){
    if(p==NULL)
        return failed;
    else{
        BST_postorderR(p->left,visit);
        BST_postorderR(p->right,visit);
        visit(p);
        return succeed;
    }
}

//前序 迭代
Status BST_preorderI(BinarySortTreePtr BST, void (*visit)(NodePtr)){
    if(BST->root==NULL){
        printf("树为空，无可遍历值\n");
        return failed;
    }
    Node *stack[50];
    int top=0;
    stack[top++]=BST->root;   //根节点入栈
    NodePtr point;
    //栈不为空
    while(top>0){
        point=stack[--top];     //出栈
        visit(point);      //打印出来
        //若存在右孩子，将弹出节点的右孩子入栈
        if(point->right!=NULL)
            stack[top++]=point->right;
        //右孩子入栈后到左孩子
        if(point->left!=NULL)
            stack[top++]=point->left;
    }
    return succeed;
}

//中序 迭代 左 根 右
Status BST_inorderI(BinarySortTreePtr BST, void (*visit)(NodePtr)){
    if(BST->root==NULL){
        printf("树为空，无可遍历值\n");
        return failed;
    }
    Node *stack[50];
    int top =0;
    NodePtr point;
    point=BST->root;
    while(top>0||point){
        //从根节点开始，先把最左支全部入栈
        while(point){
            stack[top++]=point;
            point=point->left;
        }
        //入栈完之后，弹出栈顶元素并打印出来，首先弹出的是最左下角的元素
        point=stack[--top];
        visit(point);
        //再看弹出的节点是否有右孩子，有则指向其右孩子，访问右孩子，同样是先把左支入栈（即回到上面的步骤）
        point=point->right;
    }
    return succeed;
}

//后序 迭代   左 右 根
Status BST_postorderI(BinarySortTreePtr BST, void (*visit)(NodePtr)){
    if(BST->root==NULL){
        printf("树为空，无可遍历值\n");
        return failed;
    }
    Node *stack[50];
    //flag用来标记该节点是否已经遍历完，1为未，0为已，已经遍历完代表可以输出该节点
    int top =-1,flag=1;
    //利用p指针来遍历整个二叉树
    NodePtr point;
    point=BST->root;
    //根节点先入栈（最后出）
    stack[++top]=point;
    while(top>-1){
        while(point&&flag){
            //如果该节点下右孩子存在，入栈
            if(point->right)
                stack[++top]=point->right;
            //左孩子存在，入栈
            if(point->left)
                stack[++top]=point->left;
            //当前节点的孩子入栈完之后，指针指向孩子，左孩子优先，重复刚才的步骤，直到遇到NULL
            if(point->left)
                point=point->left;
            else
                point=point->right;
        }
        point=stack[top--];
        visit(point);
        if(top==-1)     //只有根节点
            break;
        //如果弹出的节点与栈内前一个节点是父子关系，说明这个父节点的子树已经遍历完，
        // 则更改标记flag，即表示该父节点可以输出
        //top--;
        if(point==stack[top]->right||point==stack[top]->left)
            flag=0;
        else
            flag=1;
        point=stack[top];
    }

    return succeed;
}

void queue_in(NodePtr p,LQueue*Q){
    Q->num[Q->rear]=p;
    Q->rear++;
}

NodePtr queue_out(LQueue *Q){
    return Q->num[Q->front++];
}

//层序遍历
Status BST_levelOrder(BinarySortTreePtr BST, void (*visit)(NodePtr)){
    if(BST->root==NULL)
        return failed;
    //创建队列，并对其初始化
    LQueue queue;
    queue.front=0;
    queue.rear=0;

    //把根节点入队
    queue_in(BST->root,&queue);

    //开始循环，条件为队列不为空
    NodePtr point;
    while (queue.front!=queue.rear) {
        //队头元素出队
        point=queue_out(&queue);
        visit(point);
        //其孩子入队，若存在左孩子，左孩子入队
        if(point->left!=NULL){
            queue_in(point->left,&queue);
        }
        //若存在右孩子，右孩子入队
        if(point->right!=NULL){
            queue_in(point->right,&queue);
        }

    }
    return succeed;
}
