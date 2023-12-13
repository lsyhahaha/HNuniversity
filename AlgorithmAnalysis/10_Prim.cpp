#include <iostream>
#include <vector>
#include <climits>

using namespace std;

const int INF = INT_MAX; // 无穷大

class Prim {
public:
    int V; // 顶点数
    vector<vector<int>> graph; // 邻接矩阵表示图

    Prim(int vertices) : V(vertices), graph(vertices, vector<int>(vertices, INF)) {}

    // 添加边
    void addEdge(int u, int v, int weight) {
        graph[u][v] = weight;
        graph[v][u] = weight;
    }

    // 执行Prim算法生成最小生成树
    void primMST() {
        vector<int> parent(V, -1); // 存储最小生成树的父节点
        vector<int> key(V, INF);    // 存储每个顶点到最小生成树的最小权值
        vector<bool> inMST(V, false); // 标记顶点是否已经在最小生成树中

        // 从第一个顶点开始生成最小生成树
        key[0] = 0;

        for (int count = 0; count < V - 1; ++count) {
            int u = minKey(key, inMST);
            inMST[u] = true;

            // 更新相邻顶点的权值和父节点
            for (int v = 0; v < V; ++v) {
                if (graph[u][v] && !inMST[v] && graph[u][v] < key[v]) {
                    parent[v] = u;
                    key[v] = graph[u][v];
                }
            }
        }

        // 输出最小生成树
        cout << "Edges in the Minimum Spanning Tree:" << endl;
        for (int i = 1; i < V; ++i) {
            cout << "Edge: " << parent[i] << " - " << i << "  Weight: " << graph[parent[i]][i] << endl;
        }
    }

private:
    // 在不在最小生成树中的顶点中找到具有最小键值的顶点
    int minKey(const vector<int>& key, const vector<bool>& inMST) {
        int min = INF, minIndex;

        for (int v = 0; v < V; ++v) {
            if (!inMST[v] && key[v] < min) {
                min = key[v];
                minIndex = v;
            }
        }

        return minIndex;
    }
};

int main() {
    // 创建一个带权无向图
    Prim graph(5);
    graph.addEdge(0, 1, 2);
    graph.addEdge(0, 3, 6);
    graph.addEdge(1, 2, 3);
    graph.addEdge(1, 3, 8);
    graph.addEdge(1, 4, 5);
    graph.addEdge(2, 4, 7);
    graph.addEdge(3, 4, 9);

    // 执行Prim算法生成最小生成树
    graph.primMST();

    return 0;
}
