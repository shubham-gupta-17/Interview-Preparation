#include<bits/stdc++.h>
 using namespace std;
 // leetcode 90
vector<vector<int>> ans;
int n;
void find(vector<int> &nums, int i, vector<int> path)
{
    if (i == n)
        return;
    unordered_map<int, bool> map;
    for (int j = i; j < n; j++)
    {
        if (map[nums[j]])
            continue;
        map[nums[j]] = true;
        path.push_back(nums[j]);
        ans.push_back(path);
        find(nums, j + 1, path);
        path.pop_back();
    }
    return;
}
vector<vector<int>> subsetsWithDup(vector<int> &nums)
{
    n = nums.size();
    if (n == 0)
        return ans;
    ans.push_back({});
    vector<int> path;
    sort(nums.begin(), nums.end());
    find(nums, 0, path);
    return ans;
}
int main(){
    vector<int> num={4,3,21,5,6,};
    subsetWithDup(num);
}