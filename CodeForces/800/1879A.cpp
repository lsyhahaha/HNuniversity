#include <bits/stdc++.h>
using namespace std;

/*
    The idea is simple: if the endurance value is greater than Polycarp's, and the 
    physical value is also greater than his, then no matter what kind of w is chosen,
     P cannot win. Otherwise, the maximum physical value of P can be directly selected;
    
    思路很简单：如果耐力值比Polycarp大，并且体力值也比他大，则无论选什么样的w，都不能让P获胜。
    否则，直接选择P的最大体力值即可；
*/

void solve() {
    // in
    int n;
    cin >> n;
    vector<int> s(n+1), e(n+1);
    for (int i = 1; i <= n; i++) {
        cin >> s[i] >> e[i];
    }

    // 
    int cnt = e[1];
    for (int i = 2; i <= n; i++) {
        if(e[i] >= e[1] && s[i] >= s[1]) {
            cout << -1 << endl;
            return;
        }
    }

    cout << s[1] << endl;
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    int t;
    cin >> t;
    while (t --) {
        solve();
        // cout << (solve() ? "Yes" : "No");
        // cout << solve() << endl;
    }
    return 0;
}