#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include"AQueue.h"

int main() {
    AQueue queue;     //定义一个指向结构体得指针
    InitAQueue(&queue);

    while(1){
        printf( "**********************************************\n");
        printf( "*                   顺序队列                 *\n");
        printf( "**********************************************\n");
        printf( "*                1:判断是否已满              * \n");
        printf( "*                2:判断是否为空              * \n");
        printf( "*                3:获取队列长度              * \n");
        printf( "*                4:入队                      * \n");
        printf( "*                5:出队                      * \n");
        printf( "*                6:获取队头元素              * \n");
        printf( "*                7:遍历队列                  * \n");
        printf( "*                8:清空队列                  * \n");
        printf( "*                9:销毁队列                  * \n");
        printf( "*                c:清屏                      * \n");
        printf( "*                0:退出程序                  * \n");
        printf( "**********************************************\n" );
        char choice,_choice;
        char c;
        void* data;
        int num,temp;
        double a;
        void(*foo)(void*);
        printf("请输入您的选择：\n");
        scanf("%c", &choice);
        fflush(stdin);
        switch(choice){
            case('1'):
                if(IsFullAQueue(&queue))
                    printf("队列已满！\n");
                else
                    printf("队列未满！\n");
                break;
            case('2'):
                if(IsEmptyAQueue(&queue))
                    printf("队列为空！\n");
                else
                    printf("队列非空！\n");
                break;
            case('3'):
                num=LengthAQueue(&queue);
                printf("队列长度为：%d\n",num);
                break;
            case('4'):
                if(!IsFullAQueue(&queue)) {
                    printf("请选择要输入元素的数据类型：\n");
                    printf("i: int\nd: double\nc: char\n");
                    fflush(stdin);
                    scanf("%c", &type);
                    fflush(stdin);
                    switch (type) {
                        case ('i'):
                            datatype[(queue.rear + 1) % MAXQUEUE] = '4';
                            printf("请输入元素：\n");
                            scanf("%d", &num);
                            fflush(stdin);
                            data = &num;
                            EnAQueue(&queue, data);
                            break;
                        case('d'):
                            datatype[(queue.rear + 1) % MAXQUEUE] = '8';
                            printf("请输入元素：\n");
                            scanf("%lf", &a);
                            fflush(stdin);
                            data = &a;
                            EnAQueue(&queue, data);
                            break;
                        case('c'):
                            datatype[(queue.rear + 1) % MAXQUEUE] = '1';
                            printf("请输入元素：\n");
                            fflush(stdin);
                            scanf("%c", &c);
                            fflush(stdin);
                            data = &c;
                            EnAQueue(&queue, data);
                            break;
                        default:
                            printf("输入错误，请重新输入：\n");
                            break;
                    }
                    break;
                }
                else
                    printf("队列已满！\n");
                break;
            case('5'):
                DeAQueue(&queue);
                break;
            case('6'):
                if(IsEmptyAQueue(&queue))
                    printf("队列为空！\n");
                else{
                    GetHeadAQueue(&queue,data);
                    count=(queue.front+1)%MAXQUEUE;
                    APrint(data);
                    printf("\n");
                    break;
                }
                break;
            case('8'):      //清空队列
                ClearAQueue(&queue);
                break;
            case('7'):
                if(IsEmptyAQueue(&queue))
                    printf("队列为空！\n");
                else{
                    foo=APrint;
                    TraverseAQueue(&queue,foo);
                    printf("\n");
                }
                break;
            case('9'):
                DestoryAQueue(&queue);
                printf("销毁成功！\n");
                temp=1;
                while(temp){
                    printf("1.初始化队列  2.退出\n");
                    printf("请输入您的选择：\n");
                    scanf("%c", &_choice);
                    switch(_choice){
                        case ('1'):
                            InitAQueue(&queue);
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
                fflush(stdin);
                break;
            case('0'):
                printf("感谢您的使用!\n");
                exit(0);
            case('c'):
                system("cls");
                break;
            default:
                printf("输入错误，请重新输入：\n");
                break;
        }
        fflush(stdin);
    }
    return 0;
}
