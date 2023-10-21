#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void dfs(vector<vector<int>>& edges, vector<bool> &vis, int n, int u, int &ans) {
        if(u == n) return;
        vis[u] = true;
        ans ++;

        for(int i = 0; i < edges.size(); i++) {
            int a = edges[i][0], b = edges[i][1];
            if(a == u) {
                if(vis[b] == false)
                    dfs(edges, vis, n, b, ans);
            }

            if(b == u) {
                if(!vis[a]){
                    dfs(edges, vis, n, a, ans);
                }
            }
        }
    }

    long long countPairs(int n, vector<vector<int>>& edges) {
        // total = n
        if (edges.size() == 0) return n * (n - 1) / 2;

        long long res = 0;
        vector<bool> vis(n, false);
        for (int i = 0; i < n; i++) { // 结点个数
            int ans = 0;
            if(!vis[i])
                dfs(edges, vis, n, i, ans); // ans为和i在一个连通分量的结点个数

            cout << ans << endl;
            res += ans * (n - ans);
        }
        
        return res / 2;
    }
};