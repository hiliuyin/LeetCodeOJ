/*
Remove all elements from a linked list of integers that have value val.

Example
Given: 1 --> 2 --> 6 --> 3 --> 4 --> 5 --> 6, val = 6
Return: 1 --> 2 --> 3 --> 4 --> 5
*/

ListNode* removeElements(ListNode* head, int val)
{
    if (head == nullptr) return nullptr;
    
    ListNode dummy(0);
    dummy.next = head;
    
    ListNode* prev = &dummy;
    ListNode* curr = head;
    while (curr != nullptr)
    {
        if (curr->val == val)
        {
            prev->next = curr->next;
        }
        else
        {
            prev = curr;
        }
        curr = curr->next;
    }
    return dummy.next;
}
