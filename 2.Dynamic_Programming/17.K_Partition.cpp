#include <bits/stdc++.h>
using namespace std;
int find(int i, bool *vis, int n,string ans,int k)
{
   
    if (k==0 && i==n+1)
    {
        ans.pop_back();
        ans.pop_back();
        cout<<ans<<endl;
        return 1;
    }
     if(i>n || k<0) return 0;
     if (vis[i])
        return find(i + 1, vis, n,ans,k);  // i is also in pair with someone else so don't add it
    else
    {
        vis[i] = true;
        int count = 0;
        count = find(i + 1, vis, n,ans+to_string(i)+", ",k-1);  // i will remain single
        for (int j = i + 1; j <= n; j++)
        {
            if (vis[j])
                continue;
            vis[j] = true;
            count += find(i + 1, vis, n,ans+to_string(i)+to_string(j)+", ",k-1);
            vis[j] = false;
        }
        vis[i] = false;
        return count;
    }

    return 0;
}
int main()
{
    int n ;
    cin>>n;
    //cout << countFriendsPairings(n) << endl;
    bool *vis = new bool[n + 1]();
    cout << find(1, vis, n,"",3);
    return 0;
}