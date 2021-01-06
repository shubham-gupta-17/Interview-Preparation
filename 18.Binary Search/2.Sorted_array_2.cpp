#include<bits/stdc++.h>
using namespace std;
//  leetcode 81 
bool search(vector<int>& nums, int target) {
        int start=0;
        int end=nums.size()-1;
        while(start<=end){
            int mid=(start+end)/2;
            int num=nums[mid];
            if(target==num) return true;
            
            
            // the corner case in case of multiple values
            if(nums[start]==num && num==nums[end]) {
                start++;
                end--;
            }
            // if there is rotation and mid lies in 1st part
            else if(num>nums[end]){
                if(target<num && target>=nums[start]) end=mid-1;
                else start=mid+1;
            }
            // if lies in 2nd part
            else if(num<=nums[start]){
                if(target>num && target<=nums[end]) start=mid+1;
                else end=mid-1;
            }
            // 3rd part is traditional binary search
            else{
                if(target > num) start=mid+1;
                else end=mid-1;
            }
        }
        return false;
    }
int main(){
    vector<int> num={5,6,7,8,9,1,2,3,4,5,5,5,5,5};
    cout<<search(nums,7);
    return 0;
}