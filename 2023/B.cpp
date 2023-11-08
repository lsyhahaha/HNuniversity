/*
    第十题 给定一个高度为n且含有2^n-1个结点的二叉树，其叶子节点的值为[1, 2^n-1]的
    不重复排列.现为使得叶子结点的值从左到右按升序排列，可通过该二叉树非叶子结点为轴
    进行左右子树交换进行实现，设计一个算法，求最小交换的次数.若叶子结点元素不能实现
    递增，则输出-1；
*/


#include <bits/stdc++.h>
using namespace std;
#define debug(a) cout << #a << " = " << a << endl;
#define debug2(a,b) cout<< #a <<" = "<<a<<' '<< #b <<" = "<<b<<endl;
#define debug3(a,b,c) cout<<#a<<" = "<<a<<' '<<#b<<" = "<<b<<' '<<#c<<" = "<<c<<endl;
#define debug4(a,b,c,d) cout<<#a<<" = "<<a<<' '<<#b<<" = "<<b<<' '<<#c<<" = "<<c<<' '<<#d<<" = "<<d<<endl;
#define debugx(a, idx) cout << #a << "[" << idx << "] = " << a[idx] << endl;
#define debugpii(a) cout<<#a<<" = "<<a.first<<", "<<a.second<<endl;
#define debugarr(a, x) cout<<#a<<": "; for(int i = 0; i < x; i++) cout << a[i] << ' '; cout << endl;
#define debugarr2(a, n, m) cout<<#a<<": \n";for(int i=0;i<n;i++){for(int j=0;j<m;j++)cout<<a[i][j]<<' ';cout<<'\n';}
#define debugvec(a) cout<<#a<<": "; for(int i = 0; i < a.size(); i++) cout << a[i] << ' '; cout << endl;
#define debugque(a) {cout<<#a<<": ";auto TMP=a;while(TMP.size()){cout<<TMP.front()<<' ';TMP.pop();}cout<<endl;}
#define debugstk(a) {cout<<#a<<": ";auto TUP=a;while(TUP.size()){cout<<TUP.top()<<' ';TUP.pop();}cout<<endl;}
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define all(x) (x).begin(),(x).end()
#define SZ(x) ((int)(x).size())
typedef long long ll;
typedef pair<int,int> pii;
template <class T> bool chkmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template <class T> bool chkmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

struct node {
    int val;
    node* left;
    node* right;
    node() : val(0), left(nullptr), right(nullptr) {}
    node(int x) : val(x), left(nullptr), right(nullptr) {}
    node(int x, node *left, node *right) : val(x), left(left), right(right) {}
};

map<node*, pair<int, int>> mp; // <节点指针, <叶子节点的最小值，拥有的叶子节点数量>>
map<node*, int> ans; // <节点指针，子树叶子结点变合法有序最小交换次数>

int solve(node* head) {
    if(head->left != nullptr) solve(head->left);
    if(head->right != nullptr) solve(head->right);

    if(head->left == nullptr && head->right == nullptr) { // 因为是满二叉树，这里判断方法比较随意
        mp[head].first = head->val;
        mp[head].second = 1;
        ans[head] = 0; // 可省
    } else { // 因为是满二叉树，这里一定有左右儿子
        auto [l1, l2] = mp[head->left]; 
        auto [r1, r2] = mp[head->right];

        if(min(l1, r1) + l2 != max(l1, r1)) { // l2 一定等于 r2
            ans[head] = -1; return ans[head];
        }
        if(ans[head->left] == -1 || ans[head->right] == -1) {
            ans[head] = -1; return ans[head];
        }

        mp[head].first = min(l1, r1);
        mp[head].second = l2 + r2;
        ans[head] = ans[head->left] + ans[head->right] + (l1 < r1 ? 0 : 1);
    }

    return ans[head];
}

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

int main()
{
    freopen("in.txt", "rt", stdin), freopen("out.txt", "wt", stdout);
    int t;
    cin >> t;

    while (t --) {
        // cout << "preforme " << t << endl;
        node* head = create();
        cout << "ans = " << solve(head) << endl;
    }
    return 0;
}