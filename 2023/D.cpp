/*
    第十二题 给定一个含有n个元素的数组a，已知a中的元素不重复，现采用a中的
    元素作为结点来构造无向图，其中组成边的具体方法：对于a中的两个元素ai和
    aj，如果ai > aj,且i < j,则这两个结点之间可以添加一条边，请设计一算法，
    求最后构成的无向图的连通分量数。
*/

// create graph
// dfs
#include <bits/stdc++.h>
using namespace std;

int g[100][100];
int len; // node_count

void create() {
    // input
    vector<int> arr(100);
    cin >> len; 
    for (int i = 0; i < len; i++) cin >> arr[i];

    // main
    for(int i = 0; i < len; i++) {
        for(int j = 0; j < len; j++) g[i][j] = 0;
    }

    for(int i = 0; i < len; i++) {
        for(int j = i + 1; j < len; j++) {
            if(arr[i] > arr[j]) {
                g[i][j] = 1, g[j][i] = 1;
            }
        }
    }
    // output
    for(int i = 0; i < len; i++) {
        for(int j = 0; j < len; j++) 
            cout << g[i][j] << " ";
        cout << endl;
    }
}

void dfs(int g[][100], int u, vector<bool>& vis) {
    vis[u] = true;

    for (int i = 0; i < len; i++) {
        if(!vis[i] && g[u][i] == 1) {
            dfs(g, i, vis);
        }
    }
}

void solve() {
    vector<bool> vis(len, false); //  visited node is true
    int cnt = 0;
    for(int i = 0; i < len; i++) {
        if(!vis[i]) {
            dfs(g, i, vis);
            cnt++;
        }
    }
    cout << "连通分量个数:" << cnt << endl; 
}

int main()
{
    freopen("in.txt", "rt", stdin), freopen("out.txt", "wt", stdout);
    int t;
    cin >> t;

    while (t --) {
        // cout << "preforme " << t << endl;
        create();
        solve();
    }
    return 0;
}