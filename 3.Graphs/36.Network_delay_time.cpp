#include <bits/stdc++.h>
using namespace std;
// leetcode 743
#define pp pair<int, int>
int networkDelayTime(vector<vector<int>> &times, int N, int K)
{
    int n = N;
    priority_queue<pp, vector<pp>, greater<pp>> que;
    //queue<pp> que;
    unordered_map<int, vector<pp>> map;
    for (vector<int> arr : times)
    {
        map[arr[0]].push_back({arr[1], arr[2]});
    }

    que.push({0, K});
    vector<int> dis(N + 1, INT_MAX);
    dis[K] = 0;
    bool *vis = new bool[N + 1]();
    while (!que.empty())
    {

        pp top = que.top();
        //pp top=que.front();
        que.pop();
        int u = top.second;
        int wsf = top.first;
        if (vis[u])
            continue;
        vis[u] = true; // we are marking it true here because it means we have find the shortest path from source to this node bcoz of prioirty queue and now if we encounter this node again, we should not push it
        dis[u] = wsf;

        for (pp p : map[u])
        {
            int v = p.first;
            int w = p.second;
            if (!vis[v])
                que.push({wsf + w, v});
        }
    }

    int ans = 0;
    for (int i = 1; i <= N; i++)
        ans = max(ans, dis[i]);
    return ans == INT_MAX ? -1 : ans;
}
int main()
{
    vector<vector<int>> arr = {{2, 1, 1}, {2, 3, 1}, {3, 1, 4}};
    networkDelayTime(arr, 4, 2);
    return 0;
}