 #include<bits/stdc++.h>
 using namespace std;
 // leetcode 35
 int searchInsert(vector<int>& nums, int target) {
        int n=nums.size();
        if(n==0) return -1;
        int start=0;
        int end=n-1;
        int idx=INT_MAX;
        if(target>nums[n-1]) return n;
        if(target<nums[0]) return 0;
        while(start<=end){
            int mid=(start+end)/2;
            if(nums[mid]==target) return mid;
            if(mid>0 && nums[mid]>target && nums[mid-1]<target) idx=min(idx,mid);
            if(nums[mid]>target) end=mid-1;
            else start=mid+1;
        }
        return idx==INT_MAX?0:idx;
}
int main(){
    vector<int> arr={1,3,4,5,6};
    searchInsert(arr,2);
    return 0;
}