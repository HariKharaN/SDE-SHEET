// MIddleofALinkedlist
#include<iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
};

void push(Node** head,int n)
{
    Node* ne= new Node();
    ne->data=n;
    ne->next=(*head);
    (*head)=ne;
}
void print(Node* node)
{
    while(node != NULL)
    {
        cout<< node -> data <<"  ";
        node = node->next;
    }
}
Node* middleLL(Node* head)
{
    Node* slow = head, *fast = head;
    while(fast != NULL and fast->next != NULL)
    {
        slow = slow->next;
        fast=fast->next->next;
    }
    return slow;
}
int main()
{
    Node* head=NULL;
    // push(&head,6);
    push(&head,5);
    push(&head,4);
    push(&head,3);
    push(&head,2);
    push(&head,1);
    print(head);
    cout<<endl;
    Node * res = middleLL(head);
    print(res);   
}