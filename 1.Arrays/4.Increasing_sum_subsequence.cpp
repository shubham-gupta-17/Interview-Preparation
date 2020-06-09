#include <iostream>
#include<climits>
#include<algorithm>
using namespace std;
// Question link:https://www.geeksforgeeks.org/dynamic-programming-set-14-maximum-sum-increasing-subsequence/
int find_LIS(int n,int*a)
{
    int dp[n];
    int ans=INT_MIN;
    dp[0]=a[0];
    ans=a[0];
    for(int i=1;i<n;i++)
    {   
        dp[i]=a[i];
        for(int j=0;j<i;j++)
        {
            if(a[i]>a[j])
            {
                dp[i]=max(dp[i],dp[j]+a[i]);
            }
        }
        cout<<dp[i]<<" ";
        ans=max(ans,dp[i]);
    }
    return ans;
}
int main() {
	int t;
	cin>>t;
	while(t-->0)
	{
	    int n;
	    cin>>n;
	    int a[n];
	    for(int i=0;i<n;i++)
	    cin>>a[i];
	    cout<<find_LIS(n,a)<<endl;
	}
	return 0;
}