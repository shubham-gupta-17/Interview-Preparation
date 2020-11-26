#include <bits./stdc++.h>
using namespace std;
// https://practice.geeksforgeeks.org/problems/maximum-sum-increasing-subsequence4749/1
int find(vector<int>ar,int sum,int n,int count,int idx){
	    
	    int ans=0;
	    for(int j=idx+1;j<n;j++){
	        if(arr[j]>arr[idx])
	           ans=max(ans,find(arr,sum+arr[j],n,count+1,j));
	    }
	    return ans+arr[idx];
	    
	}

	
	int maxSumIS(vector<int>arr, int n)  
	{  
	    int ans=0;
	    for(int i=0;i<n;i++)
	    ans=max(ans,find(arr,arr[i],n,1,i));
	    return ans;
	}  

//=================================================================
int maxSumIS(int arr[], int n)  
	{  
	     int *dp=new int[n]();
	     int ans=0;
	     for(int i=0;i<n;i++){
	         dp[i]=arr[i];
	         for(int j=0;j<i;j++){
	             if(arr[i]>arr[j])
	                dp[i]=max(dp[i],dp[j]+arr[i]);
	         }
	         ans=max(ans,dp[i]);
	   }
	   return ans;
	}  
int main()
{
    vector<int> ar = {4, 5, 0,2,3};
    cout << maxSumIS(ar,ar.size());
    return 0;
}