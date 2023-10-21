// 使用BFS可以求解一个非带权图的单源最短路径 （23版212页）代码：template1.cpp

#include <bits/stdc++.h>

using namespace std;

typedef struct {
    int vexnum;
}*Graph;

const int N = 1000;
int d[N];
bool visited[N];

void BFS_MIN_Distance(Graph G, int u) {
    // d[i] 表示从u到i的最短路径

    for (int i = 0; i < G->vexnum; i++) 
        d[i] = INT_MAX;
    
    visited[u] = true, d[u] = 0;

    int queue[N], hh = 0, tt = -1;
    queue[++ tt] = u;// 入队

    while (tt >= hh) {
        int cur = queue[hh ++];// 出队

        for(int w = FirstNeighbor(G, u); w >= 0; w = NextNeighbor(G, u, w)) {  
            // 对于FirstNeighbor(G, u) 和 NextNeighbor(G, u, w)，使用邻接表更容易实现
            // 例如：Leetcode 2316AC.cpp NOTICE3:构建邻接表
            if(!visited[w]) {
                visited[w] = true;
                queue[++ tt] = w;
                d[w] = d[u] + 1; // 路径长度加1
            }
        }
    }
}