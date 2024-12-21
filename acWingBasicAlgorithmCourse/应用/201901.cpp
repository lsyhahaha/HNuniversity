#include <iostream>
#include <vector>
#include <string>

using namespace std;

// 定义特殊标记
const int EMPTY = -1;    // 空槽位标记
const int DELETED = -2;  // 已删除标记

class HashTable {
private:
    vector<int> table;   // 散列表
    int size;            // 散列表大小

    // 哈希函数
    int hash(int key) {
        return key % size;
    }

public:
    // 构造函数
    HashTable(int n) : size(n), table(n, EMPTY) {}

    // 插入元素
    void insert(int key) {
        int index = hash(key); // 计算哈希值
        for (int i = 0; i < size; ++i) {
            int probe = (index + i) % size; // 线性探测
            if (table[probe] == EMPTY || table[probe] == DELETED) {
                table[probe] = key;
                return;
            }
        }
        cout << "散列表已满，无法插入 " << key << endl;
    }

    // 查找元素
    bool search(int key) {
        int index = hash(key); // 计算哈希值
        for (int i = 0; i < size; ++i) {
            int probe = (index + i) % size; // 线性探测
            if (table[probe] == EMPTY) return false; // 找到空位，说明不存在
            if (table[probe] == key) return true;    // 找到目标值
        }
        return false;
    }

    // 删除元素
    void remove(int key) {
        int index = hash(key); // 计算哈希值
        for (int i = 0; i < size; ++i) {
            int probe = (index + i) % size; // 线性探测
            if (table[probe] == EMPTY) {
                cout << "未找到要删除的元素 " << key << endl;
                return; // 找到空位，说明不存在
            }
            if (table[probe] == key) {
                table[probe] = DELETED; // 标记为已删除
                cout << "元素 " << key << " 已删除" << endl;
                return;
            }
        }
        cout << "未找到要删除的元素 " << key << endl;
    }

    // 打印散列表
    void display() {
        for (int i = 0; i < size; ++i) {
            if (table[i] == EMPTY) cout << "[ ] ";
            else if (table[i] == DELETED) cout << "[X] ";
            else cout << "[" << table[i] << "] ";
        }
        cout << endl;
    }
};

// 测试代码
int main() {
    HashTable hashTable(10); // 创建一个大小为 10 的散列表

    hashTable.insert(15);
    hashTable.insert(25);
    hashTable.insert(35);

    cout << "初始散列表：" << endl;
    hashTable.display();

    hashTable.remove(25);
    cout << "删除 25 后的散列表：" << endl;
    hashTable.display();

    hashTable.insert(45);
    cout << "插入 45 后的散列表：" << endl;
    hashTable.display();

    return 0;
}
