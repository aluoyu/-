#include <stdio.h>
#include <stdlib.h>
#include<string.h>

#include"LQueue.h"




int main() {
    LQueue queue;

    InitLQueue(&queue);

    while(1){
        printf( "**********************************************\n");
        printf( "*                   ��ʽ����                 *\n");
        printf( "**********************************************\n");
        printf( "*                1:�ж��Ƿ�Ϊ��              * \n");
        printf( "*                2:��ȡ���г���              * \n");
        printf( "*                3:���                      * \n");
        printf( "*                4:����                      * \n");
        printf( "*                5:��ȡ��ͷԪ��              * \n");
        printf( "*                6:��������                  * \n");
        printf( "*                7:��ն���                  * \n");
        printf( "*                8:���ٶ���                  * \n");
        printf( "*                9:����                      * \n");
        printf( "*                0:�˳�����                  * \n");
        printf( "**********************************************\n" );
        char choice;
        void *data;
        void *data_;
        int L, a,temp;
        double b;
        char c,_choice;
        void(*foo)(void*);
        printf("����������ѡ��\n");
        scanf("%c", &choice);
        fflush(stdin);
        switch (choice) {
            case ('1'):
                if (IsEmptyLQueue(&queue))
                    printf("����Ϊ��!\n");
                else
                    printf("���зǿգ�\n");
                break;
            case ('2'):
                L = LengthLQueue(&queue);
                printf("���г���Ϊ��%d\n", L);
                break;
            case ('3'):
                printf("��ѡ��Ҫ����Ԫ�ص��������ͣ�\n");
                printf("i: int\nd: double\nc: char\n");
                fflush(stdin);
                scanf("%c", &type);
                switch (type) {
                    case ('i'):
                        datatype[count] = '4';
                        printf("������Ԫ�أ�\n");
                        scanf("%d", &a);
                        fflush(stdin);
                        data = &a;
                        EnLQueue(&queue, data);
                        break;
                    case ('d'):
                        datatype[count] = '8';
                        printf("������Ԫ�أ�\n");
                        scanf("%lf", &b);
                        fflush(stdin);
                        data = &b;
                        EnLQueue(&queue, data);
                        break;
                    case ('c'):
                        datatype[count] = '1';
                        printf("������Ԫ�أ�\n");
                        fflush(stdin);
                        scanf("%c", &c);
                        fflush(stdin);
                        data = &c;
                        EnLQueue(&queue, data);
                        break;
                    default:
                        printf("����������������룺\n");
                        break;
                }
                break;
            case ('4'):
                if (IsEmptyLQueue(&queue)) {
                    printf("����Ϊ��!\n");
                    break;
                }
                else{
                    DeLQueue(&queue);
                    break;
                }
            case('5'):
                if (IsEmptyLQueue(&queue)) {
                    printf("����Ϊ��!\n");
                    break;
                }
                else{
                    outNum=0;
                    data_=(void*)malloc(datatype[outNum]-'0');
                    GetHeadLQueue(&queue,data_);
                    LPrint(data_);
                    printf("\n");
                    break;
                }
            case('6'):
                if (IsEmptyLQueue(&queue)) {
                    printf("����Ϊ��!\n");
                    break;
                }
                else{
                    foo=LPrint;
                    TraverseLQueue(&queue,foo);
                    break;
                }
            case ('7'):
                ClearLQueue(&queue);
                printf("���������\n");
                break;
            case('8'):
                DestoryLQueue(&queue);
                printf("����������\n");
                temp=1;
                while(temp){
                    printf("1.��ʼ������  2.�˳�\n");
                    printf("����������ѡ��\n");
                    fflush(stdin);
                    scanf("%c", &_choice);
                    fflush(stdin);
                    switch(_choice){
                        case('1'):
                            InitLQueue(&queue);
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
                break;
            case('9'):
                system("cls");
                break;
            case ('0'):
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
