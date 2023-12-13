#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// 定义图的邻接表表示
class Graph {
public:
    int V; // 顶点数
    vector<vector<int>> adjList; // 邻接表

    Graph(int vertices) : V(vertices), adjList(vertices) {}

    // 添加边
    void addEdge(int v, int w) {
        adjList[v].push_back(w);
        adjList[w].push_back(v); // 如果是有向图，则不需要这行
    }

    // 广度优先搜索
    void BFS(int startVertex) {
        // 标记所有顶点为未访问
        vector<bool> visited(V, false);

        // 使用队列来实现广度优先搜索
        queue<int> q;

        // 将起始顶点入队并标记为已访问
        q.push(startVertex);
        visited[startVertex] = true;

        // 开始遍历
        while (!q.empty()) {
            // 出队并访问队头顶点
            int currentVertex = q.front();
            cout << currentVertex << " ";
            q.pop();

            // 遍历邻接的未访问顶点，并入队
            for (const auto &neighbor : adjList[currentVertex]) {
                if (!visited[neighbor]) {
                    q.push(neighbor);
                    visited[neighbor] = true;
                }
            }
        }
    }
};

int main() {
    // 创建一个图
    Graph graph(6);
    graph.addEdge(0, 1);
    graph.addEdge(0, 2);
    graph.addEdge(1, 3);
    graph.addEdge(2, 4);
    graph.addEdge(2, 5);

    cout << "Breadth-First Search starting from vertex 0:" << endl;
    graph.BFS(0);

    return 0;
}
