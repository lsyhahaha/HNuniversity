#include <bits/stdc++.h>
using namespace std;


void solve() {
    vector<vector<char>> g(11, vector<char> (11));
    for (int i = 1; i <= 10; i++) {
        for (int j = 1; j <= 10; j++) {
            cin >> g[i][j];
        }
    } 
    // 
    int ans = 0;
    for (int i = 1; i <= 10; i++) {
        for (int j = 1; j <= 10; j++) {
            if (g[i][j] == 'X') {
                int x = min(10 - i + 1, i), y = min(10 - j + 1, j);
                int dis = min(x, y);
                ans += dis;
                // cout << "dis = " << dis << endl;
            }
        }
    } 
    // out 
    cout << ans << endl;
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