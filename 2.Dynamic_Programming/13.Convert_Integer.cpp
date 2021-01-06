#include<bits/stdc++.h>
using namespace std;
// leetcode 397
 int integerReplacement(int n) {
        if(n==INT_MAX) return 32;
        if(n<=1) return 0;
        int *dp=new int[n+1]();
        dp[0]=dp[1]=0;
        for(int i=2;i<=n;i++){
            
            if(i%2==0) dp[i]=1+dp[i/2];
            else dp[i]= 1+ min(dp[i-1],1+dp[(i/2)+1]);
        }
        return dp[n];
}
//===========================================================================
int find(int n){
        if(n<=0) return 0;
        if(n==1) return 1;
        
        int count=0;
        if(n%2) count =min(find(n+1),find(n-1));
        else count=find(n/2);
        return count+1;
    }
    int integerReplacement(int n) {
        if(n==INT_MAX) return 32;
        return find(n)-1;
    }
int main(){
    integerReplacement(1000000);
    integerReplacement(1000000);
}