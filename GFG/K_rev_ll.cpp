void rev(Node* &head, Node* &tail)
{
    if(head == NULL)
    {
        tail = NULL;
        return;
    }
    Node* c = head;
    Node* p = NULL;
    Node* n = NULL;
    while(c != NULL)
    {
        n = c->next;
        c->next = p;
        p = c;
        c = n;
    }
    head = p;
    tail = p;
    while(tail->next != NULL)
    {
        tail = tail->next;
    }
}

Node *kReverse(Node *head, int k)
{
    if(k == 1 or k == 0)	return head; 
    if(head == NULL)	return NULL;
    Node* tail = head;
    int i = k;
    while(i > 1)
    {
        tail = tail->next;
        if(tail->next == NULL)	break;
        i--;
    }
    Node* head2 = NULL;
    // if(i != 0) 
    head2 = tail->next;
    tail->next = NULL;
    rev(head, tail);
    tail->next = kReverse(head2, k);
    return head;
}