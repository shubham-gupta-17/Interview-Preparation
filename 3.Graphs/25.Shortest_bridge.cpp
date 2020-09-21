#include<bits/stdc++.h>
using namespace std;

// leetcode 934
 int n,m;
    void color(vector<vector<int>>&a,int i,int j)
    {
        if(i<0 || i>=n || j<0 || j>=m || a[i][j]!=1) return ;
        a[i][j]=2;
        color(a,i+1,j);
        color(a,i-1,j);
        color(a,i,j-1);
        color(a,i,j+1);
        return;
    }
    void paint(vector<vector<int>>&a)
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(a[i][j]==1){
                    color(a,i,j);
                    return ;   
                }
            }
        }
        return ;
    }
    bool find(vector<vector<int>>&a,int i,int j,int color)
    {
         if(i<0 || i>=n || j<0 || j>=m) return false;
         if(a[i][j]==0) a[i][j]=color+1;
         return a[i][j]==1;
    }
    bool check(vector<vector<int>>&a,int i,int j,int color)
    {
        return find(a,i+1,j,color) || find(a,i-1,j,color) || find(a,i,j+1,color) || find(a,i,j-1,color);
    }
    int shortestBridge(vector<vector<int>>& A) {
         n=A.size();
        if(n==0) return 0;
         m=A[0].size();
        paint(A);   //  paint one island with different color
        
        for(int color=2; ;color++)
        {
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<m;j++)
                {
                    if(A[i][j]==color && check(A,i,j,color)) return color-2;
                }
            }
        }
        return 1;
}
int main()
{
    vector<vector<int>> a={{1,1,1},{1,0,1},{0,1,0}};
    cout<<shortestBridge(a);
    return ;
}