#include<bits/stdc++.h>
using namespace std;
//=======================================================================================
int ans=0;
bool vis[128]={false}; // do not use vector as it will take a lot of time
void find(string&s,int i,int n,int len)
{
       if(i==n || vis[s[i]-' ']==true){
           ans=max(ans,len);
           return ;
       }

       vis[s[i]-' ']=true;
       find(s,i+1,n,len+1,vis);
       vis[s[i]-' ']=false;
       return ;
}

//===========================================================================================
int lengthOfLongestSubstring(string &s) {
        int n=s.length();
        if(n==0) return 0;
        int ans=0;
        for(int i=0;i<n;i++)
        {
            bool vis[128]={false};
            vis[s[i]-' ']=true;
            int len=1;
            int j=i+1;
            while(j<n && vis[s[j]-' ']==false)
            {
                len++;
                vis[s[j]-' ']=true;
                j++;
            }

            ans=max(ans,len);
        }
        return ans;
    }
}

//=============================================================================================
int lengthOfLongestSubstring_Opti(string &s)
{
  int n=s.length();
  if(n==0)return 0;
  int ans=1;
  int i=0;
  int j=1;
  int len=1;
  bool vis[128]=false;
  vis[s[0]-' ']=true;
  while(j<n)
  {
     if(vis[s[j]-' ']){
       ans=max(ans,len);
       while(i<j && vis[s[j]-' ']) {
         vis[s[i]-' ']=false;
         i++;
       }
       len=j-i;
     }

     len++
     vis[s[j]-' ']=true;
     j++;
  }
  return  ans=max(ans,len);
}
int main()
{
    string s="aabaa!bb";
    int n=s.length();
    //Method 1: Recursion
    for(int i=0;i<n;i++)
    find(s,0,n,0);

    //Method 2: for loop= O(n^2);
     cout<<lengthOfLongestSubstring(s);

     //Method 3: O(2*n)==O(n)
     cout<<lengthOfLongestSubstring_Opti(s);

     //Method 4: sliding window: O(n)
     


}
