#include<bits/stdc++.h>
using namespace std;
int majorityElement(vector<int>& nums) {
        int n=nums.size();
        if(n==0) return 0;
        int majority=nums[0];
        int count=1;
        for(int i=1;i<n;i++){
            if(nums[i]!=majority){
                count--;
                if(count==0) {
                    majority=nums[i];
                    count++;
                }
            }
            else count++;
        }
        count=0;
        for(int i=0;i<n;i++){
            if(nums[i]==majority) count++;
        }
        
        return majority;
}
int main(){
    vector<int> nums={2,2,2,3,3,3,3,3};
    majorityElement(nums);
    return 0;
}