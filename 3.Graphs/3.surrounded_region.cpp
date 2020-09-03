#include<bits/stdc++.h>
using namespace std;
int n,m;
int dir[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
void find(vector<vector<char>>& board,int i,int j)
{

    board[i][j]='1';
    for(int d=0;d<4;d++)
    {
      int r=i+dir[d][0];
      int c=j+dir[d][1];
      if(r>=0 && c>=0 && r<n && c<m && board[r][c]=='O')
        find(board,r,c);
    }
    return;
}
void solve(vector<vector<char>>& board)
{
  // find all the cells connected with boundary once
   n=board.size();
  if(n==0) return ;
   m=board[0].size();

  for(int i=0;i<n;i++)
  {
     if(board[i][0]=='O') find(board,i,0);
     if(board[i][m-1]=='O') find(board,i,m-1);
  }

  for(int j=0;j<m;j++)
  {
    if(board[0][j]=='O') find(board,0,j);
    if(board[n-1][j]=='O') find(board,n-1,j);
  }

  // replace O with X and 1 with O
    for(int i=0;i<n;i++)
    {
      for(int j=0;j<m;j++)
      {
        if(board[i][j]=='1') board[i][j]='O';
        else if(board[i][j]=='O') board[i][j]='X';
      }
    }
    return;
}
int main()
{
    vector<vector<char>> board={{"X","X","X","X"},{"X","O","O","X"},{"X","X","O","X"},{"X","O","X","X"}};


}
