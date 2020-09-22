#include<bits/stdc++.h>
using namespace std;

class Node{

    public:
    int neighbour;
    int weight;
    Node(int v,int w)
    {
        neighbour=v;
        weight=w;
    }
};
vector<vector<Node>>arr(7,vector<Node>());
int n=7;
void addEdge(int w,int u,int v)
{
  arr[u].push_back( Node(v,w));
  arr[v].push_back(Node(u,w));
}
void create()
{
  addEdge(10,0,1);
  addEdge(10,0,3);
  addEdge(10,1,2);
  addEdge(40,2,3);
  addEdge(2,3,4);
  addEdge(2,4,5);
  addEdge(3,4,6);
  addEdge(8,5,6);
}
class dpair{

    public :
    int u;
    int v;
    int w;
    dpair(int u,int v,int w){
        this->u=u;
        this->v=v;
        this->w=w;
    }
};
struct compare{

    bool operator()(dpair const&d1,dpair const&d2)
    {
        return d1.w>d2.w;
    }
};
vector<vector<Node>> graph(n,vector<Node>());
void Prims(int src)
{
    priority_queue<dpair, vector<dpair>, compare> que;
    que.push(dpair(-1,0,0));
    vector<bool>vis(n,false);
    int ans=0;
    while(!que.empty())
    {
        dpair top=que.top();
        que.pop();
        int u=top.v;
        if(vis[u]) continue;
        vis[u]=true;
        if(top.u!=-1) graph[top.u].push_back(Node(top.v,top.w));
        ans+=top.w;
        for(Node node:arr[u])
        {
            if(!vis[node.neighbour]){
                que.push(dpair(u,node.neighbour,node.weight));
            }
        }

    }
    cout<<ans;
}
void display()
{
    for(int i=0;i<n;i++)
    {
        cout<<i<<" ->";
        for(Node node:graph[i])
            cout<<node.neighbour<<" "<<node.weight<<", ";
        cout<<endl;
    }
}
int main(){

    create();
    Prims(0);
    display();
    return 0;
}
