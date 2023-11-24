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
    bool checkIfPangram(string sentence) {
        unordered_map<char, int> mp;
        for(auto x:sentence) {
            char cur = x;
            if(x >= 'A' && x <= 'Z') {
                cur = 'a' + x - 'A'; 
            }
            mp[cur]++;
        }

        for(char i = 'a'; i <= 'z'; i++) {
            if(mp[i] == 0) return false;
        }

        return true;
    }
};
// Leetcode 对拍
// https://www.acwing.com/blog/content/33455/
int main() {
    
    return 0;
}