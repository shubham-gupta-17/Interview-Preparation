#include<bits/stdc++.h>
using namespace std;
class Node{

  public :
  int neighbour;
  int weight;
  Node(int w,int v)
  {
    neighbour=v;
    weight=w;
  }
};
int n=7;
vector<vector<Node*>>arr(n,vector<Node*>());
void addEdge(int w,int u,int v)
{
  arr[u].push_back(new Node(w,v));
  arr[v].push_back(new Node(w,u));
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

// dijikstra
class dpair{
public:
  int source; // basically u (the vertex which points to v)
  // source(parent) is necesaary to create new graph
  int vertex; // v
  int weight=0;
  int wsf;

  dpair(int u,int v,int w,int ws)
  {
    source=u;
    vertex=v;
    weight=w;
    wsf=ws;

    /*
      bool operator<(dpair const&d)const
      {
        return this.wsf>d.wsf;
      }

    */
  }
};
struct compare{
  bool operator()(dpair const&d1,dpair const&d2){
      return d1.wsf>d2.wsf;
  }
};
vector<vector<Node*>> new_graph(n,vector<Node*>());
void dijikstra(int src)
{
    priority_queue<dpair , vector<dpair>, compare> que;
    vector<bool>vis(n,false);
    que.push(dpair(-1,src,0,0));
    while(!que.empty())
    {
        dpair top=que.top();
        que.pop();
        if(vis[top.vertex]) continue;

        vis[top.vertex]=true;
        if(top.source!=-1){
          new_graph[top.source].push_back(new Node(top.weight,top.vertex));
          new_graph[top.vertex].push_back(new Node(top.weight,top.source));
        }

        for(Node *node:arr[top.vertex])
        {
            int v=node->neighbour;
            int weight_path=top.wsf+node->weight;
            if(!vis[v])
               que.push(dpair(top.vertex,v,node->weight,weight_path));

        }
    }

}

void print_dijikstra()
{
    for(int i=0;i<n;i++)
    {
      cout<<i<<"= ";
        for(Node *node:new_graph[i])
          cout<<node->neighbour<<" "<<node->weight<<", ";
          cout<<endl;
    }
}
int main()
{
    create();
    dijikstra(0);
    print_dijikstra();
    return 0;

}
