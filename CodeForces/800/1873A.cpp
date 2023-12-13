#include <bits/stdc++.h>
using namespace std;


void solve() {
    string s;
    cin >> s;

    // main
    if (s == "abc" || s == "acb" || s == "bac" || s == "cba")
        cout << "Yes" << endl;
    else 
        cout << "No" << endl;
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