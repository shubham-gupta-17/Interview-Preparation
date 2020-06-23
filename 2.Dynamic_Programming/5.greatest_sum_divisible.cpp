#include<isotream>
#include<vector>
#include<climits>
using namespace std;
 int ans=0;
void find(vector<int>&nums,int n,int sum,int i)
{
    if(i==n) return ;
    if((sum+nums[i])%3==0) ans=max(ans,sum+nums[i]);
    find(nums,n,sum+nums[i],i+1);
    find(nums,n,sum,i+1);
    return ;
}
int dp(vector<int>&nums)
{
	 vector<vector<int>>dp;
        vector<int>a;
        a.push_back(nums[0]);
        dp.push_back(a);
        ans=(nums[0]%3==0)?nums[0]:0;
        for(int i=1;i<n;i++)
        {
            vector<int>arr;
            int sum=(nums[i]%3==0)?nums[i]:0; 
            int size=dp[i-1].size();
            for(int j=0;j<size;j++)
            {
               int summ=dp[i-1][j]+nums[i];
               if(summ%3==0)
                   sum=max(sum,summ);
                arr.push_back(summ);
                arr.push_back(dp[i-1][j]);
            }
            arr.push_back(nums[i]);
            dp.push_back(arr);
            ans=max(ans,sum);
        }
        return ans;
}

//======================================================================================================================
int dp[100000][3];
int find(vector<int>&nums,int i,int k,int mod)
{
    if(i==nums.size())
        return dp[i][mod]= 0;
    if(dp[i][mod]!=-1) return dp[i][mod];
    int ans=0;
      if((mod+find(nums,i+1,k,mod))%k==0)
          ans=max(ans,dp[i+1][mod]);
    
      if((mod+nums[i]+find(nums,i+1,k,(mod+nums[i])%k))%k==0)
        ans=max(ans,nums[i]+dp[i+1][(mod+nums[i])%k]);
        
    return dp[i][mod]=ans;
}
int maxSumDivThree(vector<int>& nums) {
    int n=nums.size();
    int k=3;
    memset(dp, 0, sizeof(dp)); 
    return find(nums,0,3,0);
}


int bottom_up_dp(vector<int>&nums,int k)
{
    int n=nums.size();
    int dp[n+1][k]={0};
    for(int i=n-1;i>=0;i--)
    {   
        for(int j=0;j<k;j++)
        {   
            int mod=dp[i+1][j];
            dp[i][(mod+nums[i])%k]=max(dp[i][(mod+nums[i])%k],nums[i]+mod);
            dp[i][(mod)%k]=max(dp[i][(mod)%k],mod);
           
        }
    }
   
    return dp[0][0];
}


int top_down_dp(vector<int>&nums,int k)
{
    int n=nums.size();
    int dp[n+1][k]={0};
     for(int i=1;i<=n;i++)
        {   
            for(int j=0;j<k;j++)
            {   
                int mod=dp[i-1][j];
                dp[i][(mod+nums[i-1])%k]=max(dp[i][(mod+nums[i-1])%k],nums[i-1]+mod);
                dp[i][(mod)%k]=max(dp[i][(mod)%k],mod);
               
            }
        }
        return dp[n][0];

}
int main()
{
	 vector<int>nums={3,6,5,1,8};
	 int n=nums.size();
     if(n==0) return 0;
     // 1st approach
     find(nums,n,0,0);
     cout<<ans<<endl;
     //2nd approach
     cout<<dp(nums)<<endl;
     // 3rd approach memoisation
     cout<<maxSumDivThree(nums)<<endl;
     //4th : bottom up dp
     cout<<bottom_up_dp(nums,3);
     //5th approach
     cout<<top_down_dp(nums,3);
     return 0;
     
}