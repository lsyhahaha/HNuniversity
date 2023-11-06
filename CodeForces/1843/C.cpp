#include <bits/stdc++.h>

using namespace std;


void solve()
{
    // input 
    long long n, ans = 0;
    cin >> n;
    // cout << n << endl;
    // main 
    
    while(n >= 1) {
        ans += n;
        n = n / 2;
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
