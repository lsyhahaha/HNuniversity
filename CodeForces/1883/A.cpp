#include <iostream>
#include <string>

using namespace std;

void solve()
{
    string s;

    cin >> s;

    int ans = 0, pre = 1;
    for (int i = 0; i < 4; i++) {
        int cur = s[i] - '0'; // (int) s[i] is wrong!!!
        ans += cur == 0 ? abs(10 - pre) + 1 : abs(cur - pre) + 1;
        pre = cur == 0 ? 10 : cur;
    }
    cout << ans << endl;
}

int main()
{
    freopen("in.txt", "rt", stdin), freopen("out.txt", "wt", stdout);

    int t = 10;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
