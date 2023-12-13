#include <iostream>
#include <string>

using namespace std;

// 朴素模式匹配算法
void naivePatternMatching(const string& text, const string& pattern) {
    int m = pattern.length();
    int n = text.length();

    for (int i = 0; i <= n - m; ++i) {
        int j;
        for (j = 0; j < m; ++j) {
            if (text[i + j] != pattern[j]) {
                break;
            }
        }

        if (j == m) {
            cout << "Pattern found at index " << i << endl;
        }
    }
}

int main() {
    string text = "AABAACAADAABAAABAA";
    string pattern = "AABA";

    cout << "Text: " << text << endl;
    cout << "Pattern: " << pattern << endl;

    cout << "Pattern occurrences:" << endl;
    naivePatternMatching(text, pattern);

    return 0;
}
