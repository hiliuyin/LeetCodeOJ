/*
Given a linked list, remove the nth node from the end of list and return its head.

For example,
   Given linked list: 1->2->3->4->5, and n = 2.
   After removing the second node from the end, the linked list becomes 1->2->3->5.

Note:
Given n will always be valid.
Try to do this in one pass.
*/

ListNode* removeNthFromEnd(ListNode* head, int n)
{
    ListNode* fast = head;
    ListNode* slow = head;
    
    for (int k = 0; k < n; ++k)
        fast = fast->next;
    
    ListNode dummy(0);
    dummy.next = head;
    ListNode* prev = &dummy;
    while (fast != nullptr)
    {
        fast = fast->next;
        slow = slow->next;
        prev = prev->next;
    }
    
    prev->next = slow->next;
    return dummy.next;
}
