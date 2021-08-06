// addTwoNumbersGivenAsLinkedL
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
    cout<<endl;
}
Node* addTwoNum(Node* l1, Node* l2)
{
    Node* dum = new Node();
    Node* temp =dum;
    int carry=0;
    while(l1 != NULL or l2 != NULL or carry)
    {
        int sum=0;
        if(l1 != NULL)
        {
            sum+=l1->data;
            l1=l1->next;
        }
        if(l2 != NULL)
        {
            sum+=l2->data;
            l2=l2->next;
        }
        sum+=carry;
        carry=sum/10;
        Node* newnode = new Node();
        newnode->data = sum%10;
        temp->next = newnode;
        temp=temp->next;
    }
    return dum->next;
}
int main()
{
    Node* l1=NULL;
    push(&l1,2);
    push(&l1,4);
    push(&l1,3);
    cout<<"FIRST LL : ";
    print(l1);
    Node* l2=NULL;
    push(&l2,9);
    push(&l2,6);
    push(&l2,1);
    push(&l2,7);
    cout<<"SECOND LL : ";
    print(l2);
    Node* res = addTwoNum(l1,l2);
    cout<<"ADDED LL : ";
    print(res);
}