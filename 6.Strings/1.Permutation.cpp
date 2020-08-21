#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
vector<string> ans;
unordered_map<char,bool>map;
void find_permutation(string&s,int i,string s1)
{
  if(i==s.length())
  {
    ans.push_back(s1);
    return ;
  }

  for(int j=0;j<s.length();j++)
  {
    if(!map[s[j]])
    {
      map[s[j]]=true;
      find_permutation(s,i+1,s1+s[j]);
      map[s[j]]=false;
    }
  }
  return ;
}
int main()
{
  string s="123";
  find_permutation(s,0,"");
  for(string &a: ans)
    cout<<a<<endl;

  return 0;
}
