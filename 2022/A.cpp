// 判断一棵树是否是完全二叉树

#include <bits/stdc++.h>

using namespace std;

struct node {
    int val;
    node* left;
    node* right;
    node() : val(0), left(nullptr), right(nullptr) {}
    node(int x) : val(x), left(nullptr), right(nullptr) {}
    node(int x, node *left, node *right) : val(x), left(left), right(right) {}
};

node* create() {
    // create tree from level visited

    // input
    vector<int> arr(100, 0);
    int len;
    cin >> len;
    for (int i = 0; i < len; i++) cin >> arr[i];

    // cout << len << endl;
    // for(int i = 0; i < len; i++) cout << arr[i] << " ";
    // cout << endl;

    // mian
    node* head = new node(arr[0]);
    node* queue[1000];
    int hh = 0, tt = -1;
    queue[++ tt] = head;

    for (int i = 1; i < len; i = i + 2) {
        node* cur = queue[hh ++];
        cur->left = new node(arr[i]), cur->right = new node(arr[i+1]);
        queue[++ tt] = cur->left, queue[++ tt] = cur->right;
    }
    
    // output
    node* que[1000];
    int h = 0, t = -1;
    que[++ t] = head;

    while(h <= t) {
        node* cur = que[h ++];
        cout << cur->val << " ";
        if(cur->left) que[++ t] = cur->left;
        if(cur->right) que[++ t] = cur->right;
    }
    cout << endl;

    return head;
}

bool solve(node* root)
{
    // input

    // main 
    
    // output

}



int main()
{
    freopen("in.txt", "rt", stdin), freopen("out.txt", "wt", stdout);
    int t;
    cin >> t;

    while (t --) {
        // cout << "preforme " << t << endl;
        node* root = create();
        
        if (solve(root) == true) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
    return 0;
}
