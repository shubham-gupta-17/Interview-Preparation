#include<bits/stdc++.h>
using namespace std;
// leetcode 477
int hammingDistance2(int x,int y){
int dist=0;
int n=(x^y);  // xor will set the bit of n which is different in both x and y
while(n>0){
    n&=(n-1);  // count no of set bits in n
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
         int n=nums.size();
        if(n<2) return 0;
        int *a=new int[2]();
        int count=0;
        int ans=0;
        while(1){
            a[0]=0;
            a[1]=0;
            count=0;
            for(int i=0;i<n;i++){
                if(nums[i]==0) count++;
                a[nums[i]%2]++;
                nums[i]>>=1;
            }
            ans+=a[0]*a[1];
             if(count==n) return ans;
        }
        return ans;
}
int main(){
    vector<int> nums={4,2,5,6,10};
    cout<<totalHammingDistance1(nums);
}