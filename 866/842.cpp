#include<iostream>
using namespace std;

/*
    可以使用DFS, 空间复杂度O(h),不具有最短路径性质,回溯
    DFS就是递归
    
    思路一般只占算法的10%，考场上考的都是算法实现。
    
    存的时候只会存当前路径，也不需要真的写一个栈出来，系统会帮我们写出来
    
    回溯的时候一定要注意的一点就是恢复现场，下去的时候是什么样子，回溯回来了也要是什么样子的。
*/

const int N = 10;
int n;
int path[N];
bool st[N]; // 判断数是否使用过了

void dfs(int u){
    // 全排列，1,2,3....n
    if(u == n) {
        for(int i = 0; i < n; i++) printf("%d ", path[i]);
        puts("");
        return;
    }
    
    for(int i = 1; i <= n; i++) {
        if(!st[i]) {
            path[u] = i;
            st[i] = true;
            dfs(u+1);
            
            // 恢复现场
            // path[u] = 0; path[u] 会被覆盖
            st[i] = false;
        }
    }
}

int main(){
    cin >> n;
    dfs(0);
    return 0;
}