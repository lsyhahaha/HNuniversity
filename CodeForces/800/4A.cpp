#include <bits/stdc++.h>

using namespace std;

void solve()
{
    // input 
    int n;
    cin >> n;

    // main 
    if (n % 2 == 0 && n != 2) 
        cout << "Yes" << endl;
    else if (n % 2 == 1 || n == 2) 
        cout << "No" << endl;
}

int main()
{
    freopen("in.txt", "rt", stdin), freopen("out.txt", "wt", stdout);
    int t = 1;

    while (t --) {
        // cout << "preforme " << t << endl;
        solve();
    }
    return 0;
}
