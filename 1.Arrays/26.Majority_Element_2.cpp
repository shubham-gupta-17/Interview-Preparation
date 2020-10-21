#include<bits/stdc++.h>
using namespace std;
 vector<int> majorityElement(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans;
        if(n==0) return ans;
        unordered_map<int,int> map;
        for(int i=0;i<n;i++)
            map[nums[i]]+=1;
        
        int k=floor(n/3);
        for(auto it:map){
            if(it.second>k) ans.push_back(it.first);
        }
        return ans;
    }
int main(){
    vector<int> nums={2,2,2,3,3,3,3,3};
    majorityElement(nums);
    return 0;
}