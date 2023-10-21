#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

const int N = 100010;
const int INF = 0x3f3f3f3f;

int n, m, d[N];
vector<vector<int>> g(N);
bool visited[N];

void bfs_mindistance(vector<vector<int>> &g, int u) {
    for(int i = 1; i <= n; i++) d[i] = INF;
    d[u] = 0, visited[u] = true; // d[i]表示1到u的距离

    int queue[N], hh = 0, tt = -1;
    queue[++ tt] = u;
    while(tt >= hh) {
        int cur = queue[hh ++];

        // NOTICE 1:是g[cur] 不是 g[u];
        for(int i = 0; i < g[cur].size(); i++) { // 遍历u的每一个邻接点
            int b = g[cur][i];
            if(!visited[b]) {
                queue[++ tt] = b;
                visited[b] = true;
                d[b] = d[cur] + 1;
                
                if(b == n) {
                    cout << d[b] << endl;
                    return ;
                }
            }
        }
    }
    
    if(d[n] == INF) cout << -1 << endl;
    else cout << d[n] << endl;
}

int main(){
    cin >> n >> m;
    for(int i = 1; i <= m; i++) {
        // 1≤n,m≤1e5
        int a, b;
        cin >> a >> b; // a -> b有向边
        g[a].push_back(b); // 邻接表
    }
    
    // for(int i = 1; i <= 10; i++) {
    //     cout << "i=" << i << ": ";
    //     for(int j = 0; j < g[i].size(); j++) cout << g[i][j] << " ";
    //     cout << endl;
    // }

    bfs_mindistance(g, 1);

    return 0;
}