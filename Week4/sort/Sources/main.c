#include "qgsort.h"


int main() {
    while(1) {
        printf("**********************************************\n");
        printf("*                1:��������                  * \n");
        printf("*                2:�������򣨵ݹ飩          * \n");
        printf("*                3:�������򣨷ǵݹ飩        * \n");
        printf("*                4:�鲢����                  * \n");
        printf("*                5:��������                  * \n");
        printf("*                6:������������              * \n");
        printf("*                7:��ɫ����                  * \n");
        printf("*                8:Ѱ�ҵ�KС��ֵ             * \n");
        printf("*                9:����                      * \n");
        printf("*                0:�˳�����                  * \n");
        printf("**********************************************\n");
        printf("��ѡ���ܣ�\n");
        char choice;
        scanf("%c",&choice);
        getchar();
        if (input(choice) == 1) {
            int*a,*temp,n,i,res;
            switch(choice){
                case('1'):      //��������
                    printf("������Ԫ�ظ�����\n");
                    scanf("%d",&n);
                    a=(int*)malloc(n*sizeof(int));
                    printf("����������Ԫ�أ�\n");
                    PutNum(a,n);
                    insertSort(a,n);
                    PrintNum(a,n);
                    printf("\n");
                    free(a);
                    break;

                case('2'):      //�������򣨵ݹ�棩
                    printf("������Ԫ�ظ�����\n");
                    scanf("%d",&n);
                    a=(int*)malloc(n*sizeof(int));
                    printf("����������Ԫ�أ�\n");
                    PutNum(a,n);
                    QuickSort_Recursion(a,0,n-1);
                    PrintNum(a,n);
                    printf("\n");
                    free(a);
                    break;

                case('3'):
                    printf("������Ԫ�ظ�����\n");
                    scanf("%d",&n);
                    a=(int*)malloc(n*sizeof(int));
                    printf("����������Ԫ�أ�\n");
                    PutNum(a,n);
                    QuickSort(a,n);
                    PrintNum(a,n);
                    printf("\n");
                    free(a);
                    break;

                case('4'):      //�鲢����
                    printf("������Ԫ�ظ�����\n");
                    scanf("%d",&n);
                    a=(int*)malloc(n*sizeof(int));
                    printf("����������Ԫ�أ�\n");
                    PutNum(a,n);
                    temp=(int*)malloc(n*sizeof(int));   //����һ����������
                    MergeSort(a,0,n-1,temp);
                    free(temp);    //�ͷŸ���������ڴ�
                    PrintNum(a,n);
                    printf("\n");
                    free(a);
                    break;

                case('5'):      //��������
                    printf("������Ԫ�ظ�����\n");
                    scanf("%d",&n);
                    a=(int*)malloc(n*sizeof(int));
                    printf("����������Ԫ�أ�\n");
                    PutNum(a,n);
                    int max=a[0];
                    for(i=0;i<n;i++)
                        max=(max>a[i])?max:a[i];
                    CountSort(a,n,max);
                    PrintNum(a,n);
                    printf("\n");
                    free(a);
                    break;

                case('6'):      //������������
                    printf("������Ԫ�ظ�����\n");
                    scanf("%d",&n);
                    a=(int*)malloc(n*sizeof(int));
                    printf("����������Ԫ�أ�\n");
                    PutNum(a,n);
                    RadixCountSort(a,n);
                    PrintNum(a,n);
                    printf("\n");
                    free(a);
                    break;

                case('7'):      //��ɫ����
                    printf("������Ԫ�ظ�����\n");
                    scanf("%d",&n);
                    a=(int*)malloc(n*sizeof(int));
                    printf("����������Ԫ�أ�\n");
                    PutNum(a,n);
                    ColorSort(a,n);
                    PrintNum(a,n);
                    printf("\n");
                    free(a);
                    break;

                case('8'):
                    printf("������Ԫ�ظ�����\n");
                    scanf("%d",&n);
                    a=(int*)malloc((n+1)*sizeof(int));
                    printf("����������Ԫ�أ�\n");
                    PutNum(a,n);

                    res=FindKthSmall(a,n);
                    printf("��K����СֵΪ��%d\n",res);
                    break;

                case('9'):
                    system("cls");
                    break;

                case('0'):
                    printf("��л����ʹ�ã������˳�����\n");
                    exit(0);
            }
            fflush(stdin);
        }

        else {
            printf("����������������룡\n");
        }
    }
}
