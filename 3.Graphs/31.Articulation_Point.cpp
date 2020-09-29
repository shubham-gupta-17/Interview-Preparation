#include<bits/stdc++.h>
using namespace std;
vector<vector<int>>ans;
vector<vector<int>>graph;
int *dis;
int *low;
int *par;
int *AP;
bool *vis;
int rootTime=0;
int countTime=0;
void dfs(int src){
    // set discovery and low time for each vertex
    dis[src]=low[src]=countTime++;
    vis[src]=true;

    for(int neigh:graph[src]){
        if(!vis[neigh])
        {
            if(par[src]==-1) rootTime++;
            par[neigh]=src;
            dfs(neigh);

            if(dis[src] <= low[neigh]) AP[src]++;
            if(dis[src] < low[neigh]) {
                ans.push_back({src,neigh});
                //cout<<"Remove edge between "<<src<<"and "<<neigh<<endl;
            }
            low[src]=min(low[neigh],low[src]);
        }
        else if(par[src]!=neigh) 
            low[src]=min(low[src],dis[neigh]);
    }
}
vector<vector<int>> connected_components(int n,vector<vector<int>>&edges)
{
     if(n==0) return ans;
     graph.resize(n,vector<int>());
     
     // create graph
     for(vector<int>arr:edges)
     {
         graph[arr[0]].push_back(arr[1]);
         graph[arr[1]].push_back(arr[0]);
     }
     dis=new int[n]();
     low=new int[n]();
     par=new int[n]();
     vis=new bool[n]();
     AP=new int[n]();
     for(int i=0;i<n;i++) par[i]=-1;

     dfs(0);

     if(rootTime==1) AP[0]--;

     //for(int i=0;i<n;i++)
     // if(AP[i]>0) cout<<"AP wrt "<<i<<"->"<<AP[i]<<endl;
    
     return ans;

}
int main(){
    int n;
    cin>>n;
    vector<vector<int>> edges={{0,1},{0,2},{0,3},{0,4},{0,5},{4,5}};
    connected_components(n,edges);
    return 0;

}