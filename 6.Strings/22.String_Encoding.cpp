#include <bits/stdc++.h>
using namespace std;
//leetcode 443
int compress(vector<char>& s) {
        int n=s.size();
        if(n==0) return 0;
        string ans="";
        for(int i=0;i<n;){
            int j=i+1;
            while(j<n && s[j]==s[i]) j++;
            ans=ans+s[i];
            if(j-i>1) ans+=to_string(j-i);
            i=j;
        }
        
       
        for(int i=0;i<ans.length();i++){
            s[i]=ans[i];
        }
        return ans.length();
}
//==============================================================
 int compress(vector<char>& s) {
        int n=s.size();
        if(n==0) return 0;
        int idx=0;
        for(int i=0;i<n;){
            int j=i+1;
            while(j<n && s[j]==s[i]) j++;
            s[idx++]=s[i];
            
            if(j-i>1){
                string count=to_string(j-i);
                for(int k=0;k<count.length();k++) s[idx++]=count[k];
            }
            i=j;
            
        }
        
        return idx;
}
int main()
{
  vector<char> a={'a','a','b','b'};
  compress(a);
  return 0;
}
