#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
private:
    int ans = 0;
public:
    void inorder(TreeNode* root, int &cnt) {
        if(root->right) inorder(root->right, cnt);
        cnt--;
        if(cnt == 0) {
            ans = root->val;
            return;
        }
        if(root->left) inorder(root->left, cnt);
    }

    int findTargetNode(TreeNode* root, int cnt) {
        inorder(root, cnt);
        return ans;
    }
};