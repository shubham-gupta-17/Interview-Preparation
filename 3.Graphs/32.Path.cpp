#include <bits/stdc++.h>
using namespace std;
// leetcode 797
int n;
vector<vector<int>> path;
void find_path(vector<vector<int>> &graph, int i, vector<int> &ans)
{
    if (i == n - 1)
    {
        ans.push_back(i);
        path.push_back(ans);
        ans.pop_back();
        return;
    }

    for (int v : graph[i])
    {
        ans.push_back(i);
        find_path(graph, v, ans);
        ans.pop_back();
    }
    return;
}
vector<vector<int>> allPathsSourceTarget(vector<vector<int>> &graph)
{
    n = graph.size();
    if (n == 0)
        return path;
    vector<int> ans;
    cout << n;
    find_path(graph, 0, ans);
    return path;
}
int main()
{
}