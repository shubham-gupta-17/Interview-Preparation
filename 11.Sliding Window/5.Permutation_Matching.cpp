#include <bits/stdc++.h>
using namespace std;
// leetcode 567
bool checkInclusion(string p, string s)
{
    int n = s.length();
    int m = p.length();
    vector<int> ans;
    if (n == 0)
        return true;
    if (n < m)
        return false;

    unordered_map<char, int> mapp;
    for (char ch : p)
        mapp[ch]++;

    unordered_map<char, int> maps;
    int start = 0, end = 0;

    while (end < n)
    {
        maps[s[end++]]++;
        m--;
        if (m == 0)
        {
            if (maps == mapp)
                return true;
            if (maps[s[start]] == 1)
                maps.erase(s[start]);
            else
                maps[s[start]]--;
            start++;
            m++;
        }
    }
    return false;
}
int main()
{
    string s = "cbaacbcbdfsacb";
    string t = "abc";
    cout << balancedString(t, s);
}