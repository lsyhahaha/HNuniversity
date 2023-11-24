// 模板

#include <algorithm>
#include <array>
#include <cassert>
#include <chrono>
#include <cmath>
#include <cstring>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <vector>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *middleNode(ListNode *head)
    {
        int n = 0;
        ListNode *p = head;
        while(p != nullptr) {
            n++;
            p = p->next;
        }
        int i = 1;
        while (i++ <= n / 2) {
            cout << head->val << endl;
            head = head->next;
        }

        return head;
    }
};

// Leetcode 对拍
// https://www.acwing.com/blog/content/33455/
int main()
{
    // 生成一组随机数据，放在data.in里面

    // 暴力解法运行，将结果存放在bf.out中

    // 解法一运行，将输出结果放在sol1.out中，并且与bf.out对比
    // 解法二运行，将输出结果放在sol2.out中，并且与bf.out对比
    return 0;
}