# include <bits/stdc++.h>
# define mem(a,b) memset(a,b,sizeof(a))
# define lb(x) ((x) & -(x))
# define pi pair<int,int>
# define X first
# define Y second
# ifdef LOCAL
# include "leetcode.h"
# endif // LOCAL
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
int dx[4]={-1,1,0,0},dy[4]={0,0,-1,1};

template<typename T>
ostream & operator << (ostream &out,const set<T>&obj){out<<"set(";for(auto it=obj.begin();it!=obj.end();it++) out<<(it==obj.begin()?"":", ")<<*it;out<<")";return out;}
template<typename T>
ostream & operator << (ostream &out,const unordered_set<T>&obj){out<<"unordered_set(";for(auto it=obj.begin();it!=obj.end();it++) out<<(it==obj.begin()?"":", ")<<*it;out<<")";return out;}
template<typename T1,typename T2>
ostream & operator << (ostream &out,const map<T1,T2>&obj){out<<"map(";for(auto it=obj.begin();it!=obj.end();it++) out<<(it==obj.begin()?"":", ")<<it->first<<": "<<it->second;out<<")";return out;}
template<typename T1,typename T2>
ostream & operator << (ostream &out,const unordered_map<T1,T2>&obj){out<<"unordered_map(";for(auto it=obj.begin();it!=obj.end();it++) out<<(it==obj.begin()?"":", ")<<it->first<<": "<<it->second;out<<")";return out;}
template<typename T1,typename T2>
ostream & operator << (ostream &out,const pair<T1,T2>&obj){out<<"<"<<obj.first<<", "<<obj.second<<">";return out;}
template<typename T>
ostream & operator << (ostream &out,const vector<T>&obj){out<<"vector(";for(auto it=obj.begin();it!=obj.end();it++) out<<(it==obj.begin()?"":", ")<<*it;out<<")";return out;}

template <typename T>
struct HashTable {
  vector<T> val;
  void add(T x) { val.push_back(x); }
  void init() {
    sort(ALL(val));
    val.erase(unique(ALL(val)), val.end());
  }
  int query(T x) { return lower_bound(ALL(val), x) - val.begin() + 1; }
  T operator[](const int t) const { return val[t - 1]; }
  int size() { return val.size(); }
  void clear(){val.clear();}
};

class Solution {
public:
    int minGroupsForValidAssignment(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(int x:nums) ++mp[x];
        vector<int>a;
        for(auto &[k,v]:mp) a.push_back(v);
        int mn=*min_element(a.begin(),a.end());
        int ans=1e9;
        for(int i=mn;i>=1;i--){
            int k=0;
            for(int x:a){
                int d=x/(i+1),r=x%(i+1);
                if(r==0) k+=d;
                else{
                    if(d+r<i){
                        k=-1;break;
                    }
                    else{
                        k+=d+1;
                    }
                }
            }
            if(k!=-1) ans=min(ans,k);
        }
        return ans;
    }
};