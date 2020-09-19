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
int numberOfSubarrays_opti(vector<int>& nums, int k) {
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

// Approach 3: O(n) time and O(k) space
int numberofSubarrays_3(vector<int>&nums,int k)
{
    int n=nums.size();
    if(n==0) return 0;

    deque<int> deq={-1};
    int ans=0;
    for(int i=0;i<n;i++)
    {
        if(nums[i]%2) deq.push_back(i);
        if(deq.size()>k+1) deq.pop_front();
        if(deq.size()==k+1) ans+=deq[1]-deq[0];

    }
    return ans;
}
int main()
{
    vector<int> arr={2,2,2,1,2,2,1,2,2,2};
    int k=2;
    cout<<numberOfSubarrays(arr,k)<<endl;
    cout<<numberOfSubarrays_opti(arr,k)<<endl;
}