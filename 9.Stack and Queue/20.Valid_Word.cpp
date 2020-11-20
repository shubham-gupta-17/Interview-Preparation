#include <bits/stdc++.h>
using namespace std;
//leetcode 1003
bool find(string &s,string t){
        if(s==t) return true;
        if(t.length()>s.length()) return false;
        
        bool ans=false;
        for(int i=1;i<=t.length();i++){
            ans=ans || find(s,t.substr(0,i)+"abc"+t.substr(i,t.length()-i));
        }
        return ans;
}
bool isValid_1(string &s) {
    if(s=="" || s=="abc") return true;
    return  find(s,"abc");
}
int main()
{
  string s="abc";
  cout<<isValid_1(s);
  return 0;
}
