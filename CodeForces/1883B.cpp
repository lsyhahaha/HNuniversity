#include <bits/stdc++.h>

using namespace std;

void solve()
{
    // input 
    int len, k;
    cin >> len >> k;
    string s;
    cin >> s;
    // cout << "s = " << s << " " << "len =" << len << " " << "k = " << k << endl;

    // main 
    if (len == 1 || len - k <= 1) {
        cout << "YES" << endl;
        return;
    }
    unordered_map<char, int> mp;
    for (auto x : s) {
        if (mp[x] == 0) mp[x] = 1;
        else mp[x] ++;
    }

    k ++;
    int cnt = 0; // 元素个数为奇数的个数
    for (auto it : mp) {
        if (it.second % 2 == 1) k --;
    }

    // output
    if (k < 0) cout << "NO" << endl;
    else cout << "YES" << endl;
}

int main()
{
    int t;
    cin >> t;

    while (t --) {
        solve();
    }
    return 0;
}
