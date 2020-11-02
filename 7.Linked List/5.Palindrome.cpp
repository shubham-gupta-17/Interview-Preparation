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
ListNode *node = NULL;
void find(ListNode *head)
{
    if (!head)
        return;

    find(head->next);
    if (head->val == node->val)
        node = node->next;

    return;
}
bool isPalindrome(ListNode *head)
{
    node = head;
    find(head);

    return node == NULL;
}

//===============================================================================
 ListNode *find_middle(ListNode *head){
        ListNode *slow=head;
        ListNode *fast=head;
        while(slow!=NULL && fast->next!=NULL && fast->next->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
    ListNode *head1;
ListNode *reverse(ListNode *head)
{
    ListNode *node;
    if (!head->next)
    {
        node = new ListNode(head->val);
        head1 = node;
        return node;
    }
    node = reverse(head->next);
    node->next = new ListNode(head->val);
    return node->next;
}
    void print(ListNode *node){
        while(node!=NULL){
            cout<<node->val<<" ";
            node=node->next;
        }
    }
    bool isPalindrome(ListNode* head) {
        if(!head || head->next==NULL) return true;
        // find middle
        ListNode *mid=find_middle(head);
        cout<<mid->val;
        
        // reverse all elements after middle
        reverse(mid->next);
        mid->next=head1;
        // shift middle to next node
        mid=mid->next;
        ListNode *node=head;
        print(head);
        // compare node and middle value
        while(mid!=NULL){
            if(node->val!=mid->val) return false;
            mid=mid->next;
            node=node->next;
        }
        return true;
    }
int main()
{
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    ListNode *node = middleNode(head);
    return 0;
}
