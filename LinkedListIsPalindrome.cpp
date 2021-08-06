// LinkedListIsPalindrome
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
Node* reverseList(Node* head)
{
    Node* pre = NULL;
    Node* next = NULL;
    while(head != NULL)
    {
        next = head->next;
        head->next = pre;
        pre  = head;
        head = next;
    }
    return pre;
}
bool isPalindromeNode(Node* head)
{
    if(head == NULL || head->next == NULL) return true;
    Node* slow = head,*fast = head;
    while(fast->next != NULL and fast->next->next != NULL)
    {
        fast = fast->next->next; 
        slow = slow->next;
    }// finding the  middle node;
    slow->next = reverseList(slow->next);
    slow = slow->next;

    while(slow != NULL)
    {
        if(head->data != slow->data)
            return false;
        head = head->next;
        slow= slow->next;
    }

    return true;
}

int main()
{
    Node* head=NULL;
    
    push(&head,1);
    push(&head,2);
    push(&head,2);
    push(&head,1);
    print(head);
    cout<<endl;
    if(isPalindromeNode(head))
        cout<<" YES ";
    else
        cout<<"NO";  
}