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
ListNode *middleNode(ListNode *head)
{
    if (!head)
        return head;
    ListNode *slow = head;
    ListNode *fast = head;
    while (slow != NULL && fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}
int main()
{
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    ListNode *node = middleNode(head);
    return 0;
}
