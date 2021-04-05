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
        printf( "*                   顺序栈                   *\n");
        printf( "**********************************************\n");
        printf( "*                1:初始化                    * \n");
        printf( "*                2:入栈                      * \n");
        printf( "*                3:出栈                      * \n");
        printf( "*                4:获取栈顶元素              * \n");
        printf( "*                5:判断空栈                  * \n");
        printf( "*                6:检测长度                  * \n");
        printf( "*                7:清空                      * \n");
        printf( "*                8:销毁                      * \n");
        printf( "*                9:清屏                      * \n");
        printf( "*                0:退出程序                  * \n");
        printf( "**********************************************\n" );
        int choice;
        printf("请输入您的选择：\n");
        scanf("%d", &choice);
        switch (choice) {
            case (1):   //初始化栈
                printf("请输入栈的最大长度：\n");
                scanf("%d", &sizes);
                initStack(&stack, sizes);   //初始化
                break;
            case(2):    //入栈
                if(stack.elem==NULL) {
                    printf("未初始化栈，栈不存在！\n");
                }
                else{
                    printf("请输要入栈的数据：\n");
                    scanf("%d", &data);
                    pushStack(&stack,data);
                }
                break;
            case(3):    //出栈
                if(stack.elem==NULL) {     //判断是否初始化
                    printf("未初始化栈，栈不存在！\n");
                }
                else{
                    situation=isEmptyStack(&stack);//判断是否为空
                    if(situation==SUCCESS){    //不为空时，可以出栈
                        popStack(&stack,&num);
                        printf("出栈成功\n");
                        printf("出栈的数据为：%d\n",num);
                    }
                    else{   //栈为空
                        printf("此为空栈，无可出栈的数值\n");
                    }
                }
                break;
            case(4):
                if(stack.elem==NULL) {
                    printf("未初始化栈，栈不存在！\n");
                }
                else {
                    getTopStack(&stack, element);
                    if (element==NULL) {
                        printf("不存在栈顶元素\n");
                    }
                    else
                        printf("%d", *element);
                }
                break;
            case(5):    //判断是否为空
                if(stack.elem==NULL) {
                    printf("未初始化栈，栈不存在！\n");
                }
                else{
                    situation=isEmptyStack(&stack);
                    if(situation==SUCCESS){
                        printf("此非空栈\n");
                    }
                    else{
                        printf("此为空栈\n");
                    }
                }
                break;
            case(6):
                stackLength(&stack,&length);
                break;
            case(7):
                if(stack.elem==NULL) {
                    printf("未初始化栈，栈不存在！\n");
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
                        printf("1.初始化栈  2.退出\n");
                        printf("请输入您的选择：\n");
                        scanf("%d", &choice_);
                        switch (choice_) {
                            case (1):
                                printf("请输入栈的最大长度：\n");
                                scanf("%d", &sizes);
                                initStack(&stack, sizes);   //初始化
                                temp=0;
                                break;
                            case (2):
                                exit(0);
                            default:
                                printf("输入错误，请重新输入：\n");
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
