// Given a linked list, determine if it has a cycle in it.

// Follow up:
// Can you solve it without using extra space?

bool hasCycle(ListNode *head) {
    ListNode* fast = head, *slow = head;
    for (;;) {
        if (fast == nullptr || fast->next == nullptr) break;
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) return true;
    }
    return false;
}
