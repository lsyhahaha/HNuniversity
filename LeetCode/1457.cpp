/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };



class Solution {
private:
    bool check(vector<int> &path) {
        unordered_map<int, int> map;
        for(auto &x : path) {
            map[x] ++;
        }

        int cnt = 0; // 统计元素数量为奇数的个数
        for(auto mp : map) {
            if(mp.second % 2 == 1) cnt ++;
            if (cnt > 1) return false;
        }
        return true;
    }

public:
    void dfs(TreeNode* root, vector<int> &path, int &res) {
        if (root == nullptr) return;
        
        path.push_back(root->val);
        if(root->left == nullptr && root->right == nullptr && check(path) == true) res ++;

        dfs(root->left, path, res), dfs(root->right, path, res);

        //恢复状态，回溯
        path.pop_back();
    }

    int pseudoPalindromicPaths (TreeNode* root) {
        vector<int> path;
        int res = 0;

        dfs(root, path, res);

        return res;
    }
};