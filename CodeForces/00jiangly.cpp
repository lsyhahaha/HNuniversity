#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n, m;
    std::cin >> n >> m;
    
    std::vector<int> a(n), cnt(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
        a[i] -= 1;
        cnt[a[i]] += 1;
    }
    
    std::vector<int> s(m), d(m);
    for (int i = 0; i < m; i++) {
        std::cin >> s[i];
    }
    for (int i = 0; i < m; i++) {
        std::cin >> d[i];
    }
    
    std::priority_queue<std::pair<int, int>> q;
    for (int i = 0; i < n; i++) {
        q.emplace(cnt[i], i);
    }
    std::vector<std::vector<int>> ans(m);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < s[i]; j += d[i]) {
            std::vector<int> res;
            int C = std::min(d[i], s[i] - j);
            for (int k = 0; k < C; k++) {
                int x = q.top().second;
                q.pop();
                if (cnt[x] == 0) {
                    std::cout << -1 << "\n";
                    return;
                }
                res.push_back(x);
            }
            for (auto x : res) {
                ans[i].push_back(x);
                cnt[x] -= 1;
                q.emplace(cnt[x], x);
            }
        }
    }
    for (int i = 0; i < m; i++) {
        for (auto x : ans[i]) {
            cnt[x] += 1;
        }
        int lim = (s[i] - 1 + d[i]) / d[i];
        std::sort(ans[i].begin(), ans[i].end(),
            [&](int x, int y) {
                if ((cnt[x] == lim) != (cnt[y] == lim)) {
                    return cnt[x] == lim;
                }
                if ((cnt[x] == lim - 1) != (cnt[y] == lim - 1)) {
                    return cnt[y] == lim - 1;
                }
                return x < y;
            });
        std::vector<int> a(s[i]);
        for (int b = 0, j = 0; b < d[i]; b++) {
            for (int k = b; k < s[i]; k += d[i]) {
                a[k] = ans[i][j++];
            }
        }
        for (int j = 0; j < s[i]; j++) {
            std::cout << a[j] + 1 << " \n"[j == s[i] - 1];
        }
        for (auto x : ans[i]) {
            cnt[x] -= 1;
        }
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int t;
    std::cin >> t;
    
    while (t--) {
        solve();
    }
    
    return 0;
}