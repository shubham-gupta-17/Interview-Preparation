#include<iostream>
#include<queue>
#include<vector>
using namespace std;
vector<vector<int *>>graph(7,vector<int*>());
int n=7;
void addEdge(int u ,int v)
{
  graph[u].push_back(new int(v));
  graph[v].push_back(new int(u));
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
}
void display_graph()
{
    for(int i=0;i<graph.size();i++)
    {
      cout<<i<<"->";
      for(int*a: graph[i])
         cout<<(*a)<<", ";
      cout<<endl;
    }
    return ;
}
int all_path( string path, vector<bool>&vis,int *src)
{
   int i=(*src);
    if(i==graph.size()-1){
      cout<<path+"->"+to_string(i)<<endl;
      return 1;
    }
    if(vis[i]) return 0;

    vis[i]=true;
    int count=0;
    for(int*a : graph[i]){
      count+=all_path(path+"->"+to_string(i),vis,a);
    }

    vis[i]=false;
    return count;
}
// it will search if there is a direct edge between these two vertexs
int search_edge(int u,int v)
{
  int i=u;
  for(int j=0;j<graph[u].size();j++)
  {
    if((*graph[i][j])==v) return 1;
  }
  return -1;
}

int hamitonian_path(int source,int v,int count,string path,vector<bool>&vis)
{
    if(count==n-1){
      path+=to_string(v);
      // hamitonian_path:
      cout<<path<<endl;

      // hamitonian cycle : if there is a cycle between source and last vertex
      int original_source=(source);
      int vertex=(v);
      int cycle=search_edge(original_source,vertex);

      if(cycle==1) cout<<"There is a hamitonian cycle"<<endl;
      else cout<<"No hamitonian cycle"<<endl;
      return 1;
    }
    vis[v]=true;
    int ans=0;
    for(int *i:graph[v])
    {
        if(!vis[(*i)]) ans+=hamitonian_path(source,(*i),count+1,path+to_string(v)+"->",vis);
    }
    vis[v]=false;
    return ans;
}

void dfs(string path,int i,vector<bool>&vis,int count)
{
    if(vis[i]) return ;
    if(i==n-1){
      path+=to_string(i);
      cout<<path<<endl;
      return ;
    }

    vis[i]=true;
    //cout<<i<<" ";
    for(int *n:graph[i])
    {
        if(!vis[(*n)]) dfs(path+to_string(i)+"->",(*n),vis,count+1);
    }
    vis[i]=false;
    return;
}

int bfs(int src,int destination)
{
  vector<bool>vis(n,false); // to prevent Cycle
  queue<int> que;
  que.push(src);
 //vis[src]=true;
  int level=0;
  while(!que.empty())
  {
    int size=que.size();
    while(size--)
    {
      int vertex=que.front();
      que.pop();

      if(vertex==destination) return level;
      
      if(vis[vertex]){
         cout<<"Cycle is present between: "<<src<<"and "<<vertex;
         continue;
       }

         vis[vertex]=true;
         for(int *v:graph[vertex]){
           if(!vis[*v])  que.push(*v);
         }

    }
    level++;
  }
  return -1;
}
int main()
{

    create_graph();
    display_graph();
    vector<bool>vis(7,false);
    int*src=new int(0);

    // all path from source to destination
    cout<<"ALL PATHS: "<<endl;
    cout<<all_path("",vis,src)<<endl;

    // hamitonian path
    vis.resize(7,false);
    cout<<"HAMITONIAN PATH:"<<endl;
    cout<<hamitonian_path((*src),(*src),0,"",vis)<<endl;

    //DFS : traverse the graph using recursion for all sources
    vis.resize(n,false);
    cout<<endl<<"DFS TRAVERSAL: "<<endl;
    for(int i=0;i<n;i++){
      if(!vis[i])
      dfs("",i,vis,0);
      cout<<endl;
    }

    //BFS: it will give minimum no of edges from src to destination
    int ans=bfs(0,6);
    cout<<ans;


}
