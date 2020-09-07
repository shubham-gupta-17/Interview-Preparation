#include<bits/stdc++.h>
using namespace std;
int find_par(int u,vector<int>&par)
{
    if(par[u]==u) return u;
    return par[u]=find_par(par[u],par);
}
void merge(int u,int v,vector<int>&parent,vector<int>&size)
{
    int p1=parent[u];
    int p2=parent[v];
    if(size[p1]<size[p2])
    {
        parent[p1]=p2;
        size[p2]+=size[p1];
    }
    else
    {
        parent[p2]=p1;
        size[p1]+=size[p2];
    }
    return ;
}
vector<int> detect_cycle(vector<vector<int>>&arr,int a,int b)
{
    int n=arr.size();
    vector<int>size(n+1,1);
    vector<int>parent(n+1,-1);
    for(int i=0;i<=n;i++) parent[i]=i;

    for(vector<int> ar:arr)
    {
        if(ar[0]==a && ar[1]==b) continue;  // skip the edge with more than 1 parent
        if(find_par(ar[0],parent)!=find_par(ar[1],parent)) merge(ar[0],ar[1],parent,size);
        else return ar;
    }
    vector<int> skip;
    return skip;
}
vector<int> findRedundantDirectedConnection(vector<vector<int>>& arr) {
    int n=arr.size();
    vector<int>a;
    if(n==0) return a;
    int *indegree=new int[n+1]();  // calculate incoming edges on each Vertex
    int hasdegree=0;
    for(int i=0;i<n;i++)
    {
        indegree[arr[i][1]]++;
        if(indegree[arr[i][1]]>1){  // find vertex with more than 1 incoming edge
            hasdegree=arr[i][1];
            break;
        }
    }
    // if all has only one incoming edge then there will be a cycle and remove that cycle by simple dsu
    if(hasdegree==0) return detect_cycle(arr,-1,-1);

    // else there is a vertex with 2 parent and remove the last edge added on that vertex by running a loop from back
    for(int i=n-1;i>=0;i--)
    {
        if(arr[i][1]==hasdegree){
            vector<int> skip=detect_cycle(arr,arr[i][0],arr[i][1]);
            if(skip.size()==0) return arr[i];
        }
    }
    return a;
}
int main()
{
   vector<vector<int>> edge={{2,1},{3,1},{4,2},{1,4}};
   vector<int> cycle=findRedundantDirectedConnection(edge);
   cout<<cycle[0]<<" "<<cycle[1];
   return 0;
}
