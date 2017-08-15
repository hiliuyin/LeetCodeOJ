// Given a sorted linked list, delete all duplicates such that each element appear only once.
// For example,
// Given 1->1->2, return 1->2.
// Given 1->1->2->3->3, return 1->2->3.

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return head;
        
        for (ListNode* prev = head, *curr = head->next; curr != nullptr; curr = curr->next) {
            if (curr->val != prev->val) {
                prev = curr;
            }
            else {
                prev->next = curr->next;
            }
        }
        return head;
    }
};
