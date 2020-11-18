#include<bits/stdc++.h>
using namespace std;
// leetcode 416
int n;
int find(int i, bool *vis, vector<int>&arr, string ans, int k)
{

    if (k == 0 && i == n )
    {
        ans.pop_back();
        cout<<ans<<endl;
        return 1;
    }
    if (i >= n || k < 0)
        return 0;
    if (vis[i])
        return find(i + 1, vis, n, ans, k); // i is also in pair with someone else so don't add it
    else
    {
        vis[i] = true;
        int count = 0;
        count = find(i + 1, vis, n, ans + to_string(arr[i]) + ",", k - 1); // i will remain single
        for (int j = i + 1; j < n; j++)
        {
            if (vis[j])
                continue;
            vis[j] = true;
            count += find(i + 1, vis, n, ans + to_string(arr[i]) + to_string(arr[j]) + ",", k - 1);
            vis[j] = false;
        }
        vis[i] = false;
        return count;
    }

    return 0;
}
int main(){
	vector<int> ar={1,5,11,5};
	int k=2;
	n=ar.size();
	bool *vis=new bool[n]();
	cout<<find(0,vis,arr,"",k);
	return 0;
}