#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
// Question link: https://www.geeksforgeeks.org/minimum-number-swaps-required-sort-array/
int main()
{
  int n;
  cin>>n;
  int a[n];
  for(int i=0;i<n;i++) cin>>a[i];
  pair<int,int> arr[n];
  for(int i=0;i<n;i++)
  {
    arr[i].first=a[i];
    arr[i].second=i;
  }
  sort(arr,arr+n);
  int j;
  int cycle=0;
  int ans=0;
  vector<bool> vis(n,false);
  for(int i=0;i<n;i++)
  {
     if(vis[i] || arr[i].second==i) continue;
     j=i;
     cycle=0;
     while(!vis[j])
     {
       vis[j]=true;
       j=arr[j].second;
       cycle++;
     }
     if(cycle>0) ans+=(cycle-1);
  }
  cout<<ans;
    //T.C= O(nlogn);
}
