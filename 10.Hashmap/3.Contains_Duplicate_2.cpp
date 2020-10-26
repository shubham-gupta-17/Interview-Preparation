#include <bits/stdc++.h>
using namespace std;
// leetcode 219
bool containsNearbyDuplicate(vector<int> &nums, int k)
{
    int n = nums.size();
    if (n == 0)
        return false;
    unordered_map<int, int> map;
    for (int i = 0; i < n; i++)
    {
        int val = nums[i];
        if (map.find(val) == map.end())
            map[val] = i;
        else
        {
            if (i - map[val] <= k)
                return true;
            else
                map[val] = i;
        }
    }
    return false;
}
int main()
{
    vector<int> arr = {1, 0, 1, 1, 1};
    containsNearbyDuplicate(arr, 2);
    return 0;
}