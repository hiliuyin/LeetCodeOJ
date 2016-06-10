// Rotate List 
// Given a list, rotate the list to the right by k places, where k is non-negative.
// 
// For example:
// Given 1->2->3->4->5->NULL and k = 2,
// return 4->5->1->2->3->NULL.

{
    if (head == nullptr || head->next == nullptr || k <= 0) return head;
    
    ListNode* tail;
    int len = 0;
    for (ListNode *p = head; p != nullptr; p = p->next)
    {
        tail = p;
        ++len;
    }
    k = k%len;
    
    if (k == 0) return head;
    
    ListNode* dummy = head;
    for (int i = 0, iEnd = len-k-1; i < iEnd; ++i)
    {
        dummy = dummy->next;
    }
    tail->next = head;
    head = dummy->next;
    dummy->next = nullptr;
    
    return head;
}

