#include <stdio.h>
#include <stdlib.h>
#include "binary_sort_tree.h"

//��ʼ��
Status BST_init(BinarySortTreePtr BST){
    BST->root=NULL;
    return succeed;
}

//����
Status BST_insert(BinarySortTreePtr BST, ElemType data){
    NodePtr point=(NodePtr)malloc(sizeof(Node));
    if(point!=NULL) {
        point->value = data;
        point->right = NULL;
        point->left = NULL;

        //������ʱ��ֱ�Ӱ����ݷ��ڸ��ڵ���
        if(BST->root==NULL){
            BST->root=point;
            printf("����ɹ�\n");
            return succeed;
        }

        //����Ϊ��
        else {
            //�����鿴�����Ƿ��Ѿ����ڸ�ֵ������Ϊ1��������Ϊ0
            if (BST_search(BST, data) == 1) {
                printf("��ֵ�Ѵ��ڣ�\n\n");
                return failed;
            }
            //������
            if(data<temp_point->value){
                temp_point->left=point;
            }
            else
                temp_point->right=point;
	    printf("����ɹ�\n\n");
            return succeed;
        }
    }
    else {
        printf("�ڴ����ʧ�ܣ�\n\n");
        return failed;
    }
}

Status search(Node*p,int data,Node*parent){
    //������Ľڵ�Ϊ��
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


//����,���ش��ڵ�ֵ
Status BST_search(BinarySortTreePtr BST, ElemType data){
    if(BST->root==NULL)     //��Ϊ��
        return false;
    //���ڸ��ڵ㣬ֱ�ӷ���
    if(data==BST->root->value)
        return true;
    //С�ڸ��ڵ㣬������������
    else if(data<BST->root->value){
        if(search(BST->root->left,data,BST->root))
            return true;
        else
            return false;
    }
    //���ڸ��ڵ㣬������������
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
    //��Ϊ��
    if(BST->root==NULL){
        printf("��Ϊ��\n");
        return failed;
    }
    //����������ֵ�Ƿ����
    if(BST_search(BST,data)){
        NodePtr q,parent;
        //ֻ������
        if(temp_point->right==NULL&temp_point->left!=NULL){
            q=temp_point->left;
            temp_point->value=q->value;
            temp_point->left=q->left;
            temp_point->right=q->right;
            free(q);
        }
        //ֻ���Һ���
        else if(temp_point->left==NULL&temp_point->right!=NULL){
            q=temp_point->right;
            temp_point->value=q->value;
            temp_point->left=q->left;
            temp_point->right=q->right;
            free(q);
        }

        //�����Һ���
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

        //û�к���
        else{
            //ֻ��һ�����ڵ�
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

//ǰ�� �ݹ� �� �� ��
Status BST_preorderR(NodePtr p, void (*visit)(NodePtr)){
    if(p==NULL)
        return failed;
    visit(p);
    BST_preorderR(p->left,visit);
    BST_preorderR(p->right,visit);

    return succeed;
}

//���� �ݹ�
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

//���� �ݹ�
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

//ǰ�� ����
Status BST_preorderI(BinarySortTreePtr BST, void (*visit)(NodePtr)){
    if(BST->root==NULL){
        printf("��Ϊ�գ��޿ɱ���ֵ\n");
        return failed;
    }
    Node *stack[50];
    int top=0;
    stack[top++]=BST->root;   //���ڵ���ջ
    NodePtr point;
    //ջ��Ϊ��
    while(top>0){
        point=stack[--top];     //��ջ
        visit(point);      //��ӡ����
        //�������Һ��ӣ��������ڵ���Һ�����ջ
        if(point->right!=NULL)
            stack[top++]=point->right;
        //�Һ�����ջ������
        if(point->left!=NULL)
            stack[top++]=point->left;
    }
    return succeed;
}

//���� ���� �� �� ��
Status BST_inorderI(BinarySortTreePtr BST, void (*visit)(NodePtr)){
    if(BST->root==NULL){
        printf("��Ϊ�գ��޿ɱ���ֵ\n");
        return failed;
    }
    Node *stack[50];
    int top =0;
    NodePtr point;
    point=BST->root;
    while(top>0||point){
        //�Ӹ��ڵ㿪ʼ���Ȱ�����֧ȫ����ջ
        while(point){
            stack[top++]=point;
            point=point->left;
        }
        //��ջ��֮�󣬵���ջ��Ԫ�ز���ӡ���������ȵ������������½ǵ�Ԫ��
        point=stack[--top];
        visit(point);
        //�ٿ������Ľڵ��Ƿ����Һ��ӣ�����ָ�����Һ��ӣ������Һ��ӣ�ͬ�����Ȱ���֧��ջ�����ص�����Ĳ��裩
        point=point->right;
    }
    return succeed;
}

//���� ����   �� �� ��
Status BST_postorderI(BinarySortTreePtr BST, void (*visit)(NodePtr)){
    if(BST->root==NULL){
        printf("��Ϊ�գ��޿ɱ���ֵ\n");
        return failed;
    }
    Node *stack[50];
    //flag������Ǹýڵ��Ƿ��Ѿ������꣬1Ϊδ��0Ϊ�ѣ��Ѿ�����������������ýڵ�
    int top =-1,flag=1;
    //����pָ������������������
    NodePtr point;
    point=BST->root;
    //���ڵ�����ջ��������
    stack[++top]=point;
    while(top>-1){
        while(point&&flag){
            //����ýڵ����Һ��Ӵ��ڣ���ջ
            if(point->right)
                stack[++top]=point->right;
            //���Ӵ��ڣ���ջ
            if(point->left)
                stack[++top]=point->left;
            //��ǰ�ڵ�ĺ�����ջ��֮��ָ��ָ���ӣ��������ȣ��ظ��ղŵĲ��裬ֱ������NULL
            if(point->left)
                point=point->left;
            else
                point=point->right;
        }
        point=stack[top--];
        visit(point);
        if(top==-1)     //ֻ�и��ڵ�
            break;
        //��������Ľڵ���ջ��ǰһ���ڵ��Ǹ��ӹ�ϵ��˵��������ڵ�������Ѿ������꣬
        // ����ı��flag������ʾ�ø��ڵ�������
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

//�������
Status BST_levelOrder(BinarySortTreePtr BST, void (*visit)(NodePtr)){
    if(BST->root==NULL)
        return failed;
    //�������У��������ʼ��
    LQueue queue;
    queue.front=0;
    queue.rear=0;

    //�Ѹ��ڵ����
    queue_in(BST->root,&queue);

    //��ʼѭ��������Ϊ���в�Ϊ��
    NodePtr point;
    while (queue.front!=queue.rear) {
        //��ͷԪ�س���
        point=queue_out(&queue);
        visit(point);
        //�亢����ӣ����������ӣ��������
        if(point->left!=NULL){
            queue_in(point->left,&queue);
        }
        //�������Һ��ӣ��Һ������
        if(point->right!=NULL){
            queue_in(point->right,&queue);
        }

    }
    return succeed;
}
