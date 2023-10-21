#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    long long dfs(vector<vector<int>> &g, vector<bool> &vis, int n, int x) {
        vis[x] = true;
        long long count = 1;
        // cout << "访问" << x << endl;

        int y;
        // NOTICE 2： g[x].size();
        for (int i = 0; i < g[x].size(); i++) {
            y = g[x][i]; // 与x相邻的结点y
            if(!vis[y]) {
                count += dfs(g, vis, n, y);
            }
        }

        return count;
    }

    long long countPairs(int n, vector<vector<int>>& edges) {
        // NOTICE 1; 
        if(edges.size() == 0) {
            long long cur = n;
            return cur * (cur - 1) / 2;
        }

        vector<vector<int>> g(n);
        long long res = 0;

        // NOTICE 3:构造邻接表
        for (auto edge : edges) {
            int x = edge[0], y = edge[1];
            g[x].push_back(y), g[y].push_back(x); 
        }

        vector<bool> vis(n, false);

        for(int i = 0; i < n; i++) {
            if(!vis[i]) {
                long long count = dfs(g, vis, n, i);
                res += count * (n - count);
            }
        }
        
        return res / 2;
    }
};