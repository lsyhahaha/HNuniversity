#include <iostream>

using namespace std;

class TreeNode {
public:
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value) : data(value), left(nullptr), right(nullptr) {}
};

class BinarySearchTree {
private:
    TreeNode* root;

public:
    BinarySearchTree() : root(nullptr) {}

    // 插入节点
    void insert(int value) {
        root = insertRecursive(root, value);
    }

    // 递归插入节点
    TreeNode* insertRecursive(TreeNode* root, int value) {
        if (root == nullptr) {
            return new TreeNode(value);
        }

        if (value < root->data) {
            root->left = insertRecursive(root->left, value);
        } else if (value > root->data) {
            root->right = insertRecursive(root->right, value);
        }

        return root;
    }

    // 查找节点
    bool search(int value) {
        return searchRecursive(root, value);
    }

    // 递归查找节点
    bool searchRecursive(TreeNode* root, int value) {
        if (root == nullptr) {
            return false;
        }

        if (value == root->data) {
            return true;
        } else if (value < root->data) {
            return searchRecursive(root->left, value);
        } else {
            return searchRecursive(root->right, value);
        }
    }

    // 删除节点
    void remove(int value) {
        root = removeRecursive(root, value);
    }

    // 递归删除节点
    TreeNode* removeRecursive(TreeNode* root, int value) {
        if (root == nullptr) {
            return nullptr;
        }

        if (value < root->data) {
            root->left = removeRecursive(root->left, value);
        } else if (value > root->data) {
            root->right = removeRecursive(root->right, value);
        } else {
            // 找到要删除的节点

            // 如果只有一个子节点或者没有子节点
            if (root->left == nullptr) {
                TreeNode* temp = root->right;
                delete root;
                return temp;
            } else if (root->right == nullptr) {
                TreeNode* temp = root->left;
                delete root;
                return temp;
            }

            // 如果有两个子节点，找到右子树中的最小节点替代当前节点
            TreeNode* temp = findMin(root->right);
            root->data = temp->data;
            root->right = removeRecursive(root->right, temp->data);
        }

        return root;
    }

    // 查找最小值节点
    TreeNode* findMin(TreeNode* root) {
        while (root->left != nullptr) {
            root = root->left;
        }
        return root;
    }

    // 中序遍历
    void inorderTraversal() {
        inorderTraversalRecursive(root);
        cout << endl;
    }

    // 递归中序遍历
    void inorderTraversalRecursive(TreeNode* root) {
        if (root != nullptr) {
            inorderTraversalRecursive(root->left);
            cout << root->data << " ";
            inorderTraversalRecursive(root->right);
        }
    }
};

int main() {
    BinarySearchTree bst;

    // 插入节点
    bst.insert(50);
    bst.insert(30);
    bst.insert(70);
    bst.insert(20);
    bst.insert(40);
    bst.insert(60);
    bst.insert(80);

    // 中序遍历
    cout << "Inorder Traversal: ";
    bst.inorderTraversal();

    // 查找节点
    int valueToFind = 40;
    cout << "Search " << valueToFind << ": " << boolalpha << bst.search(valueToFind) << endl;

    // 删除节点
    int valueToRemove = 30;
    bst.remove(valueToRemove);
    cout << "Inorder Traversal after removing " << valueToRemove << ": ";
    bst.inorderTraversal();

    return 0;
}
