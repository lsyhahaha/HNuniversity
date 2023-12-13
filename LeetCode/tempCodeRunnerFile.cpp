class Solution {
public:
    // [2,3,4,-1,4]
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();

        vector<int> arr(n * 2);
        vector<int> stack(n * 2);
        int top = -1;

        // 1 2 3 4 3, 1 2 3 4 3
        for (int i = 0; i < n; i++) {
            arr[i] = nums[i];
            arr[n+i] = nums[i];
        }

        reverse(arr.begin(), arr.end());

        int f, s;
        unordered_map<int, int> mp; 

        for (int i = 0; i <= 2*n - 1; i++) {
            while(top != -1 && arr[i] >= stack[top]) {
                top --;
            }

            if (i >= n)
                cout << "cur = " << arr[i] << "    ";

            stack[++ top] = arr[i];
            for(int i = 0; i <= top; i++) cout << stack[i] << " ";
            cout << endl;

            if (i >= n) {
                f = n - 1 - (i - n);
                s = top >=1 ? stack[top - 1] : -1;
                mp[f] = s;
            }
        }

        vector<int> ans;

        for (int i = 0; i < n; i++) {
            ans.push_back(mp[i]);
        }

        return ans;
    }
};