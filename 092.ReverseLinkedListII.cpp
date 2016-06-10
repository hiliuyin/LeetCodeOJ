/*
Reverse a linked list from position m to n. Do it in-place and in one-pass.

For example:
Given 1->2->3->4->5->NULL, m = 2 and n = 4,
return 1->4->3->2->5->NULL.

Note:
Given m, n satisfy the following condition:
1 ≤ m ≤ n ≤ length of list.
*/

ListNode* reverseBetween(ListNode* head, int m, int n)
{
    if (head == nullptr || head->next == nullptr || m == n) return head;
    
    ListNode dummy(0);
    dummy.next = head;

    ListNode* prevBegin = &dummy;
    ListNode* begin = head;
    for (int i = 1; i < m; ++i)
    {
        prevBegin = begin;
        begin = begin->next;
    }
    
    ListNode* prev = nullptr;
    ListNode* curr = begin;
    for (int i = m; i <= n; ++i)
    {
        ListNode* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    
    prevBegin->next = prev;
    begin->next = curr;
    
    return dummy.next;
}
