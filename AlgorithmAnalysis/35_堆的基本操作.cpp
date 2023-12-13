#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // 创建一个堆（最小堆）
    vector<int> minHeap = {4, 10, 3, 5, 1};

    // 将一个元素插入堆
    push_heap(minHeap.begin(), minHeap.end());
    cout << "Min Heap after push: ";
    for (const auto& element : minHeap) {
        cout << element << " ";
    }
    cout << endl;

    // 弹出堆顶元素
    pop_heap(minHeap.begin(), minHeap.end());
    minHeap.pop_back();
    cout << "Min Heap after pop: ";
    for (const auto& element : minHeap) {
        cout << element << " ";
    }
    cout << endl;

    return 0;
}
