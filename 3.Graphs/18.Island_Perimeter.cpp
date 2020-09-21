#include<bits/stdc++.h>
using namespace std;
// leetcode 200
int islandPerislandPerimeterimeter(vector<vector<int>>& grid) {
     n=grid.size();
     if(n==0) return 0;
     m=grid[0].size();
     int island=0;
     int neigh=0;
       for(int i=0;i<n;i++)
       {
           for(int j=0;j<m;j++)
           {
               if(grid[i][j]==1) {
                   island++;
                   if(j+1<m && grid[i][j+1]==1) neigh++;
                   if(i+1<n && grid[i+1][j]==1) neigh++;
               }
           }
       }
       return island*4-(2*neigh);
}
//========================================================================================================================
vector<vector<int>>dir={{0,1},{1,0},{0,-1},{-1,0}};
int count=0;
void find(vector<vector<int>>& grid,int r,int c)
{
   if(grid[r][c]==0)
       return ;
   int n=grid.size();
   int m=grid[0].size();
   for(int i=0;i<4;i++)
   {
       int row=r+dir[i][0];
       int col=c+dir[i][1];
       if(row <0 || row>=n ||col<0 || col>=m || grid[row][col]==0)
       {
           count++;
       }

       else if(grid[row][col]==1)
       {
           grid[row][col]=2;
           find(grid,row,col);
       }
   }
   return;
}
int islandPerimeter(vector<vector<int>>& grid) {

   for(int i=0;i<grid.size();i++)
   {
       for(int j=0;j<grid[0].size();j++)
       {
           if(grid[i][j]==1)
           {
               grid[i][j]=2;
               find(grid,i,j);
           }
       }
   }
   return count;
}
int main()
{
  vector<vector<char>> grid={{"1","1","0","0","0"},{"1","1","0","0","0"},{"0","0","1","0","0"},{"0","0","0","1","1"}};
  cout<<islandPerimeter(grid);
  cout<<islandPerimeter2(grid);
}
