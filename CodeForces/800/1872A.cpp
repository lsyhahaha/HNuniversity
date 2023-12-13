//
// Created by 98708 on 2023/9/17.
//

/*
   两个容器，a, b ,用c去把多的那个装到少的那个里面
   问：最少需要多少次？
*/
#include <iostream>
using namespace std;

int main(){
    int N;
    cin>>N;
    while(N--){
        int a, b, c;
        cin >> a >> b >> c;

        int A = max(a,b), B = min(a, b);

        if((A-B)%(c*2) == 0){
            cout << (A-B)/(c*2) <<endl;
        }else{
            cout << (A-B)/(c*2)+1 <<endl;
        }
    }

    return 0;
}