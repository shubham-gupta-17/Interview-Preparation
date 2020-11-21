#include<bits/stdc++.h>
using namespace std;
vector<string> ans;
int dir[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
char alph[4]={'R','L','D','U'};
void find_Path(int n,int m[][],int row,int col,string path){
    if(row==n-1 && col==n-1){
        if(m[row][col]==1) ans.push_back(path);
        return ;
    }
    
    m[row][col]=0;
    for(int d=0;d<4;d++){
        int i=row+dir[d][0];
        int j=col+dir[d][1];
        
        if(i>=0 && j>=0 && i<n && j<n && m[i][j]==1)
            find_Path(n,m,i,j,path+alph[d]);
    }
    m[row][col]=1;
    return ;
}
vector<string> printPath(int m[][], int n) {
    find_Path(n,m,0,0,"");
    return ans;
}
int main(){
	int n=4;
	int arr[n][n]={{1, 0, 0, 0},
                       {1, 1, 0, 1}, 
                       {1, 1, 0, 0},
                       {0, 1, 1, 1}};
	printPath(arr,n);
	return 0;
}