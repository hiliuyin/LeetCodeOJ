// Rotate List 
// Given a list, rotate the list to the right by k places, where k is non-negative.
// 
// For example:
// Given 1->2->3->4->5->NULL and k = 2,
// return 4->5->1->2->3->NULL.

ListNode *rotateRight(ListNode *head, int k) 
{
    if (head == NULL) return NULL;
    
    // calculate the list length
    int len = 0;
    ListNode *p = head;
    while (p != NULL)
    {
        len++;
        p = p->next;
    }

    // In case of k > len
    k = k%len;
    if (k == 0) return head;

    // Use two pointers p and q with k interval
    p = head;
    for (int i = 0; i < k; ++i)
        p = p->next;
 
    ListNode *q = head;
    while (p->next!= NULL)
    {
        p = p->next;
        q = q->next;
    }
    
    // Rotate the list
    ListNode *newhead = q->next;
    q->next = NULL;
    p->next = head;
    
    return newhead;
}
