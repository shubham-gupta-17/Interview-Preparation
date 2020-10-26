#include<bits/stdc++.h>
using namespace std;
// leetcode 289
int n;
    int m;
    int  dir[8][2]={{0,1},{0,-1},{1,0},{-1,0},{1,1},{-1,1},{1,-1},{-1,-1}};
    int getValue(vector<vector<int>>&board,int i,int j){
        int count=0;
        for(int d=0;d<8;d++){
            int x=i+dir[d][0];
            int y=j+dir[d][1];
            if(x>=0 && y>=0 && x<n && y<m) 
                count+=board[x][y];
        }
        return count;
    }
    
    int setValue(int count,int value){
        int ans=0;
        if(value==1 && count<2) return 0;
        if(value==1 && (count==2 || count==3)) return 1;
        if(value==1 && count>3) return 0;
        if(value==0 && count==3) return 1;
        
        return value;
    }
    void gameOfLife(vector<vector<int>>& board) {
        n=board.size();
        m=board[0].size();
        vector<vector<int>> ans(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int get=getValue(board,i,j);
                ans[i][j]=setValue(get,board[i][j]);
            }
        }
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++)
                board[i][j]=ans[i][j];
        }
        
        return ;
    }

int main(){
    vector<vector<int>> board={{0,0,0},{1,1,1},{0,1,0}};
    gameOfLife(board);
    return 0;
}