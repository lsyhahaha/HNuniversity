/*
    N皇后问题有多种搜索方式
    1. 第一种思路，和全排列一样的思路：(全排列解法)
        先看第一行这个皇后可以放在哪一列（枚举每一行这个皇后可以放在哪一列）
        注意一定要剪枝（即不符合要求的）
    
    2.第二种思路：
        一个格子一个格子枚举，算法时间复杂度为O(2^(n^2))
        
*/

#include<iostream>
using namespace std;

int n;
const int N = 20;
char g[N][N];
bool row[N], col[N], dg[N], udg[N];

void dfs(int x, int y, int s) {
    if(y == n) y = 0, x++;
    
    if(x == n){
        if(s == n) {
            for(int i = 0; i < n; i++) puts(g[i]);
            puts("");
        }
        return;
    }
    
    // 不放皇后
    dfs(x, y + 1, s);
    
    // 放皇后
    if(!row[x] && !col[y] && !dg[x+y] && !udg[x-y+n]){
        g[x][y] = 'Q';
        row[x] = col[y] = dg[x+y] = udg[x-y+n] = true;
        dfs(x, y+1, s+1);
        row[x] = col[y] = dg[x+y] = udg[x-y+n] = false;
        g[x][y] = '.';
    }
}



int main(){
    cin >> n;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n;j++){
            g[i][j] = '.';
        }
    }
    
    dfs(0, 0, 0);
    
    return 0;
}