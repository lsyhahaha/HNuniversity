#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    void dfs(int u, vector<vector<string>> &g, vector<vector<string>> &res, int n, vector<bool> &col, vector<bool> &dg, vector<bool> &udg) {
        if (u == n) {
            vector<string> cur;
            for (int i = 0; i < n; i ++ ) {
                string ss = "";
                for (int j = 0; j < n; j++) {
                    ss += g[i][j];
                } 
                cur.push_back(ss);
            }
            res.push_back(cur);
            return;
        }

        for (int i = 0; i < n; i ++ )
            if (!col[i] && !dg[u + i] && !udg[n - u + i])
            {
                g[u][i] = 'Q';
                col[i] = dg[u + i] = udg[n - u + i] = true;
                dfs(u + 1, g, res, n, col, dg, udg);
                col[i] = dg[u + i] = udg[n - u + i] = false;
                g[u][i] = '.';
            }
    }

    int totalNQueens(int n) {
        const int N = 20;
        vector<vector<string>> res, g(N, vector<string> (N));
        vector<bool> col(N), dg(N), udg(N);

        for (int i = 0; i < n; i ++ )
            for (int j = 0; j < n; j ++ )
                g[i][j] = '.';
        
        dfs(0, g, res, n, col, dg, udg);

        return res.size();
    }
};