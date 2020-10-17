#include<bits/stdc++.h>
using namespace std;
// leetcode  137
int singleNumber(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int> map;
        int ele=0;
        for(int i=0;i<n;i++){
            map[nums[i]]+=1;
        }
        
        for(auto it:map){
            if(it.second==1) ele=it.first;
        }
       
         return ele;
            
    }
int main()
{

}