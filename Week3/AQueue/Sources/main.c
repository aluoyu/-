#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include"AQueue.h"

int main() {
    AQueue queue;     //����һ��ָ��ṹ���ָ��
    InitAQueue(&queue);

    while(1){
        printf( "**********************************************\n");
        printf( "*                   ˳�����                 *\n");
        printf( "**********************************************\n");
        printf( "*                1:�ж��Ƿ�����              * \n");
        printf( "*                2:�ж��Ƿ�Ϊ��              * \n");
        printf( "*                3:��ȡ���г���              * \n");
        printf( "*                4:���                      * \n");
        printf( "*                5:����                      * \n");
        printf( "*                6:��ȡ��ͷԪ��              * \n");
        printf( "*                7:��������                  * \n");
        printf( "*                8:��ն���                  * \n");
        printf( "*                9:���ٶ���                  * \n");
        printf( "*                c:����                      * \n");
        printf( "*                0:�˳�����                  * \n");
        printf( "**********************************************\n" );
        char choice,_choice;
        char c;
        void* data;
        int num,temp;
        double a;
        void(*foo)(void*);
        printf("����������ѡ��\n");
        scanf("%c", &choice);
        fflush(stdin);
        switch(choice){
            case('1'):
                if(IsFullAQueue(&queue))
                    printf("����������\n");
                else
                    printf("����δ����\n");
                break;
            case('2'):
                if(IsEmptyAQueue(&queue))
                    printf("����Ϊ�գ�\n");
                else
                    printf("���зǿգ�\n");
                break;
            case('3'):
                num=LengthAQueue(&queue);
                printf("���г���Ϊ��%d\n",num);
                break;
            case('4'):
                if(!IsFullAQueue(&queue)) {
                    printf("��ѡ��Ҫ����Ԫ�ص��������ͣ�\n");
                    printf("i: int\nd: double\nc: char\n");
                    fflush(stdin);
                    scanf("%c", &type);
                    fflush(stdin);
                    switch (type) {
                        case ('i'):
                            datatype[(queue.rear + 1) % MAXQUEUE] = '4';
                            printf("������Ԫ�أ�\n");
                            scanf("%d", &num);
                            fflush(stdin);
                            data = &num;
                            EnAQueue(&queue, data);
                            break;
                        case('d'):
                            datatype[(queue.rear + 1) % MAXQUEUE] = '8';
                            printf("������Ԫ�أ�\n");
                            scanf("%lf", &a);
                            fflush(stdin);
                            data = &a;
                            EnAQueue(&queue, data);
                            break;
                        case('c'):
                            datatype[(queue.rear + 1) % MAXQUEUE] = '1';
                            printf("������Ԫ�أ�\n");
                            fflush(stdin);
                            scanf("%c", &c);
                            fflush(stdin);
                            data = &c;
                            EnAQueue(&queue, data);
                            break;
                        default:
                            printf("����������������룺\n");
                            break;
                    }
                    break;
                }
                else
                    printf("����������\n");
                break;
            case('5'):
                DeAQueue(&queue);
                break;
            case('6'):
                if(IsEmptyAQueue(&queue))
                    printf("����Ϊ�գ�\n");
                else{
                    GetHeadAQueue(&queue,data);
                    count=(queue.front+1)%MAXQUEUE;
                    APrint(data);
                    printf("\n");
                    break;
                }
                break;
            case('8'):      //��ն���
                ClearAQueue(&queue);
                break;
            case('7'):
                if(IsEmptyAQueue(&queue))
                    printf("����Ϊ�գ�\n");
                else{
                    foo=APrint;
                    TraverseAQueue(&queue,foo);
                    printf("\n");
                }
                break;
            case('9'):
                DestoryAQueue(&queue);
                printf("���ٳɹ���\n");
                temp=1;
                while(temp){
                    printf("1.��ʼ������  2.�˳�\n");
                    printf("����������ѡ��\n");
                    scanf("%c", &_choice);
                    switch(_choice){
                        case ('1'):
                            InitAQueue(&queue);
                            temp=0;
                            break;
                        case('2'):
                            printf("��л����ʹ�ã��ټ���\n");
                            exit(0);
                        default:
                            printf("����������������룺\n");
                            break;
                    }
                    fflush(stdin);
                }
                fflush(stdin);
                break;
            case('0'):
                printf("��л����ʹ��!\n");
                exit(0);
            case('c'):
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
