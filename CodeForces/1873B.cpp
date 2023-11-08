#include <bits/stdc++.h>
using namespace std;


void solve() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i ++) cin >> arr[i];

    // mian
    int pro = 1, cnt = 0, idx = 0;
    for(int i = 0; i < n; i++) {
        if (arr[i] == 0) {
            cnt ++;
            idx = i;
        }
    }

    if (cnt >= 2) {
        cout << 0 << endl;
        return;
    } else if (cnt == 1) {
        pro = 1, arr[idx] = 1;
        for(int i = 0; i < n; i++) pro *= arr[i];
        cout << pro << endl;
        return;
    } 

    int minnum = arr[0];
    for(int i = 0; i < n; i++) {
        if (arr[i] < minnum) {
            minnum = arr[i];
            idx = i;
        }
    }

    pro = 1, arr[idx]++;
    // cout << "idx = " << idx << endl;
    for(int i = 0; i < n; i++) pro *= arr[i];
    cout << pro <<endl;
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    int t;
    cin >> t;
    while (t --) {
        solve();
    }
    return 0;
}