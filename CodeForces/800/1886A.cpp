#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
    int n;
    cin >> n;

    int k;
    bool flag = false;
    for (int i = 1; i < n; i++) {
        if (i % 3 == 0) continue;

        for (int j = i + 1; j < n; j++) {
            k = n - j - i;

            if (j % 3 == 0 || j == k || i == k) continue;
            if (i + j >= n) break;

            if (k % 3 != 0) {
                flag = true;
                cout << "Yes" << endl;
                cout << i << " " << j << " " << k << endl;
                return;
            }
        }
    }

    if (flag == false) {
        cout << "No" << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;

    while (t --) {
        solve();
    }

    return 0;
}