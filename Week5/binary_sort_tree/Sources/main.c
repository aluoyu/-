#include <stdio.h>
#include <stdlib.h>
#include "binary_sort_tree.h"

int input(char choice){
    if((choice>='0'&&choice<='9')||choice=='c'||choice=='q'){
        return 1;
    }
    else
        return -1;
}

int main() {
    BinarySortTree binarySortTree;
    BinarySortTreePtr BST;
    BST=&binarySortTree;
    BST_init(BST);     //初始化
    while(1) {
        printf("***********************************************\n");
        printf("*                0:插入                       * \n");
        printf("*                1:搜索                       * \n");
        printf("*                2:删除                       * \n");
        printf("*                3:前序遍历（递归）           * \n");
        printf("*                4:前序遍历（迭代）           * \n");
        printf("*                5:中序遍历（递归）           * \n");
        printf("*                6:中序遍历（迭代）           * \n");
        printf("*                7:后序遍历（递归）           * \n");
        printf("*                8:后序遍历（迭代）           * \n");
        printf("*                9:层序遍历                   * \n");
        printf("*                c:清屏                       * \n");
        printf("*                q:退出程序                   * \n");
        printf("***********************************************\n");
        printf("请选择功能：\n");
        char choice;
        scanf("%c",&choice);
        fflush(stdin);
        if (input(choice) == 1) {
            int data,num;
            void (*visit)(NodePtr);

            switch (choice) {
                case('0'):
                    printf("请输入插入元素：\n");
                    scanf("%d",&data);
                    BST_insert(BST,data);
                    break;
                case('1'):
                    printf("请输入搜索的元素：\n");
                    scanf("%d",&data);
                    num=BST_search(BST,data);
                    if(num==0)
                        printf("该值不存在\n");
                    else
                        printf("该值存在\n");
                    break;

                case('2'):
                    printf("请输入删除的元素：\n");
                    scanf("%d",&data);
                    num=BST_delete(BST,data);
                    if(num==1)
                        printf("删除成功\n");
		    else
                        printf("该值不存在\n");
                    break;

                case('3'):
                    if(BST->root==NULL){
                        printf("树为空,无可遍历值\n");
                    }
                    else {
                        visit=show;
                        BST_preorderR(BST->root, visit);
                        printf("\n");
                    }
                    break;

                case('4'):
                    visit=show;
                    BST_preorderI(BST,visit);
                    printf("\n");
                    break;

                case('5'):
                    if(BST->root==NULL){
                        printf("树为空,无可遍历值\n");
                    }
                    else {
                        visit=show;
                        BST_inorderR(BST->root, visit);
                        printf("\n");
                    }
                    break;

                case('6'):
                    visit=show;
                    BST_inorderI(BST, visit);
                    printf("\n");
                    break;

                case('7'):
                    if(BST->root==NULL){
                        printf("树为空,无可遍历值\n");
                    }
                    else {
                        visit=show;
                        BST_postorderR(BST->root, visit);
                        printf("\n");
                    }
                    break;

                case('8'):
                    visit=show;
                    BST_postorderI(BST, visit);
                    printf("\n");
                    break;

                case('9'):
                    if(BST->root==NULL){
                        printf("树为空,无可遍历值\n");
                    }
                    else{
                        visit=show;
                        BST_levelOrder(BST, visit);
                        printf("\n");
                    }
                    break;

                case('c'):
                    system("cls");
                    break;
                case('q'):
                    printf("感谢您的使用，即将退出程序\n");
                    exit(0);
            }
            fflush(stdin);
        }
        else{
            printf("输入错误，请重新输入！\n");
        }
    }

}
