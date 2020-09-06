#include<bits/stdc++.h>
using namespace std;
int find_parent(int u,vector<int>&par)
{
   if(par[u]==u) return u;
   return par[u]=find_parent(par[u],par);

}

void merge(int u,int v,vector<int>&size,vector<int>&par)
{
    int p1=par[u];
    int p2=par[v];
    if (size[p1] < size[p2])
    {
        par[p1] = p2;
        size[p2] += size[p1];
    }
    else
    {
        par[p2] = p1;
        size[p1] += size[p2];
    }
    return ;
}
vector<int> findRedundantDirectedConnection(vector<vector<int>>& arr) {
    int n=arr.size();
    vector<int>size(n+1,1);
    vector<int>parent(n+1,-1);

    // make each vertex a parent of its own
    for(int i=0;i<=n;i++) parent[i]=i;


    for(int i=0;i<=n;i++)
    {
        int u=arr[i][0];
        int v=arr[i][1];
        int p1=find_parent(u,parent);
        int p2=find_parent(v,parent);
        if(p1!=p2)
        {
          merge(u,v,size,parent);
        }
        else return arr[i];
    }

         vector<int> a;
        return a;
}
int main()
{
    vector<vector<int>>arr={{1,2},{1,3},{2,3}};
    findRedundantDirectedConnection(arr);
    return 0;
    
}
