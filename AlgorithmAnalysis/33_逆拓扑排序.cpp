#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Graph {
public:
    int V; // 顶点数
    vector<vector<int>> adjList; // 邻接表

    Graph(int vertices) : V(vertices), adjList(vertices) {}

    // 添加有向边
    void addEdge(int v, int w) {
        adjList[v].push_back(w);
    }

    // 深度优先搜索，逆拓扑排序的关键
    void DFS(int vertex, vector<bool>& visited, stack<int>& resultStack) {
        visited[vertex] = true;

        for (const auto &neighbor : adjList[vertex]) {
            if (!visited[neighbor]) {
                DFS(neighbor, visited, resultStack);
            }
        }

        resultStack.push(vertex);
    }

    // 逆拓扑排序
    void topologicalSort() {
        stack<int> resultStack;
        vector<bool> visited(V, false);

        for (int i = 0; i < V; ++i) {
            if (!visited[i]) {
                DFS(i, visited, resultStack);
            }
        }

        // 输出结果
        cout << "Topological Order (Reverse): ";
        while (!resultStack.empty()) {
            cout << resultStack.top() << " ";
            resultStack.pop();
        }
        cout << endl;
    }
};

int main() {
    // 创建一个有向无环图（DAG）
    Graph graph(6);
    graph.addEdge(5, 2);
    graph.addEdge(5, 0);
    graph.addEdge(4, 0);
    graph.addEdge(4, 1);
    graph.addEdge(2, 3);
    graph.addEdge(3, 1);

    // 进行逆拓扑排序
    graph.topologicalSort();

    return 0;
}
