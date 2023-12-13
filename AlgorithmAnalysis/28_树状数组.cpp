#include <iostream>
#include <vector>

using namespace std;

class FenwickTree {
private:
    vector<int> BIT; // 树状数组
    int size;        // 数组大小

public:
    FenwickTree(int n) {
        size = n + 1; // BIT 的下标从 1 开始
        BIT.resize(size, 0);
    }

    // 单点更新
    void update(int index, int val) {
        while (index <= size) {
            BIT[index] += val;
            index += (index & -index); // 更新下一个节点
        }
    }

    // 查询前缀和
    int query(int index) {
        int sum = 0;
        while (index > 0) {
            sum += BIT[index];
            index -= (index & -index); // 获取父节点
        }
        return sum;
    }

    // 查询区间和
    int rangeQuery(int left, int right) {
        return query(right) - query(left - 1);
    }
};

int main() {
    // 示例：使用树状数组求区间和

    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int n = arr.size();

    // 构建树状数组
    FenwickTree fenwickTree(n);
    for (int i = 1; i <= n; ++i) {
        fenwickTree.update(i, arr[i - 1]);
    }

    // 查询区间和
    int left = 2, right = 8;
    cout << "Sum in range [" << left << ", " << right << "]: " << fenwickTree.rangeQuery(left, right) << endl;

    // 单点更新
    int indexToUpdate = 5, valueToUpdate = 15;
    cout << "Update element at index " << indexToUpdate << " to " << valueToUpdate << endl;
    fenwickTree.update(indexToUpdate, valueToUpdate);

    // 查询更新后的区间和
    cout << "Sum in range [" << left << ", " << right << "] after update: " << fenwickTree.rangeQuery(left, right) << endl;

    return 0;
}
