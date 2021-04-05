#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 100      // 顺序栈的最大长度

typedef enum Status
{
    SUCCESS = 1
} Status;

typedef char ElemType;
typedef struct Stack
{
    ElemType data[MAXSIZE];   // 用数组存储顺序栈中的元素，长度为100
    ElemType top;
}Stack;

typedef struct NStack
{
    int data[MAXSIZE];   // 用数组存储顺序栈中的元素，长度为100
    int top;
}NStack;

Status initStack(Stack *s)
{
    s->top = -1;
    return SUCCESS;
}

Status pushStack(Stack *s, ElemType data)
{
    s->top++;
    s->data[s->top]=data;
    return SUCCESS;
}

Status pushNStack(NStack *s, int data)
{
    s->top++;
    s->data[s->top]=data;
    return SUCCESS;
}

Status popStack(Stack *s, ElemType *data)
{
    *data=s->data[s->top];
    s->top--;
    return SUCCESS;
}

Status popNStack(NStack *s, ElemType *data)
{
    *data=s->data[s->top];
    s->top--;
    return SUCCESS;
}

int main()
{
    Stack signStack;
    NStack numStack;
    numStack.top = -1;
    ElemType ch, poppedSign;
    ElemType str1[100];
    initStack(&signStack);    //初始化符号栈


        while(1) {
            
            printf("**********************************************\n");
            printf("**                  计算器                  **\n");
            printf("**********************************************\n");
            printf("**                 1.开始计算               **\n");
            printf("**                 2.清屏                   **\n");
            printf("**                 0.退出程序               **\n");
            printf("**********************************************\n");
            printf("**                   Tips                   **\n");
            printf("**    输入中缀表达式时，请以#为结束标志     **\n");
            printf("**            负数请勿放在第一位            **\n");
            printf("**           该机仅支持个位数运算           **\n");
            printf("**              更多功能敬请期待            **\n");
            printf("**********************************************\n");
            char run;
            printf("--             请输入您的选择             --\n");
            scanf("%c",&run);
            int i = 0;
            switch(run) {
                case('1'):
                    fflush(stdin);
                    numStack.top = -1;
                    initStack(&signStack);    //初始化符号栈

                    printf("请输入中缀表达式，以#为结束标志：");    //输入中缀表达式
                    scanf("%c", &ch);

                    while (ch != '#') {
                        while (ch >= '0' && ch <= '9')     //遇到数字把它放进数组中
                        {
                            str1[i] = ch;
                            i++;

                            scanf("%c", &ch);    //看下一个是不是数字
                            if (ch < '0' || ch > '9') {
                                printf(" ");
                            }
                        }

                        if (')' == ch)    //遇到右括号则把符号栈的栈顶元素弹出，判断是不是左括号
                        {
                            popStack(&signStack, &poppedSign);
                            while ('(' != poppedSign) {
                                str1[i] = poppedSign;
                                i++;

                                popStack(&signStack, &poppedSign);
                            }
                        } else if ('+' == ch || '-' == ch) {
                            if (signStack.top == -1)    //符号栈为空
                            {
                                pushStack(&signStack, ch);     //遇到+ -则入栈
                            } else    //不为空时，说明栈馁有其他运算符，如果里面含有*/+-，就要将它们弹出，把当前+-放入
                            {
                                do {
                                    popStack(&signStack, &poppedSign);
                                    if ('(' == poppedSign)   //若弹出的是左括号，将其放回原位
                                    {
                                        pushStack(&signStack, poppedSign);
                                    } else    //不是左括号，则将其输出
                                    {
                                        str1[i] = poppedSign;
                                        i++;
                                    }
                                } while (signStack.top != -1 && '(' != poppedSign);
                                pushStack(&signStack, ch);     //弹出栈中符号后，将当前符号入栈
                            }
                        } else if ('*' == ch || '/' == ch || '(' == ch)   //遇到* / 或左括号则入栈
                        {
                            pushStack(&signStack, ch);
                        } else if ('#' == ch) {
                            break;
                        } else {
                            printf("输入错误，请重新输入!\n");
                            return -1;
                        }
                        scanf("%c", &ch);
                    }

                    while (signStack.top != -1)   //符号全部入栈后，要将栈内的符号依次输出
                    {
                        popStack(&signStack, &poppedSign);

                        str1[i] = poppedSign;
                        i++;

                    }
                    printf("\n后缀表达式为：%s\n", str1);

                    int j, result;
                    char num1, num2;
                    int a1, a2;
                    for (j = 0; str1[j] != '\0'; j++) {    //遍历字符串
                        if (str1[j] >= '0' && str1[j] <= '9') {    //遇到数字就入栈
                            pushNStack(&numStack, (int) str1[j] - 48);
                        } else {
                            if (str1[j] == '+') {
                                popNStack(&numStack, &num1);     //将栈顶元素出栈
                                popNStack(&numStack, &num2);
                                a1 = (int) num1;
                                a2 = (int) num2;
                                result = a2 + a1;      //进行运算
                                pushNStack(&numStack, result);    //将运算结果入栈
                            }
                            if (str1[j] == '-') {
                                popNStack(&numStack, &num1);     //将栈顶元素出栈
                                popNStack(&numStack, &num2);
                                a1 = (int) num1;
                                a2 = (int) num2;
                                result = a2 - a1;      //进行运算
                                pushNStack(&numStack, result);    //将运算结果入栈
                            }
                            if (str1[j] == '*') {
                                popNStack(&numStack, &num1);     //将栈顶元素出栈
                                popNStack(&numStack, &num2);
                                a1 = (int) num1;
                                a2 = (int) num2;
                                result = a2 * a1;      //进行运算
                                pushNStack(&numStack, result);    //将运算结果入栈
                            }
                            if (str1[j] == '/') {
                                popNStack(&numStack, &num1);     //将栈顶元素出栈
                                popNStack(&numStack, &num2);
                                a1 = (int) num1;
                                a2 = (int) num2;
                                result = a2 / a1;      //进行运算
                                pushNStack(&numStack, result);    //将运算结果入栈
                            }
                        }
                    }
                    result = numStack.data[0];    //将运算结果出栈
                    printf("运算结果为：%d\n", result);
                    printf("top:%d\n", numStack.data[numStack.top]);
                    break;
                case('2'):
                    system("cls");
                    break;

                case('0') :
                    printf("感谢您的使用!\n");
                    exit(0);

                default:
                    printf("错误，请重新输入\n");
                    break;

            }
            fflush(stdin);
    }

    return 0;
}

