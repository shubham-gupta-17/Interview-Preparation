#include<bits/stdc++.h>
using namespace std;
// leetcode 451
#define pp pair<char,int>
    struct compare{
        bool operator()(pp a,pp b){
            return a.second < b.second;
        }
    };
    string frequencySort(string s) {
        priority_queue<pp,vector<pp>, compare> que;
        int n=s.length();
        int *vis=new int[256]();
       
       
        for(int i=0;i<n;i++)
            vis[s[i]-0]++;
        
       
        for(int i=0;i<256;i++){
            if(vis[i]>0)
            que.push({0+i,vis[i]});
        }
        
        
        string ans="";
        while(!que.empty())
        {
            pp top=que.top();
            que.pop();
            while(top.second--)
            ans+=top.first;
        }
        return ans;
}
int main()
{
    
    cout<<frequencySort("his s he a ha he  ha ae");
}