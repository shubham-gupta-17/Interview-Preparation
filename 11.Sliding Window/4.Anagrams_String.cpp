#include <bits/stdc++.h>
using namespace std;
// leetcode 438
vector<int> findAnagrams(string s, string p)
{
    int n = s.length();
    int m = p.length();
    vector<int> ans;
    if (n == 0)
        return ans;
    if (n < m)
        return ans;

    // create mask of p
    unordered_map<char, int> mapp;
    for (char ch : p)
        mapp[ch]++;

    // create mask of first m characters of s
    unordered_map<char, int> maps;
    for (int i = 0; i < m; i++)
    {
        char ch = s[i];
        maps[ch]++;
    }

    int start = 0, end = m;
    if (mapp == maps)
        ans.push_back(start);

    // remove start, add end and create mask_s
    while (end < n)
    {
        char first = s[start++];
        char last = s[end++];
        // unset the bit corresponding to first
        if (maps[first] == 1)
            maps.erase(first);
        else
            maps[first]--;
        // set the bit corresponding to last
        maps[last]++;
        if (maps == mapp)
            ans.push_back(start);
    }

    return ans;
}
int main()
{
    string s = "cbaacbcbdfsacb";
    string t = "abc";
    cout << balancedString(s, t);
}