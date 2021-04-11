#include <stdio.h>
#include <stdlib.h>
#include<string.h>

#include"LQueue.h"




int main() {
    LQueue queue;

    InitLQueue(&queue);

    while(1){
        printf( "**********************************************\n");
        printf( "*                   链式队列                 *\n");
        printf( "**********************************************\n");
        printf( "*                1:判断是否为空              * \n");
        printf( "*                2:获取队列长度              * \n");
        printf( "*                3:入队                      * \n");
        printf( "*                4:出队                      * \n");
        printf( "*                5:获取队头元素              * \n");
        printf( "*                6:遍历队列                  * \n");
        printf( "*                7:清空队列                  * \n");
        printf( "*                8:销毁队列                  * \n");
        printf( "*                9:清屏                      * \n");
        printf( "*                0:退出程序                  * \n");
        printf( "**********************************************\n" );
        char choice;
        void *data;
        void *data_;
        int L, a,temp;
        double b;
        char c,_choice;
        void(*foo)(void*);
        printf("请输入您的选择：\n");
        scanf("%c", &choice);
        fflush(stdin);
        switch (choice) {
            case ('1'):
                if (IsEmptyLQueue(&queue))
                    printf("队列为空!\n");
                else
                    printf("队列非空！\n");
                break;
            case ('2'):
                L = LengthLQueue(&queue);
                printf("队列长度为：%d\n", L);
                break;
            case ('3'):
                printf("请选择要输入元素的数据类型：\n");
                printf("i: int\nd: double\nc: char\n");
                fflush(stdin);
                scanf("%c", &type);
                switch (type) {
                    case ('i'):
                        datatype[count] = '4';
                        printf("请输入元素：\n");
                        scanf("%d", &a);
                        fflush(stdin);
                        data = &a;
                        EnLQueue(&queue, data);
                        break;
                    case ('d'):
                        datatype[count] = '8';
                        printf("请输入元素：\n");
                        scanf("%lf", &b);
                        fflush(stdin);
                        data = &b;
                        EnLQueue(&queue, data);
                        break;
                    case ('c'):
                        datatype[count] = '1';
                        printf("请输入元素：\n");
                        fflush(stdin);
                        scanf("%c", &c);
                        fflush(stdin);
                        data = &c;
                        EnLQueue(&queue, data);
                        break;
                    default:
                        printf("输入错误，请重新输入：\n");
                        break;
                }
                break;
            case ('4'):
                if (IsEmptyLQueue(&queue)) {
                    printf("队列为空!\n");
                    break;
                }
                else{
                    DeLQueue(&queue);
                    break;
                }
            case('5'):
                if (IsEmptyLQueue(&queue)) {
                    printf("队列为空!\n");
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
                    printf("队列为空!\n");
                    break;
                }
                else{
                    foo=LPrint;
                    TraverseLQueue(&queue,foo);
                    break;
                }
            case ('7'):
                ClearLQueue(&queue);
                printf("队列已清空\n");
                break;
            case('8'):
                DestoryLQueue(&queue);
                printf("队列已销毁\n");
                temp=1;
                while(temp){
                    printf("1.初始化队列  2.退出\n");
                    printf("请输入您的选择：\n");
                    fflush(stdin);
                    scanf("%c", &_choice);
                    fflush(stdin);
                    switch(_choice){
                        case('1'):
                            InitLQueue(&queue);
                            temp=0;
                            break;
                        case('2'):
                            printf("感谢您的使用，再见！\n");
                            exit(0);
                        default:
                            printf("输入错误，请重新输入：\n");
                            break;
                    }
                    fflush(stdin);
                }
                break;
            case('9'):
                system("cls");
                break;
            case ('0'):
                printf("感谢您的使用!\n");
                exit(0);
            default:
                printf("输入错误，请重新输入：\n");
                break;
        }
        fflush(stdin);
    }
    return 0;
}
