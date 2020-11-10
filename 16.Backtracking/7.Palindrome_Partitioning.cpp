#include <bits/stdc++.h>
using namespace std;
// leetcode 131
bool is_palindrome(string &s)
{
    int i = 0, j = s.length() - 1;
    while (i <= j)
        if (s[i++] != s[j--])
            return false;

    return true;
}
vector<vector<string>> ans;
void find_part(string s, vector<string> &path)
{
    if (s.length() == 0)
    {
        ans.push_back(path);
        return;
    }

    int n = s.length();
    for (int i = 1; i <= n; i++)
    {
        string pal = s.substr(0, i);
        if (is_palindrome(pal))
        {
            path.push_back(pal);
            find_part(s.substr(i, n - i), path);
            path.pop_back();
        }
    }
    return;
}
vector<vector<string>> partition(string s)
{
    if (s == "")
        return ans;
    vector<string> path;
    find_part(s, path);
    return ans;
}
int main()
{
    string s = "aab";
    partition(s);
    return 0;
}