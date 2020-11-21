#include<bits/stdc++.h>
using namespace std;
// leetcode 1008
struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
 TreeNode *root=NULL;
    TreeNode* create(TreeNode*node,int data){
        if(node==NULL){
            TreeNode *nnode=new TreeNode(data);
            return nnode;
        }
        if(data>node->val) node->right= create(node->right,data);
        else node->left= create(node->left,data);
        return node;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int n=preorder.size();
        if(n==0) return NULL;
        root=new TreeNode(preorder[0]);
        for(int i=1;i<n;i++){
           root=create(root,preorder[i]);
        }
        return root;
    }