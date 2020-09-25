#include<bits/stdc++.h>
using namespace std;
vector<vector<int>>graph(7,vector<int*>());
int n=7;
void addEdge(int u ,int v)
{
  graph[u].push_back(v);
  graph[v].push_back(u);
}
void create_graph()
{

  addEdge(0,3);
  addEdge(0,1);
  addEdge(1,2);
  addEdge(3,2);
  //addEdge(3,4);
  addEdge(4,5);
  addEdge(4,6);
  addEdge(5,6);
}
bool find_cycle(int src, int i,int *vis,vector<int>&path)
{
    if(i==n) return false;
    if(i==src && vis[i]) return true;

    vis[i]=1;
    bool has_cycle=false;
    for(int v:graph[i])
       if(vis[v]==0) has_cycle= has_cycle || find_cycle(v,vis,path);

    if(has_cycle){
      path.push_back(i)
    }
}
int main()
{
     create_graph();

     int *vis=new int[n]();
     vector<vector<int>> path;
     for(int i=0;i<n;i++)
     {
        if(vis[i]==0){
          vector<int> cycle_path;
          find_cycle(i,i,vis,cycle);
          path.push_back(cycle);
        }
     }

     for(vector<int> ar:path)
     {
       for(int a: ar)
       cout<<a<<" ";
       cout<<endl;
     }
     return 0;

}
