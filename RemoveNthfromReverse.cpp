// RemoveNthfromReverse
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
Node* removeNthNode(Node* head,int n)
{
    Node* start = new Node();
    start->next =head;
    Node* slow = start;
    Node* fast = start;
    for(int i=0;i<n;i++)
        fast=fast->next;
    while(fast->next != NULL)
    {
        slow=slow->next;
        fast=fast->next;
    }
    slow->next = slow->next->next;
    return start->next;
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
    Node * res = removeNthNode(head,2);
    print(res);   
}