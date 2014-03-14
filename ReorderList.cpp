// Reorder List
// Given a singly linked list L: L0→L1→…→Ln-1→Ln,
// reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→…
//
// You must do this in-place without altering the nodes' values.
//
// For example,
// Given {1,2,3,4}, reorder it to {1,4,2,3}.

// Use stack
// O(n) complexity with extra O(n) space
void reorderList(ListNode *head)
{
    if (head == NULL) return;
    
    std::stack<ListNode*> s;
    
    for (ListNode *p = head; p != NULL; p = p->next)
        s.push(p);
    
    for (ListNode *q = head; q != NULL; )
    {
        ListNode *r = s.top();
        s.pop();
        
        if (q == r)
        {
            q->next = NULL;
            break;
        }
        else if (q->next == r)
        {
            break;
        }
        
        r->next = q->next;
        q->next = r;
        q = r->next;

        ListNode *tmp = s.top();
        tmp->next = NULL;
    }
}

// use constant extra space
// TODO: 
