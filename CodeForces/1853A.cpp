#include <bits/stdc++.h>
using namespace std;


void solve() {
  int n;
  cin >> n;
  vector<int> arr(n);
  for(int i = 0; i < n; i++) cin >> arr[i];

  int ans = INT_MAX;
  for(int i = 0; i < n - 1; i++) {
    if(arr[i+1] < arr[i]) {
      cout << 0 << endl;
      return;
    }
    int cur = (arr[i + 1] - arr[i]) / 2 + 1;
    if(cur < ans) ans = cur;
  }
  cout << ans << endl;
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