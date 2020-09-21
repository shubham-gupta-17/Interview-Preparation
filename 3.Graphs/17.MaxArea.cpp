#include<bits/stdc++.h>
using namespace std;
int n,m;
// leetcode 695
int dfs(vector<vector<int>>&grid,int i,int j)
{
   if(grid[i][j]!=1) return 0;
   if(i==n && j==m) return grid[i][j];

   grid[i][j]=2;
   int ans=0;
   if(j+1<m) ans+=dfs(grid,i,j+1);
   if(j-1>=0) ans+=dfs(grid,i,j-1);
   if(i+1<n) ans+=dfs(grid,i+1,j);
   if(i-1>=0) ans+=dfs(grid,i-1,j);
   return ans+1;
}
int maxAreaOfIsland(vector<vector<int>>& grid) {
    n=grid.size();
   if(n==0) return 0;
    m=grid[0].size();
   int ans=0;
   for(int i=0;i<n;i++)
   {
       for(int j=0;j<m;j++)
       {
           if(grid[i][j]==1) {
               ans=max(ans,dfs(grid,i,j));
           }
       }
   }
   return ans;
}

//====================================================================================
// Approach 2: union find
vector<int>parent;
vector<int>size;
int n,m;
int par(int u)
{
  if(parent[u]==u) return u;
  return parent[u]=par(parent[u]);
}

void merge(int p1,int p2)
{
   if(size[p1]<size[p2])
   {
     parent[p1]=p2;
     size[p2]+=size[p1];
   }
   else{
     parent[p2]=p1;
     size[p1]+=size[p2];
   }
   return ;
}
int max_area_union(vector<vector<int>>&grid)
{
    n=grid.size();
    if(n==0) return 0;
    m=grid[0].size();
    parent.resize(n*m,-1);
    size.resize(n*m,1);
    // set parent of all
    for(int i=0;i<n;i++)
    {
      for(int j=0;j<m;j++)
        parent[i*m+j]=i*m+j;
    }

    // union findParent
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
          if(grid[i][j]==1){
            int p1=par(i*m+j);
            if(i+1<n && grid[i+1][j]==1)
            {
                int p2=par((i+1)*m+j);
                if(p1!=p2)
                  merge(p1,p2);
            }

            if(j+1<m && grid[i][j+1]==1)
            {
              int p2=par(i*m+(j+1));
              if(p1!=p2) merge(p1,p2);
            }

          }
        }
    }

  int max_size=0;
    for(int i=0;i<(n*m);i++)
    {
        int r=(i/m);
        int c=(i%m);
      if(parent[i]==i && grid[r][c]==1){
      max_size=max(size[i],max_size);

      }
    }
    return max_size;
}
int main()
{
  vector<vector<char>> grid={{0,0,1,0,0,0,0,1,0,0,0,0,0},
 {0,0,0,0,0,0,0,1,1,1,0,0,0},
 {0,1,1,0,1,0,0,0,0,0,0,0,0},
 {0,1,0,0,1,1,0,0,1,0,1,0,0},
 {0,1,0,0,1,1,0,0,1,1,1,0,0},
 {0,0,0,0,0,0,0,0,0,0,1,0,0},
 {0,0,0,0,0,0,0,1,1,1,0,0,0},
 {0,0,0,0,0,0,0,1,1,0,0,0,0}};
  cout<<maxAreaOfIsland(grid);
  return 0;
}
