#include <iostream>
#include <vector>

using namespace std;

class UnionFind {
public:
    explicit UnionFind(int size) {
        parent.resize(size);
        rank.resize(size, 0);

        // 初始化时，每个元素的父节点是它自己
        for (int i = 0; i < size; ++i) {
            parent[i] = i;
        }
    }

    // 查找元素所属的集合的代表元素
    int find(int x) {
        if (parent[x] != x) {
            // 路径压缩：将当前节点直接指向根节点
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    // 合并两个集合
    void unionSets(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);

        // 将rank较小的树合并到rank较大的树上
        if (rank[rootX] < rank[rootY]) {
            parent[rootX] = rootY;
        } else if (rank[rootX] > rank[rootY]) {
            parent[rootY] = rootX;
        } else {
            // 如果两个树的高度相等，则任意选择一个作为根，同时增加rank
            parent[rootX] = rootY;
            rank[rootY]++;
        }
    }

    // 判断两个元素是否属于同一个集合
    bool areConnected(int x, int y) {
        return find(x) == find(y);
    }

private:
    vector<int> parent; // 记录每个元素的父节点
    vector<int> rank;   // 记录每个集合的高度（秩）
};

int main() {
    UnionFind uf(5); // 创建一个包含5个元素的并查集

    // 合并集合
    uf.unionSets(0, 1);
    uf.unionSets(1, 2);
    uf.unionSets(3, 4);

    // 判断元素是否属于同一个集合
    cout << "0 and 2 are connected: " << boolalpha << uf.areConnected(0, 2) << endl;
    cout << "1 and 3 are connected: " << boolalpha << uf.areConnected(1, 3) << endl;

    return 0;
}
