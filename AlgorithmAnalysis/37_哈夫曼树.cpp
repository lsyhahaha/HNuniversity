#include <iostream>
#include <queue>
#include <vector>

using namespace std;

// 哈夫曼树节点的结构定义
struct HuffmanNode {
    char data;             // 字符数据
    int frequency;         // 字符频率
    HuffmanNode *left, *right; // 左右子树指针

    // 构造函数
    HuffmanNode(char d, int f) : data(d), frequency(f), left(nullptr), right(nullptr) {}
};

// 优先队列的比较函数，用于构建最小堆
struct Compare {
    bool operator()(HuffmanNode* a, HuffmanNode* b) {
        return a->frequency > b->frequency;
    }
};

// 构建哈夫曼树的函数
HuffmanNode* buildHuffmanTree(vector<pair<char, int>>& charFreq) {
    priority_queue<HuffmanNode*, vector<HuffmanNode*>, Compare> minHeap;

    // 初始化最小堆，将字符频率信息转化为节点
    for (const auto& pair : charFreq) {
        HuffmanNode* node = new HuffmanNode(pair.first, pair.second);
        minHeap.push(node);
    }

    // 构建哈夫曼树
    while (minHeap.size() > 1) {
        HuffmanNode* left = minHeap.top();
        minHeap.pop();

        HuffmanNode* right = minHeap.top();
        minHeap.pop();

        HuffmanNode* newNode = new HuffmanNode('$', left->frequency + right->frequency);
        newNode->left = left;
        newNode->right = right;

        minHeap.push(newNode);
    }

    return minHeap.top();
}

// 生成哈夫曼编码的辅助函数
void generateHuffmanCodes(HuffmanNode* root, string code, vector<pair<char, string>>& result) {
    if (root) {
        if (root->data != '$') {
            result.push_back({root->data, code});
        }

        generateHuffmanCodes(root->left, code + "0", result);
        generateHuffmanCodes(root->right, code + "1", result);
    }
}

// 生成哈夫曼编码的函数
vector<pair<char, string>> getHuffmanCodes(vector<pair<char, int>>& charFreq) {
    HuffmanNode* root = buildHuffmanTree(charFreq);
    vector<pair<char, string>> result;
    generateHuffmanCodes(root, "", result);
    return result;
}

int main() {
    // 示例字符频率
    vector<pair<char, int>> charFreq = {
        {'a', 5},
        {'b', 9},
        {'c', 12},
        {'d', 13},
        {'e', 16},
        {'f', 45}
    };

    // 生成哈夫曼编码
    vector<pair<char, string>> huffmanCodes = getHuffmanCodes(charFreq);

    // 输出结果
    cout << "Huffman Codes:" << endl;
    for (const auto& pair : huffmanCodes) {
        cout << pair.first << ": " << pair.second << endl;
    }

    return 0;
}
