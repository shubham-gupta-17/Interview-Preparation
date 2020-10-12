#include <bits/stdc++.h>
using namespace std;
// leetcode 127
unordered_map<string, bool> map;
int len = INT_MAX;
int n;
void find(string &begin, string &end, int ans)
{
    if (begin == end)
    {
        len = min(len, ans);
        return;
    }

    for (int i = 0; i < n; i++)
    {
        char ch = begin[i];
        for (int j = 0; j < 26; j++)
        {
            begin[i] = 'a' + j;
            if (map[begin])
            {
                map[begin] = false;
                find(begin, end, ans + 1);
                map[begin] = true;
            }
        }
        begin[i] = ch;
    }
    return;
}

//=========================================================================================
int ladderLength(string &beginWord, string &endWord, vector<string> &wordList)
{
    if (beginWord == "")
        return 0;
    queue<string> que;
    que.push(beginWord);
    int n = beginWord.length();
    unordered_map<string, bool> map;
    for (string &s : wordList)
        map[s] = true;
    int ans = 1;
    while (!que.empty())
    {
        int size = que.size();
        while (size--)
        {
            string tmp = que.front();
            que.pop();

            if (tmp == endWord)
                return ans;

            //map[tmp]=false;
            for (int i = 0; i < n; i++)
            {
                char ch = tmp[i];
                for (int j = 0; j < 26; j++)
                {
                    tmp[i] = 'a' + j;
                    if (map[tmp])
                    {
                        map[tmp] = false;
                        que.push(tmp);
                    }
                }
                tmp[i] = ch;
            }
        }
        ans++;
    }

    return 0;
}
int main()
{
}