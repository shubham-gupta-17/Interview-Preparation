#include <bits/stdc++.h>
using namespace std;
// leetcode 839
int *par;
int *size;
int n;
int find_parent(int u)
{
    if (par[u] == u)
        return u;
    return par[u] = find_parent(par[u]);
}

void merge(int i, int j, int p1, int p2, vector<string> &a)
{
    int count = 0;
    for (int k = 0; k < a[p1].length(); k++)
    {
        if (a[i][k] != a[j][k])
            count++;
    }

    if (count > 2)
        return;
    //else merge
    par[p2] = p1;
    return;
}
int numSimilarGroups(vector<string> &A)
{
    n = A.size();
    if (n == 0 || n == 1)
        return n;
    par = new int[n]();
    size = new int[n]();
    for (int i = 0; i < n; i++)
    {
        size[i] = 1;
        par[i] = i;
    }

    for (int i = 0; i < n; i++)
    {
        int p1 = find_parent(i);
        for (int j = i + 1; j < n; j++)
        {

            int p2 = find_parent(j);
            if (p1 != p2)
                merge(i, j, p1, p2, A);
        }
    }

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        // cout<<par[i]<<" ";
        if (par[i] == i)
            ans++;
    }
    return ans;
}
int main()
{
    vector<string> s = {"kccomwcgcs", "socgcmcwkc", "sgckwcmcoc", "coswcmcgkc", "cowkccmsgc", "cosgmccwkc", "sgmkwcccoc", "coswmccgkc", "kowcccmsgc", "kgcomwcccs"};
    cout << numSimilarGroups(s);
}