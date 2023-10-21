// 构造有向图，判断是否能构成拓扑排序

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        if(prerequisites.size() == 0) return true;

        vector<vector<string>> g(9, vector<string> (9, "."));

        int g[2010][2010], d[2010];
        for(int i = 0; i < prerequisites.size(); i++) {
            int a = prerequisites[i][0], b = prerequisites[i][1];
            if(a == b) return false;
            // cout << a << " " << b << endl;
            g[b][a] = 1, d[a]++;
        }

        int q[2010], hh = 0, tt = -1;
        vector<bool> vt(2010, false);
        for(int i = 0; i < numCourses; i++) {
            if(d[i] == 0) {
                q[++ tt] = i; // i的入度为0，加入队列
                vt[i] = true; // 标记i已经被访问
            }
        }

        while(tt >= hh) {
            int cur = q[hh ++]; // 出队
            // 访问cur
            vt[cur] = true;
            for(int i = 0; i < numCourses; i++) { // 删除cur结点, 以及与其相关的边
                if(g[cur][i] == 1) {
                    g[cur][i] = 0;
                    d[i]--;

                    if(d[i] == 0 && vt[i] == false) q[++ tt] = i;
                }
            }
        }

        // cout << tt << endl;
        if(tt == numCourses-1) return true;
        return false;
    }
};