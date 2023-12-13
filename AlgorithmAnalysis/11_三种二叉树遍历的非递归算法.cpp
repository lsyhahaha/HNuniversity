#include <iostream>
#include <stack>

using namespace std;

// 二叉树节点的定义
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// 先序遍历的非递归算法
void iterativePreorder(TreeNode* root) {
    if (!root) return;

    stack<TreeNode*> s;
    s.push(root);

    while (!s.empty()) {
        TreeNode* current = s.top();
        s.pop();

        cout << current->val << " ";

        if (current->right) {
            s.push(current->right);
        }

        if (current->left) {
            s.push(current->left);
        }
    }
}

// 中序遍历的非递归算法
void iterativeInorder(TreeNode* root) {
    if (!root) return;

    stack<TreeNode*> s;
    TreeNode* current = root;

    while (current || !s.empty()) {
        while (current) {
            s.push(current);
            current = current->left;
        }

        current = s.top();
        s.pop();

        cout << current->val << " ";

        current = current->right;
    }
}

// 后序遍历的非递归算法
void iterativePostorder(TreeNode* root) {
    if (!root) return;

    stack<TreeNode*> s;
    stack<TreeNode*> output; // 用于存储逆后序遍历结果

    s.push(root);

    while (!s.empty()) {
        TreeNode* current = s.top();
        s.pop();

        output.push(current);

        if (current->left) {
            s.push(current->left);
        }

        if (current->right) {
            s.push(current->right);
        }
    }

    while (!output.empty()) {
        cout << output.top()->val << " ";
        output.pop();
    }
}

int main() {
    // 构建一个二叉树
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    cout << "Iterative Preorder Traversal: ";
    iterativePreorder(root);
    cout << endl;

    cout << "Iterative Inorder Traversal: ";
    iterativeInorder(root);
    cout << endl;

    cout << "Iterative Postorder Traversal: ";
    iterativePostorder(root);
    cout << endl;

    // 释放内存，防止内存泄漏
    // 实际应用中可能需要使用智能指针来管理内存
    delete root->left->right;
    delete root->left->left;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}
