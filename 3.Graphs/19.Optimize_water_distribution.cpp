#include<bits/stdc++.h>
using namespace std;
// leetcode  1168
// basically we have to find out MST
vector<int>parent;
vector<int>size;
int find_parent(int u)
{
  if(parent[u]==u) return u;
  return parent[u]=find_parent(parent[u]);
}

void merge(int p1,int p2)
{
    if(size[p1]>size[p2])
    {
      parent[p2]=p1;
      size[p1]+=size[p2];
    }

    else {
      parent[p1]=p2;
      size[p2]+=size[p1];
    }
    return;
}
int optimize_cost(int n,int*wells,vector<vector<int>>&pipes)
{
   parent.resize(n+1,0);
   size.resize(n+1,1);
   vector<vector<int>>edges;
   for(int i=0;i<n;i++)
   {
     parent[i+1]=i+1;
     edges.push_back({0,i+1,wells[i]});
   }

   for(vector<int> arr:pipes)
      edges.push_back(arr);

   sort(edges.begin(),edges.end(),[](vector<int>a,vector<int>b){
      return a[2]<b[2];
   });

  int ans=0;
   for(vector<int> node:edges)
   {
      int p1=find_parent(node[0]);
      int p2=find_parent(node[1]);
      if(p1!=p2)
      {
        merge(p1,p2);
        ans+=node[2];
      }
   }

    return ans;
}
int main()
{
  int n=3;
  int wells[3]={1,2,2};
  vector<vector<int>> pipes={{1,2,1},{2,3,1}};
  cout<<optimize_cost(n,wells,pipes);
  return 0;

}
