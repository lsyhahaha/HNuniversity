/**
 *    author:  tourist
 *    created: 07.11.2023 10:24:41       
**/
#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n, m;
    cin >> n >> m;
    vector<int> cnt(n);
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      --x;
      cnt[x] += 1;
    }
    vector<int> s(m);
    for (int i = 0; i < m; i++) {
      cin >> s[i];
    }
    vector<int> d(m);
    for (int i = 0; i < m; i++) {
      cin >> d[i];
    }
    vector<vector<int>> a(m);
    multiset<pair<int, int>> g;
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < s[i] / d[i]; j++) {
        g.emplace(d[i], i);
      }
      if (s[i] % d[i] > 0) {
        g.emplace(s[i] % d[i], i);
      }
    }
    vector<int> order(n);
    iota(order.begin(), order.end(), 0);
    sort(order.begin(), order.end(), [&](int i, int j) {
      return cnt[i] > cnt[j];
    });
    bool fail = false;
    for (int col : order) {
      int x = cnt[col];
      if ((int) g.size() < x) {
        fail = true;
        break;
      }
      vector<pair<int, int>> rm;
      for (int i = 0; i < x; i++) {
        auto it = prev(g.end());
        a[it->second].push_back(col);
        rm.emplace_back(it->first - 1, it->second);
        g.erase(it);
      }
      for (auto& p : rm) {
        if (p.first > 0) {
          g.insert(p);
        }
      }
    }
    if (fail) {
      cout << -1 << '\n';
    } else {
      for (int i = 0; i < m; i++) {
        assert((int) a[i].size() == s[i]);
        sort(a[i].begin(), a[i].end());
        vector<pair<int, int>> cc;
        int j = 0;
        while (j < (int) a[i].size()) {
          int k = j;
          while (k + 1 < (int) a[i].size() && a[i][k + 1] == a[i][k]) {
            k += 1;
          }
          cc.emplace_back(k - j + 1, a[i][j]);
          j = k + 1;
        }
        sort(cc.rbegin(), cc.rend());
        vector<int> b(s[i], -1);
        int ptr = 0;
        for (auto& p : cc) {
          if (p.first == (s[i] + d[i] - 1) / d[i]) {
            for (int k = ptr; k < s[i]; k += d[i]) {
              b[k] = p.second;
            }
            ptr += 1;
          }
        }
        vector<int> rest;
        for (int rm = d[i] - 1; rm >= ptr; rm--) {
          for (int k = rm; k < s[i]; k += d[i]) {
            rest.push_back(k);
          }
        }
        int at = 0;
        for (auto& p : cc) {
          if (p.first < (s[i] + d[i] - 1) / d[i]) {
            for (int k = 0; k < p.first; k++) {
              b[rest[at++]] = p.second;
            }
            ptr += 1;
          }
        }
        assert(at == (int) rest.size());
        for (int j = 0; j < s[i]; j++) {
          cout << b[j] + 1 << " \n"[j == s[i] - 1];
        }
      }
    }
  }
  return 0;
}
