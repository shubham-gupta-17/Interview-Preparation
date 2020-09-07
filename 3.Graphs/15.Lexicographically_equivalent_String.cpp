#include<bits/stdc++.h>
using namespace std;
// leetcode 1061
char find_parent(char u,vector<char>&par)
{
  if(par[u-'a']==u) return u;
  return par[u-'a']=find_parent(par[u-'a'],par);
}

string equivalent_String(string &a,string &b,string &source)
{
  int n=a.length();
  vector<char> parent;
  for(int i=0;i<26;i++){
    parent.push_back('a'+i);
  }
  for(int i=0;i<n;i++)
  {
      char p1=find_parent(a[i],parent);
      char p2=find_parent(b[i],parent);
      char min_=(p1<p2)?p1:p2;
      parent[p1-'a']=min_;
      parent[p2-'a']=min_;
  }

  string ans="";
  for(int i=0;i<source.length();i++)
  {
    char ch=source[i];
    ans+=find_parent(ch,parent);
  }
  return ans;
}
int main()
{
   string a="leetcode";
   string b="programs";
   string source="sourcecode";
   cout<<equivalent_String(a,b,source);
   return 0;

}
