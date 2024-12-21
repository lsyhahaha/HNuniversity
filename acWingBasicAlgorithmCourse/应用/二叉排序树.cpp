#include <iostream>
using namespace std;

// 二叉排序树的节点结构
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// 插入节点
TreeNode* insert(TreeNode* root, int key) {
    if (root == nullptr) {
        return new TreeNode(key); // 如果树为空，创建一个新的节点
    }

    // 按照二叉排序树规则插入
    if (key < root->val) {
        root->left = insert(root->left, key); // 插入到左子树
    } else if (key > root->val) {
        root->right = insert(root->right, key); // 插入到右子树
    }
    return root;
}

// 找到树中的最小值节点
TreeNode* minNode(TreeNode* node) {
    TreeNode* current = node;
    while (current && current->left != nullptr) {
        current = current->left;
    }
    return current;
}

// 删除节点
TreeNode* deleteNode(TreeNode* root, int key) {
    if (root == nullptr) {
        return root; // 如果树为空，直接返回
    }

    // 找到要删除的节点
    if (key < root->val) {
        root->left = deleteNode(root->left, key); // 删除左子树中的节点
    } else if (key > root->val) {
        root->right = deleteNode(root->right, key); // 删除右子树中的节点
    } else {
        // 找到要删除的节点
        if (root->left == nullptr) {
            // 只有右子树，替换节点
            TreeNode* temp = root->right;
            delete root;
            return temp;
        } else if (root->right == nullptr) {
            // 只有左子树，替换节点
            TreeNode* temp = root->left;
            delete root;
            return temp;
        } else {
            // 两个子树都有，找到右子树中的最小节点，替代当前节点
            TreeNode* temp = minNode(root->right);
            root->val = temp->val; // 用右子树中的最小节点替代当前节点
            root->right = deleteNode(root->right, temp->val); // 删除右子树中的最小节点
        }
    }
    return root;
}

// 中序遍历打印树
void inorderTraversal(TreeNode* root) {
    if (root == nullptr) return;
    inorderTraversal(root->left);
    cout << root->val << " ";
    inorderTraversal(root->right);
}

int main() {
    TreeNode* root = nullptr;

    // 插入节点
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 70);
    root = insert(root, 60);
    root = insert(root, 80);

    cout << "中序遍历插入后的二叉排序树: ";
    inorderTraversal(root);
    cout << endl;

    // 删除节点
    root = deleteNode(root, 20);
    cout << "中序遍历删除节点20后的二叉排序树: ";
    inorderTraversal(root);
    cout << endl;

    root = deleteNode(root, 30);
    cout << "中序遍历删除节点30后的二叉排序树: ";
    inorderTraversal(root);
    cout << endl;

    root = deleteNode(root, 50);
    cout << "中序遍历删除节点50后的二叉排序树: ";
    inorderTraversal(root);
    cout << endl;

    return 0;
}
