#include <bits/stdc++.h>
using namespace std;
// leetcode 290
bool wordPattern(string pattern, string s)
{
    int n = pattern.size();
    int m = s.length();
    vector<string> str;
    int i = 0;
    while (i < m)
    {
        string st = "";
        while (i < m && s[i] != ' ')
        {
            st += s[i];
            i++;
        }
        str.push_back(st);
        i++;
    }

    unordered_map<char, string> map;
    unordered_map<string, bool> mp;
    m = str.size();
    if (n != m)
        return false;
    for (int i = 0; i < n && i < m; i++)
    {
        char ch = pattern[i];
        if (map.find(ch) == map.end())
        {
            if (mp[str[i]])
                return false;
            map[ch] = str[i];
            mp[str[i]] = true;
        }
        else
        {
            if (map[ch] != str[i])
                return false;
        }
    }
    return true;
}

int main()
{
    cout << wordPattern("abba", "dog cat cat dog");
    return 0;
}