#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include "time_test.h"


void createText(){
    int i;
    srand((unsigned)time(NULL));
    //创建含有200000个数的数组
    int a[200000];
    for(i=0;i<200000;i++)   //把随机数存进数组
        a[i]=rand();

    //创建含有10000个数的文件
    FILE *p=fopen("bigdata1.txt","a");
    if(p==NULL){
        printf("文件创建失败！\n");
    }
    else{
        fwrite(a,sizeof(int),10000,p);
    }
    fclose(p);

    //创建含有50000个数的文件
    FILE *q=fopen("bigdata2.txt","a");
    if(q==NULL){
        printf("文件创建失败！\n");
    }
    else{
        fwrite(a,sizeof(int),50000,p);
    }
    fclose(q);

    //创建含有200000个数的文件
    FILE *r=fopen("bigdata3.txt","a");
    if(r==NULL){
        printf("文件创建失败！\n");
    }
    else{
        fwrite(a,sizeof(int),200000,p);
    }
    fclose(r);
}

int main(){
    createText();
    while(1){
    printf("欢迎来到排序算法时间测试系统！\n");
    printf("1.在大量小数组下的用时\n2.在大数据量下的用时\n3.清屏\n0.退出程序\n");
    printf("请输入您的选择：\n");
    char choice;
    scanf("%c",&choice);
    getchar();
    if (input(choice) == 1){
        clock_t start,finish;
        double duration;
        int i,max1,max2,max3;
        int *temp;
        int*a=(int*)malloc(10000*sizeof(int));
        int*b=(int*)malloc(50000*sizeof(int));
        int*c=(int*)malloc(200000*sizeof(int));
        int*d=(int*)malloc(100* sizeof(int));
        FILE *p,*q,*r,*s;

        switch (choice) {
            case('2'):
                p=fopen("bigdata1.txt","r");
                q=fopen("bigdata2.txt","r");
                r=fopen("bigdata3.txt","r");
                for(i=0;i<10000;i++){
                    fread(&a[i], sizeof(int),1,p);
                }
                for(i=0;i<50000;i++){
                    fread(&b[i], sizeof(int),1,q);
                }
                for(i=0;i<200000;i++){
                    fread(&c[i], sizeof(int),1,r);
                }

                //选择排序
                start =clock();     //开始计时
                insertSort(a,10000);
                finish=clock();     //结束计时
                duration=(double)(finish-start)/CLOCKS_PER_SEC;
                printf("选择排序\n");
                printf("10000数据量：%f seconds\n",duration);
                start =clock();
                insertSort(b,50000);
                finish=clock();
                duration=(double)(finish-start)/CLOCKS_PER_SEC;
                printf("50000数据量：%f seconds\n",duration);
                start =clock();
                insertSort(c,200000);
                finish=clock();
                duration=(double)(finish-start)/CLOCKS_PER_SEC;
                printf("200000数据量：%f seconds\n",duration);
                printf("\n");

                //归并排序
                temp=(int*)malloc(10000*sizeof(int));
                start=clock();
                MergeSort(a,0,10000-1,temp);
                finish=clock();
                free(temp);
                duration=(double)(finish-start)/CLOCKS_PER_SEC;
                printf("归并排序\n");
                printf("10000数据量：%f seconds\n",duration);

                temp=(int*)malloc(50000*sizeof(int));
                start =clock();
                MergeSort(b,0,50000-1,temp);
                finish=clock();
                free(temp);
                duration=(double)(finish-start)/CLOCKS_PER_SEC;
                printf("50000数据量：%f seconds\n",duration);

                temp=(int*)malloc(200000*sizeof(int));
                start =clock();
                MergeSort(c,0,200000-1,temp);
                finish=clock();
                free(temp);
                duration=(double)(finish-start)/CLOCKS_PER_SEC;
                printf("200000数据量：%f seconds\n",duration);
                printf("\n");

                //计数排序
                for(i=0;i<10000;i++)
                    max1=(max1>a[i])?max1:a[i];
                for(i=0;i<50000;i++)
                    max2=(max2>b[i])?max2:b[i];
                for(i=0;i<200000;i++)
                    max3=(max3>c[i])?max3:c[i];
                start =clock();     //开始计时
                CountSort(a,10000,max1);
                finish=clock();     //结束计时
                duration=(double)(finish-start)/CLOCKS_PER_SEC;
                printf("计数排序\n");
                printf("10000数据量：%f seconds\n",duration);

                start =clock();
                CountSort(b,50000,max2);
                finish=clock();
                duration=(double)(finish-start)/CLOCKS_PER_SEC;
                printf("50000数据量：%f seconds\n",duration);

                start =clock();
                CountSort(c,200000,max3);
                finish=clock();
                duration=(double)(finish-start)/CLOCKS_PER_SEC;
                printf("200000数据量：%f seconds\n",duration);
                printf("\n");

                //基数计数排序
                start = clock();     //开始计时
                RadixCountSort(a, 10000);
                finish = clock();     //结束计时
                duration = (double) (finish - start) / CLOCKS_PER_SEC;
                printf("基数计数排序\n");
                printf("10000数据量：%f seconds\n", duration);
                start = clock();
                RadixCountSort(b, 50000);
                finish = clock();
                duration = (double) (finish - start) / CLOCKS_PER_SEC;
                printf("50000数据量：%f seconds\n", duration);
                start = clock();
                RadixCountSort(c, 200000);
                finish = clock();
                duration = (double) (finish - start) / CLOCKS_PER_SEC;
                printf("200000数据量：%f seconds\n", duration);
                printf("\n");

                //快速排序
                start =clock();     //开始计时
                QuickSort(a,10000);
                finish=clock();     //结束计时
                duration=(double)(finish-start)/CLOCKS_PER_SEC;
                printf("快速排序\n");
                printf("10000数据量：%f seconds\n",duration);

                start =clock();
                QuickSort(b,50000);
                finish=clock();
                duration=(double)(finish-start)/CLOCKS_PER_SEC;
                printf("50000数据量：%f seconds\n",duration);

                start =clock();
                QuickSort(c,200000);
                finish=clock();
                duration=(double)(finish-start)/CLOCKS_PER_SEC;
                printf("200000数据量：%f seconds\n",duration);
                printf("\n");



                break;

            case('1'):
                s=fopen("bigdata1.txt","r");
                for(i=0;i<100;i++){
                    fread(&d[i], sizeof(int),1,s);
                }
                //选择排序
                start=clock();
                for(i=0;i<100000;i++)
                    insertSort(d,100);
                finish=clock();
                duration = (double) (finish - start) / CLOCKS_PER_SEC;
                printf("选择排序：%f seconds\n", duration);

                //归并排序
                start=clock();
                for(i=0;i<100000;i++){
                    temp=(int*)malloc(100*sizeof(int));
                    MergeSort(d,0,99,temp);
                    free(temp);
                }
                finish=clock();
                duration = (double) (finish - start) / CLOCKS_PER_SEC;
                printf("归并排序：%f seconds\n", duration);

                //计数排序
                for(i=0;i<100;i++)
                    max1=(max1>d[i])?max1:d[i];
                start=clock();
                for(i=0;i<100000;i++) {
                    CountSort(d, 100, max1);
                }
                finish=clock();
                duration = (double) (finish - start) / CLOCKS_PER_SEC;
                printf("计数排序：%f seconds\n", duration);

                //基数计数排序
                start=clock();
                for(i=0;i<100000;i++){
                    RadixCountSort(d,100);
                }
                finish=clock();
                duration = (double) (finish - start) / CLOCKS_PER_SEC;
                printf("基数计数排序：%f seconds\n", duration);

                //快速排序
                start=clock();
                for(i=0;i<100000;i++){
                    QuickSort_Recursion(d,0,99);
                }
                finish=clock();
                duration = (double) (finish - start) / CLOCKS_PER_SEC;
                printf("快速排序：%f seconds\n", duration);
                printf("\n");

                break;

	    case('3'):
		system("cls");
		break;

	    case('0'):
		printf("感谢您的使用！\n即将退出程序");
		exit(0);
        }
    }
	else {
		printf("输入错误，请重新输入！\n");
	}
    }
}
