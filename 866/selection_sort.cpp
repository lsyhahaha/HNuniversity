// 直接选择排序 或叫 简单选择排序

#include<iostream>
using namespace std;


//交换元素
void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

//简单选择排序
void SelectSort(int arr[], int n) {
    //遍历数组 arr[0~n-2] 最后一个元素arr[n-1]不用遍历；
    for (int i = 0; i < n-1; i++) {
       
        int min = i;     //标记未排序数列中最小值元素的下标，初始为第 i 个元素;
              
        for (int j = i + 1; j< n; j++) {  //从i + 1开始遍历数组
              if (arr[j] < arr[min])   
                min = j;
        }//for完之后min指向未排序数列中最小值元素的下标
      
       if(min!=i) swap(arr[i], arr[min]);  //交换第 i 个元素和最小值元素

       printf("第%d趟简单选择排序：", i + 1);
       for(int i = 0; i < n; i++) cout << arr[i] <<" ";
       cout << endl;
    }
}

int main(){
    int A[] = {46, 74, 53, 14, 26, 38, 86, 65, 27, 34};
    SelectSort(A, 10); 
    return 0;
}