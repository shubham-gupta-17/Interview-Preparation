#include <bits/stdc++.h>
using namespace std;
//leetcode 931
int minAddToMakeValid(string &s) {
        int n=s.length();
        if(n==0) return 0;
        stack<char> st;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='(') st.push('(');
            else if(!st.empty() && st.top()=='(') st.pop();
            else st.push(')');

        }
        return st.size();
}
int main()
{
  string s="()))()()))(()))))()()()()()())()()()((()))";
  cout<<minAddToMakeValid(s);
  return 0;
}
