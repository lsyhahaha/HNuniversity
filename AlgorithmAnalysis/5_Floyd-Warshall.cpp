#include <iostream>
#include <vector>
#include <limits>

using namespace std;

const int INF = numeric_limits<int>::max(); // 无穷大

// Floyd-Warshall算法
void floydWarshall(vector<vector<int>>& graph, int numNodes) {
    // 初始化距离矩阵
    vector<vector<int>> distance(numNodes, vector<int>(numNodes, INF));
    for (int i = 0; i < numNodes; ++i) {
        for (int j = 0; j < numNodes; ++j) {
            if (i == j) {
                distance[i][j] = 0;
            } else if (graph[i][j] != 0) {
                distance[i][j] = graph[i][j];
            }
        }
    }

    // 更新距离矩阵
    for (int k = 0; k < numNodes; ++k) {
        for (int i = 0; i < numNodes; ++i) {
            for (int j = 0; j < numNodes; ++j) {
                if (distance[i][k] != INF && distance[k][j] != INF &&
                    distance[i][k] + distance[k][j] < distance[i][j]) {
                    distance[i][j] = distance[i][k] + distance[k][j];
                }
            }
        }
    }

    // 输出最短路径
    cout << "Shortest distances between all nodes:" << endl;
    for (int i = 0; i < numNodes; ++i) {
        for (int j = 0; j < numNodes; ++j) {
            cout << distance[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    // 示例图的邻接矩阵表示
    vector<vector<int>> graph = {
        {0, 4, 0, 0},
        {0, 0, 5, 0},
        {0, 1, 0, 8},
        {0, 0, 0, 0}
    };

    int numNodes = 4;

    floydWarshall(graph, numNodes);

    return 0;
}
