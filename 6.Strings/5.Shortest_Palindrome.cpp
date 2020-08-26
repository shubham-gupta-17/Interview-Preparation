#include<bits/stdc++.h>
using namespace std;
// Leetcode 214


int ans=1;

int find(string &s,int i,int j)
{
      if(i>j || i==j) return (i==j)?1:0;
      if(i+1==j && s[i]==s[j]){
          if(i==0) ans=max(ans,2);
          return 2;
      }
      int a=0;
      if(s[i]==s[j] && find(s,i+1,j-1))  a=find(s,i+1,j-1)+2;
      find(s,i,j-1);
      if(i==0) ans=max(ans,a);
      return a;

}
string shortestPalindrome_rec(string &s) {
    int n=s.length();
    int b=find(s,0,n-1);
    string a="";
    cout<<ans<<endl<<ans;
    for(int i=n-1;i>=dp[0];i--) a+=s[i];
    for(int i=0;i<n;i++) a+=s[i];
    return a;
}
//=================================================================================================
string shortestPalindrome_dp(string &s) {
       int n=s.length();
       string a="";

       vector<vector<int>>dp(n+1,vector<int>(n+1,0));
       for(int i=n-1;i>=0;i--)
       {
           for(int j=i;j<n;j++)
           {
               if(i==j){
                   dp[i][j]=1;
                   continue;
               }
               if(s[i]==s[j] && (j-i==1)) dp[i][j]=2;
               else if(s[i]==s[j] && dp[i+1][j-1]!=0) dp[i][j]=dp[i+1][j-1]+2;
           }
       }

       int ans=1;
       for(int i=0;i<n;i++)
           ans=max(ans,dp[0][i]);
       cout<<ans;
        for(int i=n-1;i>=ans;i--) a+=s[i];
        for(int i=0;i<n;i++) a+=s[i];
       return a;
}
int main()
{
  string s="ababbbabbaba";
  cout<<shortestPalindrome_rec()<<endl;
  cout<<shortestPalindrome_dp(s); // dp solution will give TLE at "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"

}
