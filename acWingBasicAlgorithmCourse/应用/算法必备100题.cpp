#include<bits/stdc++.h>
using namespace std;

//  Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// 1.顺序表的插入元素操作

// 1.如果插入位置不合理，结束程序，输出异常信息；
// 2.如果线性表长度大于或者等于数组长度，结束程序，输出异常信息；
// 3.从顺序表的最后一个元素开始遍历到第i个位置，依次将其向后移动一个位置；
// 4.将元素加入指定位置i；
// 5.表长加1；
struct LNode1
{
    int data[100];
    int length = 0;
};
LNode1* insertLnode1(LNode1* l1, int x, int i) {
    if (i < 0 || i > l1->length) {
        cout << "插入位置不合理"  << endl;
        return ;
    }

    for (int i = l1->length; i >= 0; i -- ) {
        if (x < l1->data[i]) {
            for (int j = l1->length; j > i; j --) {
                l1->data[j] = l1->data[j - 1];
            }
        }

        l1->data[i] = x;
        l1->length ++;
    }

    return l1;
}


// 7.链表逆置  LRC024逆置链表
/**
 * 算法思想：用curnext标记head的下一个节点，以便于当head所指节点逆置后，找不到原来的链表：
 * ①head->next = pre;
 * pre = head;
 * head = curNext;
 * 
 * 最后return pre即可；
 * **/

// 方法一：迭代
class Solution {
public:
    ListNode* reverseList(ListNode* head) { 
        if (!head) return nullptr;

        ListNode* pre = nullptr;
        ListNode* curNext = head->next;

        while (head != nullptr) {
            curNext = head->next;
            head->next = pre;
            pre = head;
            head = curNext;
        }

        return pre;
    }
};
// 方法二：递归
class Solution {
public:
    ListNode* reverseList(ListNode* head) { 
        if (!head) return nullptr;
        if(!head->next) return head;

        ListNode* newList = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;

        return newList;
    }
};

// 8.编写一个算法，逆置一个含有两个以上节点的循环双链表
/**
 * 算法思想：只需要交换数据成员data,其他的前后指针不变
 * **/


// 10.东华大学2017 判断单链表前n个元素是否中心对称


// 11.2020 408统考，三元组的距离的最小值
// 算法思想：只需要移动最小的元素即可


// 13.荷兰国旗