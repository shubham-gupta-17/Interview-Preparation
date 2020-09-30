#include<bits/stdc++.h>
using namespace std;
// first check whethere is is possible to break a word or not
int n;
unordered_map<string,bool> map;
int *dp;
bool check_break(string &s)
{
    dp=new int[n]();
    for(int i=0;i<n;i++)
    {
        string tar="";
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

vector<string> ans;
vector<string> res;
void word_break(string &s,int st)
{
    if(st==n){
        string tmp="";
       for(string str:res){
           tmp+=str+" ";
       }
       tmp.pop_back();
       ans.push_back(tmp);
        return;
    }

    string tar="";
    for(int i=st;i<n;i++)
    {
        tar+=s[i];
        if(!dp[i]) continue;
        if(map[tar]){
            res.push_back(tar);
            word_break(s,i+1);
            res.pop_back();
        }
    }

    return ;
}
vector<string> wordBreak_II(string &s,vector<string>&word)
{
    n=s.length();
    if(n==0) return ans;
    for(string &s1:word) map[s1]=true;

    // check if possible to break or not
    if(!check_break(s)) return ans;
    word_break(s,0);
    return ans;
}
int main()
{
    vector<string> word={"leet","code"};
    cout<<wordBreak_II("Leetcode",word)<<endl;
}