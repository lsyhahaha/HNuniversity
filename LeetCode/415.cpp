#include<iostream>
using namespace std;

class Solution {
public:
    string addStrings(string num1, string num2) {
        int n1 = num1.size(), n2 = num2.size();

        string ans = "";
        int i = n1 -1, j = n2 -1;
        int dital = 0;
        while (i >= 0 && j >= 0) {
            int cur = (num1[i] - '0') + (num2[j] - '0') + dital;
            string c =  to_string(cur % 10);
            ans += c;
            dital = cur / 10;
            i--, j--;
        }
        while(j >= 0) {
            int cur = (num2[j] - '0') + dital;
            string c=  to_string(cur % 10);
            ans += c ;
            dital = cur / 10;
            j--;
        }

        while(i >= 0) {
            int cur = (num1[i] - '0') + dital;
            string c= to_string(cur % 10);
            ans += c ;
            dital = cur / 10;
            i--;
        }
        if(dital != 0) ans += to_string(dital);
        
        int n = ans.size();
        for(int i = 0; i < n / 2; i++) {
            char temp = ans[i];
            ans[i] = ans[n - 1 -i];
            ans[n - 1 - i] = temp;
        }
        return ans;
    }
};