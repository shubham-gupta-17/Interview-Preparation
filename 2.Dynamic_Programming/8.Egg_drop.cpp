#include<bits/stdc++.h>
using namespace std;
// leetcode 887
//Approach 1: DP O(nk) time and  O(nk) space
 int superEggDrop(int K, int N) {
         vector<vector<int>> dp(N + 1, vector<int>(K + 1, 0));
        int m = 0;
        while (dp[m][K] < N) {
            m++;
            for (int k = 1; k <= K; ++k)
                dp[m][k] = dp[m - 1][k - 1] + dp[m - 1][k] + 1;
        }
        return m;
}

// Approach 2: Binary Search
int main()
{
    int k;
    int n;
    cin>>k>>n;
    cout<<superEggDrop(k,n)<<endl;
}