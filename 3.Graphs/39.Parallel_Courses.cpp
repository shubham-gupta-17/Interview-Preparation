#include <bits/stdc++.h>
using namespace std;
int find_Semester(vector<vector<int>> &arr, int n)
{
    int m = arr.size();

    // to find start of graph find vertex with incoming edges ==0
    int *incoming = new int[n]();
    for (vector<int> vtx : arr)
        incoming[vtx[1]]++;

    unordered_map<int, vector<int>> map;
    for (vector<int> a : arr)
        map[a[0]].push_back(a[1]);

    queue<int> que;
    for (int i = 0; i < n; i++)
    {
        if (incoming[i] == 0)
            que.push(i);
    }

    if(que.empty()) return -1;

    bool *vis = new bool[n]();
    int sem = 0;

    while (!que.empty())
    {
        int size = que.size();
        while (size--)
        {
            int top = que.front();
            que.pop();

            if (vis[top])
               continue;

            vis[top] = true;
            for (int a : map[top])
               if(--incoming[a]==0) que.push(a);
        }
        sem++;
    }
    for(int i=0;i<n;i++) if(incoming[i]!=0) return -1;
    return sem;
}
int main()
{
    vector<vector<int>> arr = {{1, 0}, {1, 2}, {2, 3}};
    int n = 4;
    cout << find_Semester(arr, n);
    return 0;
}