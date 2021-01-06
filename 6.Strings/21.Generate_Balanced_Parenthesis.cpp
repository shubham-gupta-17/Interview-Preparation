#include <bits/stdc++.h>
using namespace std;
//leetcode 22
  vector<string> dp;
    void find(string s,int n,int open,int closed)
    {   
        if(open>n || closed>n)
            return ;
        
        if(open==n && closed==n)
        {   
            //if(help(s))
            dp.push_back(s);
            return ;  
        }
        
        if(closed+1<=open)
        find(s+")",n,open,closed+1);
        if(open+1>=closed)
        find(s+"(",n,open+1,closed);
        
        return;
        
    }
    vector<string> generateParenthesis(int n) {
       string s;
        s="(";
        find(s,n,1,0);
        return dp;
    }
int main()
{
  int n;
  cin>>n;
  generateParenthesis(n);
  return 0;
}
