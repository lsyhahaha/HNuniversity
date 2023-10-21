#include <bits/stdc++.h>
using namespace std;

const int N = 2010;

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> res;
        if (prerequisites.size() == 0) {
           vector<int> ans(numCourses, 0);
            for(int i = 0; i < numCourses; i++) ans[i] = i;
            return ans;
        }

        int g[N][N], d[N];
        for (int i = 0; i < prerequisites.size(); i++) {
            int a = prerequisites[i][0], b = prerequisites[i][1];
            g[b][a] = 1;
            d[b] ++; // d: 统计出度
        }

        int stack[N], top = -1;
        vector<bool> vis(N, false);
        for (int i = numCourses - 1; i >= 0; i--) {
            if(d[i] == 0) stack[++ top] = i;
        }

        int cnt = 0;
        while (top != -1) {
            int cur = stack[top --]; // 出栈
            res.push_back(cur);
            cnt ++;
            vis[cur] = true;
            cout << cur << " ";

            // 删除与cur相关的边
            for (int j = 0; j < numCourses; j++) {
                if(g[j][cur] == 1) {
                    g[j][cur] = 0;
                    d[j] --;
                    if(d[j] == 0 && vis[j] == false) stack[++ top] = j; 
                }
            }//for
        }// while

        cout << endl;
        cout << "cnt == " << cnt << endl;
        if(cnt != numCourses) return vector<int> {};

        reverse(res.begin(), res.end());
        return res;
    }
};