// FindStartingPointOfLoopInLL
#include <bits/stdc++.h>
using namespace std;
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
void print(Node* node)
{
    while(node != NULL)
    {
        cout<< node -> data <<"  ";
        node = node->next;
    }
}
Node* detectLoop(Node* head)
{
    if(head == NULL || head->next == NULL)
     return NULL;
    Node* fast = head,*slow = head,*entry = head;
    while(fast->next and fast->next->next)
    {
        fast=fast->next->next;
        slow = slow->next;
        if(slow == fast)
            {
                while(slow != entry)
                {
                    slow=slow->next;
                    entry = entry->next;
                }
                return entry;
            }
    }
    return NULL;
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
 
    Node* res = detectLoop(head);
    print(res);
    return 0;
}
// 