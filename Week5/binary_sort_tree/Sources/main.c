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
    BST_init(BST);     //��ʼ��
    while(1) {
        printf("***********************************************\n");
        printf("*                0:����                       * \n");
        printf("*                1:����                       * \n");
        printf("*                2:ɾ��                       * \n");
        printf("*                3:ǰ��������ݹ飩           * \n");
        printf("*                4:ǰ�������������           * \n");
        printf("*                5:����������ݹ飩           * \n");
        printf("*                6:���������������           * \n");
        printf("*                7:����������ݹ飩           * \n");
        printf("*                8:���������������           * \n");
        printf("*                9:�������                   * \n");
        printf("*                c:����                       * \n");
        printf("*                q:�˳�����                   * \n");
        printf("***********************************************\n");
        printf("��ѡ���ܣ�\n");
        char choice;
        scanf("%c",&choice);
        fflush(stdin);
        if (input(choice) == 1) {
            int data,num;
            void (*visit)(NodePtr);

            switch (choice) {
                case('0'):
                    printf("���������Ԫ�أ�\n");
                    scanf("%d",&data);
                    BST_insert(BST,data);
                    break;
                case('1'):
                    printf("������������Ԫ�أ�\n");
                    scanf("%d",&data);
                    num=BST_search(BST,data);
                    if(num==0)
                        printf("��ֵ������\n");
                    else
                        printf("��ֵ����\n");
                    break;

                case('2'):
                    printf("������ɾ����Ԫ�أ�\n");
                    scanf("%d",&data);
                    num=BST_delete(BST,data);
                    if(num==1)
                        printf("ɾ���ɹ�\n");
		    else
                        printf("��ֵ������\n");
                    break;

                case('3'):
                    if(BST->root==NULL){
                        printf("��Ϊ��,�޿ɱ���ֵ\n");
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
                        printf("��Ϊ��,�޿ɱ���ֵ\n");
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
                        printf("��Ϊ��,�޿ɱ���ֵ\n");
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
                        printf("��Ϊ��,�޿ɱ���ֵ\n");
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
                    printf("��л����ʹ�ã������˳�����\n");
                    exit(0);
            }
            fflush(stdin);
        }
        else{
            printf("����������������룡\n");
        }
    }

}
