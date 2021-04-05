#include <stdio.h>
#include <stdlib.h>
#include "SqStack.h"

int main() {
    SqStack stack;
    stack.elem=NULL;
    int *element=NULL;
    int sizes;
    int length=0;
    ElemType data;
    ElemType num;
    enum Status situation,condition;
    int choice_;
    int temp;
    while (1) {
        printf( "**********************************************\n");
        printf( "*                   ˳��ջ                   *\n");
        printf( "**********************************************\n");
        printf( "*                1:��ʼ��                    * \n");
        printf( "*                2:��ջ                      * \n");
        printf( "*                3:��ջ                      * \n");
        printf( "*                4:��ȡջ��Ԫ��              * \n");
        printf( "*                5:�жϿ�ջ                  * \n");
        printf( "*                6:��ⳤ��                  * \n");
        printf( "*                7:���                      * \n");
        printf( "*                8:����                      * \n");
        printf( "*                9:����                      * \n");
        printf( "*                0:�˳�����                  * \n");
        printf( "**********************************************\n" );
        int choice;
        printf("����������ѡ��\n");
        scanf("%d", &choice);
        switch (choice) {
            case (1):   //��ʼ��ջ
                printf("������ջ����󳤶ȣ�\n");
                scanf("%d", &sizes);
                initStack(&stack, sizes);   //��ʼ��
                break;
            case(2):    //��ջ
                if(stack.elem==NULL) {
                    printf("δ��ʼ��ջ��ջ�����ڣ�\n");
                }
                else{
                    printf("����Ҫ��ջ�����ݣ�\n");
                    scanf("%d", &data);
                    pushStack(&stack,data);
                }
                break;
            case(3):    //��ջ
                if(stack.elem==NULL) {     //�ж��Ƿ��ʼ��
                    printf("δ��ʼ��ջ��ջ�����ڣ�\n");
                }
                else{
                    situation=isEmptyStack(&stack);//�ж��Ƿ�Ϊ��
                    if(situation==SUCCESS){    //��Ϊ��ʱ�����Գ�ջ
                        popStack(&stack,&num);
                        printf("��ջ�ɹ�\n");
                        printf("��ջ������Ϊ��%d\n",num);
                    }
                    else{   //ջΪ��
                        printf("��Ϊ��ջ���޿ɳ�ջ����ֵ\n");
                    }
                }
                break;
            case(4):
                if(stack.elem==NULL) {
                    printf("δ��ʼ��ջ��ջ�����ڣ�\n");
                }
                else {
                    getTopStack(&stack, element);
                    if (element==NULL) {
                        printf("������ջ��Ԫ��\n");
                    }
                    else
                        printf("%d", *element);
                }
                break;
            case(5):    //�ж��Ƿ�Ϊ��
                if(stack.elem==NULL) {
                    printf("δ��ʼ��ջ��ջ�����ڣ�\n");
                }
                else{
                    situation=isEmptyStack(&stack);
                    if(situation==SUCCESS){
                        printf("�˷ǿ�ջ\n");
                    }
                    else{
                        printf("��Ϊ��ջ\n");
                    }
                }
                break;
            case(6):
                stackLength(&stack,&length);
                break;
            case(7):
                if(stack.elem==NULL) {
                    printf("δ��ʼ��ջ��ջ�����ڣ�\n");
                }
                else {
                    clearStack(&stack);
                    length=0;
                }
                break;
            case(8):
                temp=1;
                condition=destroyStack(&stack);
                if(condition==SUCCESS){
                    while(temp) {
                        printf("1.��ʼ��ջ  2.�˳�\n");
                        printf("����������ѡ��\n");
                        scanf("%d", &choice_);
                        switch (choice_) {
                            case (1):
                                printf("������ջ����󳤶ȣ�\n");
                                scanf("%d", &sizes);
                                initStack(&stack, sizes);   //��ʼ��
                                temp=0;
                                break;
                            case (2):
                                exit(0);
                            default:
                                printf("����������������룺\n");
                                break;
                        }
                        fflush(stdin);
                    }
                }
                break;
            case(9):
                system("cls");
                break;
            case(0):
                printf("��л����ʹ��!\n");
                exit(0);
            default:
                printf("����������������룺\n");
                break;
        }
        fflush(stdin);
    }
    return 0;
}
