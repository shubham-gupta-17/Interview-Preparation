#include<bits/stdc++.h>
using namespace std;
vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n=nums.size();
        vector<int>ans;
        if(n==0) return ans;
        int *dp=new int[n];
        int *prev=new int[n];
        int size=0;
        int idx=-1;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++)
        { 
            dp[i]=1;
            prev[i]=-1;
            for(int j=0;j<i;j++)
            {
                 bool flag=(nums[i]%nums[j]);
                 if(!flag){
                     if(dp[i]<dp[j]+1){
                         dp[i]=dp[j]+1;
                         prev[i]=j;
                     }
                     
                 }
            }
            if(size<dp[i])
            {
                size=dp[i];
                idx=i;
            }
        }
 
        while(idx!=-1)
        {
            ans.push_back(nums[idx]);
            idx=prev[idx];
        }
        return ans;
}
int main()
{

	vector<int> a={3,4,16,8};
	vector<int>ans=largestDivisibleSubset(a);
	for(int b:ans) cout<<b<<" ";
	return 0;
}
