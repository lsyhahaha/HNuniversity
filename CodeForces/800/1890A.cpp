#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];

    unordered_map<int, int> mp;
    set<int> st;
    for (auto &x:arr){
        st.insert(x);
        mp[x]++;
    }

    if (st.size() > 2) {
        cout << "No" << endl;
        return;
    } else if (st.size() == 1) {
        cout << "Yes" << endl;
        return;
    }

    int a = arr[0], b, i = 0;
    while(arr[i] == a) {
        i++;
    }
    b = arr[i];

    if (abs(mp[a] - mp[b]) > 1) {
        cout << "No" << endl;
        return;
    } else {
        cout << "Yes" << endl;
        return;
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