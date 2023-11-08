// 感觉题目有问题

/*
第十一题
现有n堆坚果排成一行，每小堆有ai个坚果，这行坚果两端有松鼠p和q，他们在玩一个
游戏，p从左向右开始取坚果，q从右向左取坚果，只能从各自方向按顺序连续分别取了
kp和kq堆（0<=kp<=n,0<=kq<=n,0<=kq+kp<=n）注意不能跳跃取堆，请设计算法，求
在满足两只松鼠取得相同的数量的坚果下，取称最大堆数之和，即max（kp+kq）
{408算法三段式问答}
*/

#include <bits/stdc++.h>

using namespace std;

void solve()
{
    // input 
    int len;
    cin >> len;
    vector<int> arr(len, 0);
    for(int i = 0; i < len; i++) cin >> arr[i];

    // main 
    int l = 0, r = len - 1;
    while(l <= r) {

    }

    // output

}

int main()
{
    freopen("in.txt", "rt", stdin), freopen("out.txt", "wt", stdout);
    int t;
    cin >> t;

    while (t --) {
        // cout << "preforme " << t << endl;
        solve();
    }
    return 0;
}
