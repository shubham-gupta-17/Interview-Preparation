#include <iostream>
#include <bits/stdc++.h>
using namespace std;
// leetcode 1047
string removeDuplicates(string &s)
{
    int n = s.length();
    if (n == 0)
        return s;
    stack<char> st;
    for (int i = 0; i < n; i++)
    {
        bool flag = false;
        while (!st.empty() && st.top() == s[i])
        {
            flag = true;
            st.pop();
        }
        if (!flag)
            st.push(s[i]);
    }

    string ans = "";
    while (!st.empty())
    {
        char ch = st.top();
        st.pop();
        ans += ch;
    }
    reverse(ans.begin(), ans.end());
    return ans;
}
//======================================================================
string removeDuplicates(string &s)
{
    int n = s.length();
    if (n == 0)
        return s;
    string res = "";
    for (char ch : s)
    {
        if (res.size() && res.back() == ch)
            res.pop_back();
        else
            res.push_back(ch);
    }
    return res;
}
int main()
{
    string s;
    cin >> s;
    cout << removeDuplicates(s);
    return 0;
}