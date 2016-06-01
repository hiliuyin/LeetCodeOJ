// Given a linked list, determine if it has a cycle in it.

// Follow up:
// Can you solve it without using extra space?

class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (head == nullptr || head->next == nullptr) return false;
        
        for (auto fast = head->next->next, slow = head; fast != nullptr;)
        {
            if (slow == fast) return true;
            if (fast->next != nullptr)
            {
                fast = fast->next->next;
                slow = slow->next;
            }
            else
            {
                break;
            }
        }
        
        return false;
    }
};
