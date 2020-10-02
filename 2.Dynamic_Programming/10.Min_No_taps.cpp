#include <bits/stdc++.h>
using namespace std;
// leetcode 1326
int minTaps(int n, vector<int> &ranges)
{
    int *dp = new int[n + 1];
    for (int i = 0; i <= n; i++)
        dp[i] = n + 2; // set max value
    dp[0] = 0;         //no need of tap to water an area of 0 length
    for (int i = 0; i <= n; i++)
    {
        int left = max(0, i - ranges[i]);
        int right = min(n, i + ranges[i]);
        for (int j = left + 1; j <= right; j++)
            dp[j] = min(dp[j], dp[left] + 1);
    }
    return dp[n] == n + 2 ? -1 : dp[n];
}
int main()
{
    int n = 19;
    vector<int> ar = {4, 1, 5, 0, 5, 3, 3, 3, 0, 0, 3, 3, 2, 2, 4, 4, 2, 3, 4, 2};
    cout << minTaps(n, ar);
}