#include <iostream>
#include <vector>

using namespace std;

// 栈节点的定义
struct StackNode {
    int data;
    StackNode* next;

    StackNode(int value) : data(value), next(nullptr) {}
};

class Stack {
private:
    vector<int> data;
public:
    // 入栈操作
    void push(int value) {
        data.push_back(value);
    }

    // 出栈操作
    void pop() {
        if (!isEmpty()) {
            data.pop_back();
        }
    }

    // 获取栈顶元素
    int top() const {
        if (!isEmpty()) {
            return data.back();
        }
        // 返回一个特殊值表示栈空
        return -1;
    }

    // 判断栈是否为空
    bool isEmpty() const {
        return data.empty();
    }

    // 获取栈的大小
    int size() const {
        return data.size();
    }
};

class LinkedStack {
private:
    StackNode* topNode;
public:
    // 构造函数
    LinkedStack() : topNode(nullptr) {}

    // 入栈操作
    void push(int value) {
        StackNode* newNode = new StackNode(value);
        newNode->next = topNode;
        topNode = newNode;
    }

    // 出栈操作
    void pop() {
        if (!isEmpty()) {
            StackNode* temp = topNode;
            topNode = topNode->next;
            delete temp;
        }
    }

    // 获取栈顶元素
    int top() const {
        if (!isEmpty()) {
            return topNode->data;
        }
        // 返回一个特殊值表示栈空
        return -1;
    }

    // 判断栈是否为空
    bool isEmpty() const {
        return topNode == nullptr;
    }
};

// 队列节点的定义
struct QueueNode {
    int data;
    QueueNode* next;

    QueueNode(int value) : data(value), next(nullptr) {}
};

class Queue {
private:
    vector<int> data;
    int front; // 队头指针
    int rear;  // 队尾指针
public:
    // 构造函数
    Queue() : front(0), rear(0) {}

    // 入队操作
    void enqueue(int value) {
        data.push_back(value);
        rear++;
    }

    // 出队操作
    void dequeue() {
        if (!isEmpty()) {
            front++;
        }
    }

    // 获取队头元素
    int frontElement() const {
        if (!isEmpty()) {
            return data[front];
        }
        // 返回一个特殊值表示队列空
        return -1;
    }

    // 判断队列是否为空
    bool isEmpty() const {
        return front == rear;
    }

    // 获取队列的大小
    int size() const {
        return rear - front;
    }
};

class LinkedQueue {
private:
    QueueNode* front; // 队头指针
    QueueNode* rear;  // 队尾指针
public:
    // 构造函数
    LinkedQueue() : front(nullptr), rear(nullptr) {}

    // 入队操作
    void enqueue(int value) {
        QueueNode* newNode = new QueueNode(value);
        if (isEmpty()) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
    }

    // 出队操作
    void dequeue() {
        if (!isEmpty()) {
            QueueNode* temp = front;
            front = front->next;
            delete temp;

            if (front == nullptr) {
                rear = nullptr; // 如果队列为空，队尾指针也应为空
            }
        }
    }

    // 获取队头元素
    int frontElement() const {
        if (!isEmpty()) {
            return front->data;
        }
        // 返回一个特殊值表示队列空
        return -1;
    }

    // 判断队列是否为空
    bool isEmpty() const {
        return front == nullptr;
    }
};

int main() {
    // 栈的顺序存储结构
    Stack stack;
    stack.push(1);
    stack.push(2);
    stack.push(3);
    cout << "Top element of stack: " << stack.top() << endl;
    stack.pop();
    cout << "Top element after pop: " << stack.top() << endl;

    // 栈的链式存储结构
    LinkedStack linkedStack;
    linkedStack.push(1);
    linkedStack.push(2);
    linkedStack.push(3);
    cout << "Top element of linked stack: " << linkedStack.top() << endl;
    linkedStack.pop();
    cout << "Top element after pop: " << linkedStack.top() << endl;

    // 队列的顺序存储结构
    Queue queue;
    queue.enqueue(1);
    queue.enqueue(2);
    queue.enqueue(3);
    cout << "Front element of queue: " << queue.frontElement() << endl;
    queue.dequeue();
    cout << "Front element after dequeue: " << queue.frontElement() << endl;

    // 队列的链式存储结构
    LinkedQueue linkedQueue;
    linkedQueue.enqueue(1);
    linkedQueue.enqueue(2);
    linkedQueue.enqueue(3);
    cout << "Front element of linked queue: " << linkedQueue.frontElement() << endl;
    linkedQueue.dequeue();
    cout << "Front element after dequeue: " << linkedQueue.frontElement() << endl;

    return 0;
}
