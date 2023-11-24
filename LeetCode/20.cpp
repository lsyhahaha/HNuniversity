#include <bits/stdc++.h>
using namespace std;

bool isValid(char* s) {
    int len=strlen(s);            //求字符串长度
    if(len%2 != 0) return false;  //字符串长度为奇数，一定不匹配
    char stack[len];              //数组栈
    int top = -1;                    //栈顶指针top初值设为0
    for(int i=0;i<len;i++){
        if(s[i]=='(' || s[i]=='{' || s[i]=='['){   //左括号入栈
            stack[++ top] = s[i];
        }  
        else{      //s[i]要么为右括号，要么为其他
            if(top == -1) return false;   //栈空，不匹配
            char topchar = stack[top];
            if((s[i]==')' && topchar=='(') || (s[i]=='}' && topchar=='{') || (s[i]==']' && topchar=='[')){        //匹配成功，右括号出栈，栈顶指针-1
                top --;
            }//if                
            else{          //匹配失败，返回false
                return false;
            }        
        }//else
    }//for

    // return true;
    return top == -1;
}//