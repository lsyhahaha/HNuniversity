// 直接插入排序

#include<iostream>
using namespace std;

//arr[0~n-1]存数据；
void InsertSort(int A[], int n)
{
    int i, j, temp;
    //遍历数组
    for (i = 1; i < n; i++){
        int cnt = 0; // 记录每趟的移动次数

        //当前元素的前驱大于当前元素
        if (A[i - 1] > A[i]) {
            temp = A[i];  //保存arr[i]
            //将前面有序序列中的所有大于arr[i]的值全部后移一位
            for (j = i - 1; j >= 0 && A[j] > temp; j--){
                A[j + 1] = A[j];
                cnt++; // 移动次数++
            }
            A[j + 1] = temp;  //将原arr[i]赋值给arr[j + 1]
        }//if

        printf("第%d趟直接插入排序：", i);
        for(int i = 0; i < n; i++) cout << A[i] <<" ";
        cout << "\t" << "移动次数（或者称为交换次数）：" << cnt ;
        cout << endl;
    }//for
}

int main(){
    int A[] = {46, 32, 55, 81, 65, 11, 25, 43};
    InsertSort(A,8);
    return 0;
}