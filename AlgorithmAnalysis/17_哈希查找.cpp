#include <iostream>
#include <vector>

using namespace std;

class HashTableLinearProbing {
private:
    vector<int> table;
    int size;

public:
    HashTableLinearProbing(int tableSize) : size(tableSize) {
        table.resize(size, -1); // 初始化哈希表，-1 表示空槽
    }

    // 哈希函数
    int hashFunction(int key) {
        return key % size;
    }

    // 插入元素
    void insert(int key) {
        int index = hashFunction(key);

        // 线性探测找到下一个可用的槽
        while (table[index] != -1) {
            index = (index + 1) % size;
        }

        table[index] = key;
    }

    // 查找元素
    bool search(int key) {
        int index = hashFunction(key);

        // 线性探测查找元素
        while (table[index] != -1) {
            if (table[index] == key) {
                return true;
            }
            index = (index + 1) % size;
        }

        return false;
    }

    // 删除元素
    void remove(int key) {
        int index = hashFunction(key);

        // 线性探测找到要删除的元素
        while (table[index] != -1) {
            if (table[index] == key) {
                table[index] = -1; // 标记为删除
                return;
            }
            index = (index + 1) % size;
        }
    }
};

int main() {
    HashTableLinearProbing hashTable(10);

    // 插入元素
    hashTable.insert(5);
    hashTable.insert(15);
    hashTable.insert(25);

    // 查找元素
    cout << "Search 15: " << boolalpha << hashTable.search(15) << endl; // 输出 true
    cout << "Search 10: " << boolalpha << hashTable.search(10) << endl; // 输出 false

    // 删除元素
    hashTable.remove(15);

    // 再次查找元素
    cout << "Search 15 after removal: " << boolalpha << hashTable.search(15) << endl; // 输出 false

    return 0;
}