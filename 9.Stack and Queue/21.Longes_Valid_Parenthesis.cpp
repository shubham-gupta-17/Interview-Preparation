#include <bits/stdc++.h>
using namespace std;
//leetcode 32
int longestValidParentheses(string &s) {
        stack<int> st;
        int n=s.length();
        bool prev=false;
        st.push(-1);
        int ans=0;
        for(int i=0;i<n;){
            char ch=s[i];
            
            while(i<n &&st.top()!=-1 && s[st.top()]=='(' && s[i]==')'){
                st.pop();
                i++;
                prev=true;
            }
           if(prev){
            ans=max(ans,i-st.top()-1);
            prev=false;   
           }
            st.push(i);
           i++;
            
        }
        return ans;
}
int main()
{
  string s="()))()()))(()))))()()()()()())()()()((()))";
  cout<<longestValidParentheses(s);
  return 0;
}
