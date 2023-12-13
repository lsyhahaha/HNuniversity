#include <iostream>
#include <vector>

using namespace std;

// 希尔排序函数
void shellSort(vector<int>& arr) {
    int n = arr.size();

    // 使用 Knuth 序列来确定间隔值
    int gap = 1;
    while (gap < n / 3) {
        gap = gap * 3 + 1;
    }

    while (gap > 0) {
        // 使用插入排序对间隔为 gap 的子数组进行排序
        for (int i = gap; i < n; i++) {
            int temp = arr[i];
            int j = i;

            while (j >= gap && arr[j - gap] > temp) {
                arr[j] = arr[j - gap];
                j -= gap;
            }

            arr[j] = temp;
        }

        // 缩小间隔
        gap /= 3;
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

    // 调用希尔排序函数
    shellSort(arr);

    cout << "Sorted array: ";
    printArray(arr);

    return 0;
}
