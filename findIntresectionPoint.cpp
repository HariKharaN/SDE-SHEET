
Node* findInter(Node* head1, Node* head2)
{
    if(head1 == NULL || head2 == NULL) return NULL;

    Node* a = head1, *b = head2;
    while(a != b)
    {
        a= a==NULL?head2:a->next;
        b= b==NULL?head1:b->next;
    }
    return a;
}
