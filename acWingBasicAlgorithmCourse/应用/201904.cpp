#include <iostream>
using namespace std;

// 定义二叉搜索树节点结构
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// 查找最小值节点（右子树中的最小节点）
TreeNode* findMin(TreeNode* root) {
    while (root->left != nullptr) {
        root = root->left;
    }
    return root;
}

// 删除二叉搜索树中的节点
TreeNode* deleteNode(TreeNode* root, int key) {
    if (root == nullptr) {
        return root; // 找不到要删除的节点
    }

    if (key < root->val) {
        // 在左子树中查找
        root->left = deleteNode(root->left, key);
    } else if (key > root->val) {
        // 在右子树中查找
        root->right = deleteNode(root->right, key);
    } else {
        // 找到要删除的节点
        // 1. 节点没有子节点（叶子节点）
        if (root->left == nullptr && root->right == nullptr) {
            delete root; // 直接删除
            return nullptr;
        }
        // 2. 节点只有一个子节点
        else if (root->left == nullptr) {
            TreeNode* temp = root->right;
            delete root; // 删除当前节点
            return temp;
        } else if (root->right == nullptr) {
            TreeNode* temp = root->left;
            delete root; // 删除当前节点
            return temp;
        }
        // 3. 节点有两个子节点
        else {
            // 找到右子树中的最小节点
            TreeNode* minNode = findMin(root->right);
            root->val = minNode->val;  // 用右子树的最小节点替代当前节点
            root->right = deleteNode(root->right, minNode->val); // 删除右子树中的最小节点
        }
    }
    return root;
}

// 中序遍历打印树（验证删除是否成功）
void inorderTraversal(TreeNode* root) {
    if (root == nullptr) return;
    inorderTraversal(root->left);
    cout << root->val << " ";
    inorderTraversal(root->right);
}

int main() {
    // 创建二叉搜索树
    TreeNode* root = new TreeNode(50);
    root->left = new TreeNode(30);
    root->right = new TreeNode(70);
    root->left->left = new TreeNode(20);
    root->left->right = new TreeNode(40);
    root->right->left = new TreeNode(60);
    root->right->right = new TreeNode(80);

    cout << "原始树的中序遍历：";
    inorderTraversal(root);
    cout << endl;

    // 删除值为 70 的节点
    root = deleteNode(root, 70);

    cout << "删除节点 70 后的中序遍历：";
    inorderTraversal(root);
    cout << endl;

    // 删除值为 30 的节点
    root = deleteNode(root, 30);

    cout << "删除节点 30 后的中序遍历：";
    inorderTraversal(root);
    cout << endl;

    return 0;
}
