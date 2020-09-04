#include<bits/stdc++.h>
using namespace std;
//==================================================================
int n=7;
vector<vector<int>>graph(n,vector<int>());
void addEdge(int u ,int v)
{
  graph[u].push_back(v);
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
  // addEdge(0,1);
  // addEdge(1,2);
  // addEdge(2,3);
  // addEdge(3,4);
  // addEdge(4,1);
}

//================================================================
void topo_dfs(int src,vector<bool>&vis,vector<int>&topo)
{
    vis[src]=true;

    for(int i:graph[src])
    {
       if(!vis[i])
         topo_dfs(i,vis,topo);
    }

    topo.push_back(src);
}
void topological_sort()
{
    vector<int> topo;
    vector<bool> vis(n,false);
    for(int i=0;i<n;i++)
    {
      if(!vis[i]) topo_dfs(i,vis,topo);
    }

    for(int i=topo.size()-1;i>=0;i--)
    cout<<topo[i]<<" ";
}

//==================================================================
void find_incoming_edges(vector<int>&edge)
{
    for(int i=0;i<n;i++)
    {
      for(int v:graph[i])
        edge[v]++;
    }
    return ;
}

void find_source(vector<int>&edge,queue<int>&que)
{
  for(int i=0;i<n;i++)
  {
    if(edge[i]==0) que.push(i);
  }
  return ;
}

bool khans_BFS(vector<int>&ans,vector<int>&edge)
{
    // 1st find starting of queue i.e. search
    queue<int> que;
    find_source(edge,que);
    if(que.empty()) return false;

    while(!que.empty())
    {
        // remove the top
         int vtx=que.front();
         que.pop();
         // push that vtx in ans
         ans.push_back(vtx);

         for(int v:graph[vtx])
         {
           // nullifiy the effect of vtx on its neighbour and if count==0 push neighbour in queue
           if(--edge[v]==0) que.push(v);
         }

    }


    // if size of ans is not equal to n means there was a cycle due to which count was not equal to
    // 0 and no vertex was pushed in queue
    if(ans.size()!=n) return false;
    return true;
}

void khansAlgo()
{
   // find incoming edges Array
   vector<int> edge(n,0);
   find_incoming_edges(edge);

   // call bfs
   vector<int> ans;
   bool anss=khans_BFS(ans,edge);

   cout<<endl;
   if(!anss) cout<<"TOPOLOGICAL SORT IS NOT POSSIBLE";
   else {
        // print topo sort
        for(int a:ans) cout<<a<<" ";
   }


}
//============================================================================
bool topt_dfs_opti(int src,vector<bool>&vis,vector<bool>&mypath,vector<int>st)
{
    vis[src]=mypath[src]=true;

    bool cycle=false;
    for(int vtx:graph[src])
    {
       if(!vis[vtx] && !cycle)
        cycle=cycle||topo_dfs_opti(vtx,vis,mypath,st);

       if(mypath[vtx]) return true;
    }

    st.push_back(src);
    mypath[src]=false;
    return cycle;
}

// we can do this using one array also
// 1 for mypath
// 2 for visited
bool topo_sort_dfs_(int src,vector<int>&vis,vector<int>&st)
{
  if (vis[src]==1) return true;
  if (vis[src]==2) return false;

  vis[src]=1;
  bool cycle=false;
  for(int vtx:graph[src])
  {
      cycle=cycle||topo_sort_dfs_(vtx,vis,st);
      
  }
  vis[src]=2;
  st.push_back(src);
  return cycle;

}
vector<int> topological_sort_opti()
{
  // we are using this algo for cycle detection in directed graph and find the path in which cycle is present

    vector<bool>vis(n,false);
    vector<bool>mypath(n,false);
    vector<int> st;
    bool ans=false;
    for(int i=0;i<n;i++)
    {
      if(!vis[i]) ans=ans||topo_dfs_opti(i,vis,mypath,st);
    }

// if ans is true then there is no hamintonian Path and return empty Array
    if(ans){
      st.clear();
    }
    return st;

}

int main()
{
   create_graph();

   topological_sort();

   khansAlgo();

  vector<int>path = topological_sort_opti();

  return 0;
}
