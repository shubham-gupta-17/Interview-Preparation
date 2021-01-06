#include<bits/stdc++.h>
using namespace std;
// leetcode 238
vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int>ans(n,0);
        if(n==0) return ans;
        ans[0]=1;
        for(int i=1;i<n;i++){
            ans[i]=ans[i-1]*nums[i-1];
        }
        int right=1;
        for(int i=n-1;i>=0;i--){
            ans[i]*=right;
            right*=nums[i];
        }
        return ans;
}
int main(){
    vector<int> arr={1,2,3,4};
    productExceptSelf(arr);
    return 0;
}