#include<isotream>
using namespace std;

//Resource link:https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/discuss/108870/most-consistent-ways-of-dealing-with-the-series-of-stock-problems
//Important discussion: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/discuss/54113/a-concise-dp-solution-in-java

int buy_sell_1(int *prices,int n) {
        int profit=0;
        for(int i=0;i<n-1;i++)
        {   int diff=0;
            int sell=0;
            for(int j=i+1;j<n;j++)
            {
                if(prices[i]<prices[j])
                    sell=max(sell,prices[j]);
            }
         diff=sell-prices[i];
         profit=max(diff,profit);
        }
        return profit;
 }
int buy_sell_1_optimise(vector<int>& prices) {
    int n=prices.size();
    if(n==0) return 0;
    int profit=0;
    int bought=prices[0];
    int diff=0;
 	/*
	At every index i find the min value till i-1 and find diff at that i if it is greater then profit than 
	update profit else if value is lesser than price[i] update your bought value
 	*/
    for(int i=1;i<n;i++)
    {
        if(prices[i]>bought)
        {
            diff=prices[i]-bought;
            profit=max(diff,profit);
        }
        else
            bought=prices[i];
    }
    return profit;
}
// kadane's approach
int buy_sell_1_kadane(int *a,int n)
{
	int profit=0;
	int *diff=new int[n]();
	for(int i=1;i<n;i++)
		diff[i]=a[i]-a[i-1];
	int sum=0;
	for(int i=0;i<n;i++)
	{
		sum+=diff[i];
		profit=max(profit,sum);
		if(sum<0) sum=0;
	}
	return profit;
}

// divide and conquer approach
class stock{
	int profit=0;
	int sell=0;  // the maximum at which i have sold my share
	int buy=0;  // the minimum value at which i have bought a share
};
 
 stock buy_sell_2_divide(int *a ,int n,int start,int end)
 {
 	stock arr;
 	if(start==end)
 	{	
 		arr.sell=arr.buy=a[start];
 		if(start==0) arr.sell=INT_MIN;
 		if(start==n-1) arr.buy=INT_MAX;
 		return arr;
 	}

 	int mid=(start+end)/2;
 	stock left=buy_sell_2_divide(a,n,start,mid);
 	stock right=buy_sell_2_divide(a,n,mid+1,end);

 	arr.profit=max(max(right.profit,left.profit),right.sell-left.buy);
 	arr.buy=min(left.buy,right.buy);
 	arr.sell=max(left.sell,right.sell);
 	return arr;

 }
//===============================================================================================================
int find(vector<int>&prices,int n,int i,int bought_price)
{
    if(i==n) return 0;
    int ans=0;
    if(bought_price>prices[i])  // change bought price i.e. buy a stock
        ans=find(prices,n,i+1,prices[i]);
    
    // sell a stock 
     ans=max(ans,prices[i]-bought_price);
     if(bought_price<prices[i] &&i+1<n)  
      ans+= find(prices,n,i+2,prices[i+1]);
    
    // don't do any operation
      ans=max(ans,find(prices,n,i+1,bought_price));
      return ans;
        
}
int buy_sell_2_recursion(int* prices,int n) {

    if(n==0 || n==1) return 0;
    return find(prices,n,1,prices[0]);
}

int find_map(int*prices,int n,int i,int bought_price,vector<unordered_map<int,int>>&map)
{
    if(i==n) return 0;
    if(map[i].find(bought_price)!=map[i].end()) return map[i][bought_price];
    int ans=0;
    if(bought_price>prices[i])  // change bought price i.e. buy a stock
        ans=find_map(prices,n,i+1,prices[i],map);
    
    // sell a stock 
     ans=max(ans,prices[i]-bought_price);
     if(bought_price<prices[i] &&i+1<n)  
      ans+= find_map(prices,n,i+2,prices[i+1],map);
    
    // don't do any operation
      ans=max(ans,find_map(prices,n,i+1,bought_price,map));
      map[i][bought_price]=ans;
      return ans;
        
}
int buy_sell_2_map(int *prices,int n) {
    if(n==0 || n==1) return 0;
    vector<unordered_map<int,int>>map(n+1);
    return find_map(prices,n,1,prices[0],map);
}

