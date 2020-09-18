#include<bits/stdc++.h>
using namespace std;
 int *parent;
    int *size;
int find(int u)
{
        if(parent[u]==u) return u;
        return parent[u]=find(parent[u]);
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
        return ;
}
int makeConnected(int n, vector<vector<int>>& nums) {
        int m=nums.size();
        if(m==0 || n==0) return 0;
        parent=new int[n]();
        size=new int[n]();
        for(int i=0;i<n;i++)
        {
            parent[i]=i;
            size[i]=1;
        }
        
        int edge=0;
        int cycle=0;
        for(int i=0;i<m;i++)
        {
            int p1=find(nums[i][0]);
            int p2=find(nums[i][1]);
            if(p1!=p2){
                edge++;
                merge(p1,p2);
            }
            else if(p1==p2) cycle++;
        }
      
        cout<<cycle+edge;
      if(cycle+edge==n-1) return cycle;
      if(edge+cycle>n-1) return n-1-edge;
      return -1;
        
}
int main()
{
    vector<vector<int>> ar={{0,1},{0,2},{0,3},{1,2}};
    int n=4;
    cout<<makeConnected(n,ar);
    return 0;
}