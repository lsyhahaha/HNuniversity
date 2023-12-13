#include <iostream>
#include <vector>

using namespace std;

// 分区函数，返回分区后的中轴索引
int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high]; // 选择数组最后一个元素作为中轴值
    int i = low - 1; // 初始化 i 为分区前的起始索引

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]); // 将当前元素交换到分区的左侧
        }
    }

    swap(arr[i + 1], arr[high]); // 将中轴值交换到正确的位置
    return i + 1; // 返回中轴索引
}

// 快速排序函数
void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        // 找到中轴索引
        int pivotIndex = partition(arr, low, high);

        // 递归对中轴左侧和右侧进行排序
        quickSort(arr, low, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, high);
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
    vector<int> arr = {10, 7, 8, 9, 1, 5};

    cout << "Original array: ";
    printArray(arr);

    // 调用快速排序函数
    quickSort(arr, 0, arr.size() - 1);

    cout << "Sorted array: ";
    printArray(arr);

    return 0;
}
