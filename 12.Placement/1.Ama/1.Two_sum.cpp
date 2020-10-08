#include<bits/stdc++.h>
using namespace std;
//leetcode 1
 vector<int> twoSum(vector<int>& nums, int target) {
        int n=nums.size();
        multimap<int,int> map;
        for(int i=0;i<n;i++)
            map.insert({nums[i],i});
        
        vector<int>ans(2,0);
        for(int i=0;i<n;i++)
        {
            auto it=map.find(target-nums[i]);
            if(it!=map.end() && it->second!=i)
            {
                ans[0]=i;
                ans[1]=it->second;
                return ans;
            }
        }
        return ans;
 }

// sort the numbers array and use binary search
 int find(vector<int>&arr,int start,int end,int target){
        
        while(start<=end){
          int mid=(start+end)/2;
          if(arr[mid]==target) return mid;
          else if(target < arr[mid]) end=mid-1;
          else start=mid+1;
        }
        return -1;
    }
    vector<int> twoSum(vector<int>& num, int target) {
        int n=num.size();
        vector<int>ans(2,0);
        for(int i=0;i<n;i++)
        {
            int remaining=target-num[i];
            int a=find(num,i+1,n-1,remaining);
            if(a!=-1){
                ans[0]=i+1;
                ans[1]=a+1;
                return ans;
            }
            
        }
        return ans;
    }
int main()
{

}