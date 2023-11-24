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
    int largestAltitude(vector<int>& gain) {
        int ans = 0, pre = 0, n = gain.size();
        for(int i = 0; i < n; i++){
            int cur = pre + gain[i];
            if(cur > ans) ans = cur;
            pre = cur;
        }

        return ans;
    }
};

// Leetcode 对拍
// https://www.acwing.com/blog/content/33455/
int main() {
    
    return 0;
}