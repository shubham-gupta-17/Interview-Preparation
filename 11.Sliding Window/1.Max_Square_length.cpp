#include<bits/stdc++.h>
using namespace std;
// leetcode 192
 int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int n=mat.size();
        int m=mat[0].size();
        int k=threshold;
        int sum[n+1][m+1];
        
        
        for(int i=0;i<n;i++) sum[i][0]=0;
        for(int j=1;j<m;j++) sum[0][j]=0;
        
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
                sum[i][j]=mat[i-1][j-1] + sum[i-1][j] + sum[i][j-1] -sum[i-1][j-1];
        }
        
       
        int prev=0;
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=m;j++)
            {
                int len=prev+1;
                while(i+len<=n && j+len<=m && (sum[i+len][j+len] - sum[i+len][j] - sum[i][j+len]+sum[i][j] <=k) ){
                    prev=len;
                    len++;
                }
            }
        }
        return prev;
        
}
int main()
{

    
}