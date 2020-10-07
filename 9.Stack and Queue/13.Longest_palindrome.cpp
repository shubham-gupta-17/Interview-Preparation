#include<bits/stdc++.h>
using namespace std;
// leetcode 32
 int longestValidParentheses(string s) {
       int n=s.length();
        if(n==0) return 0;
        int ans=0;
        bool flag=false;
        stack<int> st;
        st.push(-1);
        for(int i=0;i<n;i++)
        {
            if(st.top()!=-1 && s[st.top()]=='(' && s[i]==')')
            {
                st.pop();
                ans=max(ans,i-st.top());
            }
            
           else st.push(i);
        }
       
        
        return ans;
 }
int main()
{
	string s="()()()()()()()()((()))";
	cout<<longestValidParentheses(s);
	return 0;
	
}
