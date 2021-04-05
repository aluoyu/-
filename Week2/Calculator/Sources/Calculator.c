#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 100      // ˳��ջ����󳤶�

typedef enum Status
{
    SUCCESS = 1
} Status;

typedef char ElemType;
typedef struct Stack
{
    ElemType data[MAXSIZE];   // ������洢˳��ջ�е�Ԫ�أ�����Ϊ100
    ElemType top;
}Stack;

typedef struct NStack
{
    int data[MAXSIZE];   // ������洢˳��ջ�е�Ԫ�أ�����Ϊ100
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
    initStack(&signStack);    //��ʼ������ջ


        while(1) {
            
            printf("**********************************************\n");
            printf("**                  ������                  **\n");
            printf("**********************************************\n");
            printf("**                 1.��ʼ����               **\n");
            printf("**                 2.����                   **\n");
            printf("**                 0.�˳�����               **\n");
            printf("**********************************************\n");
            printf("**                   Tips                   **\n");
            printf("**    ������׺���ʽʱ������#Ϊ������־     **\n");
            printf("**            ����������ڵ�һλ            **\n");
            printf("**           �û���֧�ָ�λ������           **\n");
            printf("**              ���๦�ܾ����ڴ�            **\n");
            printf("**********************************************\n");
            char run;
            printf("--             ����������ѡ��             --\n");
            scanf("%c",&run);
            int i = 0;
            switch(run) {
                case('1'):
                    fflush(stdin);
                    numStack.top = -1;
                    initStack(&signStack);    //��ʼ������ջ

                    printf("��������׺���ʽ����#Ϊ������־��");    //������׺���ʽ
                    scanf("%c", &ch);

                    while (ch != '#') {
                        while (ch >= '0' && ch <= '9')     //�������ְ����Ž�������
                        {
                            str1[i] = ch;
                            i++;

                            scanf("%c", &ch);    //����һ���ǲ�������
                            if (ch < '0' || ch > '9') {
                                printf(" ");
                            }
                        }

                        if (')' == ch)    //������������ѷ���ջ��ջ��Ԫ�ص������ж��ǲ���������
                        {
                            popStack(&signStack, &poppedSign);
                            while ('(' != poppedSign) {
                                str1[i] = poppedSign;
                                i++;

                                popStack(&signStack, &poppedSign);
                            }
                        } else if ('+' == ch || '-' == ch) {
                            if (signStack.top == -1)    //����ջΪ��
                            {
                                pushStack(&signStack, ch);     //����+ -����ջ
                            } else    //��Ϊ��ʱ��˵��ջ���������������������溬��*/+-����Ҫ�����ǵ������ѵ�ǰ+-����
                            {
                                do {
                                    popStack(&signStack, &poppedSign);
                                    if ('(' == poppedSign)   //���������������ţ�����Ż�ԭλ
                                    {
                                        pushStack(&signStack, poppedSign);
                                    } else    //���������ţ��������
                                    {
                                        str1[i] = poppedSign;
                                        i++;
                                    }
                                } while (signStack.top != -1 && '(' != poppedSign);
                                pushStack(&signStack, ch);     //����ջ�з��ź󣬽���ǰ������ջ
                            }
                        } else if ('*' == ch || '/' == ch || '(' == ch)   //����* / ������������ջ
                        {
                            pushStack(&signStack, ch);
                        } else if ('#' == ch) {
                            break;
                        } else {
                            printf("�����������������!\n");
                            return -1;
                        }
                        scanf("%c", &ch);
                    }

                    while (signStack.top != -1)   //����ȫ����ջ��Ҫ��ջ�ڵķ����������
                    {
                        popStack(&signStack, &poppedSign);

                        str1[i] = poppedSign;
                        i++;

                    }
                    printf("\n��׺���ʽΪ��%s\n", str1);

                    int j, result;
                    char num1, num2;
                    int a1, a2;
                    for (j = 0; str1[j] != '\0'; j++) {    //�����ַ���
                        if (str1[j] >= '0' && str1[j] <= '9') {    //�������־���ջ
                            pushNStack(&numStack, (int) str1[j] - 48);
                        } else {
                            if (str1[j] == '+') {
                                popNStack(&numStack, &num1);     //��ջ��Ԫ�س�ջ
                                popNStack(&numStack, &num2);
                                a1 = (int) num1;
                                a2 = (int) num2;
                                result = a2 + a1;      //��������
                                pushNStack(&numStack, result);    //����������ջ
                            }
                            if (str1[j] == '-') {
                                popNStack(&numStack, &num1);     //��ջ��Ԫ�س�ջ
                                popNStack(&numStack, &num2);
                                a1 = (int) num1;
                                a2 = (int) num2;
                                result = a2 - a1;      //��������
                                pushNStack(&numStack, result);    //����������ջ
                            }
                            if (str1[j] == '*') {
                                popNStack(&numStack, &num1);     //��ջ��Ԫ�س�ջ
                                popNStack(&numStack, &num2);
                                a1 = (int) num1;
                                a2 = (int) num2;
                                result = a2 * a1;      //��������
                                pushNStack(&numStack, result);    //����������ջ
                            }
                            if (str1[j] == '/') {
                                popNStack(&numStack, &num1);     //��ջ��Ԫ�س�ջ
                                popNStack(&numStack, &num2);
                                a1 = (int) num1;
                                a2 = (int) num2;
                                result = a2 / a1;      //��������
                                pushNStack(&numStack, result);    //����������ջ
                            }
                        }
                    }
                    result = numStack.data[0];    //����������ջ
                    printf("������Ϊ��%d\n", result);
                    printf("top:%d\n", numStack.data[numStack.top]);
                    break;
                case('2'):
                    system("cls");
                    break;

                case('0') :
                    printf("��л����ʹ��!\n");
                    exit(0);

                default:
                    printf("��������������\n");
                    break;

            }
            fflush(stdin);
    }

    return 0;
}

