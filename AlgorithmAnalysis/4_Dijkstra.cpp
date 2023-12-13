#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

// 定义图的邻接列表表示
typedef pair<int, int> Edge; // (目标节点, 边权重)
typedef vector<vector<Edge>> Graph;

const int INF = numeric_limits<int>::max(); // 无穷大

vector<int> dijkstra(const Graph& graph, int start) {
    int n = graph.size();
    vector<int> distance(n, INF); // 到每个节点的距离
    vector<bool> visited(n, false); // 节点是否已被访问

    // 优先队列，存储节点和到该节点的距离
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    distance[start] = 0;
    pq.push({0, start});

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        // 如果节点已经被访问，则跳过
        if (visited[u]) {
            continue;
        }

        visited[u] = true;

        // 遍历邻接节点
        for (const Edge& edge : graph[u]) {
            int v = edge.first;
            int weight = edge.second;

            // 更新到邻接节点的距离
            if (distance[u] + weight < distance[v]) {
                distance[v] = distance[u] + weight;
                pq.push({distance[v], v});
            }
        }
    }

    return distance;
}

int main() {
    // 示例图的邻接列表表示
    Graph graph = {
        {{1, 4}, {2, 2}},
        {{3, 5}},
        {{1, 1}, {3, 8}},
        {}
    };

    int startNode = 0;

    vector<int> shortestDistances = dijkstra(graph, startNode);

    // 输出最短路径
    for (int i = 0; i < shortestDistances.size(); ++i) {
        cout << "Shortest distance from node " << startNode << " to node " << i << ": ";
        if (shortestDistances[i] == INF) {
            cout << "INF" << endl;
        } else {
            cout << shortestDistances[i] << endl;
        }
    }

    return 0;
}
