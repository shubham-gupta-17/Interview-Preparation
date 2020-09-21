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
vector<int>parent;
vector<int>size;
int findParent(int u)
{
  if(parent[u]==u) return u;
  return parent[u]=findParent(parent[u]);
}

void merge(int p1,int p2)
{
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

}

int numIslands_Unionfind(vector<vector<char>>&grid)
{
  int n=graph.size();
  if(n==0) return 0;
  int m=graph[0].size();
  parent.resize(n*m,-1);
  size.resize(n*m,1);

  int count=0; // count of island
  for(int i=0;i<n;i++)
  {
    for(int j=0;j<m;j++){
      parent[i*m+j]=i*m+j;
      if(graph[i][j]=='1') count++;
    }
  }

  for(int i=0;i<n;i++)
  {
    for(int j=0;j<m;j++)
    {
      if(graph[i][j]=='1')
      {
         if(j+1<m && graph[i][j+1]=='1'){  // right call
           int p1=findParent(i*m+j);
           int p2=findParent(i*m+j+1);
           if(p1!=p2)
           {
             count--;
             merge(p1,p2);
           }
         }

         if(i+1<n && graph[i+1][j]=='1')  // down call
         {
            int p1=findParent(i*m+j);
            int p2=findParent((i+1)*m+j);
            if(p1!=p2)
            {
              count--;
              merge(p1,p2);
            }
         }

      }
    }
  }
  return count;

}
int main()
{
  vector<vector<char>> grid={{"1","1","0","0","0"},{"1","1","0","0","0"},{"0","0","1","0","0"},{"0","0","0","1","1"}};

  // Method 1: DFS
  cout<<numIslands_DFS(grid);

  //Method 2: union find
  cout<<numIslands_Unionfind(grid);
}
