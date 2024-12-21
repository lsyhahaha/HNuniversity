#include <iostream>

class ListNode {
public:
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// 对一个单链表使用冒泡排序算法
void bubbleSort(ListNode* head) {
    if (!head || !head->next) return;

    bool swapped;
    do {
        swapped = false;
        ListNode* current = head;
        while (current && current->next) {
            if (current->val > current->next->val) {
                // Swap values
                std::swap(current->val, current->next->val);
                swapped = true;
            }
            current = current->next;
        }
    } while (swapped);
}

void printList(ListNode* head) {
    ListNode* current = head;
    while (current) {
        std::cout << current->val << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

int main() {
    // Creating a sample linked list: 5 -> 3 -> 8 -> 1 -> 7
    ListNode* head = new ListNode(5);
    head->next = new ListNode(3);
    head->next->next = new ListNode(8);
    head->next->next->next = new ListNode(1);
    head->next->next->next->next = new ListNode(7);

    std::cout << "Original list: ";
    printList(head);

    bubbleSort(head);

    std::cout << "Sorted list: ";
    printList(head);

    return 0;
}
