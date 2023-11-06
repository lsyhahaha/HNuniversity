#include <bits/stdc++.h>

using namespace std;

int N, Q;
int dfs(vector<vector<int>>& g, vector<bool>& vt, int u, int v);

int main(){
    cin >> N >> Q;
    vector<vector<int>> g(N, vector<int>(N, 0));

    int qq, u, v;
    while(Q --) {
        cin >> qq >> u >> v;
        if(qq == 0) {
            g[u][v] = 1;
        }else if (qq == 1) {
            vector<bool> vt(g.size(), false);
            vt[u] = true;
            int res = dfs(g, vt, u, v); // u是否能够到v,如果能，则返回1，否则返回0；
            if(res == 1) cout << 1 << endl;
            else cout << 0 << endl;
        }
    }

    return 0;
}

int dfs(vector<vector<int>>& g, vector<bool>& vt, int u, int v) {
    if (u >= g.size() || v >= g.size()) return 0;
    
    if(v == u) return 1;

    for(int i = 0; i < g.size(); i++) {
        if(g[u][i] == 1 && !vt[i]) {
            vt[i] = true;
            dfs(g, vt, i, v);
        }
    }

    return 0;
 }