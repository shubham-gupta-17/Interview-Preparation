#include<bits/stdc++.h>
using namespace std;
int n,m;
// leetcode 463
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
int main()
{
  vector<vector<int>> grid={{"1","1","0","0","0"},{"1","1","0","0","0"},{"0","0","1","0","0"},{"0","0","0","1","1"}};
  cout<<maxAreaOfIsland(grid);
  return 0;
}
