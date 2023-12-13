#include <iostream>
#include <vector>

using namespace std;

// 简单选择排序函数
void selectionSort(vector<int>& arr) {
    int n = arr.size();

    for (int i = 0; i < n - 1; ++i) {
        // 假设当前位置的元素最小
        int minIndex = i;

        // 在未排序部分找到最小元素的索引
        for (int j = i + 1; j < n; ++j) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }

        // 将找到的最小元素与当前位置交换
        swap(arr[i], arr[minIndex]);
    }
}

int main() {
    // 示例数据
    vector<int> data = {64, 25, 12, 22, 11};

    // 输出原始数据
    cout << "Original data: ";
    for (int num : data) {
        cout << num << " ";
    }
    cout << endl;

    // 进行简单选择排序
    selectionSort(data);

    // 输出排序后的数据
    cout << "Sorted data: ";
    for (int num : data) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
