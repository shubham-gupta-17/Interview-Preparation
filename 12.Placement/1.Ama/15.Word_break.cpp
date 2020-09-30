#include<bits/stdc++.h>
using namespace std;
unordered_set<string>map;
vector<bool>vis;
// Memo approach
bool word_break(string &s,int start)
{
    if(start==s.length()) return true;
    string tar="";
    bool ans=false;
    for(int i=start;i<s.length();i++)
    {
        tar+=s[i];
        if(map.find(tar)==map.end() || !vis[i]) continue;
        else if(word_break(s,i+1)) return true; // i can do this bcoz i am making a cut only after checking if string from start to i is present in dictionary or not
        else vis[i]=false;  // this means after this index break is not possible 
    }
    return ans;
}
bool wordBreak(string &s, vector<string>& wordDict) {
    
    for(string s1:wordDict)
        map.insert(s1);
    vis.resize(s.length(),true);
    return word_break(s,0);
}

// dp Approach
bool wordBreak_dp(string &s,vector<string>&words)
{
    int n=s.length();
    unordered_map<string,bool> map;
    for(string &s1:words) map[s1]=true;
    
    // dp
    int *dp=new int[n+1]();
    for(int i=0;i<n;i++)
    {   string tar="";
        for(int j=i;j<n;j++)
        {
            tar+=s[j];
            if(map[tar]){
                if(i==0) dp[j]=true;
                else if(dp[i-1]) dp[j]=true;
            }
        }
    }
    return dp[n-1];
}
int main()
{
    vector<string> word={"leet","code"};
    cout<<wordBreak("Leetcode",word)<<endl;
    cout<<wordBreak_dp("Leetcode",word);
    return 0;
}