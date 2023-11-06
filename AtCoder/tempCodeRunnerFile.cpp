#include <bits/stdc++.h>

using namespace std;

int N, Q;

int main(){
    cin >> N >> Q;
    vector<vector<int>> g(N, vector<int>(N, 0));

    int qq, u, v;
    while(Q --) {
        cin >> qq >> u >> v;
        if(qq == 0) {
            g[u][v] = 1;
        }else if (qq == 1) {
            if(g[u][v] == 1) cout << 1 << endl;
            else cout << 0 << endl;
        }
    }

    return 0;
}