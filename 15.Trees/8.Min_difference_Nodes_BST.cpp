#include<bits/stdc++.h>
using namespace std;
// leetcode 783
class TreeNode{
    public:
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int val){
        data=val;
        left=NULL;
        right=NULL;
    }
};

int dis=INT_MAX;
TreeNode *prev=NULL;
int distance(Node *root){
    if(!root) return 0;
    distance(root->left);
    if(prev!=NULL)
        dis=min(root->val-prev->val,dis);
    prev=root;
    distance(root->right);
    return ;
}
int main(){
    return 0;
}