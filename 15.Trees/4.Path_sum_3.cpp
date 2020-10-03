#include <bit/stdc++.h>
using namespace std;
//leetcode 437
int count = 0;
void summ(TreeNode *root, int sum)
{
    if (!root)
        return;
    if (sum == root->val)
        count++;

    summ(root->left, sum - root->val);
    summ(root->right, sum - root->val);
    return;
}
int pathSum(TreeNode *root, int sum)
{
    if (root)
    {
        summ(root, sum);
        pathSum(root->left, sum);
        pathSum(root->right, sum);
    }
    return count;
}