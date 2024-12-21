#include <iostream>
#include <algorithm>
using namespace std;

// AVL树的节点结构
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    int height;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr), height(1) {}
};

// 获取节点的高度
int height(TreeNode* node) {
    return node ? node->height : 0;
}

// 计算节点的平衡因子
int getBalance(TreeNode* node) {
    return node ? height(node->left) - height(node->right) : 0;
}

// 右旋转
TreeNode* rightRotate(TreeNode* y) {
    TreeNode* x = y->left;
    TreeNode* T2 = x->right;

    // 旋转
    x->right = y;
    y->left = T2;

    // 更新高度
    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    return x;
}

// 左旋转
TreeNode* leftRotate(TreeNode* x) {
    TreeNode* y = x->right;
    TreeNode* T2 = y->left;

    // 旋转
    y->left = x;
    x->right = T2;

    // 更新高度
    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    return y;
}

// 插入节点
TreeNode* insert(TreeNode* node, int key) {
    if (node == nullptr) {
        return new TreeNode(key);
    }

    // 插入到左子树或右子树
    if (key < node->val) {
        node->left = insert(node->left, key);
    } else if (key > node->val) {
        node->right = insert(node->right, key);
    } else {
        return node; // 相同值不插入
    }

    // 更新节点的高度
    node->height = max(height(node->left), height(node->right)) + 1;

    // 检查是否平衡，若不平衡，执行旋转
    int balance = getBalance(node);

    // 左左情况
    if (balance > 1 && key < node->left->val) {
        return rightRotate(node);
    }

    // 右右情况
    if (balance < -1 && key > node->right->val) {
        return leftRotate(node);
    }

    // 左右情况
    if (balance > 1 && key > node->left->val) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // 右左情况
    if (balance < -1 && key < node->right->val) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

// 找到树中的最小值节点
TreeNode* minNode(TreeNode* node) {
    TreeNode* current = node;
    while (current->left != nullptr) {
        current = current->left;
    }
    return current;
}

// 删除节点
TreeNode* deleteNode(TreeNode* root, int key) {
    if (root == nullptr) {
        return root;
    }

    // 找到要删除的节点
    if (key < root->val) {
        root->left = deleteNode(root->left, key);
    } else if (key > root->val) {
        root->right = deleteNode(root->right, key);
    } else {
        // 找到要删除的节点
        if (root->left == nullptr || root->right == nullptr) {
            TreeNode* temp = root->left ? root->left : root->right;
            if (temp == nullptr) {
                temp = root;
                root = nullptr;
            } else {
                *root = *temp;
            }
            delete temp;
        } else {
            // 找到右子树中的最小节点
            TreeNode* temp = minNode(root->right);

            // 复制最小节点的值到当前节点
            root->val = temp->val;

            // 删除右子树中的最小节点
            root->right = deleteNode(root->right, temp->val);
        }
    }

    // 如果树只有一个节点
    if (root == nullptr) {
        return root;
    }

    // 更新节点的高度
    root->height = max(height(root->left), height(root->right)) + 1;

    // 检查是否平衡，若不平衡，执行旋转
    int balance = getBalance(root);

    // 左左情况
    if (balance > 1 && getBalance(root->left) >= 0) {
        return rightRotate(root);
    }

    // 右右情况
    if (balance < -1 && getBalance(root->right) <= 0) {
        return leftRotate(root);
    }

    // 左右情况
    if (balance > 1 && getBalance(root->left) < 0) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    // 右左情况
    if (balance < -1 && getBalance(root->right) > 0) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

// 中序遍历
void inorderTraversal(TreeNode* root) {
    if (root == nullptr) return;
    inorderTraversal(root->left);
    cout << root->val << " ";
    inorderTraversal(root->right);
}

int main() {
    TreeNode* root = nullptr;

    // 插入节点
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 40);
    root = insert(root, 50);
    root = insert(root, 25);

    cout << "中序遍历插入后的AVL树: ";
    inorderTraversal(root);
    cout << endl;

    // 删除节点
    root = deleteNode(root, 40);
    cout << "中序遍历删除节点40后的AVL树: ";
    inorderTraversal(root);
    cout << endl;

    root = deleteNode(root, 30);
    cout << "中序遍历删除节点30后的AVL树: ";
    inorderTraversal(root);
    cout << endl;

    return 0;
}
