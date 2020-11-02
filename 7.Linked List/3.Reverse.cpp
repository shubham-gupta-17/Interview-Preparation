#include<bits/stdc++.h>
using namespace std;
// leetcode 209
class ListNode{

    public:
    int val;
    ListNode *next=NULL;
    ListNode(int x){
        val=x;
    }
};
 ListNode *head1;
    ListNode *reverse(ListNode *head){
        ListNode *node;
        if(!head->next){
          node=new ListNode(head->val);
          head1=node;
            return node;
        }
        node=reverse(head->next);
        node->next=new ListNode(head->val);
        return node->next;
    }
    ListNode* reverseList(ListNode* head) {
        if(!head) return head;
        reverse(head);
        return head1;
    }
int main(){
	ListNode *head=new ListNode(1);
	head->next=new ListNode(2);
	head->next->next=new ListNode(3);
	ListNode *node=reverseList(head);
	return 0;	
}
