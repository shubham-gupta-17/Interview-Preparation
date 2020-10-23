#include<bits/stdc++.h>
using namespace std;
// leetcode 75
 void sortColors(vector<int>& nums) {
        int start=0;
        int n=nums.size();
        int end=n-1;
        for(int i=0;i<=end;){
            if(nums[i]==0) swap(nums[start++],nums[i++]);
            else if(nums[i]==2) swap(nums[end--],nums[i]);
            else i++;
        }
        return ;
        
    }
int main(){
    vector<int> nums={2,2,2,2,2,0,0,0,1,1,1,1};
    cout<<findMaxConsecutiveOnes(nums);
    return 0;
}