#include <bits/stdc++.h>
using namespace std;
// leetcode 332
int n;
unordered_map<string, priority_queue<string, vector<string>, greater<string>>> map;
vector<string> ans;
bool find(string s, int i)
{
    bool flag = false;
    auto &que = map[s];
    cout << s << " ";
    while (!que.empty())
    {
        string top = que.top();
        que.pop();
        find(top, i + 1);
    }
    ans.push_back(s);
    return flag;
}
vector<string> findItinerary(vector<vector<string>> &tickets)
{
    n = tickets.size();
    for (int i = 0; i < n; i++)
        map[tickets[i][0]].push(tickets[i][1]);
    find("JFK", 0);
    reverse(ans.begin(), ans.end());
    return ans;
}
int main()
{
    vector<vector<int>> arr = {{"JFK", "KUL"}, {"JFK", "NRT"}, {"NRT", "JFK"}};
    findItinerary(arr);
    return 0;
}