#include <stdio.h>
#include <stdlib.h>
#include"LinkStack.h"

int main() {
    LinkStack linkStack;
    ElemType e,data;
    int length,number,temp=1;
    char choice_;
    enum Status situation;
    initLStack(&linkStack);
    while (1) {
        printf("**********************************************\n");
        printf("*                    ��ջ                    *\n");
        printf("**********************************************\n");
        printf("*                1:��ʼ��                    * \n");
        printf("*                2:��ջ                      * \n");
        printf("*                3:��ջ                      * \n");
        printf("*                4:��ȡջ��Ԫ��              * \n");
        printf("*                5:�жϿ�ջ                  * \n");
        printf("*                6:��ⳤ��                  * \n");
        printf("*                7:���                      * \n");
        printf("*                8:����                      * \n");
        printf("*                9:����                      * \n");
        printf("*                0:�˳�                      * \n");
        printf("**********************************************\n");
        char choice;
        printf("����������ѡ��\n");
        scanf("%c", &choice);
        switch (choice) {
            case ('1'):   //��ʼ��ջ
                initLStack(&linkStack);   //��ʼ��
                break;
            case('2'):
                printf("����Ҫ��ջ�����ݣ�\n");
                scanf("%d", &data);
                pushLStack(&linkStack,data);
                break;
            case('3'):
                if(isEmptyLStack(&linkStack)==SUCCESS){    //��ջ�ǿյ�ʱ��
                    popLStack(&linkStack,&data);
                    printf("��ջԪ��Ϊ��%d\n",data);
                }
                else{
                    printf("��ջΪ��,�����ݿɻ�ȡ\n");
                }
                break;
            case('4'):
                if(isEmptyLStack(&linkStack)==SUCCESS){    //��ջ�ǿյ�ʱ��
                    getTopLStack(&linkStack,&e);
                    printf("ջ��Ԫ��Ϊ��%d\n",e);
                }
                else{
                    printf("��ջΪ��,�����ݿɻ�ȡ\n");
                }
                break;
            case('5'):
                situation=isEmptyLStack(&linkStack);
                if(situation==SUCCESS){
                    printf("��ջ�ǿ�\n");
                }
                else
                    printf("��ջΪ��\n");
                break;
            case('6'):
                LStackLength(&linkStack,&length);
                printf("��ջ����Ϊ��%d\n",length);
                break;
            case('7'):
                clearLStack(&linkStack);
                break;
            case('8'):
                printf("ȷ�����٣�\n");
                printf("ȷ��������1  ȡ������������һ����\n");
                scanf("%d", &number);
                fflush(stdin);
                if (number == 1){
                    destroyLStack(&linkStack);
                    printf("���ٳɹ�\n");
                    while(temp) {
                        printf("1.��ʼ��ջ  2.�˳�\n");
                        printf("����������ѡ��\n");
                        scanf("%c", &choice_);
                        switch (choice_) {
                            case ('1'):
                                initLStack(&linkStack);   //��ʼ��
                                temp=0;
                                break;
                            case ('2'):
                                printf("��л����ʹ�ã��ټ���\n");
                                exit(0);
                            default:
                                printf("����������������룺\n");
                                break;
                        }
                        fflush(stdin);
                    }
                }
                break;
            case('0'):
                printf("��л����ʹ�ã��ټ���\n");
                exit(0);
            case('9'):
                system("cls");
                break;
            default:
                printf("����������������룺\n");
                break;
        }
        fflush(stdin);
    }
    return 0;
}
