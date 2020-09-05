#include<bits/stdc++.h>
using namespace std;
// leetcode 886
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
bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
       int n=dislikes.size();
       if(n==0 || N==0) return true;
       vector<vector<int>> graph(N+1,vector<int>());
       for(int i=0;i<n;i++){
           graph[dislikes[i][0]].push_back(dislikes[i][1]);
           graph[dislikes[i][1]].push_back(dislikes[i][0]);
       }
       vector<int> vis(N+1,-1);
       bool ans=false;
       for(int i=1;i<=N;i++)
       {
           if(vis[i]==-1) ans=isbi(i,graph,vis);
           if(!ans) return false;
       }
       return true;
}
int main()
{
    int N=5;
    vector<vector<int>> graph={{1,2},{2,3},{3,4},{4,5},{1,5}};
    cout<<possibleBipartition(N,graph);
    return 0;
}
