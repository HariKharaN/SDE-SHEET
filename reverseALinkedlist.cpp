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
Node* reverseLL(Node* head)
{
    Node* newhead = NULL;
    while(head != NULL)
    {
        Node* next = head->next;
        head->next = newhead;
        newhead  = head;
        head = next;
    }
    return newhead;
}
int main()
{
    Node* head=NULL;
    push(&head,5);
    push(&head,4);
    push(&head,3);
    push(&head,2);
    push(&head,1);
    print(head);
    cout<<endl;
    Node* res = reverseLL(head);
    cout<<"AFTER REVERSING THE LINKED LIST : ";
    print(res);
}