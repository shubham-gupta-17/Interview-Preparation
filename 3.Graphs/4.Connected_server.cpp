#include<bits/stdc++.h>
using namespace std;
int countServers(vector<vector<int>>& grid) {
       int n=grid.size();
       if(n==0) return 0;
       int m=grid[0].size();
       int *row=new int[n]();
       int *col=new int[m]();
       for(int i=0;i<n;i++)
       {
           for(int j=0;j<m;j++)
           {
               if(grid[i][j]==1){
                   row[i]++;
                   col[j]++;
               }
           }
       }

       int ans=0;
        for(int i=0;i<n;i++)
       {
           for(int j=0;j<m;j++)
           {
               if(grid[i][j]==1 && (col[j]>1 || row[i]>1)){
                   ans++;
               }
           }
       }
       return ans;
}
int main()
{
  vector<vector<int>> grid={{1,1,0,0},{0,0,1,0},{0,0,1,0},{0,0,0,1}};
  cout<<countServers(grid);
  return ;
}
