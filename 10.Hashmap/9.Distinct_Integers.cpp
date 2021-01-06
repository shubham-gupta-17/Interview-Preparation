#include <bits/stdc++.h>
using namespace std;
// leetcode 992

int count(vector<int> &a, int k)
{
    int n = a.size();
    unordered_map<int, int> map;
    int start = 0, end = 0, count = 0;
    int ans = 0;
    while (end < n)
    {
        if (map.find(a[end]) == map.end() || map[a[end]] == 0)
            count++;
        map[a[end]]++;
        while (start <= end && count > k)
        {
            if (map[a[start]] == 1)
                count--;
            map[a[start]]--;
            start++;
        }
        ans += end - start + 1;
        end++;
    }
    return ans;
}
int subarraysWithKDistinct(vector<int> &a, int k)
{
    // ans= count of  subarrays with atmost k distinct integers - with atmost k-1 distinct integers
    return count(a, k) - count(a, k - 1);
}
int main()
{
    int n = 7;
    int *a = new int[n];
    countDistinct(a, n, 2);
    return 0;
}