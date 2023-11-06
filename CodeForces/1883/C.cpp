#include <bits/stdc++.h>

using namespace std;

void solve()
{
    // input 
    int n, k;
    cin >> n >> k;
    // cout << n << " " << k << endl;

    vector<int> A(n, 0);
    for(int i = 0; i < n; i++) cin >> A[i];

    // for (int i = 0; i < n; i ++) cout << A[i] << " ";
    // cout << endl;

    // main 
    int ans = INT_MAX, sum = 0;
    for (int i = 0; i < n; i++) {
        if (A[i] % k == 0) {
            cout << 0 << endl;
            break;
        } else {
            // 找到离k的倍数最近的数字 ans = ?
            int case1 = k - (A[i] % k);
            // int case2 = A[i] % k;
            ans = min(ans, case1);
        }
    }

    // output
    cout << ans << endl;
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

// 5  1 -> 6 2
