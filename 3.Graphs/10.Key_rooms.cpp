#include<bits/stdc++.h>
using namespace std;
// leetcode 841
void visit(vector<vector<int>>&graph,vector<bool>&vis,int i)
{
       vis[i]=true;
       for(int vtx:graph[i])
       {
           if(!vis[vtx])
               visit(graph,vis,vtx);
       }
       return ;
}
bool canVisitAllRooms(vector<vector<int>>& rooms) {
       int n=rooms.size();
       if(n==0) return true;
       vector<bool>vis(n,false);
        visit(rooms,vis,0);
       for(int i=0;i<n;i++)
       {
           if(!vis[i]) return false;
       }
       return true;
}
int main()
{
  vector<vector<int>> graph={{1,3},{3,0,1},{2},{0}};
  cout<<canVisitAllRooms(graph);
  return 0;
}
