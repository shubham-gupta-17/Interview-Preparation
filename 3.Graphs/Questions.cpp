#include<bits/stdc++.h>
using namespace std;20200803_204907
vector<vector<int>> graph(7,vector<int>());
int n=7;
void addEdge(int u,int v)
{
    graph[u].push_back(v);
    graph[v].push_back(u);
    return ;
}
int size(){
  return graph.size();
}
void create_graph()
{

  addEdge(0,3);
  addEdge(0,1);
  addEdge(1,2);
  addEdge(3,2);
  addEdge(3,4);
  addEdge(4,5);
  addEdge(4,6);
  addEdge(5,6);
  addEdge(0,6);
}

void dispay_graph()
{
  for(int i=0;i<n;i++)
  {
    cout<<i<<"->";
    for(int j=0;j<graph[i].size();j++)
      cout<<graph[i][j]<<", ";
    cout<<endl;
  }
  return ;
}

// it will search if there is a direct edge between these two vertexs
int search_edge(int u,int v)
{
  int i=u;
  for(int j=0;j<graph[u].size();j++)
  {
    if(graph[i][j]==v) return 1;
  }
  return -1;
}

// print all paths between source and destination
int all_path(int source,int destination,string path,vector<bool>&vis)
{
    if(source==destination){
      path+=to_string(source);
      cout<<path<<endl;
      return 1;
    }
    vis[source]=true;
    int count=0;
    for(int i:graph[source])
    {
        if(!vis[i]) count+=all_path(i,destination,path+to_string(source)+"->",vis);
    }
    vis[source]=false;
    return count;
}


int hamitonian_path(int source,int v,int count,string path,vector<bool>&vis)
{
    if(count==n-1){
      path+=to_string(v);
      // hamitonian_path:
      cout<<path<<endl;

      // hamitonian cycle : if there is a cycle between source and last vertex
      int original_source=source;
      int vertex=v;
      int cycle=search_edge(original_source,vertex);

      if(cycle==1) cout<<"There is a hamitonian cycle"<<endl;
      else cout<<"No hamitonian cycle"<<endl;
      return 1;
    }
    vis[v]=true;
    int ans=0;
    for(int i:graph[v])
    {
        if(!vis[i]) ans+=hamitonian_path(source,i,count+1,path+to_string(v)+"->",vis);
    }
    vis[v]=false;
    return ans;
}

int main()
{
    create_graph();
    //int n=size();
    vector<bool> vis(n,false);
    dispay_graph();
    cout<<all_path(0,6,"",vis);
    cout<<endl;
    vis.resize(n,false);
    cout<<hamitonian_path(0,0,0,"",vis);

}
