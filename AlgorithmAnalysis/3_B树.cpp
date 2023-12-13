#include <iostream>
#include <vector>

using namespace std;

const int t = 2; // B树的度

// B树节点的定义
struct BTreeNode {
    vector<int> keys;          // 存储关键字的向量
    vector<BTreeNode*> children; // 存储子节点的向量
    bool leaf;                 // 是否是叶子节点

    BTreeNode(bool isLeaf = true) : leaf(isLeaf) {}
};

// B树的定义
class BTree {
public:
    BTreeNode* root; // 根节点

    BTree() : root(nullptr) {}

    // 插入关键字
    void insert(int key) {
        if (!root) {
            root = new BTreeNode(true);
            root->keys.push_back(key);
        } else {
            if (root->keys.size() == 2 * t - 1) {
                BTreeNode* newRoot = new BTreeNode(false);
                newRoot->children.push_back(root);
                splitChild(newRoot, 0);
                root = newRoot;
            }
            insertNonFull(root, key);
        }
    }

    // 中序遍历B树
    void inorderTraversal() const {
        inorderTraversal(root);
        cout << endl;
    }

private:
    // 在非满节点插入关键字
    void insertNonFull(BTreeNode* node, int key) {
        int i = node->keys.size() - 1;

        if (node->leaf) {
            // 如果是叶子节点，直接插入
            node->keys.push_back(0); // 为关键字腾出空间
            while (i >= 0 && key < node->keys[i]) {
                node->keys[i + 1] = node->keys[i];
                i--;
            }
            node->keys[i + 1] = key;
        } else {
            // 如果是内部节点，找到子树并插入
            while (i >= 0 && key < node->keys[i]) {
                i--;
            }

            i++;

            if (node->children[i]->keys.size() == 2 * t - 1) {
                splitChild(node, i);
                if (key > node->keys[i]) {
                    i++;
                }
            }

            insertNonFull(node->children[i], key);
        }
    }

    // 分裂子节点
    void splitChild(BTreeNode* parentNode, int childIndex) {
        BTreeNode* childNode = parentNode->children[childIndex];
        BTreeNode* newChild = new BTreeNode(childNode->leaf);

        parentNode->keys.insert(parentNode->keys.begin() + childIndex, childNode->keys[t - 1]);
        parentNode->children.insert(parentNode->children.begin() + childIndex + 1, newChild);

        newChild->keys.assign(childNode->keys.begin() + t, childNode->keys.end());
        childNode->keys.erase(childNode->keys.begin() + t, childNode->keys.end());

        if (!childNode->leaf) {
            newChild->children.assign(childNode->children.begin() + t, childNode->children.end());
            childNode->children.erase(childNode->children.begin() + t, childNode->children.end());
        }
    }

    // 中序遍历B树的辅助函数
    void inorderTraversal(BTreeNode* node) const {
        if (node) {
            int i;
            for (i = 0; i < node->keys.size(); ++i) {
                if (!node->leaf) {
                    inorderTraversal(node->children[i]);
                }
                cout << node->keys[i] << " ";
            }

            if (!node->leaf) {
                inorderTraversal(node->children[i]);
            }
        }
    }
};

int main() {
    BTree btree;

    // 插入关键字
    btree.insert(3);
    btree.insert(7);
    btree.insert(1);
    btree.insert(5);
    btree.insert(11);
    btree.insert(9);
    btree.insert(13);
    btree.insert(15);
    btree.insert(17);

    // 中序遍历B树
    cout << "Inorder Traversal of B-Tree: ";
    btree.inorderTraversal();

    return 0;
}
