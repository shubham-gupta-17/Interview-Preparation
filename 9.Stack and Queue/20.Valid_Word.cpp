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

//====================================================================================
bool isValid(string s) {
        for(auto it=s.find("abc");it!=string::npos;it=s.find("abc")) s.erase(it,3);
        return s.empty();
}

//======================================================================================
int main()
{
  string s="abc";
  cout<<isValid_1(s);
  cout<<isValid(s);
  return 0;
}
