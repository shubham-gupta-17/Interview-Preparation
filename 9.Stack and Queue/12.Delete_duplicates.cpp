#include<bits/stdc++.h>
using namespace std;
// leetcode 316 or 1081
string removeDuplicateLetters(string s) {
        int n=s.length();
        if(n==0) return "";
        string ans="";
        stack<char> st;
        int *vis=new int[26]();
        int *occurence=new int[26]();
        for(int i=0;i<n;i++) occurence[s[i]-'a']++;
        
        for(int i=0;i<n;i++)
        {
            occurence[s[i]-'a']--;
            if(vis[s[i]-'a']) continue;
            while(!st.empty() && s[i]<st.top() && occurence[st.top()-'a']!=0)
            {   
                char ch=st.top();
                st.pop();
                vis[ch-'a']=false;
            }
             st.push(s[i]);
             vis[s[i]-'a']=true;
        }
        
        while(!st.empty())
        {
            char ch =st.top();
            st.pop();
            ans+=ch;
        }
        string res="";
        for(int i=ans.length()-1;i>=0;i--) res+=ans[i];
        return res;
}
int main()
{
    string s="cbacdbcdc";
    cout<<removeDuplicateLetters(s);
    return 0;
}