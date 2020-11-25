#include <bits./stdc++.h>
using namespace std;
// leetcode 713
int numSubarrayProductLessThanK(vector<int> &nums, int k)
{
    int n = nums.size();
    if (n == 0)
        return 0;
    int start = 0, end = 0;
    long long prod = 1;
    int count = 0;
    while (end < n)
    {
        prod *= nums[end];
        while (start <= end && prod >= k)
            prod /= nums[start++];
        count += (end - start + 1);
        end++;
    }
    return count;
}
int main()
{
    vector<int> ar = {10, 2, 5, 6};
    cout << numSubarrayProductLessThanK(ar, 100);
    return 0;
}