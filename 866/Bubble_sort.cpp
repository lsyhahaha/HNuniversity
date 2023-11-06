#include <iostream>
using namespace std;

typedef char ElemType;

void swap(ElemType &a, ElemType &b) {
    ElemType temp = a;
    a = b;
    b = temp;
}

// 对A[]数组共n个元素进行冒泡排序
void Bubble(ElemType A[], int n) {
    for(int i = 0; i < n; i++) {
        bool flag = false;
        for(int j = n-1; j > i; j--) {
            if(A[j-1] > A[j]) 
                swap(A[j], A[j-1]), flag = true;
        }// for
        if(flag == false) break;

        // printf("第%d趟排序结果:\t", i + 1);
        // for(int k = 0; k < n; k++) cout << A[k] << " ";
        // cout << endl;
    }// for
}

// 对A[]数组共n个元素进行冒泡排序
// 湖大期末题 2015年秋 选择题19题
void Bubble1(ElemType A[], int n) {
    for(int i = n; i >= 0; i--) {
        bool flag = false;
        for(int j = 1; j < i; j++) {
            if(A[j-1] > A[j]) 
                swap(A[j], A[j-1]), flag = true;
        }// for
        if(flag == false) break;

        printf("第%d趟排序结果:\t", i + 1);
        for(int k = 0; k < n; k++) cout << A[k] << " ";
        cout << endl;
    }// for
}

int main(){
    ElemType A[] = {'Q', 'H', 'C', 'Y', 'P', 'A', 'M', 'S', 'R', 'D', 'F', 'X'};
    Bubble1(A, 12);
    return 0;
}