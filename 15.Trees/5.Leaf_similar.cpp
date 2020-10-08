#include<bits/stdc++.h>
using namespace std;
// leetcode 872
struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };

    void bfs(TreeNode *node,vector<int>&arr)
    {
            if(node==NULL) return ;
            if(node->left==NULL && node->right==NULL){
                arr.push_back(node->val);
            }
            if(node->left!=NULL) bfs(node->left,arr);
            if(node->right!=NULL) bfs(node->right,arr);
        return ;
       
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        if(!root1 || !root2) return false;
         vector<int> leaf1;
          bfs(root1,leaf1);
         vector<int> leaf2;
        bfs(root2,leaf2);
        if(leaf1.size()!=leaf2.size()) return false;
        
        for(int i=0;i<leaf1.size();i++)
        {
            if(leaf1[i]!=leaf2[i]) return false;
        }
        return true;
    }
    
int main()
{

}
