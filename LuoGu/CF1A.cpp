#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


void solve() {
    ll n, m, a;
    cin >> n >> m >> a;

    ll l = (m % a) == 0 ? m / a : m / a + 1;
    ll r = (n % a) == 0 ? n / a : n / a + 1;
    cout << l * r << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    solve();
    return 0;
}