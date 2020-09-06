#include<bits/stdc++.h>
using namespace std;
class Node{
  public :
  int neighbour;
  int weight;
  Node(int v,int w)
  {
    neighbour=v;
    weight=w;
  }
};
void create(vector<vector<int>>&arr)
{
  arr.push_back({40, 0, 1});
  arr.push_back({10, 0, 3});
  arr.push_back({10, 1, 2});
  arr.push_back({10, 2, 3});
  arr.push_back({2, 3, 4});
  arr.push_back({2, 4, 5});
  arr.push_back({10, 4, 6});
  arr.push_back({8, 5, 6});

}
void display(vector<vector<Node>>&graph)
{
  for(int i=0;i<graph.size();i++)
  {
     cout<<i<<" ->";
    for(Node v:graph[i]) cout<<v.neighbour<<","<<v.weight<<"->";
    cout<<endl;
  }
  return ;
}

void create_graph(int w,int u,int v,vector<vector<Node>>&graph)
{
  Node node(v,w);
    graph[u].push_back(node);
}


int find_parent(int u,vector<int>&par)
{
   if(par[u]==u) return u;
   return par[u]=find_parent(par[u],par);

}

void merge(int u,int v,vector<int>&size,vector<int>&par)
{
    int p1=par[u];
    int p2=par[v];
    if(size[p1]>=size[p2])
    {
       // append v into u
       par[p2]=p1;
       size[p1]+=size[p2];

    }
    else {
      par[p1]=p2;
      size[p2]+=size[p1];
    }
    return ;
}
int main()
{
    vector<vector<int>> arr;
    int n=7;
    vector<int>size(n,1);
    vector<int>parent(n,-1);

    // make each vertex a parent of its own
    for(int i=0;i<n;i++) parent[i]=i;

    create(arr);

    // sort the vector on the basis of weight to make a MST
    sort(arr.begin(),arr.end(),[](vector<int> a,vector<int>b){
      return a[0]<b[0];
    });

    int min_weight=0;
    vector<vector<Node>>graph(n,vector<Node>());
    for(int i=0;i<arr.size();i++)
    {
        int u=arr[i][1];
        int v=arr[i][2];
        int p1=find_parent(u,parent);
        int p2=find_parent(v,parent);
        if(p1!=p2)
        {
          create_graph(arr[i][0],u,v,graph);
          merge(u,v,size,parent);
          min_weight+=arr[i][0];
        }
    }
    cout<<min_weight<<endl;
    display(graph);

    for(int i=0;i<n;i++) cout<<parent[i]<<" ";
    return 0;


}
