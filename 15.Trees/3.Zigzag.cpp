#include <bits/stdc++.h>
using namespace std;
// leetcode 103
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
vector<vector<int>> zigzagLevelOrder(TreeNode *root)
{
    vector<vector<int>> ans;
    if (!root)
        return ans;

    stack<TreeNode *> odd;
    stack<TreeNode *> even;
    even.push(root);
    int i = 0;
    while (!even.empty() || !odd.empty())
    {
        vector<int> level;
        if (odd.empty() && !even.empty())
        {
            int size = even.size();
            while (size--)
            {
                TreeNode *top = even.top();
                even.pop();
                level.push_back(top->val);
                if (top->left)
                    odd.push(top->left);
                if (top->right)
                    odd.push(top->right);
            }
            ans.push_back(level);
            level.clear();
        }
        else
        {
            int size = odd.size();
            while (size--)
            {
                TreeNode *top = odd.top();
                odd.pop();
                level.push_back(top->val);
                if (top->right)
                    even.push(top->right);
                if (top->left)
                    even.push(top->left);
            }
            ans.push_back(level);
            level.clear();
        }
    }

    return ans;
}
int main()
{
    return 0;
}