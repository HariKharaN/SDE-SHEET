// detectCycleInLinkedList
#include <bits/stdc++.h>
using namespace std;
/* Link list node */
struct Node {
    int data;
    struct Node* next;
};
void push(struct Node** head_ref, int new_data)
{
    struct Node* new_node = new Node;
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

bool detectLoop(Node* head)
{
    if(head == NULL || head->next == NULL)
     return NULL;
    Node* fast = head,*slow = head;
    while(fast->next and fast->next->next)
    {
        fast=fast->next->next;
        slow = slow->next;
        if(slow == fast)
            return true;
    }
    return false;
}

int main()
{
    struct Node* head = NULL;
 
    push(&head, 20);
    push(&head, 4);
    push(&head, 15);
    push(&head, 10);
 
    /* Create a loop for testing */
    head->next->next->next->next = head;
 
    if (detectLoop(head))
        cout << "Loop found";
    else
        cout << "No Loop";
 
    return 0;
}
// 