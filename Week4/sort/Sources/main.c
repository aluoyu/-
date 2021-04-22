#include "qgsort.h"


int main() {
    while(1) {
        printf("**********************************************\n");
        printf("*                1:插入排序                  * \n");
        printf("*                2:快速排序（递归）          * \n");
        printf("*                3:快速排序（非递归）        * \n");
        printf("*                4:归并排序                  * \n");
        printf("*                5:计数排序                  * \n");
        printf("*                6:基数计数排序              * \n");
        printf("*                7:颜色排序                  * \n");
        printf("*                8:寻找第K小的值             * \n");
        printf("*                9:清屏                      * \n");
        printf("*                0:退出程序                  * \n");
        printf("**********************************************\n");
        printf("请选择功能：\n");
        char choice;
        scanf("%c",&choice);
        getchar();
        if (input(choice) == 1) {
            int*a,*temp,n,i,res;
            switch(choice){
                case('1'):      //插入排序
                    printf("请输入元素个数：\n");
                    scanf("%d",&n);
                    a=(int*)malloc(n*sizeof(int));
                    printf("请依次输入元素：\n");
                    PutNum(a,n);
                    insertSort(a,n);
                    PrintNum(a,n);
                    printf("\n");
                    free(a);
                    break;

                case('2'):      //快速排序（递归版）
                    printf("请输入元素个数：\n");
                    scanf("%d",&n);
                    a=(int*)malloc(n*sizeof(int));
                    printf("请依次输入元素：\n");
                    PutNum(a,n);
                    QuickSort_Recursion(a,0,n-1);
                    PrintNum(a,n);
                    printf("\n");
                    free(a);
                    break;

                case('3'):
                    printf("请输入元素个数：\n");
                    scanf("%d",&n);
                    a=(int*)malloc(n*sizeof(int));
                    printf("请依次输入元素：\n");
                    PutNum(a,n);
                    QuickSort(a,n);
                    PrintNum(a,n);
                    printf("\n");
                    free(a);
                    break;

                case('4'):      //归并排序
                    printf("请输入元素个数：\n");
                    scanf("%d",&n);
                    a=(int*)malloc(n*sizeof(int));
                    printf("请依次输入元素：\n");
                    PutNum(a,n);
                    temp=(int*)malloc(n*sizeof(int));   //创建一个辅助数组
                    MergeSort(a,0,n-1,temp);
                    free(temp);    //释放辅助数组的内存
                    PrintNum(a,n);
                    printf("\n");
                    free(a);
                    break;

                case('5'):      //计数排序
                    printf("请输入元素个数：\n");
                    scanf("%d",&n);
                    a=(int*)malloc(n*sizeof(int));
                    printf("请依次输入元素：\n");
                    PutNum(a,n);
                    int max=a[0];
                    for(i=0;i<n;i++)
                        max=(max>a[i])?max:a[i];
                    CountSort(a,n,max);
                    PrintNum(a,n);
                    printf("\n");
                    free(a);
                    break;

                case('6'):      //基数计数排序
                    printf("请输入元素个数：\n");
                    scanf("%d",&n);
                    a=(int*)malloc(n*sizeof(int));
                    printf("请依次输入元素：\n");
                    PutNum(a,n);
                    RadixCountSort(a,n);
                    PrintNum(a,n);
                    printf("\n");
                    free(a);
                    break;

                case('7'):      //颜色排序
                    printf("请输入元素个数：\n");
                    scanf("%d",&n);
                    a=(int*)malloc(n*sizeof(int));
                    printf("请依次输入元素：\n");
                    PutNum(a,n);
                    ColorSort(a,n);
                    PrintNum(a,n);
                    printf("\n");
                    free(a);
                    break;

                case('8'):
                    printf("请输入元素个数：\n");
                    scanf("%d",&n);
                    a=(int*)malloc((n+1)*sizeof(int));
                    printf("请依次输入元素：\n");
                    PutNum(a,n);

                    res=FindKthSmall(a,n);
                    printf("第K个最小值为：%d\n",res);
                    break;

                case('9'):
                    system("cls");
                    break;

                case('0'):
                    printf("感谢您的使用，即将退出程序\n");
                    exit(0);
            }
            fflush(stdin);
        }

        else {
            printf("输入错误，请重新输入！\n");
        }
    }
}
