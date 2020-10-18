#include<bits/stdc++.h>
using namespace std;
// leetcode 477
int hammingDistance2(int x,int y){
int dist=0;
int n=(x^y);
while(n>0){
    n&=(n-1);
    dist++;
}
return dist;
}
int totalHammingDistance1(vector<int>& nums) {
    int n=nums.size();
    if(n==0) return 0;
    int sum=0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            sum+=hammingDistance2(nums[i],nums[j]);
        }
    }
    return sum;
}
//=====================================================================================
int totalHammingDistance2(vector<int>&nums){
    
}
int main(){
    vector<int> nums={4,2,5,6,10};
    cout<<totalHammingDistance1(nums);
}