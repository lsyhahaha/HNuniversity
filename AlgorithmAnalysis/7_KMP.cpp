#include <iostream>
#include <vector>

using namespace std;

// 构建部分匹配表（Partial Match Table）
vector<int> buildPartialMatchTable(const string& pattern) {
    int m = pattern.length();
    vector<int> pi(m, 0);

    int k = 0;
    for (int q = 1; q < m; ++q) {
        while (k > 0 && pattern[k] != pattern[q]) {
            k = pi[k - 1];
        }
        if (pattern[k] == pattern[q]) {
            k++;
        }
        pi[q] = k;
    }

    return pi;
}

// KMP算法
void KMP(const string& text, const string& pattern) {
    int n = text.length();
    int m = pattern.length();

    // 构建部分匹配表
    vector<int> pi = buildPartialMatchTable(pattern);

    int q = 0;
    for (int i = 0; i < n; ++i) {
        while (q > 0 && pattern[q] != text[i]) {
            q = pi[q - 1];
        }
        if (pattern[q] == text[i]) {
            q++;
        }
        if (q == m) {
            cout << "Pattern found at index " << i - m + 1 << endl;
            q = pi[q - 1];
        }
    }
}

int main() {
    string text = "ABABDABACDABABCABAB";
    string pattern = "ABABCABAB";

    cout << "Text: " << text << endl;
    cout << "Pattern: " << pattern << endl;

    cout << "Pattern occurrences using KMP algorithm:" << endl;
    KMP(text, pattern);

    return 0;
}
