#include <iostream>
#include <vector>
#include <stack>

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

    // 深度优先搜索
    void DFS(int startVertex) {
        // 标记所有顶点为未访问
        vector<bool> visited(V, false);

        // 使用栈来实现深度优先搜索
        stack<int> stack;

        // 将起始顶点入栈
        stack.push(startVertex);

        // 开始遍历
        while (!stack.empty()) {
            // 弹出栈顶顶点
            int currentVertex = stack.top();
            stack.pop();

            // 如果该顶点未被访问，则访问并标记为已访问
            if (!visited[currentVertex]) {
                cout << currentVertex << " ";
                visited[currentVertex] = true;
            }

            // 将邻接的未访问顶点入栈
            for (const auto &neighbor : adjList[currentVertex]) {
                if (!visited[neighbor]) {
                    stack.push(neighbor);
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

    cout << "Depth-First Search starting from vertex 0:" << endl;
    graph.DFS(0);

    return 0;
}
