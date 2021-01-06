#include<bits/stdc++.h>
using namespace std;
// insert data in a sorted list
struct Node
{
  int data;
  struct Node *next;
  
  Node(int x){
      data = x;
      next = NULL;
  }
  
};
Node *sortedInsert(Node* head, int data)
{
    if(!head) return head;
     Node *prev=head;
     Node *curr=head->next;
     bool flag=false;
     while(curr){
         if(curr->data<prev->data){
             Node *node=new Node(data);
             node->next=curr;
             prev->next=node;
             if(data<=curr->data) return node;
             return head;
         }
         if(data>=prev->data && data<=curr->data){
             Node *node=new Node(data);
             node->next=curr;
             prev->next=node;
             return head;
         }
         prev=prev->next;
         curr=curr->next;
         
     }
     
     return head;
}
int main(){

	return 0;
}