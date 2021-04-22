#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "time_test.h"

int input(char choice){
    if(choice>='0'&&choice<='3'){
        return 1;
    }
    else
        return -1;
}

void CountSort(int *a, int size , int max){
    int min=a[0];
    for(int i=0;i<size;i++)
        min=(min<a[i])?min:a[i];
    int len;
    len=max-min+1;
    int* temp;
    temp=(int*)malloc(len*sizeof(int));    //����һ����������������
    if(temp!=NULL) {
        memset(temp, 0, len * sizeof(int));     //��ʼ�����飬��ֵΪ0

        //��ʼ����
        for (int k = 0; k < size; k++)
            temp[a[k] - min]++;

        //���źõ������¸���ԭ����
        int count = 0;
        for (int i = 0; i < len; i++) {
            if (temp[i] == 0)
                continue;
            else {
                for (int j = temp[i]; j > 0; j--) {
                    a[count] = i + min;
                    count++;
                }
            }
        }
        free(temp);
    }
    else
        printf("�ڴ����ʧ�ܣ�\n");
}

void RadixCountSort(int *a,int size){
    int max=a[0],bit=1;
    for(int i=0;i<size;i++)     //��ȡ���ֵ
        max=(max<a[i])?max:a[i];
    //�������ֵ��λ��
    while(max!=0){
        max/=10;
        bit++;
    }

    int count[10],j,k,radix=1;    //count[]����������k��������radix�ǻ��������Ի���֮��������
    int* temp;
    temp=(int*)malloc(size*sizeof(int));
    //int temp[size];     //�������飬��ʱ�������
    if(temp!=NULL) {
        for (int i = 0; i < bit; i++) {
            memset(count, 0, 10 * sizeof(int));     //ÿ�η���ǰ��Ҫ��ռ�����
            for (j = 0; j < size; j++) {
                k = (a[j] / radix) % 10;     //���Ի���֮�������࣬�õ�����
                count[k]++;     //����
            }
            for (j = 1; j < 10; j++)      //��λ�÷����ÿ��Ͱ
                count[j] += count[j - 1];
            for (j = size - 1; j >= 0; j--) {
                k = (a[j] / radix) % 10;
                temp[count[k] - 1] = a[j];
                count[k]--;     //������һ
            }
            for (j = 0; j < size; j++)     //���źõ����鸳��ԭ����
                a[j] = temp[j];
            radix *= 10;
        }
        free(temp);
    }
    else
        printf("�ڴ����ʧ�ܣ�\n");
}

void ColorSort(int *a,int size){
    int begin=0,curt=0,end=size-1,temp;
    while(curt<=end){
        if(a[curt]==2){
            temp=a[curt];
            a[curt]=a[end];
            a[end]=temp;
            end--;
        }
        else if(a[curt]==0){
            temp=a[curt];
            a[curt]=a[begin];
            a[begin]=temp;
            begin++;
            curt++;
        }
        else
            curt++;
    }
}

void insertSort(int *a,int n){
    int temp,k,t;
    for(k=1;k<n;k++){
        temp=a[k];
        t=k-1;
        while(t>=0&&temp<a[t]){    //��ǰ����û�бȵ�ǰ������������ǰ������������
            a[t+1]=a[t];
            t--;
        }
        a[t+1]=temp;    //�ѵ�ǰ������Ų�����λ��
    }
}

int Partition(int *a, int begin, int end){
    int mid=(begin+end)/2;     //�м��±�
    int temp,index=mid;
    if(a[mid]>a[end]){
        temp=a[mid];
        a[mid]=a[end];
        a[end]=temp;
        index=end;     //��¼�±�
    }
    if(a[begin]>a[end]){
        temp=a[begin];
        a[begin]=a[end];
        a[end]=temp;
    }
    if(a[begin]>a[mid]){
        temp=a[begin];
        a[begin]=a[mid];
        a[mid]=temp;
        index=begin;
    }
    return index;      //�����±�
}

int onetime_sort(int *a,int begin,int end){
    int temp=a[begin];
    while(begin!=end)
    {
        while ((begin<end)&&(temp<=a[end]))
            end--;
        a[begin]=a[end];
        while ((begin<end)&&(temp>a[begin]))
            begin++;
        a[end]=a[begin];
    }
    a[begin]=temp;
    return begin;
}

void QuickSort(int *a,int size){
    int len=size-1;
    int *temp=(int*)malloc(len* sizeof(int));
    int begin=0,end=len-1,top=0;
    int p=onetime_sort(a,begin,len);    //����һ�λ���

    if(p>(begin+1)){
        temp[top++]=p-1;
        temp[top++]=begin;
    }
    if(p<end){
        temp[top++]=len;
        temp[top++]=p+1;
    }
    while(top>0){
        begin=temp[--top];
        end=temp[--top];
        p=onetime_sort(a,begin,end);
        if(p>(begin+1)){
            temp[top++]=p-1;
            temp[top++]=begin;
        }
        if(p<end){
            temp[top++]=len;
            temp[top++]=p+1;
        }
    }
    free(temp);
}


void QuickSort_Recursion(int *a, int begin, int end){
    if (begin >= end)
        return;

    int left = begin, right = end;
    //int point = Partition(a,begin,end);
    int pivot = a[left];
    while (left < right)
    {
        while ((left < right) && (pivot <= a[right]))
        {
            right--;
        }
        if (left < right)
        {
            a[left] = a[right];
        }
        while ((left < right) && (pivot > a[left]))
        {
            left++;
        }
        if (left < right)
        {
            a[right] = a[left];
        }
        if (left == right)
        {
            a[left] = pivot;
        }
    }
    QuickSort_Recursion(a, begin, right - 1);
    QuickSort_Recursion(a, right + 1, end);
}


int FindKthSmall(int *a, int size) {
    int k;
    printf("������K��ֵ��\n");
    scanf("%d",&k);
    fflush(stdin);

    insertSort(a,size);
    return a[k-1];
}


void MergeSort(int *a,int begin,int end,int *temp){
    if(begin<end){
        int mid;
        mid=(begin+end)/2;
        MergeSort(a,begin,mid,temp);
        MergeSort(a,mid+1,end,temp);
        MergeArray(a,begin,mid,end,temp);   //ֻ��һ������ֱ�Ӻ���һ��
    }
}

void MergeArray(int *a,int begin,int mid,int end,int *temp){
    //����Ԫ�ش��м�ֿ�
    int i = begin;     //��ֵ����ߣ�������д�begin��mid
    int j = mid + 1;    //��ֵ�м䣬�ұ����д�mid+1��end
    int k = begin;     //��������Ԫ��
    while (i <= mid && j <= end){//�������������е�Ԫ�����ζԱȣ���ķŽ�temp
        if (a[i] < a[j]){
            temp[k] = a[i++];
        }
        else{
            temp[k] = a[j++];
        }
        k++;
    }
    while (i <=mid){    //����ұߵ����ˣ���ʣ�µķ���temp
        temp[k++] = a[i++];
    }
    while (j <= end){   //���ͬ��
        temp[k++] = a[j++];
    }
    for (i = begin; i <= end; i++){
        a[i] = temp[i];
    }
}

void PutNum(int*a,int n){
    for(int i=0;i<n;i++){
        scanf("%d",&(a[i]));
    }
}

void PrintNum(int*a,int n){
    for(int j=0;j<n;j++){
        printf("%d ",a[j]);
    }
}

