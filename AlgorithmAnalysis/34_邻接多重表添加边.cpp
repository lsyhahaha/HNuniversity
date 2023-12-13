#include <iostream>
#include <vector>

using namespace std;

// 边结点的定义
struct EdgeNode {
    int vertex;          // 邻接点的序号
    EdgeNode* nextVertex; // 指向下一个邻接点的指针
    EdgeNode* opposite;   // 指向对应的反向边的指针（仅在无向图中使用）

    EdgeNode(int v) : vertex(v), nextVertex(nullptr), opposite(nullptr) {}
};

// 顶点结点的定义
struct VertexNode {
    int data;            // 顶点数据
    EdgeNode* firstEdge;  // 指向第一个邻接边的指针

    VertexNode(int d) : data(d), firstEdge(nullptr) {}
};

class AdjacencyMultilist {
public:
    vector<VertexNode> vertices; // 顶点数组

    // 添加无向边
    void addUndirectedEdge(int v1, int v2) {
        EdgeNode* edge1 = new EdgeNode(v2);
        edge1->nextVertex = vertices[v1].firstEdge;
        vertices[v1].firstEdge = edge1;

        EdgeNode* edge2 = new EdgeNode(v1);
        edge2->nextVertex = vertices[v2].firstEdge;
        vertices[v2].firstEdge = edge2;

        // 在无向图中，每个边还有对应的反向边
        edge1->opposite = edge2;
        edge2->opposite = edge1;
    }

    // 添加有向边
    void addDirectedEdge(int from, int to) {
        EdgeNode* edge = new EdgeNode(to);
        edge->nextVertex = vertices[from].firstEdge;
        vertices[from].firstEdge = edge;
    }

    // 打印邻接多重表
    void printMultilist() {
        for (int i = 0; i < vertices.size(); ++i) {
            cout << "Vertex " << i << ": ";
            EdgeNode* edge = vertices[i].firstEdge;
            while (edge) {
                cout << edge->vertex << " ";
                edge = edge->nextVertex;
            }
            cout << endl;
        }
    }
};

int main() {
    // 创建一个邻接多重表
    AdjacencyMultilist graph;

    // 添加无向边
    graph.addUndirectedEdge(0, 1);
    graph.addUndirectedEdge(0, 2);
    graph.addUndirectedEdge(1, 2);
    graph.addUndirectedEdge(1, 3);
    graph.addUndirectedEdge(2, 3);

    // 添加有向边
    graph.addDirectedEdge(3, 0);

    // 打印邻接多重表
    cout << "Adjacency Multilist:" << endl;
    graph.printMultilist();

    return 0;
}
