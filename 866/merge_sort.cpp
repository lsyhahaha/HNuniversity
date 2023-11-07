// 归并排序

#include <iostream>
using namespace std;

const int n = 100;

// 建立辅助数组B
int *B = (int *)malloc(n * sizeof(int));

// 归并函数
void Merge(int A[], int low, int mid, int high)
{
    int i, j, k; // 三个指针，i j是B上的，K是A上的
    // 把A复制到B
    for (k = low; k <= high; k++)
        B[k] = A[k];
    // 比较i j的key值，把小的放入A[k]
    for (i = low, j = mid + 1, k = i; i <= mid && j <= high; k++)
    {
        if (B[i] <= B[j])
            A[k] = B[i++];
        else
            A[k] = B[j++];
    }
    // 把没有扫描完的直接复制进入A
    while (i <= mid)
        A[k++] = B[i++];
    while (j <= high)
        A[k++] = B[j++];
}

// 归并排序主体函数
void MergeSort(int A[], int low, int high)
{
    if (low < high)
    {
        int mid = (low + high) / 2;  // 从中间划分
        MergeSort(A, low, mid);      // 对左半部分进行归并排序
        MergeSort(A, mid + 1, high); // 对右半部分进行归并排序
        Merge(A, low, mid, high);    // 调用归并函数
    }
}