#include <iostream>
#include <vector>

using namespace std;

// 判断一个图是否是无向图
bool isUndirectedGraph(const vector<vector<int>>& adjList) {
    int n = adjList.size();
    
    // 遍历邻接表
    for (int u = 0; u < n; ++u) {
        for (int v : adjList[u]) {
            // 如果从u到v有边，检查从v到u是否也有边
            bool foundReverseEdge = false;
            for (int reverseV : adjList[v]) {
                if (reverseV == u) {
                    foundReverseEdge = true;
                    break;
                }
            }
            // 如果没有找到反向边，则不是无向图
            if (!foundReverseEdge) {
                return false;  // 发现某条边的反向边不存在，说明是有向图
            }
        }
    }
    return true;  // 如果所有边的反向边都存在，说明是无向图
}

int main() {
    // 示例：无向图的邻接表
    vector<vector<int>> adjList = {
        {1, 2},   // 节点 0 的邻接节点：1, 2
        {0, 2},   // 节点 1 的邻接节点：0, 2
        {0, 1}    // 节点 2 的邻接节点：0, 1
    };

    if (isUndirectedGraph(adjList)) {
        cout << "该图是无向图" << endl;
    } else {
        cout << "该图是有向图" << endl;
    }

    return 0;
}
