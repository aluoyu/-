#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include "time_test.h"


void createText(){
    int i;
    srand((unsigned)time(NULL));
    //��������200000����������
    int a[200000];
    for(i=0;i<200000;i++)   //��������������
        a[i]=rand();

    //��������10000�������ļ�
    FILE *p=fopen("bigdata1.txt","a");
    if(p==NULL){
        printf("�ļ�����ʧ�ܣ�\n");
    }
    else{
        fwrite(a,sizeof(int),10000,p);
    }
    fclose(p);

    //��������50000�������ļ�
    FILE *q=fopen("bigdata2.txt","a");
    if(q==NULL){
        printf("�ļ�����ʧ�ܣ�\n");
    }
    else{
        fwrite(a,sizeof(int),50000,p);
    }
    fclose(q);

    //��������200000�������ļ�
    FILE *r=fopen("bigdata3.txt","a");
    if(r==NULL){
        printf("�ļ�����ʧ�ܣ�\n");
    }
    else{
        fwrite(a,sizeof(int),200000,p);
    }
    fclose(r);
}

int main(){
    createText();
    while(1){
    printf("��ӭ���������㷨ʱ�����ϵͳ��\n");
    printf("1.�ڴ���С�����µ���ʱ\n2.�ڴ��������µ���ʱ\n3.����\n0.�˳�����\n");
    printf("����������ѡ��\n");
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

                //ѡ������
                start =clock();     //��ʼ��ʱ
                insertSort(a,10000);
                finish=clock();     //������ʱ
                duration=(double)(finish-start)/CLOCKS_PER_SEC;
                printf("ѡ������\n");
                printf("10000��������%f seconds\n",duration);
                start =clock();
                insertSort(b,50000);
                finish=clock();
                duration=(double)(finish-start)/CLOCKS_PER_SEC;
                printf("50000��������%f seconds\n",duration);
                start =clock();
                insertSort(c,200000);
                finish=clock();
                duration=(double)(finish-start)/CLOCKS_PER_SEC;
                printf("200000��������%f seconds\n",duration);
                printf("\n");

                //�鲢����
                temp=(int*)malloc(10000*sizeof(int));
                start=clock();
                MergeSort(a,0,10000-1,temp);
                finish=clock();
                free(temp);
                duration=(double)(finish-start)/CLOCKS_PER_SEC;
                printf("�鲢����\n");
                printf("10000��������%f seconds\n",duration);

                temp=(int*)malloc(50000*sizeof(int));
                start =clock();
                MergeSort(b,0,50000-1,temp);
                finish=clock();
                free(temp);
                duration=(double)(finish-start)/CLOCKS_PER_SEC;
                printf("50000��������%f seconds\n",duration);

                temp=(int*)malloc(200000*sizeof(int));
                start =clock();
                MergeSort(c,0,200000-1,temp);
                finish=clock();
                free(temp);
                duration=(double)(finish-start)/CLOCKS_PER_SEC;
                printf("200000��������%f seconds\n",duration);
                printf("\n");

                //��������
                for(i=0;i<10000;i++)
                    max1=(max1>a[i])?max1:a[i];
                for(i=0;i<50000;i++)
                    max2=(max2>b[i])?max2:b[i];
                for(i=0;i<200000;i++)
                    max3=(max3>c[i])?max3:c[i];
                start =clock();     //��ʼ��ʱ
                CountSort(a,10000,max1);
                finish=clock();     //������ʱ
                duration=(double)(finish-start)/CLOCKS_PER_SEC;
                printf("��������\n");
                printf("10000��������%f seconds\n",duration);

                start =clock();
                CountSort(b,50000,max2);
                finish=clock();
                duration=(double)(finish-start)/CLOCKS_PER_SEC;
                printf("50000��������%f seconds\n",duration);

                start =clock();
                CountSort(c,200000,max3);
                finish=clock();
                duration=(double)(finish-start)/CLOCKS_PER_SEC;
                printf("200000��������%f seconds\n",duration);
                printf("\n");

                //������������
                start = clock();     //��ʼ��ʱ
                RadixCountSort(a, 10000);
                finish = clock();     //������ʱ
                duration = (double) (finish - start) / CLOCKS_PER_SEC;
                printf("������������\n");
                printf("10000��������%f seconds\n", duration);
                start = clock();
                RadixCountSort(b, 50000);
                finish = clock();
                duration = (double) (finish - start) / CLOCKS_PER_SEC;
                printf("50000��������%f seconds\n", duration);
                start = clock();
                RadixCountSort(c, 200000);
                finish = clock();
                duration = (double) (finish - start) / CLOCKS_PER_SEC;
                printf("200000��������%f seconds\n", duration);
                printf("\n");

                //��������
                start =clock();     //��ʼ��ʱ
                QuickSort(a,10000);
                finish=clock();     //������ʱ
                duration=(double)(finish-start)/CLOCKS_PER_SEC;
                printf("��������\n");
                printf("10000��������%f seconds\n",duration);

                start =clock();
                QuickSort(b,50000);
                finish=clock();
                duration=(double)(finish-start)/CLOCKS_PER_SEC;
                printf("50000��������%f seconds\n",duration);

                start =clock();
                QuickSort(c,200000);
                finish=clock();
                duration=(double)(finish-start)/CLOCKS_PER_SEC;
                printf("200000��������%f seconds\n",duration);
                printf("\n");



                break;

            case('1'):
                s=fopen("bigdata1.txt","r");
                for(i=0;i<100;i++){
                    fread(&d[i], sizeof(int),1,s);
                }
                //ѡ������
                start=clock();
                for(i=0;i<100000;i++)
                    insertSort(d,100);
                finish=clock();
                duration = (double) (finish - start) / CLOCKS_PER_SEC;
                printf("ѡ������%f seconds\n", duration);

                //�鲢����
                start=clock();
                for(i=0;i<100000;i++){
                    temp=(int*)malloc(100*sizeof(int));
                    MergeSort(d,0,99,temp);
                    free(temp);
                }
                finish=clock();
                duration = (double) (finish - start) / CLOCKS_PER_SEC;
                printf("�鲢����%f seconds\n", duration);

                //��������
                for(i=0;i<100;i++)
                    max1=(max1>d[i])?max1:d[i];
                start=clock();
                for(i=0;i<100000;i++) {
                    CountSort(d, 100, max1);
                }
                finish=clock();
                duration = (double) (finish - start) / CLOCKS_PER_SEC;
                printf("��������%f seconds\n", duration);

                //������������
                start=clock();
                for(i=0;i<100000;i++){
                    RadixCountSort(d,100);
                }
                finish=clock();
                duration = (double) (finish - start) / CLOCKS_PER_SEC;
                printf("������������%f seconds\n", duration);

                //��������
                start=clock();
                for(i=0;i<100000;i++){
                    QuickSort_Recursion(d,0,99);
                }
                finish=clock();
                duration = (double) (finish - start) / CLOCKS_PER_SEC;
                printf("��������%f seconds\n", duration);
                printf("\n");

                break;

	    case('3'):
		system("cls");
		break;

	    case('0'):
		printf("��л����ʹ�ã�\n�����˳�����");
		exit(0);
        }
    }
	else {
		printf("����������������룡\n");
	}
    }
}
