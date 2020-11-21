#include<bits/stdc++.h>
using namespace std;
// leetcode 98
struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
 bool isBST(TreeNode *root,TreeNode* left,TreeNode* right){
        if(!root) return true;
        if(left && root->val<=left->val || right && root->val>=right->val) return false;
        return isBST(root->left,left,root) && isBST(root->right,root,right);
        
    }
    bool isValidBST(TreeNode* root) {
        if(!root) return true;
        return isBST(root,NULL,NULL);
   }