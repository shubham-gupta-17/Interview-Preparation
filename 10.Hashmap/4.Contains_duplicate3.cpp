#include <bits/stdc++.h>
using namespace std;
// leetcode 219
bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        int n = nums.size();
        if (n == 0)
        return false;
        set<long> map;
        for(int i=0;i<n;i++){
            if(i>k) map.erase(nums[i-k-1]);
            auto it=map.lower_bound(1L*nums[i]-t);
            if(it!=map.end() && abs(1L*(*it)-nums[i])<=t) return true;
            map.insert(nums[i]);
        }
        return false;
    }
        
int main()
{
    vector<int> arr = {1, 0, 1, 1, 1};
    containsNearbyAlmostDuplicate(arr, 2,0);
    return 0;
}