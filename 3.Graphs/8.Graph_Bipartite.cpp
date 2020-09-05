#include<bits/stdc++.h>
using namespace std;
// leetcode 785
class pairr{
     public :
       int vtx;
       int color;
       pairr(){

       }
       pairr(int u,int c){
           vtx=u;
           color=c;
       }
};
bool isbi(int i,vector<vector<int>>& graph,vector<int>&vis) {
       queue<pairr> que;
       pairr p1(i,0);
       que.push(p1);
       while(!que.empty())
       {
           pairr p=que.front();
           que.pop();
           // if(vis[p.vtx]!=-1)
           // {
           //     if(vis[p.vtx]!=p.color) return false;
           //     else continue;
           // }
           vis[p.vtx]=p.color;

           for(int i:graph[p.vtx])
           {
               if(vis[i]==-1) {
                   pairr p2(i,1-p.color);
                   vis[i]=1-p.color;
                   que.push(p2);
               }
               else if(vis[i]!=-1){
                   if(vis[i]!=1-p.color)
                       return false;
               }
           }

       }
       return true;
}
bool isBipartite(vector<vector<int>>& graph) {
       int n=graph.size();
       if(n==0)return true;
       vector<int> color(n,-1);
       bool ans=false;
       for(int i=0;i<n;i++)
       {
           if(color[i]==-1)
               ans= isbi(i,graph,color);
           if(!ans) return false;
       }
       return true;
}
int main()
{
    vector<vector<int>> graph={{1,3},{0,2},{1,3},{0,2}};
    cout<<isBipartite(graph);
    return 0;
}
