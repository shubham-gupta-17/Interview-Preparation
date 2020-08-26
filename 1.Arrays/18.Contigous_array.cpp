#include<bits/stdc++.h>
using namespace std;
int find()
{
  int arr={1,0,0,1,1,1,0,0,0};
  int n=9;
  unordered_map<int,int> map;
  int count=0;
  int ans=0;
  for(int i=0;i<n;i++)
  {
      count=(arr[i]==0)?count-1:count+1;
      if(count==0) ans=max(ans,i+1);
      if(map.find(count)!=map.end())
        ans=max(ans,i-map[count]+1);
      else map[count]=i;
  }
  return ans;
}
int main()
{
  find();
   return 0;
}
