#include <bits/stdc++.h>
using namespace std;

/*
    Every time a black block is encountered, an operation is
     performed, and after an operation, there is no need to 
     deal with the following k cells, because they have turned 
     white. So i = i+ k; Just walk through one side.

    每当遇到黑块的时候就执行一次操作，当执行一次操作后，就不需要再管
    后面的k个单元格了，因为他们已经变白了。所以i = i+ k;遍历一边即可
*/

void solve() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    // mian
    int ans = 0, i = 0;

    while (i < n) {
        while (i < n && s[i] == 'W') i++;
        if (i >= n) break;
        if (s[i] == 'B') {
            ans ++;
            i = i + k;
        }
    }
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