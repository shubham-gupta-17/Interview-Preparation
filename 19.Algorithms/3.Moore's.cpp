#include<bits/stdc++.h>
using namespace std;
int majorityElement(vector<int>& nums) {
        int n=nums.size();
        if(n==0) return 0;
        // set the 1st number as a candidate for majority element and set count=1
        int majority=nums[0];
        int count=1;
        for(int i=1;i<n;i++){

            // if current number is not equal to majority element then decrement the count
            if(nums[i]!=majority){
                count--;

                // if count==0 then set current element as a candidate for majority element and increment the count
                if(count==0) {
                    majority=nums[i];
                    count++;
                }
            }
            else count++;
        }
        count=0;

        // verify that the candidate for majority element is the actual majority element
        for(int i=0;i<n;i++){
            if(nums[i]==majority) count++;
        }
        
        if(count>(n/2))
        return majority;
        else return -1;
}
int main(){
    vector<int> nums={2,2,2,3,3,3,3,3};
    majorityElement(nums);
    return 0;
}