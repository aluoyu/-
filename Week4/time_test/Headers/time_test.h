#ifndef TIME_TEST_H_INCLUDED
#define TIME_TEST_H_INCLUDED

void insertSort(int *a,int n);
void MergeArray(int *a,int begin,int mid,int end,int *temp);
void MergeSort(int *a,int begin,int end,int *temp);
void QuickSort_Recursion(int *a, int begin, int end);
void QuickSort(int *a,int size);    //���ţ��ǵݹ�棩
int Partition(int *a, int begin, int end);      //���ţ������ţ�
void CountSort(int *a, int size , int max);
void RadixCountSort(int *a,int size);      //������������
void ColorSort(int *a,int size);    //��ɫ����
int FindKthSmall(int *a,int size);
void PutNum(int*a,int n);
void PrintNum(int*a,int n);
int input(char choice);


#endif // TIME_TEST_H_INCLUDED
