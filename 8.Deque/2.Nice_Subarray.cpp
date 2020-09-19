#include<bits/stdc++.h>
using namespace std;

//leetcode 1248

// Approach 1:O(n) time and O(1) space 
// Replace even with 0 and odd with 1 the question becomes find subarray with sum equal k
int numberOfSubarrays(vector<int>& nums, int k) {
        int n=nums.size();
        if(n==0) return 0;
        for(int i=0;i<n;i++)
        {
            if(nums[i]%2==0) nums[i]=0;
            else nums[i]=1;
        }
        unordered_map<int,int> map;
        map[0]=1;
        int sum=0;
        int count=0;
        for(int i=0;i<n;i++)
        {
            sum+=nums[i];
            if(map.find(sum-k)!=map.end()) count+=map[sum-k];
            map[sum]+=1;
        }
        
        return count;
}
// Approach 2: O(n) time and O(1) space
int numberOfSubarrays(vector<int>& nums, int k) {
       int n=nums.size();
       if(n==0) return 0;
       int i=0;
       int j=0;
       int ans=0;
       int prev=0;
        while(j<n)
        {
            if(nums[j++]%2==1) k--;
            if(k==0)
            {
                int even_count=0;
                while(i<n && (nums[i++]%2==0)) even_count++; // find difference btw i and 1st odd
                k++;
                prev=even_count+1;  // store previous no of subarrays
                ans+=prev;
            }
            else ans+=prev;
        }
        return ans;

}