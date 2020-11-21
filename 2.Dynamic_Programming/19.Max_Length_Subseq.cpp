#include<bits/stdc++.h>
using namespace std;
// https://www.geeksforgeeks.org/maximum-length-subsequence-difference-adjacent-elements-either-0-1/
int find_Subseq(int n,int arr[]){
    int *dp=new int[n]();
    for(int i=0;i<n;i++) dp[i]=1;
    int ans=0;
    for(int i=1;i<n;i++){
        for(int j=0;j<i;j++){
            int diff=abs(arr[i]-arr[j]);
            if(diff==0 || diff==1) 
                dp[i]=max(dp[i],dp[j]+1);
        }
        ans=max(ans,dp[i]);
    }
    return ans;
}
int main(){
    int n;
    cin>>n;
	int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];

    cout<<find_Subseq(n, arr);
	return 0;
}