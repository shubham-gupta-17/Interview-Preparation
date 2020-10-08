#include<bits/stdc++.h>
using namespace std;
//leetcode 15
vector<vector<int>> threeSum(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>ans;
        if(n==0 || n<3) return ans;
        
        sort(nums.begin(),nums.end());
        for(int i=0;i<n-2;i++)
        {
            if(i>0 && nums[i]==nums[i-1]) continue;
            
            int target=0-nums[i];
            int start=i+1;
            int end=n-1;
            while(start<end){
                int num= nums[start]+nums[end];
                if(num==target){
                    ans.push_back({nums[i],nums[start],nums[end]});
                    end--;
                    while(end>start && nums[end]==nums[end+1]) end--;
                }
                
                else if(num>target) end--;
                else start++;
            }
            
        }
        return ans;
}
int main()
{
    return 0;
}