#include<bits/stdc++.h>
using namespace std;

// leetcode 560
int subarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        if(n==0) return 0;
        unordered_map<int,int> map;
        map[0]=1;
        int sum=0;
        int count=0;
        for(int i=0;i<n;i++)
        {
            sum+=nums[i];
            if(map.find(sum-k)!=map.end()) count+=map[sum-k];
            map[sum]+=1;
        }
        
        return count;
}
int main()
{
    vector<int> a={2,3,5,5,3,7};
    // the input can contains negative number also
    cout<<subarraySum(a,10);
    return 0;
}