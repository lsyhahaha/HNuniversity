#include <iostream>
#include <vector>

using namespace std;

// 直接插入排序函数
void insertionSort(vector<int>& arr) {
    int n = arr.size();

    for (int i = 1; i < n; ++i) {
        int key = arr[i];
        int j = i - 1;

        // 将比 key 大的元素都向后移动
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }

        // 插入 key 到正确位置
        arr[j + 1] = key;
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
    vector<int> arr = {12, 11, 13, 5, 6};

    cout << "Original array: ";
    printArray(arr);

    // 调用直接插入排序函数
    insertionSort(arr);

    cout << "Sorted array: ";
    printArray(arr);

    return 0;
}