int buy_sell_2_peak_valley(int*prices,int n)
{

        int buy=0;
        int profit=0;
        int i=0;
        while(i<n)
        {
            buy=prices[i];
            while(i+1<n && prices[i+1]<=prices[i])
                i++;
            if(i<n) buy=prices[i++];
            while(i+1<n && prices[i+1]>=prices[i])
                i++;
            if(i<n) profit+=prices[i++]-buy;
        }
        return profit;
    
}
//=============================================================================================================
int buy_sell_3_dp(int*price,int n)
{
	 int n=price.size();
        if(n==0 || n==1) return 0;
        int k=2;
        int profit=0;
        vector<vector<int>>dp(k+1,vector<int>(n,0));
        for(int t=1;t<=k;t++)
        {
             int current_price=INT_MIN;
             current_price=max(current_price,dp[t-1][0]-price[0]);
            for(int i=1;i<n;i++)
            {   current_price=max(current_price,dp[t-1][i-1]-price[i-1]);
                dp[t][i]=max(dp[t][i-1],price[i]+current_price);
                profit=max(dp[t][i],profit);
            }
        }
        
        return profit;
}
//========================================================================================================================
int buy_sell_4_dp(int*price,int n)
{
	 
        if(n==0 || n==1) return 0;

// if K>=n/2 then it will have upto infinite transactions so it is similar to buy and sell 2 bcoz i can have atmost n/2 transactions
// else it is similar to buy and sell 3
         if(k>=(n/2)) return buy_sell_2_peak_valley(price,n);
        int profit=0;
        vector<vector<int>>dp(k+1,vector<int>(n,0));
        for(int t=1;t<=k;t++)
        {
             int current_price=INT_MIN;
             current_price=max(current_price,dp[t-1][0]-price[0]);
            for(int i=1;i<n;i++)
            {   
            	int x=(i-2>=0)?dp[t-1][i-2]:0;
                current_price=max(current_price,x-price[i-1]);
                dp[t][i]=max(dp[t][i-1],price[i]+current_price);
                profit=max(dp[t][i],profit);
            }
        }
        
        return profit;
}

int buy_sell_4_dp_space_opti(int*price,int n,int k)
{
	int n=price.size();
        if(n==0 || n==1) return 0;
         if(k>=(n/2)) return buy_sell_2_peak_valley(price);
        int profit=0;
       vector<int>dp(n,0);
        for(int t=1;t<=k;t++)
        {
             int current_price=INT_MIN;
            vector<int>dp1(n,0);
            for(int i=1;i<n;i++)
            {   current_price=max(current_price,dp[i-1]-price[i-1]);
                dp1[i]=max(dp1[i-1],price[i]+current_price);
                profit=max(dp1[i],profit);
            }
            for(int i=0;i<n;i++)
                dp[i]=dp1[i];
        }
        
        return profit;
}
//=========================================================================================================
int buy_and_sell_cooldown(int*price,int n)
{
	return buy_sell_2_map(price,n);
}
int buy_and_sell_cooldown_dp(int*prices,int n)
{
	  if(n==0 || n==1) return 0;
        
        int *dp0=new int[n]();
        int *dp1=new int[n]();
        dp1[0]=-prices[0];
        for(int i=1;i<n;i++)
        {   
            int pre=i-2>=0?dp0[i-2]:0;
            dp0[i]=max(dp0[i-1],dp1[i-1]+prices[i]);
            dp1[i]=max(dp1[i-1],pre-prices[i]);
        }
        
        return dp0[n-1];
}
//=============================================================================================
int buy_sell_5_opti(int*prices,int n)
{

        if(n==0 || n==1) return 0;
        
       
        int dp0=0;
        int dp1=-prices[0];
        int dp0_pre=0;
        for(int i=1;i<n;i++)
        {   
            dp0_pre=dp0;
            dp0=max(dp0,dp1+prices[i]-fee);
            dp1=max(dp1,dp0_pre-prices[i]);
        }
        return dp0;
    
}
int buy_sell_5_dp(int*prices,int n)
{
	if(n==0 || n==1) return 0;
        
        int *dp0=new int[n]();  // maximum profit after selling stock 
        int *dp1=new int[n]();  // maximum profit after buying a stock
        dp1[0]=-prices[0];
        for(int i=1;i<n;i++)
        {
            dp0[i]=max(dp0[i-1],dp1[i-1]+prices[i]-fee);
            dp1[i]=max(dp1[i-1],dp0[i-1]-prices[i]);
        }
      
        return dp0[n-1];
}
int main()
{
	int a[]={7,1,5,3,6,4};
	int n=6;
	//1.leetcode 121
	cout<<buy_sell_1(a,n);
	cout<<buy_sell_1_optimise(a,n);
	cout<<buy_sell_1_kadane(a,n);
	cout<<buy_sell_2_divide(a,n,0,n-1);  // divide and conquer approach

	//leetcode 122
	cout<<buy_sell_2_recursion(a,n); // but this will probably give TLE
	cout<<buy_sell_2_map(a,n);  // it will also give TLE
	cout<<buy_sell_2_peak_valley(a,n); // this algo is also know as peak valley algorithm

	// leetcode 123
	cout<<buy_sell_3_dp(a,n);

	//leetcode 188
	cout<<buy_sell_4_dp(a,n,3);
	cout<<buy_sell_4_dp_space_opti(a,n,3);

	//leetcode 309
	cout<<buy_and_sell_cooldown(a,n);
	cout<<buy_and_sell_cooldown_dp(a,n);

	//leetcode 714
	cout<<buy_sell_5_dp(a,n);
	cout<<buy_sell_5_opti(a,n);

}