#include<iostream>
#include<string>
using namespace std;
string find_next(string &a)
{

  int n=a.length();
  if(n==0) return "";
  int i1=0,i2=0;
  for(int i=n-1;i>=0;i--)   // find the 1st break point
    {
      if(a[i]<a[i+1]){
         i1=i;
         break;
       }
    }

  for(int i=n-1;i>=0;i--)
  {
     if(a[i]>a[i1])
     {
       i2=i;
       break;
     }
  }

  swap(a[i1],a[i2]);
  string ans="";
   for(int i=0;i<=i1;i++) ans+=a[i];
   for(int i=n-1;i>i1;i--) ans+=a[i];
   return ans;
}
int main()
{
  string a="1234";
  /*
     edge case 321 and 12

  */
   cout<<find_next(a);
   return 0;
}
