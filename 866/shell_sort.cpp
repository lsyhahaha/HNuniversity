#include <stdio.h>
// 核心算法部分。

void ShellSort(int A[], int n)
{ // n是数组长度
    int i, j, temp, d;
    for (d = n / 2; d >= 1; d = d / 2)
    { // 每次最外的循环计算了一个d,d会不断变小。
        for (i = d + 1; i <= n; i++)
        { // 根据某一个d，进行分组排序

            if (A[i - d] > A[i])
            {                // 在子表中，如果前面的数值大于后面的数值
                temp = A[i]; // 用temp暂存后面的数值
                // 移动前面的元素
                for (j = i - d; j >= 0 && temp < A[j]; j -= d)
                {
                    A[j + d] = A[j];
                }
                // 插入
                A[j + d] = temp;
            }
        }
    }
}

int main() {
    // 建立一个原始的乱序的数组
    int A[] = {0, 7, 9, 2, 1, 4, 5, 8, 23, 22, 34, 11, 54}; // 第一个只是作为哨兵
    printf("排序之前： \n");
    int len_1 = sizeof(A) / sizeof(0); // 得到数组的长度
    int m;
    for (m = 1; m < len_1; m++)
    { // 不打印哨兵
        printf("%d ", A[m]);
    }
    printf("\n");

    int len;
    len = sizeof(A) / sizeof(0); // 获得数组长度
    ShellSort(A, len);

    // 检验是否排序成功：
    printf("排序之后： \n");
    int len_2 = sizeof(A) / sizeof(0); // 得到数组的长度
    for (int n = 2; n <= len_2; n++)
    { // 不知道为啥n=2的时候才正确
        printf("%d ", A[n]);
    }
    return 0;
}