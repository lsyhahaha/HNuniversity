// 判断图g是否满足拓扑排序

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Graph {
public:
    int V; // 顶点数
    vector<vector<int>> adj; // 邻接表

    Graph(int vertices) : V(vertices), adj(vertices) {}

    void addEdge(int v, int w) {
        adj[v].push_back(w);
    }

    void topologicalSort() {
        vector<int> inDegree(V, 0); // 记录每个节点的入度

        // 计算每个节点的入度
        for (int v = 0; v < V; ++v) {
            for (int w : adj[v]) {
                inDegree[w]++;
            }
        }

        // 创建一个队列，并将所有入度为0的节点加入队列
        queue<int> q;
        for (int v = 0; v < V; ++v) {
            if (inDegree[v] == 0) {
                q.push(v);
            }
        }

        // 记录拓扑排序的结果
        vector<int> result;

        // 开始拓扑排序
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            result.push_back(v);

            // 更新邻接节点的入度，并将入度为0的节点加入队列
            for (int w : adj[v]) {
                inDegree[w]--;
                if (inDegree[w] == 0) {
                    q.push(w);
                }
            }
        }

        // 检查是否有环
        if (result.size() != V) {
            cout << "图中存在环，无法进行拓扑排序" << endl;
            return;
        }

        // 输出拓扑排序的结果
        cout << "拓扑排序结果: ";
        for (int v : result) {
            cout << v << " ";
        }
        cout << endl;
    }
};

int main() {
    // 创建有向图
    Graph g(6);
    g.addEdge(5, 2);
    g.addEdge(5, 0);
    g.addEdge(4, 0);
    g.addEdge(4, 1);
    g.addEdge(2, 3);
    g.addEdge(3, 1);

    // 进行拓扑排序
    g.topologicalSort();

    return 0;
}

