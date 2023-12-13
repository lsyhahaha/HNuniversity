#include <iostream>

using namespace std;

// 节点结构定义
class TreeNode {
public:
    int data;
    TreeNode* left;
    TreeNode* right;
    bool leftThread;  // 左指针是否是线索
    bool rightThread; // 右指针是否是线索

    TreeNode(int value) : data(value), left(nullptr), right(nullptr), leftThread(false), rightThread(false) {}
};

class ThreadedBinaryTree {
private:
    TreeNode* root;
    TreeNode* prev; // 用于记录中序遍历的前一个节点

public:
    ThreadedBinaryTree() : root(nullptr), prev(nullptr) {}

    // 中序线索化
    void threadedInorder(TreeNode* node) {
        if (node != nullptr) {
            threadedInorder(node->left);  // 递归处理左子树

            // 处理当前节点的前驱线索
            if (node->left == nullptr) {
                node->leftThread = true;
                node->left = prev;
            }

            // 处理前一个节点的后继线索
            if (prev != nullptr && prev->right == nullptr) {
                prev->rightThread = true;
                prev->right = node;
            }

            prev = node; // 更新前一个节点

            threadedInorder(node->right); // 递归处理右子树
        }
    }

    // 中序线索化树的接口
    void threadedInorder() {
        prev = nullptr; // 初始化前一个节点
        threadedInorder(root);
    }

    // 中序遍历线索二叉树
    void inorderTraversal() {
        TreeNode* current = leftmostNode(); // 获取最左边的节点
        while (current != nullptr) {
            cout << current->data << " ";

            // 如果右指针是线索，直接跳到后继
            if (current->rightThread) {
                current = current->right;
            } else {
                // 否则，找到右子树的最左边节点
                current = leftmostNode(current->right);
            }
        }
        cout << endl;
    }

    // 查找中序遍历的最左边的节点
    TreeNode* leftmostNode(TreeNode* node = nullptr) {
        if (node == nullptr) {
            node = root;
        }
        while (node != nullptr && node->left != nullptr) {
            node = node->left;
        }
        return node;
    }

    // 插入节点
    void insert(int value) {
        root = insertRecursive(root, value);
    }

    // 递归插入节点
    TreeNode* insertRecursive(TreeNode* node, int value) {
        if (node == nullptr) {
            return new TreeNode(value);
        }

        if (value < node->data) {
            node->left = insertRecursive(node->left, value);
        } else if (value > node->data) {
            node->right = insertRecursive(node->right, value);
        }

        return node;
    }
};

int main() {
    ThreadedBinaryTree threadedTree;

    // 插入节点
    threadedTree.insert(50);
    threadedTree.insert(30);
    threadedTree.insert(70);
    threadedTree.insert(20);
    threadedTree.insert(40);
    threadedTree.insert(60);
    threadedTree.insert(80);

    // 中序线索化
    threadedTree.threadedInorder();

    // 中序遍历线索二叉树
    cout << "Inorder Traversal of Threaded Binary Tree: ";
    threadedTree.inorderTraversal();

    return 0;
}
