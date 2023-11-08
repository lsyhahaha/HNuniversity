#ifdef LOCALFLAG
#include <iostream>
#include <vector>
using namespace std;
#endif

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        for (int i = 0; i < n; i++){
            for (int j = i + 1; j < n; j++) {
                if (nums[i] + nums[j] == target) {
                    return {i, j};
                }
            }
        }

        return {};
    }
};

#ifdef LOCALFLAG
int main()
{   
    // freopen("in.txt", "rt", stdin), freopen("out.txt", "wt", stdout);
    Solution solve;
    vector<int> nums = {2, 7, 11, 5};
    auto ans = solve.twoSum(nums, 9);
    cout << ans[0] << " " << ans[1] << endl;
}
#endif