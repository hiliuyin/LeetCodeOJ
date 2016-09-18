/*
Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.

For example,
Given 1->2->3->3->4->4->5, return 1->2->5.
Given 1->1->1->2->3, return 2->3.
*/

ListNode* deleteDuplicates(ListNode* head)
{
    if (head == nullptr || head->next == nullptr) return head;
    
    ListNode dummyHead(0);
    dummyHead.next = head;
    ListNode* p = &dummyHead;
    ListNode* prev = head;
    ListNode* curr = head->next;
    while (curr != nullptr)
    {
        if (curr->val == prev->val)
        {
            prev->next = nullptr;
        }
        else
        {
            if (prev == head) // handle the case: 1->2->.....
                p = p->next;
            
            if (curr->next == nullptr || curr->val != curr->next->val)
            {
                p->next = curr;
                p = curr;
            }
        }
        prev = curr;
        curr = curr->next;
    }
    p->next = nullptr;
    
    return dummyHead.next;
}
