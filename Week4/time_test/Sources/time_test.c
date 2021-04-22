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
    temp=(int*)malloc(len*sizeof(int));    //生成一个用来计数的数组
    if(temp!=NULL) {
        memset(temp, 0, len * sizeof(int));     //初始化数组，初值为0

        //开始计数
        for (int k = 0; k < size; k++)
            temp[a[k] - min]++;

        //把排好的数重新赋给原数组
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
        printf("内存分配失败！\n");
}

void RadixCountSort(int *a,int size){
    int max=a[0],bit=1;
    for(int i=0;i<size;i++)     //获取最大值
        max=(max<a[i])?max:a[i];
    //计算最大值的位数
    while(max!=0){
        max/=10;
        bit++;
    }

    int count[10],j,k,radix=1;    //count[]用来计数，k是余数，radix是基数，除以基数之后再求余
    int* temp;
    temp=(int*)malloc(size*sizeof(int));
    //int temp[size];     //辅助数组，暂时存放数据
    if(temp!=NULL) {
        for (int i = 0; i < bit; i++) {
            memset(count, 0, 10 * sizeof(int));     //每次分配前都要清空计数器
            for (j = 0; j < size; j++) {
                k = (a[j] / radix) % 10;     //除以基数之后再求余，得到余数
                count[k]++;     //计数
            }
            for (j = 1; j < 10; j++)      //将位置分配给每个桶
                count[j] += count[j - 1];
            for (j = size - 1; j >= 0; j--) {
                k = (a[j] / radix) % 10;
                temp[count[k] - 1] = a[j];
                count[k]--;     //计数减一
            }
            for (j = 0; j < size; j++)     //将排好的数组赋给原数组
                a[j] = temp[j];
            radix *= 10;
        }
        free(temp);
    }
    else
        printf("内存分配失败！\n");
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
        while(t>=0&&temp<a[t]){    //看前面有没有比当前大的数，有则把前面大的数往后退
            a[t+1]=a[t];
            t--;
        }
        a[t+1]=temp;    //把当前数插入挪开后的位置
    }
}

int Partition(int *a, int begin, int end){
    int mid=(begin+end)/2;     //中间下标
    int temp,index=mid;
    if(a[mid]>a[end]){
        temp=a[mid];
        a[mid]=a[end];
        a[end]=temp;
        index=end;     //记录下标
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
    return index;      //返回下标
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
    int p=onetime_sort(a,begin,len);    //进行一次划分

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
    printf("请输入K的值：\n");
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
        MergeArray(a,begin,mid,end,temp);   //只有一个数的直接合在一起
    }
}

void MergeArray(int *a,int begin,int mid,int end,int *temp){
    //数组元素从中间分开
    int i = begin;     //赋值最左边，左边序列从begin到mid
    int j = mid + 1;    //赋值中间，右边序列从mid+1到end
    int k = begin;     //辅助数组元素
    while (i <= mid && j <= end){//将左右两边序列的元素依次对比，大的放进temp
        if (a[i] < a[j]){
            temp[k] = a[i++];
        }
        else{
            temp[k] = a[j++];
        }
        k++;
    }
    while (i <=mid){    //如果右边的少了，将剩下的放入temp
        temp[k++] = a[i++];
    }
    while (j <= end){   //左边同理
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

