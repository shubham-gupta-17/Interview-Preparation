#include <bits/stdc++.h>
using namespace std;
// leetcode 179
 string largestNumber(vector<int>& nums) {
        int n=nums.size();
        string ans="";
        if(n==0) return ans;
        if(n==1) return to_string(nums[0]);
        for(int i=0;i<n-1;i++)
        {
           
            for(int j=i+1;j<n;j++)
            {
                 string a=to_string(nums[i])+to_string(nums[j]);
                 string b=to_string(nums[j])+to_string(nums[i]);
                 if(a<b)
                     swap(nums[i],nums[j]);
            }
        }
        if(nums[0]==0) return "0";
        for(int i=0;i<n;i++){
            
            ans+=to_string(nums[i]);
            cout<<nums[i]<<" ";   
        }
       
        return ans;
        
            
}
int main(){
    vector<int> a={3,35,43,5,4,4,56,54};
    cout<<largestNumber(a);
    return 0;
}