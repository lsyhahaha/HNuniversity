#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumValue(vector<string>& strs) {
        int ans = 1;
        for (auto s:strs) {
            bool flag = true; // true only occpy num
            for(auto cc:s) {
                if(cc < '0' || cc > '9') {
                    flag = false;
                    break;
                }
            }

            int cur = 0, dten = 1;
            if(flag == true) {
                for(int i = s.size() - 1; i >= 0; i--) {
                    cur += (s[i] - '0') * dten;
                    dten *= 10;
                }
            } else {
                cur = s.size();
            }
            cout << s << " " << cur << endl;
            if(ans < cur) ans = cur;
        }

        return ans;
    }
};
