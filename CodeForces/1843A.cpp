#include <bits/stdc++.h>
using namespace std;


void solve() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i=0; i < n; i++) cin >> arr[i];

    // main
    sort(arr.begin(), arr.end());
    int l = 0, r = n-1, ans = 0;
    while(l < r) {
        ans += arr[r --] - arr[l ++];
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