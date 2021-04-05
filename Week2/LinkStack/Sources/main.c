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
        printf("*                    链栈                    *\n");
        printf("**********************************************\n");
        printf("*                1:初始化                    * \n");
        printf("*                2:入栈                      * \n");
        printf("*                3:出栈                      * \n");
        printf("*                4:获取栈顶元素              * \n");
        printf("*                5:判断空栈                  * \n");
        printf("*                6:检测长度                  * \n");
        printf("*                7:清空                      * \n");
        printf("*                8:销毁                      * \n");
        printf("*                9:清屏                      * \n");
        printf("*                0:退出                      * \n");
        printf("**********************************************\n");
        char choice;
        printf("请输入您的选择：\n");
        scanf("%c", &choice);
        switch (choice) {
            case ('1'):   //初始化栈
                initLStack(&linkStack);   //初始化
                break;
            case('2'):
                printf("请输要入栈的数据：\n");
                scanf("%d", &data);
                pushLStack(&linkStack,data);
                break;
            case('3'):
                if(isEmptyLStack(&linkStack)==SUCCESS){    //链栈非空的时候
                    popLStack(&linkStack,&data);
                    printf("出栈元素为：%d\n",data);
                }
                else{
                    printf("链栈为空,无数据可获取\n");
                }
                break;
            case('4'):
                if(isEmptyLStack(&linkStack)==SUCCESS){    //链栈非空的时候
                    getTopLStack(&linkStack,&e);
                    printf("栈顶元素为：%d\n",e);
                }
                else{
                    printf("链栈为空,无数据可获取\n");
                }
                break;
            case('5'):
                situation=isEmptyLStack(&linkStack);
                if(situation==SUCCESS){
                    printf("链栈非空\n");
                }
                else
                    printf("链栈为空\n");
                break;
            case('6'):
                LStackLength(&linkStack,&length);
                printf("链栈长度为：%d\n",length);
                break;
            case('7'):
                clearLStack(&linkStack);
                break;
            case('8'):
                printf("确定销毁？\n");
                printf("确定请输入1  取消请输入任意一个键\n");
                scanf("%d", &number);
                fflush(stdin);
                if (number == 1){
                    destroyLStack(&linkStack);
                    printf("销毁成功\n");
                    while(temp) {
                        printf("1.初始化栈  2.退出\n");
                        printf("请输入您的选择：\n");
                        scanf("%c", &choice_);
                        switch (choice_) {
                            case ('1'):
                                initLStack(&linkStack);   //初始化
                                temp=0;
                                break;
                            case ('2'):
                                printf("感谢您的使用，再见！\n");
                                exit(0);
                            default:
                                printf("输入错误，请重新输入：\n");
                                break;
                        }
                        fflush(stdin);
                    }
                }
                break;
            case('0'):
                printf("感谢您的使用，再见！\n");
                exit(0);
            case('9'):
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
