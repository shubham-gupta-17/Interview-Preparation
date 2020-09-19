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
int f(int x, int K, int N) {
        int ans = 0, r = 1;
        for (int i = 1; i <= K; ++i) {
            r *= x-i+1;
            r /= i;
            ans += r;
            if (ans >= N) break;
        }
        return ans;
}

int superEggDrop_2(int K, int N) {
        int lo = 1, hi = N;
        while (lo < hi) {
            int mi = (lo + hi) / 2;
            if (f(mi, K, N) < N)
                lo = mi + 1;
            else
                hi = mi;
        }

        return lo;
}

int main()
{
    int k;
    int n;
    cin>>k>>n;
    cout<<superEggDrop(k,n)<<endl;
    cout<<superEggDrop_2(k,n);
    return 0;
}