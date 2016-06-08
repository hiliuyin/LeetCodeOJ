/*
Reverse a singly linked list.

A linked list can be reversed either iteratively or recursively. Could you implement both?
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
 ListNode* reverseList(ListNode* head)
 {
    if (head == nullptr || head->next == nullptr) return head;

    ListNode *prev = nullptr;
    for (ListNode *curr = head; curr != nullptr; )
    {
        ListNode *next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}
