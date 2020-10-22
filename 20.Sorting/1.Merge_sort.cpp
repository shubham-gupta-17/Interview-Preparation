#include<bits/stdc++.h>
using namespace std;
vector<int> ans;
    void merge(vector<int>&arr,vector<int>&nums1,vector<int>&nums2){
        int i=0;
        int j=0;
        while(i<nums1.size() && j<nums2.size()){
            if(nums1[i]<nums2[j])
                arr.push_back(nums1[i++]);
            
            else arr.push_back(nums2[j++]);
        }
        
        while(j<nums2.size()) arr.push_back(nums2[j++]);
        while(i<nums1.size()) arr.push_back(nums1[i++]);
        
        return ;
    }
    void sort(vector<int> &nums,int start,int end,vector<int> &arr){
        
        if(start>end) return ;
        if(start==end){
            arr.push_back(nums[start]);
            return ;
        }
        int mid=(start+end)/2;
        
        vector<int> left;
        sort(nums,start,mid,left);
        vector<int> right;
        sort(nums,mid+1,end,right);
        
        
        merge(arr,left,right);
        return ;
    }
    vector<int> sortArray(vector<int>& nums) {
        sort(nums,0,nums.size()-1,ans);
        return ans;
    }
int main(){

}