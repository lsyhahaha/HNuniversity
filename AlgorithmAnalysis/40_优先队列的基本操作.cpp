#include <iostream>
#include <queue>

using namespace std;

int main() {
    // 创建一个优先队列（默认是最大堆）
    priority_queue<int> maxPriorityQueue;

    // 插入元素
    maxPriorityQueue.push(4);
    maxPriorityQueue.push(10);
    maxPriorityQueue.push(3);

    // 访问队列顶部元素
    cout << "Top element of max priority queue: " << maxPriorityQueue.top() << endl;

    // 弹出队列顶部元素
    maxPriorityQueue.pop();

    // 访问队列新的顶部元素
    cout << "Top element of max priority queue after pop: " << maxPriorityQueue.top() << endl;

    return 0;
}
