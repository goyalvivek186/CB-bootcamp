Node* oneZero(Node *head, int i, int j)
{
    	Node *original = head;
    	int ind = i+j;
        Node *c1 = head;
        Node *c2 = NULL;
        Node *p2 = NULL;
        int x = 0;
        while(x <= ind)
        {
            if(head == NULL)	return original;
            if(x == ind-1)	p2 = head;
            if(x == ind)	c2 = head;
            head = head->next;
            x++;
        }
        p2->next = c2->next;
        c2->next = c1->next;
        c1->next = p2->next;
        p2->next = c1;
        return c2;
}

Node* oneDiff(Node *head, int i, int j)
{
    	Node *original = head;
		j = max(i, j);
        i = j-1;
        int x = 0;
        Node* p1 = NULL;
        Node* c1 = NULL;
        Node* c2 = NULL;
        while(x <= j)
        {
            if(head == NULL)	return original;
            if(x == i-1)	p1 = head;
            if(x == i)		c1 = head;
            if(x == j)		c2 = head;
            head = head->next;
            x++;
        }
        p1->next = c2;
        c1->next = c2->next;
        c2->next = c1;
        return original;   
}

Node *one(Node *head, int i, int j)
{
		Node *c1 = NULL;
        Node *c2 = NULL;
        c1 = head;
        c2 = head->next;
        c1->next = c2->next;
        c2->next = c1;
        head = c2;
        return head;
}

Node *other(Node* head, int i, int j)
{
    Node* original = head;
    Node* p1 = NULL;
    Node* p2 = NULL;
    Node* c1 = NULL;
    Node* c2 = NULL;
    if(i > j)	swap(i, j);
    int x = 0;
    while(x <= j)
    {
        if(head == NULL)	return original;
        if(i-1 == x)	p1 = head;
        if(i == x)		c1 = head;
        if(j-1 == x)	p2 = head;
        if(j == x)		c2 = head;
        x++;
        head = head->next;
    }
    p2->next = c2->next;
    p1->next = c2;
    c2->next = c1->next;
    c1->next = p2->next;
    p2->next = c1;
    return original;
}

Node *swapNodes(Node *head, int i, int j)
{
    Node *original = head;
	if(head == NULL or i == j)	return head;
    if((i == 0 or j == 0) and abs(i-j) != 1)
    {
        return oneZero(head, i, j);
    }
    
    else if(abs(i-j) == 1 and i != 0 and j != 0)
    {
        return oneDiff(head, i, j);
    }
    
    else if(i + j == 1)
    {
        return one(head, i, j);
    }
    else
    {
        return other(head, i, j);
    }
    
    
}