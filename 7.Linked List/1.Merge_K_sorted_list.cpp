#include<iostream>
#include<vector>
using namespace std;
// Mehthod 1:
  // Resource link :https://leetcode.com/problems/merge-k-sorted-lists/discuss/10531/Sharing-my-straightforward-C%2B%2B-solution-without-data-structure-other-than-vector
ListNode* merge(ListNode* l1,ListNode* l2)
{
   if(l1==NULL) return l2;
   if(l2==NULL) return l1;
   ListNode *root1=new ListNode(-1);
   ListNode *root=root1;
   while(l1!=NULL && l2!=NULL){

       if(l1->val<l2->val){
           root->next=new ListNode(l1->val);
           l1=l1->next;
       }
       else{
           root->next=new ListNode(l2->val);
           l2=l2->next;
       }
       root=root->next;
   }
   while(l1!=NULL){
       root->next=new ListNode(l1->val);
       l1=l1->next;
       root=root->next;
   }
   while(l2!=NULL)
   {
       root->next=new ListNode(l2->val);
       l2=l2->next;
       root=root->next;
   }
   return root1->next;
}
ListNode *merge_rec(vector<ListNode*>list,int s,int e)
{
   if(s==e) return list[s];
   if(s+1==e) return merge(list[s],list[e]);

   int mid=(s+e)/2;
   ListNode *left=merge_rec(list,s,mid-1);
   ListNode *right=merge_rec(list,mid,e);

   return merge(left,right);
}

// Mehthod 1
ListNode* mergeKLists_1(vector<ListNode*>& lists) {
   int n=lists.size();
   if(n==0) return NULL;
   if(n==1) return lists[0];

   return merge_rec(lists,0,n-1);
}
//Mehthod 2
ListNode* mergeKLists_2(vector<ListNode*>& lists) {
       int n=lists.size();
       if(n==0) return NULL;
       if(n==1) return lists[0];
       ListNode* ans=NULL;

       if(n>=1)
       ans=merge(lists[0],lists[1]);
       for(int i=2;i<n;i++)
       {
           ans=merge(lists[i],ans);
       }
       return ans;
   }

// Mehthod 3
ListNode *mergeKLists_3(vector<ListNode*> &lists)
{
  if (lists.empty()) return NULL;
      int len = lists.size();
      while (len > 1)
      {
          for (int i = 0; i < len / 2; ++i)
          {
              lists[i] = merge(lists[i], lists[len - 1 - i]);
          }
          len = (len + 1) / 2;
      }

      return lists.front();
}
int main()
{
   vector<ListNode*> lists={{1,4,5},{1,3,4},{2,6}}
    mergeKLists_1(lists);  // It will give TLE
    mergeKLists_2(lists);  // merge sort using recursion
    mergeKLists_3(lists);  // merge sort using loop it will be faster than all
    return 0;

}
