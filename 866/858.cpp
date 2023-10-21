// Prim算法求最小生成树

#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 510, INF = 0x3f3f3f3f;

int n, m;
int g[N][N]; // 邻接矩阵表示图的边权
int dist[N]; // 存储从当前最小生成树到各个顶点的最小距离
bool st[N]; // 用于标记顶点是否已经包含在最小生成树中

int prim() {
    memset(dist, 0x3f, sizeof dist); // 初始化dist数组为无穷大

    int res = 0;
    for (int i = 0; i < n; i++) {
        // 在选择下一个要加入最小生成树的顶点 t，
        int t = -1;
        for (int j = 1; j <= n; j++) {
            if (!st[j] && (t == -1 || dist[t] > dist[j]))
                t = j;
        }

        if (i && dist[t] == INF) return INF; // 如果无法生成最小生成树，返回INF

        if (i) res += dist[t]; // 累加当前最小生成树的权值
        st[t] = true; // 将顶点t加入最小生成树

        for (int j = 1; j <= n; j++) {
            dist[j] = min(dist[j], g[t][j]); // 更新到其他顶点的距离
        }
    }

    return res;
}

int main() {
    scanf("%d%d", &n, &m);

    memset(g, 0x3f, sizeof g); // 初始化图的邻接矩阵为无穷大

    while (m--) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        g[a][b] = g[b][a] = min(g[a][b], c); // 更新边的权值，保留最小值
    }

    int t = prim();

    if (t == INF) puts("impossible"); // 输出无法生成最小生成树的情况
    else printf("%d\n", t); // 输出最小生成树的权值

    return 0;
}