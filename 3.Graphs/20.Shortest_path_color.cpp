#include <bits/stdc++.h>
using namespace std;
// leetcode 1129
// 1=red,0=blue

class Node{
    public :
    int u;
    int color;
    Node(int v,int c){
        u=v;
        color=c;
    }
};
vector<int> ans;
int find(vector<vector<Node>>&graph,int source,int destination)
{
     queue<Node> que;
     for(Node node:graph[source])
     {
         que.push(node);
     }
     int dis=1;
     while(!que.empty())
     {
         int size=que.size();
         while(size--)
         {
             Node node=que.front();
             que.pop();
             if(node.u==destination) return dis;
             for(Node root:graph[node.u])
             {
                 if(root.color==node.color)  continue;
                 que.push(root);

             }
         }
         dis++;
     }
    return -1;
}
vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& red, vector<vector<int>>& blue) {
    if(n==0) return ans;
    ans.push_back(0);
     vector<vector<Node>> graph(n,vector<Node>());
    for(int i=0;i<red.size();i++)
    {
        int u=red[i][0];
        int v=red[i][1];
        Node node(v,1);
        graph[u].push_back(node);
    }
    for(int i=0;i<blue.size();i++)
    {
        int u=blue[i][0];
        int v=blue[i][1];
        Node node(v,0);
        graph[u].push_back(node);
    }

    for(int i=1;i<n;i++)
    {
        ans.push_back(find(graph,0,i));
    }
    return ans;


}
int main()
{
    int n=3;
    vector<vector<int>>red={{0,1},{0,2}};
    vector<vector<int>>blue={{1,0}};

    shortestAlternatingPaths(n,red,blue);
    for(int a:ans)cout<<a<<" ";
    return 0;
}
