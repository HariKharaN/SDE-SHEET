// MergeTwosortedLinekdList
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
Node* MergertwoLL(Node* l1,Node* l2)
{
    if(l1 == NULL) return l2;
    if(l2 == NULL) return l1;
    if(l1->data > l2->data) swap(l1,l2);
    Node* res = l1;
    while(l1 != NULL and l2 != NULL)
    {
        Node* temp = NULL;
        while(l1 != NULL and l1->data <= l2->data)
        {
            temp = l1;
            l1=l1->next;
        }
        temp->next=l2;
        swap(l1,l2);
    }
    return res;
}

int main()
{
    Node* head1=NULL;
    // push(&head,6);
    push(&head1,5);
    push(&head1,2);
    push(&head1,1);
    // print(head);
    Node* head2 = NULL;
    push(&head2,9);
    push(&head2,3);
    push(&head2,1);
    cout<<"FIRST LINKED LIST : ";
    print(head1);
    cout<<"\n";
    cout<<"SECOND LINKED LIST : ";
    print(head2);
    cout<<"\n";
    Node* res = MergertwoLL(head1,head2);
    cout<<"SORTED LINKED LIST : ";
    print(res);
    cout<<"\n";
}