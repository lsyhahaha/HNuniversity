#include <iostream>
#include <vector>
#include <limits>

using namespace std;

// 定义图的边表示
struct Edge {
    int source, destination, weight;
};

const int INF = numeric_limits<int>::max(); // 无穷大

// Bellman-Ford算法
void bellmanFord(const vector<Edge>& edges, int numNodes, int start) {
    vector<int> distance(numNodes, INF);
    distance[start] = 0;

    // 松弛操作
    for (int i = 0; i < numNodes - 1; ++i) {
        for (const Edge& edge : edges) {
            int u = edge.source;
            int v = edge.destination;
            int w = edge.weight;

            if (distance[u] != INF && distance[u] + w < distance[v]) {
                distance[v] = distance[u] + w;
            }
        }
    }

    // 检测负权回路
    for (const Edge& edge : edges) {
        int u = edge.source;
        int v = edge.destination;
        int w = edge.weight;

        if (distance[u] != INF && distance[u] + w < distance[v]) {
            cout << "Graph contains negative weight cycle." << endl;
            return;
        }
    }

    // 输出最短路径
    cout << "Shortest distances from node " << start << " to all other nodes:" << endl;
    for (int i = 0; i < numNodes; ++i) {
        cout << "To node " << i << ": ";
        if (distance[i] == INF) {
            cout << "INF" << endl;
        } else {
            cout << distance[i] << endl;
        }
    }
}

int main() {
    // 示例图的边表示
    vector<Edge> edges = {
        {0, 1, 4},
        {0, 2, 2},
        {1, 3, 5},
        {2, 1, 1},
        {2, 3, 8},
        {3, 3, -10} // 包含负权边
    };

    int numNodes = 4;
    int startNode = 0;

    bellmanFord(edges, numNodes, startNode);

    return 0;
}
