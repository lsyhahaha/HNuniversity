#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>
#include <queue>

using namespace std;

const int INF = numeric_limits<int>::max() / 2; // 避免溢出

// 图的边表示
struct Edge {
    int source, destination, weight;
};

// Bellman-Ford算法，用于重新赋权
vector<int> bellmanFord(const vector<Edge>& edges, int numNodes, int start) {
    vector<int> distance(numNodes, INF);
    distance[start] = 0;

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

    return distance;
}

// 重新赋权
vector<vector<int>> reweightGraph(const vector<vector<int>>& originalGraph, const vector<int>& h) {
    int numNodes = originalGraph.size();
    vector<vector<int>> reweightedGraph(numNodes, vector<int>(numNodes, INF));

    for (int i = 0; i < numNodes; ++i) {
        for (int j = 0; j < numNodes; ++j) {
            if (originalGraph[i][j] != INF) {
                reweightedGraph[i][j] = originalGraph[i][j] + h[i] - h[j];
            }
        }
    }

    return reweightedGraph;
}

// Dijkstra算法，求解重新赋权后的图的最短路径
vector<int> dijkstra(const vector<vector<int>>& graph, int start) {
    int numNodes = graph.size();
    vector<int> distance(numNodes, INF);

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, start});
    distance[start] = 0;

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        for (int v = 0; v < numNodes; ++v) {
            if (graph[u][v] != INF && distance[u] + graph[u][v] < distance[v]) {
                distance[v] = distance[u] + graph[u][v];
                pq.push({distance[v], v});
            }
        }
    }

    return distance;
}

// Johnson算法
vector<vector<int>> johnson(const vector<Edge>& edges, int numNodes) {
    // 添加一个新的节点作为辅助节点，并添加到所有其他节点的边
    vector<Edge> augmentedEdges = edges;
    for (int i = 0; i < numNodes; ++i) {
        augmentedEdges.push_back({numNodes, i, 0});
    }

    // 使用Bellman-Ford算法计算从辅助节点到其他节点的最短路径
    vector<int> h = bellmanFord(augmentedEdges, numNodes + 1, numNodes);

    // 重新赋权
    vector<vector<int>> reweightedGraph = reweightGraph(vector<vector<int>>(numNodes, vector<int>(numNodes, INF)), h);

    // 使用Dijkstra算法计算所有节点对之间的最短路径
    vector<vector<int>> shortestPaths(numNodes, vector<int>(numNodes, INF));
    for (int i = 0; i < numNodes; ++i) {
        vector<int> dijkstraDistances = dijkstra(reweightedGraph, i);
        for (int j = 0; j < numNodes; ++j) {
            shortestPaths[i][j] = dijkstraDistances[j] + h[j] - h[i];
        }
    }

    return shortestPaths;
}

int main() {
    // 示例图的边表示
    vector<Edge> edges = {
        {0, 1, -2},
        {1, 2, 1},
        {2, 0, -3},
        {1, 3, 4},
        {3, 2, 5},
    };

    int numNodes = 4;

    vector<vector<int>> shortestPaths = johnson(edges, numNodes);

    // 输出最短路径
    cout << "Shortest paths between all nodes:" << endl;
    for (int i = 0; i < numNodes; ++i) {
        for (int j = 0; j < numNodes; ++j) {
            if (shortestPaths[i][j] == INF) {
                cout << "INF ";
            } else {
                cout << shortestPaths[i][j] << " ";
            }
        }
        cout << endl;
    }

    return 0;
}
