// reverseALinkedlistByKgrups
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
Node* revreseByKgroup(Node* head,int k)
{
    if(head == NULL || k==1) return head;
    Node* dum = new Node();
    (dum)->data=0;
    dum->next=head;
    Node* pre = dum,*cur = dum,*nex = dum;
    int count=0;
    while(cur->next != NULL)
    {
        cur=cur->next;
        count++;
    }
    while(count>=k)
    {
        cur=pre->next;
        nex=cur->next;
        for(int i=1;i<k;i++)
        {
            cur->next = nex->next;
            nex->next = pre->next;
            pre->next = nex;
            nex=cur->next;
        }
        pre = cur;
        count-=k;
    }
    return dum->next;
}
int main()
{
    Node* head=NULL;
    push(&head,8);
    push(&head,7);
    push(&head,6);
    push(&head,5);
    push(&head,4);
    push(&head,3);
    push(&head,2);
    push(&head,1);
    print(head);
    cout<<endl;
    Node * res = revreseByKgroup(head,3);
    print(res);   
}