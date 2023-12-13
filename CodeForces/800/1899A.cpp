#include <bits/stdc++.h>
using namespace std;


void solve() {
    int n;
    cin >> n;
    if(n % 3 == 0) {
        cout << "Second" << endl;
    } else {
        cout << "First" << endl;
    }
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