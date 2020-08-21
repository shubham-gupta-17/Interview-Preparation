#include<iostream>
#include<string>
using namespace std;
// leetcode : 1247
// algorithmcasts.com
int find_swap(string &s1,string &s2)
{
   int n=s1.length();
   if(n!=s2.length()) return -1;
   int xy=0;
   int yx=0;
   for(int i=0;i<n;i++)
   {
       if(s1[i]=='x' && s2[i]=='y') xy++;
       if(s1[i]=='y' && s2[i]=='x') yx++;
   }

   int ans= (xy/2) + (yx/2) +( xy%2) +(yx%2);
   return (xy+yx)%2==0 ? ans:-1;
}
int main()
{
  string s1="xxyyxyxyxx";
  string s2="xyyxyxxxyx";
  cout<<find_swap(s1,s2);
  return 0;
}
