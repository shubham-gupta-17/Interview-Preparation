#include <bits/stdc++.h>
using namespace std;
//leetcode 20
bool check(char ch,stack<char>&st){
    if(st.empty()) return false;
    if(ch==']' && st.top()=='[') return true;
    if(ch==')' && st.top()=='(') return true;
    if(ch=='}' && st.top()=='{') return true;
    return false;
}
bool ispar(string &x)
{
    stack<char> st;
    bool ans=false;
    for(int i=0;i<x.length();i++){
        if(check(x[i],st))
            st.pop();
        else st.push(x[i]);
    }
    return st.empty();
    
}
int main()
{
  string s="({[]})";
  cout<<ispar(s);
  return 0;
}
