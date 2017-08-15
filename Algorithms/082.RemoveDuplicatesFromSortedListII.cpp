/*
Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.

For example,
Given 1->2->3->3->4->4->5, return 1->2->5.
Given 1->1->1->2->3, return 2->3.
*/

ListNode* deleteDuplicates(ListNode* head) {
    if (head == nullptr || head->next == nullptr) return head;
        
    ListNode dummy(0);
    dummy.next = head;
    for (ListNode* prev = &dummy, *curr = head; curr != nullptr && curr->next != nullptr; ) {
        ListNode* node = curr->next;
        if  (node->val != curr->val) {
            prev = curr;
        }
        else {
            while (node != nullptr && node->val == curr->val) {
                node = node->next;
                prev->next = node;
            }
        }
        curr = node;
    }
    return dummy.next;
}
