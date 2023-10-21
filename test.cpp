// #include <iostream>

// using namespace std;

// const int N = 100010;


// typedef struct edge {
//     int val;
//     struct edge *next;
// }*edge;

// typedef struct adj{
//     int data;
//     struct edge *first;
// }*Adjlist;

// typedef struct Graph{
//     int vecnum;
//     int edgenum;
//     Adjlist adjlist[N];
// }*Graph;

// void InAndOut(Graph g) {
//     //求出图g各个顶点的入度和出度

//     // 入度
//     int answer[N];
//     for (int i = 0; i < N; i++) {
//         // 遍历每一个链表 p
//         Adjlist curNode = g->adjlist[i]; 

//         edge head = curNode->first; // 第i个链表的表头

//         while(head != nullptr) {// 遍历第i个链表中的每天结点
//             // head->val 表示存在一条指向head-val的边
//             answer[head->val] ++;
//             head = head->next;
//         }
//     }

//     for(int i = 1; i < N; i++) {
//         cout << answer[i] << " " << endl;
//     }

//     // 出度
// }

#include <iostream>

using namespace std;

int main() {
    int a , b;
    cin >> a >> b;
    cout << a + b << endl;

    return 0;
}