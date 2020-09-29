#include<bits/stdc++.h>
using namespace std;
unordered_map<string,int> map;
vector<string> ans;
bool dfs(string &s,int i)
{
        if(i==s.length()) return true;
        bool flag=false;
        string tar;
        for(int j=i;j<s.length();j++)
        {
            tar+=s[j];
            if(map[tar]==1) flag = flag || dfs(s,j+1);
        }
    return flag;
        
}
 vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        int n=words.size();
        if(n==0) return ans;
        for(string s:words) map[s]+=1;
        
        for(string s:words){
           if(s=="") continue;
           if(dfs(s,0)) ans.push_back(s);
        }
    
        return ans;
}

//====================================================================================================
// Method 2:
bool *vis;
bool dfs_(string s,int i)
{
        if(i==s.length()) return true;
        bool flag=false;
        string tar;
        for(int j=i;j<s.length();j++)
        {
            tar+=s[j];
            if(map.find(tar)==map.end() || vis[j]==true || s==tar) continue;
            else if(dfs_(s,j+1)) return true;
            else vis[j]=true;
        }
    return flag;
       
}
 vector<string> findAllConcatenatedWordsInADict_optimize(vector<string>& words) {
        int n=words.size();
        if(n==0) return ans;
        for(string s:words) map[s]+=1;
        
        for(string s:words){
           if(s=="") continue;
           // vis.resize(s.length(),false);
            int m=s.length();
            vis=new bool[m]();
            if(dfs_(s,0)) ans.push_back(s);
        }
    
        return ans;
}
int main()
{
    vector<string<words={};
    findAllConcatenatedWordsInADict(words);
    findAllConcatenatedWordsInADict_optimize(words);

}