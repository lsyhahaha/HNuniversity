// �ж�ͼg�Ƿ�������������

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Graph {
public:
    int V; // ������
    vector<vector<int>> adj; // �ڽӱ�

    Graph(int vertices) : V(vertices), adj(vertices) {}

    void addEdge(int v, int w) {
        adj[v].push_back(w);
    }

    void topologicalSort() {
        vector<int> inDegree(V, 0); // ��¼ÿ���ڵ�����

        // ����ÿ���ڵ�����
        for (int v = 0; v < V; ++v) {
            for (int w : adj[v]) {
                inDegree[w]++;
            }
        }

        // ����һ�����У������������Ϊ0�Ľڵ�������
        queue<int> q;
        for (int v = 0; v < V; ++v) {
            if (inDegree[v] == 0) {
                q.push(v);
            }
        }

        // ��¼��������Ľ��
        vector<int> result;

        // ��ʼ��������
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            result.push_back(v);

            // �����ڽӽڵ����ȣ��������Ϊ0�Ľڵ�������
            for (int w : adj[v]) {
                inDegree[w]--;
                if (inDegree[w] == 0) {
                    q.push(w);
                }
            }
        }

        // ����Ƿ��л�
        if (result.size() != V) {
            cout << "ͼ�д��ڻ����޷�������������" << endl;
            return;
        }

        // �����������Ľ��
        cout << "����������: ";
        for (int v : result) {
            cout << v << " ";
        }
        cout << endl;
    }
};

int main() {
    // ��������ͼ
    Graph g(6);
    g.addEdge(5, 2);
    g.addEdge(5, 0);
    g.addEdge(4, 0);
    g.addEdge(4, 1);
    g.addEdge(2, 3);
    g.addEdge(3, 1);

    // ������������
    g.topologicalSort();

    return 0;
}

