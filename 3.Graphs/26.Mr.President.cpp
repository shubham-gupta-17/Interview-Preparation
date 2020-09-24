#include<bits/stdc++.h>
using namespace std;
// int fastSpeed = []() {
//     std::ios::sync_with_stdio(false);
//     std::cin.tie(nullptr);
//     std::cout.tie(nullptr);
// }();
vector<vector<int>> arr;
int n,m,k;
// take input
void input()
{

   cin>>n>>m>>k;
   // n= cities , m=roads, k= min maintenance cost
   for(int i=0;i<m;i++)
    {
      int a,b,c;
      // a=u, b=v, c=cost of road btw a and b
      cin>>a>>b>>c;
      arr.push_back({a,b,c});
    }


}

int *parent;
int *size;
int findParent(int u)
{
  if(parent[u]==u) return u;
  return parent[u]=findParent(parent[u]);
}
void merge(int p1,int p2)
{
    if(size[p1]>size[p2])
    {
      parent[p2]=p1;
      size[p1]+=size[p2];
    }
    else{
      parent[p1]=p2;
      size[p2]+=size[p1];
    }
}
// since the total cost of maintenance shoul be min. so we will build MST hence use krushkal
vector<vector<int>>graph;
int  buil_MST_find_cost()
{
    //sort the edges in increasing order of cost
    sort(arr.begin(), arr.end(),[](vector<int> a, vector<int> b) {
        return a[2] < b[2];
    });

     parent=new int[n]();
     size=new int[n]();
    for(int i=0;i<n;i++)
    {
        parent[i]=i;
        size[i]=1;
    }

    for(int i=0;i<n;i++)
    {
        int p1=findParent(arr[i][0]);
        int p2=findParent(arr[i][1]);
        if(p1!=p2)
        {
           merge(p1,p2);
           graph.push_back(arr[i]);
        }
    }


    // find wether all cities are connected with each other or not
    // if gcc >1 then building roads is not possible
    int gcc=0;
    for(int i=0;i<n;i++){
      if(parent[i]==i) gcc++;
    }
    if(gcc>1) return -1;




    // think greedy i.e. we will start converting roads to super roads first
    // that have highest cost of maintenance and will go till amount is not less than k
    // or cities get finish

    // so sort graph in decreasing order so higher cost are at top
    sort(graph.begin(),graph.end(),[](vector<int> a,vector<int> b){
      return a[2]>b[2];
    });

    // find total amount for maintenance
    int amount=0;
    for(int i=0;i<graph.size();i++)
      amount+=graph[i][2];

    int roads=0;
    for(int i=0;i<graph.size();i++)
    {
      if(amount<k) return roads;
      amount-=graph[i][2] + 1;
      roads++;
    }

    return amount<k ? roads:-1;


}
int main()
{
   input();
   cout<<buil_MST_find_cost();
   return 0;
}
