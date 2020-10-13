#include <bits/stdc++.h>
using namespace std;
unordered_map<string, int> map;
unordered_map<string, bool> vis;
int len;
int n;
unordered_map<string, vector<string>> graph;
void find_length(string &begin, string &end)
{
    queue<string> que;
    que.push(begin);
    while (!que.empty())
    {
        string top = que.front();
        que.pop();

        if (top == end)
        {
            return;
        }

        string tmp = top;
        for (int i = 0; i < n; i++)
        {
            char ch = top[i];
            for (int j = 0; j < 26; j++)
            {
                top[i] = 'a' + j;
                if (vis[top] && ch != top[i])
                {
                    if (map[top] == 0)
                    {
                        map[top] = map[tmp] + 1;
                        que.push(top);
                        graph[tmp].push_back(top);
                    }
                    else if (map[top] == map[tmp] + 1)
                        graph[tmp].push_back(top);
                }
            }
            top[i] = ch;
        }
    }

    return;
}

void display()
{
    for (auto it : graph)
    {
        cout << it.first << "->";
        for (string &s : it.second)
            cout << s << ", ";
        cout << endl;
    }
}

vector<vector<string>> ans;
void dfs(string &begin, string &end, vector<string> &path)
{
    if (begin == end)
    {
        path.push_back(begin);
        ans.push_back(path);
        path.pop_back();
        return;
    }

    path.push_back(begin);
    for (string &child : graph[begin])
        dfs(child, end, path);
    path.pop_back();
}
vector<vector<string>> findLadder(string &beginWord, string &endWord, vector<string> WordList)
{
    for (string &s : WordList)
        map[s] = 0;
    map[beginWord] = 1;
    n = beginWord.length();
    for (string &s : WordList)
        vis[s] = true;
    find_length(beginWord, endWord);
    vector<string> path;
    dfs(beginWord, e)
}
int main()
{
}