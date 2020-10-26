#include <bits/stdc++.h>
using namespace std;
// leetcode 73
int n;
int m;
void setZero(vector<vector<int>> &grid, int x, int y)
{
    for (int j = 0; j < m; j++)
        grid[x][j] = 0;

    for (int i = 0; i < n; i++)
        grid[i][y] = 0;

    return;
}
void setZeroes(vector<vector<int>> &matrix)
{
    n = matrix.size();
    m = matrix[0].size();
    vector<vector<int>> vis;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (matrix[i][j] == 0)
            {
                vis.push_back({i, j});
            }
        }
    }

    for (vector<int> dir : vis)
        setZero(matrix, dir[0], dir[1]);

    return;
}
//=====================================================================================
// Approach 2: O(1) space
int main()
{
}