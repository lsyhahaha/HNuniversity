#include <iostream>
#include <vector>

using namespace std;

// 冒泡排序函数
void bubbleSort(vector<int>& arr) {
    int n = arr.size();

    for (int i = 0; i < n - 1; i++) {
        // 标记当前轮是否发生了交换，若未发生则说明数组已经有序，可以提前退出循环
        bool swapped = false;

        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // 交换 arr[j] 和 arr[j + 1]
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }

        // 如果在当前轮没有发生交换，说明数组已经有序，提前退出循环
        if (!swapped) {
            break;
        }
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
    vector<int> arr = {64, 34, 25, 12, 22, 11, 90};

    cout << "Original array: ";
    printArray(arr);

    // 调用冒泡排序函数
    bubbleSort(arr);

    cout << "Sorted array: ";
    printArray(arr);

    return 0;
}
