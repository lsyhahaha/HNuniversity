// 模板

#include <algorithm>
#include <array>
#include <cassert>
#include <chrono>
#include <cmath>
#include <cstring>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <vector>
using namespace std;

class Solution {
public:
    string largestOddNumber(string num) {
        int n = num.size(), idx = -1;
        for(int i = n - 1; i >= 0; i--) {
            if((num[i] - '0') % 2 == 1) {
                idx = i;
                break;
            }
        }
        if(idx == -1) return "";
        string ans = "";
        for(int i = 0; i <= idx; i++) ans.push_back(num[i]);

        return ans;
    }
};


// Leetcode 对拍
// https://www.acwing.com/blog/content/33455/
int main() {
    
    return 0;
}