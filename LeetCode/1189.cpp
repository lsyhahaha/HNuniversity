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
    int maxNumberOfBalloons(string text) {
        unordered_map<char, int> mp;
        for(auto x:text) mp[x] ++;
        
        int ans = INT_MAX;
        string s = "ballon";
        for(auto x:s) {
            if((x != 'l' && x != 'o') && ans > mp[x]) 
                ans = mp[x];
            else if ((x == 'l' || x == 'o') && ans > mp[x] / 2)
                ans = mp[x] / 2;
        }
        
        return ans == INT_MAX ? 0 : ans;
    }
};

// Leetcode 对拍
// https://www.acwing.com/blog/content/33455/
int main() {
    // 生成一组随机数据，放在data.in里面

    // 暴力解法运行，将结果存放在bf.out中

    // 解法一运行，将输出结果放在sol1.out中，并且与bf.out对比
    // 解法二运行，将输出结果放在sol2.out中，并且与bf.out对比   
    return 0;
}