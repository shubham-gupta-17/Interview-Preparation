#include<bits/stdc++.h>
using namespace std;
// leetcode 410
int getmin(vector<int>&arr){
    int min_time=INT_MIN;
    for(int num:arr)
        min_time=max(min_time,num);
    return min_time;
}
int getmax(vector<int>&arr){
    int sum=0;
    for(int num:arr)
        sum+=num;
    return sum;
}

int getPainters(vector<int>&nums,int maxTime){
    int sum=0;
    int painters=1;
    for(int num:nums){
        sum+=num;
        if(sum>maxTime){
            sum=num;
            painters++;
        }
    }
    return painters;
}
int splitArray(vector<int>& nums, int m) {
    int n=nums.size();
    int target=m;
    int start=getmin(nums);
    int end=getmax(nums);
    
    int time=INT_MAX;
    while(start<=end){
        int mid=(start+end)/2;
        
        int painters=getPainters(nums,mid);
        
        if(painters>target){
            start=mid+1;
        }
        else{
            time=mid;
            end=mid-1;
        }
    }
    return time;
}
int main(){
    int k=2;
    vector<int> arr={10, 10 ,10 ,10}; 
    cout<<splitArray(arr,k);
}