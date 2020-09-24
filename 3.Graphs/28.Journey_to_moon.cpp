#include<bits/stdc++.h>
using namespace std;
// find all GCC this can be done using Union find
// after that for all parent[i]==i multiply all size[i]with each other
vector<vector<int>>graph;
int n,m;
int *parent;
int *size;
int findParent(int u)
{
  if(parent[u]==u) return u;
  return parent[u]=findParent(parent[u]);
}
void merge(int p1,int p2)
{
    if(size[p1]>=size[p2])
    {
      parent[p2]=p1;
      size[p1]+=size[p2];
    }
    else{
      parent[p1]=p2;
      size[p2]+=size[p1];
    }
}
void union_find()
{
    parent=new int[n]();
    size=new int[n]();
    for(int i=0;i<n;i++)
    {
      parent[i]=i;
      size[i]=1;
    }
    for(vector<int>edge:graph)
    {
      int p1=findParent(edge[0]);
      int p2=findParent(edge[1]);
      if(p1!=p2)
        merge(p1,p2);
    }
}
int combinations_astronauts()
{
    int *astr=new int[n]();
    int sum=0;
     for(int i=0;i<n;i++)
     {
        if(parent[i]==i){
           astr[i]=size[i];
           sum+=size[i];
         }
     }

     int ans=0;
     for(int i=0;i<n;i++)
     {
          ans+=(sum-astr[i])*astr[i];
          sum-=astr[i];
     }
     return ans;
}
int main()
{

   // n=no of astronauts
   // m= edges or pairs of astronauts
   cin>>n>>m;
   for(int i=0;i<m;i++)
   {
     int a,b;
     cin>>a>>b;
     graph.push_back({a,b});
   }

   union_find();

   // now we have to find all the combinations of astronauts pair which we can send to moon
   cout<<combinations_astronauts();
}
