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
void setZeroes(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();

    bool fr = false, fc = false;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (matrix[i][j] == 0)
            {
                if (i == 0)
                    fr = true;
                if (j == 0)
                    fc = true;
                matrix[0][j] = 0;
                matrix[i][0] = 0;
            }
        }
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < m; j++)
        {
            if (matrix[i][0] == 0 || matrix[0][j] == 0)
                matrix[i][j] = 0;
        }
    }

    if (fr)
    {
        for (int i = 0; i < m; i++)
            matrix[0][i] = 0;
    }

    if (fc)
    {
        for (int i = 0; i < n; i++)
            matrix[i][0] = 0;
    }

    return;
}
int main()
{
}