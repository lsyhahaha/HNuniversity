#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Graph {
public:
    int V; // 顶点数
    vector<vector<int>> adjList; // 邻接表

    Graph(int vertices) : V(vertices), adjList(vertices) {}

    // 添加无向边
    void addEdge(int v, int w) {
        adjList[v].push_back(w);
        adjList[w].push_back(v);
    }

    // 深度优先搜索
    void DFS(int startVertex, vector<bool>& visited) {
        stack<int> stack;
        stack.push(startVertex);
        visited[startVertex] = true;

        while (!stack.empty()) {
            int currentVertex = stack.top();
            stack.pop();

            for (const auto &neighbor : adjList[currentVertex]) {
                if (!visited[neighbor]) {
                    stack.push(neighbor);
                    visited[neighbor] = true;
                }
            }
        }
    }

    // 判断图是否为连通图
    bool isConnectedGraph() {
        vector<bool> visited(V, false);

        // 从第一个顶点开始深度优先搜索
        DFS(0, visited);

        // 检查所有顶点是否都被访问到
        for (bool v : visited) {
            if (!v) {
                return false;
            }
        }

        return true;
    }
};

int main() {
    // 创建一个无向图
    Graph graph(5);
    graph.addEdge(0, 1);
    graph.addEdge(1, 2);
    graph.addEdge(2, 3);
    graph.addEdge(3, 4);

    // 判断图是否为连通图
    if (graph.isConnectedGraph()) {
        cout << "The graph is connected." << endl;
    } else {
        cout << "The graph is not connected." << endl;
    }

    return 0;
}
