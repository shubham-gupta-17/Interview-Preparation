#include<bits/stdc++.h>
using namespace std;
unordered_set<string>map;
vector<bool>vis;
bool word_break(string &s,int start)
{
    if(start==s.length()) return true;
    string tar="";
    bool ans=false;
    for(int i=start;i<s.length();i++)
    {
        tar+=s[i];
        if(map.find(tar)==map.end() || vis[i]) continue;
        else if(word_break(s,i+1)) return true; // i can do this bcoz i am making a cut only after checking if string from start to i is present in dictionary or not
        else vis[i]=true;
    }
    return ans;
}
bool wordBreak(string &s, vector<string>& wordDict) {
    
    for(string s1:wordDict)
        map.insert(s1);
    vis.resize(s.length(),false);
    return word_break(s,0);
}
int main()
{
    vector<string> word={"leet","code"};
    cout<<wordBreak("Leetcode",word);
    return 0;
}