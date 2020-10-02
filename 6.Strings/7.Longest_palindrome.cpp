#include <bit/stdc++.h>
using namespace std;
// leetcode 409
int longestPalindrome(string s)
{
    int n = s.length();
    if (n == 0 || n == 1)
        return n;
    int *vis = new int[256]();

    for (char ch : s)
    {
        int idx = (int)ch;
        vis[idx]++;
    }

    int odd = 0;
    for (int i = 0; i < 256; i++)
    {
        if (vis[i] % 2)
            odd++;
    }

    return odd == 0 ? n : n - odd + 1;
}
int main()
{
    string s = "aabcdssdfeffhg";
    cout << longestPalindrome(s);
    return 0;
}