#include<bits/stdc++.h>
using namespace std;
int n,m;
//================================================================
void dfs(vector<vector<char>>&grid,int i,int j)
{
   if(i==n && j==m) return;
   if(grid[i][j]!='1') return ;
   grid[i][j]=2;

   if(j+1<m) dfs(grid,i,j+1);
   if(j-1>=0) dfs(grid,i,j-1);
   if(i+1<n) dfs(grid,i+1,j);
   if(i-1>=0) dfs(grid,i-1,j);
   return ;
}
int numIslands_DFS(vector<vector<char>>& grid) {
    n=grid.size();
   if(n==0) return 0;
    m=grid[0].size();
   int count=0;
   for(int i=0;i<n;i++)
   {
       for(int j=0;j<m;j++)
       {
           if(grid[i][j]=='1') {
               count++;
               dfs(grid,i,j);
           }
       }
   }
   return count;
}

//=============================================================================

int main()
{
  vector<vector<char>> grid={{"1","1","0","0","0"},{"1","1","0","0","0"},{"0","0","1","0","0"},{"0","0","0","1","1"}}

  // Method 1: DFS
  cout<<numIslands_DFS(grid);
}
