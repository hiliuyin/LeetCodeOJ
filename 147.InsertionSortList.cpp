/*
Sort a linked list using insertion sort.
*/

ListNode* insertionSortList(ListNode* head) {
    if (head == nullptr || head->next == nullptr)
        return head;
    
    ListNode dummyHead(0);
    dummyHead.next = head;
    
    ListNode* curr = head->next;
    while (curr != nullptr)
    {
        ListNode* next = curr->next;
        
        ListNode *q = &dummyHead;
        ListNode *p = q->next;
        while (p != curr)
        {
            if (p->val > curr->val)
            {
                curr->next = p;
                q->next = curr;
                while (p->next != curr)
                    p = p->next;
                break;
            }
            p = p->next;
            q = q->next;
        }

        p->next = next;
        curr = next;
    }
    
    return dummyHead.next;
}
