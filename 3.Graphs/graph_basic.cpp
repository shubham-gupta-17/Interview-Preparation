#include<iostream>
#include<queue>
#include<vector>
using namespace std;

void addEdge(int u ,int v,vector<vector<int *>>&graph)
{
  graph[u].push_back(new int(v));
  graph[v].push_back(new int(u));
}
void create_graph(vector<vector<int *>>&graph)
{

  addEdge(0,3,graph);
  addEdge(0,1,graph);
  addEdge(1,2,graph);
  addEdge(3,2,graph);
  addEdge(3,4,graph);
  addEdge(4,5,graph);
  addEdge(4,6,graph);
  addEdge(5,6,graph);
}
void display_graph(vector<vector<int *>>&graph)
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
int all_path(vector<vector<int *>>&graph, string path, vector<bool>&vis,int *src)
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
      count+=all_path(graph,path+"->"+to_string(i),vis,a);
    }

    vis[i]=false;
    return count;
}

int hamitonian_path(vector<vector<int*>>&graph,vector<bool>&vis,int*src,string path,int ele)
{
   int i=(*src);
   if(ele==graph.size())
   {
    cout<<path+to_string(i)<<endl;
    return 1;
   }

   int count=0;
   vis[i]=true;
   for(int *a=graph[i])
   {
      count+=hamitonian_path(graph,vis,a,path+to_string(i)+"->",ele+1);

   }
   vis[i]=false;
   return count;

}
int main()
{
    vector<vector<int *>>graph(7,vector<int*>());
    create_graph(graph);
    display_graph(graph);
    vector<bool>vis(7,false);
    int*src=new int(0);

    // all path from source to destination
    cout<<all_path(graph,"",vis,src);

    // hamitonian path
    vis.resize(7,false);
    cout<<hamitonian_path(graph,vis,src,"");


}
