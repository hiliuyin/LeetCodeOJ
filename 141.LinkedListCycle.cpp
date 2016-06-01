// Given a linked list, determine if it has a cycle in it.

// Follow up:
// Can you solve it without using extra space?

class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (head == nullptr) return false;
        if (head->next == nullptr) return false;
        
        for (auto fast = head->next->next, slow = head; fast != nullptr;)
        {
            if (slow == fast) return true;
            if (fast->next != nullptr)
                fast = fast->next->next;
            else
                break;
            slow = slow->next;
        }
        
        return false;
    }
};
