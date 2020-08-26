#include<bits/stdc++.h>
using namespace std;
//=======================================================================================
int ans=0;
void find(string&s,int i,int n,int len,vector<bool>&vis)
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
            vector<bool> vis(128,false);
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
int main()
{
    string s="aabaa!bb";
    int n=s.length();
    //Method 1: Recursion
    for(int i=0;i<n;i++)
    find(s,0,n,0);

    //Method 2: for loop= O(n^2);
     cout<<lengthOfLongestSubstring(s);


}
