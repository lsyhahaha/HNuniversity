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
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        for (int i = 0; i < n; i ++) {
            for (int j = i + 1; j < n; j ++) {
                if (nums[i] + nums[j] == target)
                    return vector<int> {i, j};
            }
        }

        return {-1, -1};
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