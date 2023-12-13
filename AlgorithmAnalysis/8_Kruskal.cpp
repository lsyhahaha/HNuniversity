#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 边的结构
struct Edge {
    int src, dest, weight;

    // 排序比较函数
    bool operator<(const Edge& other) const {
        return weight < other.weight;
    }
};

class Kruskal {
public:
    int V; // 顶点数
    vector<Edge> edges; // 存储边的集合

    Kruskal(int vertices) : V(vertices) {}

    // 添加边
    void addEdge(int src, int dest, int weight) {
        edges.push_back({src, dest, weight});
    }

    // 执行Kruskal算法生成最小生成树
    void kruskalMST() {
        // 将边按照权值排序
        sort(edges.begin(), edges.end());

        vector<int> parent(V, -1); // 存储生成树的父节点

        for (const Edge& edge : edges) {
            int srcParent = findParent(parent, edge.src);
            int destParent = findParent(parent, edge.dest);

            // 如果边的两个端点不在同一分支上，则加入生成树
            if (srcParent != destParent) {
                cout << "Edge: " << edge.src << " - " << edge.dest << "  Weight: " << edge.weight << endl;
                unionSets(parent, srcParent, destParent);
            }
        }
    }

private:
    // 查找节点的根（使用路径压缩）
    int findParent(vector<int>& parent, int node) {
        if (parent[node] == -1) {
            return node;
        }
        return parent[node] = findParent(parent, parent[node]);
    }

    // 合并两个集合
    void unionSets(vector<int>& parent, int x, int y) {
        int rootX = findParent(parent, x);
        int rootY = findParent(parent, y);
        parent[rootX] = rootY;
    }
};

int main() {
    // 创建一个带权无向图
    Kruskal graph(4);
    graph.addEdge(0, 1, 10);
    graph.addEdge(0, 2, 6);
    graph.addEdge(0, 3, 5);
    graph.addEdge(1, 3, 15);
    graph.addEdge(2, 3, 4);

    // 执行Kruskal算法生成最小生成树
    cout << "Edges in the Minimum Spanning Tree:" << endl;
    graph.kruskalMST();

    return 0;
}
