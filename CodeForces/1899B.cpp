#include <bits/stdc++.h>
using namespace std;


void solve() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];

    sort(arr.begin(), arr.end());

    for(int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;

    cout << arr[n - 1] - arr[0] << endl;
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