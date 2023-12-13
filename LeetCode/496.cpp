#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int, int> mp;

        for (auto x:nums){
            mp[x]++;
        }

        int num = -1, cnt = -1;
        for (auto x:mp){
            if(x.second > cnt) {
                num = x.first;
                cnt = x.second;
            }
        }

        int i = 0, j = nums.size();

        while(nums[i] != num) i++;
        while(nums[j] != num) j--;

        return j - i + 1;
    }
};