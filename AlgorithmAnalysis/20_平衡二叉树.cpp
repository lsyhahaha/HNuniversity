#include <iostream>
#include <algorithm>

using namespace std;

class TreeNode {
public:
    int data;
    int height;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value) : data(value), height(1), left(nullptr), right(nullptr) {}
};

class AVLTree {
private:
    TreeNode* root;

public:
    AVLTree() : root(nullptr) {}

    // 获取节点的高度
    int getHeight(TreeNode* node) {
        if (node == nullptr) {
            return 0;
        }
        return node->height;
    }

    // 获取平衡因子
    int getBalanceFactor(TreeNode* node) {
        if (node == nullptr) {
            return 0;
        }
        return getHeight(node->left) - getHeight(node->right);
    }

    // 更新节点的高度
    void updateHeight(TreeNode* node) {
        if (node != nullptr) {
            node->height = 1 + max(getHeight(node->left), getHeight(node->right));
        }
    }

    // 右旋
    TreeNode* rotateRight(TreeNode* y) {
        TreeNode* x = y->left;
        TreeNode* T2 = x->right;

        x->right = y;
        y->left = T2;

        updateHeight(y);
        updateHeight(x);

        return x;
    }

    // 左旋
    TreeNode* rotateLeft(TreeNode* x) {
        TreeNode* y = x->right;
        TreeNode* T2 = y->left;

        y->left = x;
        x->right = T2;

        updateHeight(x);
        updateHeight(y);

        return y;
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
        } else {
            // 已存在相同值的节点，不插入
            return node;
        }

        updateHeight(node);

        // 平衡因子
        int balance = getBalanceFactor(node);

        // 左子树不平衡，需要右旋
        if (balance > 1 && value < node->left->data) {
            return rotateRight(node);
        }

        // 右子树不平衡，需要左旋
        if (balance < -1 && value > node->right->data) {
            return rotateLeft(node);
        }

        // 左右不平衡，需要先左旋再右旋
        if (balance > 1 && value > node->left->data) {
            node->left = rotateLeft(node->left);
            return rotateRight(node);
        }

        // 右左不平衡，需要先右旋再左旋
        if (balance < -1 && value < node->right->data) {
            node->right = rotateRight(node->right);
            return rotateLeft(node);
        }

        return node;
    }

    // 查找节点
    bool search(int value) {
        return searchRecursive(root, value);
    }

    // 递归查找节点
    bool searchRecursive(TreeNode* node, int value) {
        if (node == nullptr) {
            return false;
        }

        if (value == node->data) {
            return true;
        } else if (value < node->data) {
            return searchRecursive(node->left, value);
        } else {
            return searchRecursive(node->right, value);
        }
    }

    // 删除节点
    void remove(int value) {
        root = removeRecursive(root, value);
    }

    // 递归删除节点
    TreeNode* removeRecursive(TreeNode* node, int value) {
        if (node == nullptr) {
            return nullptr;
        }

        if (value < node->data) {
            node->left = removeRecursive(node->left, value);
        } else if (value > node->data) {
            node->right = removeRecursive(node->right, value);
        } else {
            // 找到要删除的节点

            // 如果只有一个子节点或者没有子节点
            if (node->left == nullptr) {
                TreeNode* temp = node->right;
                delete node;
                return temp;
            } else if (node->right == nullptr) {
                TreeNode* temp = node->left;
                delete node;
                return temp;
            }

            // 如果有两个子节点，找到右子树中的最小节点替代当前节点
            TreeNode* temp = findMin(node->right);
            node->data = temp->data;
            node->right = removeRecursive(node->right, temp->data);
        }

        updateHeight(node);

        // 平衡因子
        int balance = getBalanceFactor(node);

        // 左子树不平衡，需要右旋
        if (balance > 1 && getBalanceFactor(node->left) >= 0) {
            return rotateRight(node);
        }

        // 左右不平衡，需要先左旋再右旋
        if (balance > 1 && getBalanceFactor(node->left) < 0) {
            node->left = rotateLeft(node->left);
            return rotateRight(node);
        }

        // 右子树不平衡，需要左旋
        if (balance < -1 && getBalanceFactor(node->right) <= 0) {
            return rotateLeft(node);
        }

        // 右左不平衡，需要先右旋再左旋
        if (balance < -1 && getBalanceFactor(node->right) > 0) {
            node->right = rotateRight(node->right);
            return rotateLeft(node);
        }

        return node;
    }

    // 查找最小值节点
    TreeNode* findMin(TreeNode* node) {
        while (node->left != nullptr) {
            node = node->left;
        }
        return node;
    }

    // 中序遍历
    void inorderTraversal() {
        inorderTraversalRecursive(root);
        cout << endl;
    }

    // 递归中序遍历
    void inorderTraversalRecursive(TreeNode* node) {
        if (node != nullptr) {
            inorderTraversalRecursive(node->left);
            cout << node->data << " ";
            inorderTraversalRecursive(node->right);
        }
    }
};

int main() {
    AVLTree avl;

    // 插入节点
    avl.insert(50);
    avl.insert(30);
    avl.insert(70);
    avl.insert(20);
    avl.insert(40);
    avl.insert(60);
    avl.insert(80);

    // 中序遍历
    cout << "Inorder Traversal: ";
    avl.inorderTraversal();

    // 查找节点
    int valueToFind = 40;
    cout << "Search " << valueToFind << ": " << boolalpha << avl.search(valueToFind) << endl;

    // 删除节点
    int valueToRemove = 30;
    avl.remove(valueToRemove);
    cout << "Inorder Traversal after removing " << valueToRemove << ": ";
    avl.inorderTraversal();

    return 0;
}
