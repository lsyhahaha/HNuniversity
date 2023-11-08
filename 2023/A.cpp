/*
    第九题 设N>=2,有一个包含n个整数的序列a[0],a[1]......a[n-1]满足a[0] > a[n-1],
    且存在t（0 <= t <= n）满足：a0 <= ...... a[t-1] <= a[t],且a[t+1] <= a[t+2] <= ...... <= a[n-1]
    请问：设计O(logn)算法，并判断输入的整数t是否存在符合上述条件的序列
*/
#include <bits/stdc++.h>

using namespace std;

void solve()
{
    // input 
    int len, T;
    cin >> len >> T;
    vector<int> arr(len, 0);
    for (int i = 0; i < len; i++) cin >> arr[i];

    // cout << len << endl;
    // for (int i = 0; i < len; i++) cout << arr[i] << " ";
    // cout << endl;

    // main 
    int l = 0, r = len - 1, t = 0;
    while (l < r) {
        int mid = l + (r - l) / 2;
        if(arr[mid] > arr[mid + 1]) {
            t = mid;
            break;
        }

        if (arr[mid] <= arr[0]) r = mid;
        else if (arr[mid] > arr[0]) l = mid + 1; 
    }
    // output
    if (t == T) cout << "Yes" << endl;
    else cout << "No" << endl;

}

int main()
{
    freopen("in.txt", "rt", stdin), freopen("out.txt", "wt", stdout);
    int t;
    cin >> t;

    while (t --) {
        // cout << "preforme " << t << endl;
        solve();
    }
    return 0;
}
