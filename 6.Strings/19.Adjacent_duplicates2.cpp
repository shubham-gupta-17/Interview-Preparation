#include <iostream>
#include <bits/stdc++.h>
using namespace std;
// leetcode 1209
string removeDuplicates(string s, int k)
{
    int n = s.length();
    int start = 0, end = 0;
    stack<pair<char, int>> st;
    for (char ch : s)
    {
        if (st.empty() || st.top().first != ch)
            st.push({ch, 1});
        else
            st.top().second++;

        if (st.top().second == k)
            st.pop();
    }

    string ans = "";
    while (!st.empty())
    {
        auto it = st.top();
        ans.append(it.second, it.first);
        st.pop();
    }
    reverse(ans.begin(), ans.end());

    return ans;
}
int main()
{
    string s;
    cin >> s;
    cout << removeDuplicates(s);
    return 0;
}