/*
    p17 
    2.2.3 顺序表
*/
#include <bits/stdc++.h>
using namespace std;

#define MaxSize 100
typedef int ElemType;

struct SqList{
    ElemType data[MaxSize];
    int length;
};

SqList create(int A[], int len) {
    SqList L;
    for(int i = 0; i < len; i++) {
        L.data[i] = A[i];
    }
    L.length = len;
    return L;
}

void show(SqList L) {
    for(int i = 0; i < L.length; i++) {
        cout << L.data[i] << " ";
    }
    cout << endl;
}

// 01
void del(SqList &L){
    if(L.length == 0) {
        cout << "null sqlist" <<endl;
        return;
    } 

    int minnum = L.data[0], idx = 0; // min_num  and index of min_num
    for(int i = 1; i < L.length; i++) {
        if(L.data[i] < minnum) minnum = L.data[i], idx = i;
    }
    L.data[idx] = L.data[L.length - 1];
    L.length --;
}

//02
void reserve(SqList &L){
    int l = 0, r = L.length - 1, temp;
    while (l < r){
        temp = L.data[l];
        L.data[l] = L.data[r];
        L.data[r] = temp;
        l++, r--; 
    }
}

//03
void del_x(SqList &L, int x) {
    int k = 0;
    for(int i = 0; i < L.length; i++) {
        if(L.data[i] != x) {
            L.data[k] = L.data[i];
            k++;
        }
    }
    L.length = k;
}

// 04
void del_s_t(SqList &L, int s, int t) {
    if(s > t || L.length == 0) {
        cout << "error!" <<endl;
        return;
    }

    int k = 0;
    for(int i = 0; i < L.length; i++) {
        if(L.data[i] <= s || L.data[i] >= t) {
            L.data[k] = L.data[i];
            k++;
        }
    }
    L.length = k;
}

// 05  same 04

// 06
void del_same(SqList &L){
    set<int> st;
    for(int i = 0; i < L.length; i++) {
        st.insert(L.data[i]);
    }
    int i = 0;
    for(auto x: st){
        L.data[i ++] = x;
    }
    L.length = i;
}

// 07
void merge_sq(SqList &L1,SqList &L2, SqList &L3){
    int i = 0, j = 0, k = 0;
    while(i < L1.length && j < L2.length) {
        if(L1.data[i] <= L2.data[j]) {
            L3.data[k++] = L1.data[i++];
        }else{
            L3.data[k++] = L2.data[j++];
        }
    }

    while(i < L1.length) L3.data[k++] = L1.data[i++];
    while(j < L2.length) L3.data[k++] = L2.data[j++];
    L3.length = k;
}

// 08
void sol(SqList &L, int i, int j){
    int l = i, r = j, temp;
    while (l < r){
        temp = L.data[l];
        L.data[l] = L.data[r];
        L.data[r] = temp;
        l++, r--; 
    }
}
void reserve_sq(SqList &L, int m, int n){
    sol(L, 0, m + n);
    sol(L, 0, n);
    sol(L, n, m+n);
}

// 09
void binary_search(SqList &L, int x){
    int l = 0, r = L.length - 1;
    while (l < r) {
        int mid = (r + l) / 2;
        if (L.data[mid] == x) {
            cout << "idx = " << mid << endl;
            return;
        } else if (L.data[mid] > x) {
            r = mid - 1;
        } else if (L.data[mid] < x) {
            l = mid + 1;
        }
    }
} 

// 10
void move(SqList &L, int k){
    sol(L, 0, L.length - 1);
    sol(L, 0, k - 1);
    sol(L, k, L.length - 1);
}

// 11
void M_search(int A[], int B[], int n){
    int s1 = 0, d1 = n - 1, m1, s2  = 0, d2 = n -1, m2;
    while(s1 != d1 || s2 != d2) {
        m1 = (s1 + d1) / 2;
        m2 = (s2 + d2) / 2;
        if (A[m1] == B[m2]) {
            cout << "ans = " << A[m1] << endl;
            return;
        }else if (A[m1] < B[m2]) {
            s1 = (s1 + d1) % 2 == 0 ? m1 : m1 + 1;
            d2 = m2;
        }else {
            d1 = m1;
            s2 = (s2 + d2) % 2 == 0 ? m2 : m2 + 1; 
        }
    }

    int ans = A[s1] < B[s2] ? A[s1] : B[s2];
    cout << "ans = " << ans << endl;
}

//12 
void major(SqList &L) {
    unordered_map<int, int> mp;
    for(int i = 0; i < L.length; i++) {
        if(mp[L.data[i]]) {
            mp[L.data[i]] ++;
        }else {
            mp[L.data[i]] = 1;
        }
    }

    for (auto x : mp) {
        if(x.second > L.length / 2) {
            cout << "ans = " << x.first << endl;
            return;
        }
    }
    cout << "not find major" << endl;
}

int main(){
    int A[10] = {1,2,3,4,5,6,7,8,9,10};
    SqList L = create(A, 10);
    cout << "scorce sqlist:" << endl;
    cout << "scorce sqlist length: " << L.length <<endl; 
    show(L);
    cout << endl;

    // opeartion
    
    // del(L); // 01
    
    // reserve(L); // 02
    
    // del_x(L, 4);// 03
    
    // del_s_t(L, 3, 10); // 04
    
    // 05

    // del_same(L); // 06

    // SqList L3;
    // merge_sq(L, L, L3); // 07

    // reserve_sq(L, 5, 5); // 08

    // binary_search(L, 5); // 09

    // move(L, 4); // 10

    // int AA[5] = {11,13,15,17,19};
    // int BB[5] = {2,4,6,8,20};
    // M_search(AA, BB, 5); // 11

    // int AA[8] = {0,5,5,3,5,7,5,5};
    // SqList LL = create(AA, 8);
    // major(LL);//12

    
    cout << endl;

    cout << "new sqlist:" << endl;
    cout << "new sqlist length: " << L.length <<endl; 
    show(L); 

}