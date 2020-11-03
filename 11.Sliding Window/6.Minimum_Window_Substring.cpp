#include <bits/stdc++.h>
using namespace std;
// leetcode 76
int n;
int m;
int find(string &s, int j, unordered_map<char, int> map)
{
    int count = 0;
    int i = j;
    while (i < n)
    {
        if (map.find(s[i]) != map.end() && map[s[i]] > 0)
        {
            count++;
            map[s[i]]--;
        }
        if (count == m)
            return i - j + 1;
        i++;
    }
    return INT_MAX - 2;
}
string minWindow(string s, string t)
{
    n = s.length();
    m = t.length();

    unordered_map<char, int> map;
    for (char ch : t)
        map[ch]++;
    int idx = 0;
    int len = n + 1;
    for (int i = 0; i < n; i++)
    {
        int size = find(s, i, map);
        if (size < len)
        {
            idx = i;
            len = size;
        }
    }

    if (len > n)
        return "";
    return s.substr(idx, len);
}

//====================================================================================
string minWindow(string s, string t)
{
    int n = s.length();
    int m = t.length();
    unordered_map<char, int> map_t;
    for (char ch : t)
        map_t[ch]++;

    unordered_map<char, int> map_s;
    int start = 0, end = 0;
    int match = 0;
    int ans = -1;
    int idx = -1;
    while (end < n)
    {
        // adding the characters in map_s
        char ch = s[end];
        map_s[ch]++;

        // now match count will increase only if we have found same char as in t with less or equal count
        if (map_s[ch] <= map_t[ch])
            match++;

        // store answer and start releasing character to find a smaller answer
        while (start <= end && match == m)
        {
            //string res=s.substr(start,end-start+1);
            int res = end - start + 1;
            if (ans == -1 || res < ans)
            {
                ans = res;
                idx = start;
            }
            char ch1 = s[start];
            start++;
            // if count==1 then remove from map_s
            if (map_s[ch1] == 1)
                map_s.erase(ch1);
            else
                map_s[ch1]--;
                
            // if count of s less then that of t means we have lost a useful character
            if (map_s[ch1] < map_t[ch1])
                match--;
        }
        end++;
    }

    return ans == -1 ? "" : s.substr(idx, ans);
}
int main()
{
    string s = "cbaacbcbdfsacb";
    string t = "abc";
    cout << balancedString(t, s);
}