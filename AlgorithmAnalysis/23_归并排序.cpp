#include <iostream>
#include <vector>

using namespace std;

// 合并两个已排序的子数组
void merge(vector<int>& arr, int left, int middle, int right) {
    int n1 = middle - left + 1;
    int n2 = right - middle;

    // 创建临时数组来存储两个子数组
    vector<int> leftArray(n1);
    vector<int> rightArray(n2);

    // 将数据复制到临时数组 leftArray[] 和 rightArray[]
    for (int i = 0; i < n1; i++) {
        leftArray[i] = arr[left + i];
    }
    for (int j = 0; j < n2; j++) {
        rightArray[j] = arr[middle + 1 + j];
    }

    // 归并已排序的两个子数组
    int i = 0; // 初始化左子数组的索引
    int j = 0; // 初始化右子数组的索引
    int k = left; // 初始化合并数组的索引

    while (i < n1 && j < n2) {
        if (leftArray[i] <= rightArray[j]) {
            arr[k] = leftArray[i];
            i++;
        } else {
            arr[k] = rightArray[j];
            j++;
        }
        k++;
    }

    // 将左子数组的剩余部分复制到 arr[]
    while (i < n1) {
        arr[k] = leftArray[i];
        i++;
        k++;
    }

    // 将右子数组的剩余部分复制到 arr[]
    while (j < n2) {
        arr[k] = rightArray[j];
        j++;
        k++;
    }
}

// 归并排序函数
void mergeSort(vector<int>& arr, int left, int right) {
    if (left < right) {
        // 计算中间点
        int middle = left + (right - left) / 2;

        // 递归排序左半部分和右半部分
        mergeSort(arr, left, middle);
        mergeSort(arr, middle + 1, right);

        // 合并已排序的两个子数组
        merge(arr, left, middle, right);
    }
}

// 打印数组元素
void printArray(const vector<int>& arr) {
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
}

int main() {
    // 示例：创建一个未排序的数组
    vector<int> arr = {12, 11, 13, 5, 6, 7};

    cout << "Original array: ";
    printArray(arr);

    // 调用归并排序函数
    mergeSort(arr, 0, arr.size() - 1);

    cout << "Sorted array: ";
    printArray(arr);

    return 0;
}
