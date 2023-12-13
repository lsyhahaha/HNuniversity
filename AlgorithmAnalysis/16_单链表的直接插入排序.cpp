#include <iostream>

using namespace std;

// 定义单链表节点
struct ListNode {
    int data;
    ListNode* next;

    ListNode(int val) : data(val), next(nullptr) {}
};

// 插入排序函数
ListNode* insertionSortList(ListNode* head) {
    if (!head || !head->next) {
        return head;
    }

    // 创建虚拟头节点
    ListNode* dummy = new ListNode(0);
    dummy->next = head;

    ListNode* prevSorted = dummy->next;
    ListNode* curr = prevSorted->next;

    while (curr) {
        if (curr->data < prevSorted->data) {
            // 将当前节点从原位置删除
            prevSorted->next = curr->next;
            
            // 寻找插入位置
            ListNode* prevInsert = dummy;
            while (prevInsert->next && prevInsert->next->data < curr->data) {
                prevInsert = prevInsert->next;
            }

            // 插入节点到新位置
            curr->next = prevInsert->next;
            prevInsert->next = curr;

            // 移动到下一个未排序节点
            curr = prevSorted->next;
        } else {
            // 当前节点已经在正确位置，继续遍历
            prevSorted = curr;
            curr = curr->next;
        }
    }

    // 保存新的头节点并释放虚拟头节点
    head = dummy->next;
    delete dummy;

    return head;
}

// 打印链表
void printList(ListNode* head) {
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

// 释放链表内存
void deleteList(ListNode* head) {
    while (head) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }
}

int main() {
    // 示例：创建一个未排序的单链表
    ListNode* head = new ListNode(3);
    head->next = new ListNode(1);
    head->next->next = new ListNode(4);
    head->next->next->next = new ListNode(2);

    cout << "Original list: ";
    printList(head);

    // 调用插入排序函数
    head = insertionSortList(head);

    cout << "Sorted list: ";
    printList(head);

    // 释放链表内存
    deleteList(head);

    return 0;
}
