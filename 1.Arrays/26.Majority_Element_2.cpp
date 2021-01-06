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
//============================================================================
 vector<int> majorityElement(vector<int>& nums) {
         int n=nums.size();
        vector<int> ans;
        if(n==0) return ans;
        int n1=-1;
        int n2=-1;
        int c1=0;
        int c2=0;
        for(int i=0;i<n;i++){
            
            if(n1==nums[i]) c1++;
            else if(n2==nums[i]) c2++;
            else if(c1==0){
                n1=nums[i];
                c1=1;
                
            }
            else if(c2==0){
                n2=nums[i];
                c2=1;
            }
            else{
                c1--;
                c2--;
            }
        }
        
        c1=0;
        c2=0;
        for(int i=0;i<n;i++){
            if(nums[i]==n1) c1++;
            else if(nums[i]==n2) c2++;
        }
        
        int k=floor(n/3);
        if(c1>k) ans.push_back(n1);
        if(c2>k) ans.push_back(n2);
        return ans;
        
    }
int main(){
    vector<int> nums={2,2,2,3,3,3,3,3};
    majorityElement(nums);
    return 0;
}