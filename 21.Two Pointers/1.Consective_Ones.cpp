#include<bits/stdc++.h>
using namespace std;
// leetcode 485
int findMaxConsecutiveOnes(vector<int>& nums) {
        int n=nums.size();
        int start=0;
        int end=0;
        int ans=INT_MIN;
        int i=0;
        while(end<n && start<n){
            while(end<n && nums[end]==1) end++; 
            ans=max(ans,end-start);
            cout<<start<<" "<<end<<endl;
            start=end;
             while(start<n && nums[start]==0){
                start++;
                 end++;
             }
        }
        
        return ans;
}
int main(){
    vector<int> nums={0,0,0,1,1,1,1,1,1,1};
    cout<<findMaxConsecutiveOnes(nums);
    return 0;
}