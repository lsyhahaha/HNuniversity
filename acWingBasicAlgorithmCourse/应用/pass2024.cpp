#include<bits/stdc++.h>
using namespace std;

// 2024应用题 最小栈
class MinStack{
    stack<int> s1, s2;


    int getMin(){
        // 返回当前栈内最小值
        return s2.top();
    }


    void push(int x) {
        s1.push(x);
        
        int cur_min = getMin();
        if (x < cur_min) {
            s2.push(x);
        } else {
            s2.push(cur_min);
        }
    }

    int getTop() {
        return s1.top();
    }

    void pop() {
        s2.pop();
        s1.pop();
    }
};

// 2024 算法题一  Leetcode21
struct ListNode{
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* res = new ListNode(0);
        ListNode* pre = res;

        if (!l1) return l2;
        if (!l2) return l1;

        if (l1->val <= l2->val) {
            pre->next = l1;
            l1 = l1->next;
        } else {
            pre->next = l2;
            l2 = l2->next;
        }

        pre = pre->next;
        pre->next = mergeTwoLists(l1, l2);

        return res->next;
    }
};




// 2024算法题二 Leetcode33
class Solution {
public:
    int find(vector<int>& nums, int l, int r, int target) {
        int mid = 0;
        while (l <= r) {
            mid = (l + r) / 2;

            if (nums[mid] == target) return mid;
            if (nums[mid] > target) r = mid - 1;
            else if (nums[mid] < target) l = mid + 1;
        }

        return -1;
    }

    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0, r = n - 1, mid;
        int res = -1;

        // 首先找到旋转次数
        while (l <= r) {
            mid = (l + r) / 2;

            if (nums[0] <= nums[mid]) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }

        cout << "l = " << l << endl;

        // 分别在左右两部分中查询是否有目标值
        int res1 = find(nums, 0, l - 1, target), res2 = find(nums, l, n - 1, target);
        if (res1 != -1)
            return res1;
        
        if (res2 != -1)
            return res2;
        
        return -1;
    }
};



// 2024 算法题三 Leetcode743 Dijkstra算法，适用于正权值的单源最短路问题
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        // 搜索图中最远的举例
        vector<vector<int>> g(n + 1, vector<int>(n + 1, 0x3f3f3f));
        for(int i = 0; i < times.size(); i ++ ){
            int u = times[i][0], v = times[i][1], w = times[i][2];
            g[u][v] = w; // 有向图,单向的
        }

        vector<bool> st(n + 1, false); // 记录i节点是否已经确定最短路
        vector<int> dist(n + 1, 0x3f3f3f); // 记录i节点的最短路
        dist[k] = 0, st[k] = true;

        return dijkstra(g, k, st, dist);
    }

    int dijkstra(vector<vector<int>> g, int k, vector<bool> &st, vector<int> &dist) {
        int n = g.size() - 1;

        for (int i = 1; i < n; i ++ ) {
            g[i][i] = 0;
        }

        for (int i = 1; i <= n; i ++) {
            if (g[k][i] < 0x3f3f3f) {
                dist[i] = g[k][i];
            }
        }


        for (int i = 0; i < n; i ++) {
            // 寻找未加入确定集合的最近距离的点
            int t = -1;
            for (int j = 1; j <= n; j ++) {
                if (!st[j] && (t == -1  || dist[t] > dist[j]))
                    t = j;
            }

            if (t == -1) break;
            cout << "t = " << t << endl;

            // 用t节点更新距离
            for (int j = 1; j <= n; j ++ ){
                dist[j] = min(dist[j], dist[t] + g[t][j]);
            }

            st[t] = true;
        }
        
        // 最大的距离
        int res = -1;
        for (int i = 1; i <= n; i ++) {
            res = max(res, dist[i]);
        }

        if (res == 0x3f3f3f) return -1;
        return res;
    }
};


// 2024算法题四 朱刘算法，适用于求解有向图的最小生成树
