#include <iostream>
#include <vector>

using namespace std;

// 调整堆，使其满足堆的性质
void heapify(vector<int>& arr, int n, int i) {
    int largest = i; // 初始化最大值为根节点
    int left = 2 * i + 1; // 左子节点索引
    int right = 2 * i + 2; // 右子节点索引

    // 如果左子节点比根节点大
    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }

    // 如果右子节点比当前最大值大
    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }

    // 如果最大值不是根节点
    if (largest != i) {
        swap(arr[i], arr[largest]);

        // 递归调整被影响的子树
        heapify(arr, n, largest);
    }
}

// 堆排序函数
void heapSort(vector<int>& arr) {
    int n = arr.size();

    // 构建最大堆
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }

    // 逐个取出最大值并调整堆
    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]); // 将当前最大值（堆顶）放到数组末尾
        heapify(arr, i, 0);   // 调整剩余的堆
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

    // 调用堆排序函数
    heapSort(arr);

    cout << "Sorted array: ";
    printArray(arr);

    return 0;
}
