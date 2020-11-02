#include <bits/stdc++.h>
using namespace std;
// leetcode 876
class ListNode
{

public:
    int val;
    ListNode *next = NULL;
    ListNode(int x)
    {
        val = x;
    }
};
 ListNode* node=NULL;
    void find(ListNode*head)
    {
        if(!head) return ;
        
        find(head->next);
        if(head->val==node->val)
            node=node->next;
        
        return ;
    }
     bool isPalindrome(ListNode* head)
     {
         node=head;
         find(head);
         
         return node==NULL;
         
     }
int main()
{
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    ListNode *node = middleNode(head);
    return 0;
}
