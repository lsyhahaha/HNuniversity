#include<bits/stdc++.h>
using namespace std;
int p[200005]={0};
int N,Q;
int find(int x)
{
    if(x == p[x])
    {
        return x;
    }
    else
    {
       return p[x] = find(p[x]);
    }
}
void h(int x,int y)
{
    x = find(x);
    y = find(y);
    if(x == y)
    {
        return;
    } 
    else
    {
        p[x] = y;
    }
}
bool check(int x,int y)
{
    if(find(x) == find(y))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int main()
{
    int a,b,c;
    cin >> N >>Q;
    for(int i = 1;i <= N; i++)
    {
        p[i] = i;
    }
    for(int i = 1;i <= Q; i++)
    {
        cin >> a >> b >> c;
        if(a == 1)
        {
            cout << check(b,c) << "\n";
        }
        else if(a == 0) 
        {
            h(b,c);
        }
    }
}