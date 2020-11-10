#include <bits/stdc++.h>
using namespace std;
// #define int1 int
// #define int long long 
int *dp1;
int find(int i, bool *vis, int n)
{
    if (i == n + 1)
    {
        return 1;
    }
   // if(i==0 || dp1[i]!=0) return dp1[i];
    if (vis[i])
        return dp1[i] =find(i + 1, vis, n);
    else
    {
        vis[i] = true;
        int count = 0;
        count = find(i + 1, vis, n);
        for (int j = i + 1; j <= n; j++)
        {
            if (vis[j])
                continue;
            vis[j] = true;
            count += find(i + 1, vis, n);
            vis[j] = false;
        }
        vis[i] = false;
        return dp1[i]= count;
    }

    return 0;
}
int countFriendsPairings(int n)
{
   int *dp = new int[n + 1]();

    for (int i = 0; i <= n; i++)
    {
        if (i <= 2)
        {
            dp[i] = i;
            continue;
        }

        dp[i] = dp[i - 1] + (i - 1) * dp[i - 2];
    }
    return dp[n];
}
int main()
{
    int n ;
    cin>>n;
    cout << countFriendsPairings(n) << endl;
    bool *vis = new bool[n + 1]();
    dp1=new int[n+1]();
    cout << find(1, vis, n);
    return 0;
}