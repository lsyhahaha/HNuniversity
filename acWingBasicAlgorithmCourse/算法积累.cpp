// 求无向图的割点
// Tarjan算法

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAXN = 1000; // 根据需要调整节点数的上限
vector<int> graph[MAXN];
int dfn[MAXN], low[MAXN], timestamp;
bool isCut[MAXN];

void tarjan(int u, int parent) {
    dfn[u] = low[u] = ++timestamp; // 初始化时间戳
    int childCount = 0;            // 子节点计数

    for (int v : graph[u]) {
        if (!dfn[v]) { // 如果节点v未被访问
            childCount++;   
            tarjan(v, u); // 深度优先搜索

            // 回溯更新low值
            low[u] = min(low[u], low[v]);

            // 判断割点条件
            if (parent != -1 && low[v] >= dfn[u]) {
                isCut[u] = true;
            }
        } else if (v != parent) { // 回边的情况
            low[u] = min(low[u], dfn[v]);
        }
    }

    // 根节点的特殊情况
    if (parent == -1 && childCount > 1) {
        isCut[u] = true;
    }
}

int main() {
    int n, m; // n为节点数，m为边数
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    fill(dfn, dfn + n, 0); // 初始化访问数组
    fill(low, low + n, 0);
    fill(isCut, isCut + n, false);
    timestamp = 0;

    for (int i = 0; i < n; i++) {
        if (!dfn[i]) {
            tarjan(i, -1);
        }
    }

    cout << "Cut points:" << endl;
    for (int i = 0; i < n; i++) {
        if (isCut[i]) {
            cout << i << endl;
        }
    }

    return 0;
}