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
//==============================================================================
int longestAwesome_bit(string &s){
     int n=s.length();
        if(s=="") return 0;
        int len=0;
        int mask=0;
        unordered_map<int,int> map;
        map[0]=-1;
        for(int i=0;i<n;i++){
            int idx=s[i]-'0';
            mask ^=(1<<idx);
            // check if same mask was visited before or not (this is case 1 when all character have even occurence)
            if(map.find(mask)!=map.end()){
                auto it=map.find(mask);
                len=max(len,i-it->second);
            }
            else map[mask]=i;
            
            // if one character has odd occurence then mask will have one more (1) bit hence check for that
            for(int j=0;j<10;j++){
                int bit_mask= (mask ^(1<<j));
                if(auto it=map.find(bit_mask);it!=map.end())
                    len=max(len,i-it->second);
            }
        }
        
        return len;
}
int main(){
    cout<<longestAwesome("453627654161");
    cout<<longestAwesome_bit("362567352");
}