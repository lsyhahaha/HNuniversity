#include <bits/stdc++.h>
using namespace std;


void solve() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];

    int ans = 0, minpos = 0, tar = arr[0];
    for(int i = 0; i < n; i++) {
        if (arr[i] < tar) {
            minpos = i;
            tar = arr[i];
        }
    }
    for(int i = minpos; i < n - 1; i ++) {
        if (arr[i] > arr[i + 1]) {
            cout << -1 << endl;
            return;
        }
    }

    cout << minpos << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    int t;
    cin >> t;
    while (t --) {
        solve();
        // cout << (solve() ? "Yes" : "No");
        // cout << solve() << endl;
    }
    return 0;
}