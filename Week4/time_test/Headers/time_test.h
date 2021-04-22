#ifndef TIME_TEST_H_INCLUDED
#define TIME_TEST_H_INCLUDED

void insertSort(int *a,int n);
void MergeArray(int *a,int begin,int mid,int end,int *temp);
void MergeSort(int *a,int begin,int end,int *temp);
void QuickSort_Recursion(int *a, int begin, int end);
void QuickSort(int *a,int size);    //快排（非递归版）
int Partition(int *a, int begin, int end);      //快排（枢轴存放）
void CountSort(int *a, int size , int max);
void RadixCountSort(int *a,int size);      //基数计数排序
void ColorSort(int *a,int size);    //颜色排序
int FindKthSmall(int *a,int size);
void PutNum(int*a,int n);
void PrintNum(int*a,int n);
int input(char choice);


#endif // TIME_TEST_H_INCLUDED
