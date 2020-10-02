#include <bits/stdc++.h>
using namespace std;
// leetcode 979
class Node
{
public:
    int val = 0;
    Node *left = NULL;
    Node *right = NULL;

    Node(int d)
    {
        val = d;
    }
};
int moves = 0;
int distribute(TreeNode *root)
{
    if (root == NULL)
        return 0;
    int left = distribute(root->left);
    int right = distribute(root->right);
    moves += abs(right) + abs(left);
    return right + left + root->val - 1;
}
int distributeCoins(TreeNode *root)
{
    if (root == NULL)
        return 0;
    distribute(root);
    return moves;
}
int main()
{
    return 0;
}