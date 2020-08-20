#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;
// Quesiton link : https://www.geeksforgeeks.org/minimum-swaps-to-make-two-array-identical/
int main()
{
  int n;
  cin>>n;
  int a[n];
  int b[n];
  map<int,int> map;
  for(int i=0;i<n;i++) cin>>a[i];

  for(int i=0;i<n;i++) cin>>b[i];

  for(int i=0;i<n;i++)
   map.insert({b[i],i});

  vector<bool> vis(n,false);
  int ans=0;
  for(int i=0;i<n;i++)
  {
     if(vis[i] || a[i]==b[i]) continue;
     int j=i;
     int cycle=0;
     while(!vis[j])
     {
       vis[j]=true;
       j=map[a[j]];
       cycle++;
     }
     if(cycle>0) ans+=(cycle-1);

  }
  cout<<ans;
}
