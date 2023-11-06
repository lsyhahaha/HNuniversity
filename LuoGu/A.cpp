#include <iostream>

using namespace std;

const int N = 1000;
int n;

// head存储链表头，e[]存储节点的值，ne[]存储节点的next指针，idx表示当前用到了哪个节点
int head, e[N], ne[N], idx;

// 初始化
void init()
{
    head = -1;
    idx = 0;
}

// 在链表头插入一个数a
void insert(int a)
{
    e[idx] = a, ne[idx] = head, head = idx ++ ;
}

// 将头结点删除，需要保证头结点存在
void remove()
{
    head = ne[head];
}

int main(){
    // cin >> n;
    n = 8;

    init();
    for(int i = n; i >= 1; i--) insert(i);

    int sum = n, res1, res2;
    while(sum != 0) {
        int cur = head, sub = 0;
        head = ne[head];
        cur = ne[cur], sub ++;
        while (cur != -1) {
            if(cur == -1 || ne[cur] == -1 || ne[ne[cur]] == -1) break;
            cout << e[cur] << " ";
            ne[cur] = ne[ne[ne[cur]]];
            sub ++;
        }
        res1 ++;
        sum -= sub;
    }

    cout << res1 << res2;

    return 0;
}