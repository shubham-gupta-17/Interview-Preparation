#include<bits/stdc++.h>
using namespace std;
// leetcode 1162 : same as rotten oranges
int n;
int m;
int ans=-1;
int dir[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
void find(vector<vector<int>>&grid,int i,int j,int dis){

	if(i<0 || j<0 || i>=n || j>=n || (grid[i][j]<=dis && grid[i][j]!=0)) return ;
	grid[i][j]=dis;
	find(grid,i,j+1,dis+1);
	find(grid,i,j-1,dis+1);
	find(grid,i+1,j,dis+1);
	find(grid,i-1,j,dis+1);
	return;
}
int maxDistance(vector<vector<int>>& grid) {
	n=grid.size();
	if(n==0  || n==1) return -1;
	 m=grid[0].size();
	int count_zero=0;
	int count_one=0;
	for(int i=0;i<n;i++)
	{
	    for(int j=0;j<m;j++)
	    {
		if(grid[i][j]==1){
		    count_one++;
		    grid[i][j]=0;
		    find(grid,i,j,1);
		}
		else count_zero++;
	    }
	}

	for(int i=0;i<n;i++)
	{
	    for(int j=0;j<n;j++)
	    {   
		if(grid[i][j]>1)
		ans=max(ans,grid[i][j]-1);
	    }
	}
	return ans;
}
// ===================================================================================
  #define pp  pair<int,int>
    int dir[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
    int maxDistance_BFS(vector<vector<int>>& grid) {
       int  n=grid.size();
        if(n==0  || n==1) return -1;
        int  m=grid[0].size();
        int ans=0;
        queue<pp> que;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==1)
                    que.push({i,j});
            }
        }
        
        if(que.empty() || que.size()==n*n) return -1;
        while(!que.empty())
        {
            int size=que.size();
            while(size--)
            {
                pp top=que.front();
                que.pop();
                
                for(int d=0;d<4;d++)
                {
                    int r=top.first + dir[d][0];
                    int c=top.second + dir[d][1];
                    if(r>=0 && r<n && c>=0 && c<n && grid[r][c]==0)
                    {
                        grid[r][c]=1;
                        que.push({r,c});
                    }
                }
            }
            ans++;
            
        }
        
       return ans-1;
    }
int main()
{
	vector<vector<int>>grid={{1,0,0},{0,0,0},{1,0,1}};
	cout<<maxDistance(grid);
	cout<<maxDistance_BFS(grid); // very fast
	return 0;
}
