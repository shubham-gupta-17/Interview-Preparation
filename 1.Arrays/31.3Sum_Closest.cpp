 #include<bits/stdc++.h>
using namespace std;
// leetcode 16
 int threeSumClosest(vector<int>& nums, int target) {
        int n=nums.size();
        
        if(n==0 || n<3) return 0;
        
        sort(nums.begin(),nums.end());
        int closest=nums[0]+nums[1]+nums[2];
        for(int i=0;i<n-2;i++)
        {
            if(i>0 && nums[i]==nums[i-1]) continue;
        
            int start=i+1;
            int end=n-1;
            int num=0;
            while(start<end){
                 num= nums[start]+nums[end]+nums[i];
                if(num==target) return target;
                else if(abs(target-num) < abs(target-closest)) closest=num;
                else if(num>target) end--;
                else start++;
            }
            
            
        }
        return closest;
}
int main(){
    vector<int> a={4,3,1,5,4,3,7,8,6,5,3};
    cout<<threeSumClosest(nums,10);
    return 0;
}