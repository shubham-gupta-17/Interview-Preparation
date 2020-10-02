#include <bits/stdc++.h>
using namespace std;
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
int camera = 0;
int find_camera(TreeNode *root)
{
    if (root == NULL)
        return 0;
    int left = find_camera(root->left);
    int right = find_camera(root->right);
    if (left == -1 || right == -1)
    {
        camera++;
        return 1;
    }

    if (left == 1 || right == 1)
        return 0;

    return -1;
}
int minCameraCover(TreeNode *root)
{
    if (root == NULL)
        return 0;
    int val = find_camera(root);
    if (val == -1)
        camera++;
    return camera;
}
int main()
{
    return 0;
}