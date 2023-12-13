#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int top = -1, n = nums1.size(), m = nums2.size();
        vector<int> stack(n * 2);
        unordered_map<int, int> mp; // ans
        int f, s;

        reverse(nums2.begin(), nums2.end());

        for (int i = 0; i < m; i++) {
            while (top != -1 && nums2[i] >= stack[top]) {
                top--;
            }
            stack[++ top] = nums2[i];

            f = nums2[i];
            s = top >= 1 ? stack[top - 1] : -1;
            mp[f] = s;
        }


        vector<int> ans;

        for (int i = 0; i < n; i++) {
            ans.push_back(mp[nums1[i]]);
        }

        return ans;
    }
};