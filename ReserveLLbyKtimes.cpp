// ReserveLLbyKtimes
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
Node* reverseByK(Node* head,int k)
{
    if(head == NULL or head->next == NULL or k==0)
        return head;
    Node* cur = head;
    int len=1;
    while(cur->next != NULL){
        cur=cur->next;
        len++;
    }
    cur->next = head;
    k=k%len;
    k=len-k;
    while(k--)
        cur=cur->next;
    head = cur->next;
    cur->next = NULL;
    return head;
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
    Node * res = reverseByK(head,2);
    print(res);   
}