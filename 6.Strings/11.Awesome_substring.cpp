#include<bits/stdc++.h>
using namespace std;
// leetcode 1542
int longestAwesome(string s) {
        int n=s.length();
        if(s=="") return 0;
        int *vis=new int[10]();
        int len=0;
        for(int i=0;i<n;i++){
            int count=0;
            vis=new int[10]();
            for(int j=i;j<n;j++){
                int idx=s[j]-'0';
                vis[idx]++;
                if(vis[idx]%2) count++;
                else count--;
                
                if(count==0 || count==1) len=max(len,j-i+1);
            }
        }
        
        return len;
}
int main(){
    cout<<longestAwesome("453627654161");
    cout<<longestAwesome_bit("362567352");
}