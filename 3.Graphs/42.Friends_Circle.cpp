#include <bits/stdc++.h>
using namespace std;
// leetcode  547
int n;
int *parent;
int *size;
int find_parent(int u)
{
    if (parent[u] == u)
        return u;
    return parent[u] = find_parent(parent[u]);
}
int dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
void merge(int p1, int p2)
{
    if (size[p1] < size[p2])
    {
        parent[p1] = p2;
        size[p2] += size[p1];
    }
    else
    {
        parent[p2] = p1;
        size[p1] += size[p2];
    }
    return;
}
int findCircleNum(vector<vector<int>> &M)
{
    n = M.size();
    if (n == 0)
        return 0;
    parent = new int[n]();
    size = new int[n]();
    for (int i = 0; i < n; i++)
    {
        parent[i] = i;
        size[i] = 1;
    }

    for (int i = 0; i < n; i++)
    {

        for (int j = i + 1; j < n; j++)
        {
            if (M[i][j] == 0)
                continue;

            int p1 = find_parent(i);
            int p2 = find_parent(j);
            if (p1 != p2)
                merge(p1, p2);
        }
    }
    int ans = 0;

    for (int i = 0; i < n; i++)
        if (parent[i] == i)
            ans++;

    return ans;
}
int main()
{
    vector<vector<int>> arr = {{1, 1, 0}, {0, 1, 1}, {1, 0, 1}};
    findCircleNum(arr);
    return 0;
}