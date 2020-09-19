#include<bits/stdc++.h>
using namespace std;
// leetcode 80
int remove(vector<int>&nums,int k)
{
   int n=nums.size();
        if(n==0) return 0;
        int i=1;
        int j=1;
        int count=1;
        while(j<n)
        {
            if(nums[j]==nums[j-1])
            {
                count++;
                if(count<=k){
                    nums[i++]=nums[j];
                }
            }
            else{
                count=1;
                nums[i++]=nums[j];
            }
            j++;
        }
        return i;
}
int main()
{
    vector<int> arr={0,0,0,0,1,1,1,2,2,3,3,3};
    cout<<remove(arr,2);
    return 0;
}