#include<bits/stdc++.h>
using namespace std;
// leetcode  260
vector<int> singleNumber(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int> map;
        vector<int> ans;
        for(int i=0;i<n;i++){
            map[nums[i]]+=1;
        }
        
        for(auto it:map){
            if(it.second==1) ans.push_back(it.first);
        }
        return ans;
       
}
int main()
{
    
}