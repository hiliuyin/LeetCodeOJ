/*
Given a linked list, return the node where the cycle begins. If there is no cycle, return null.

Note: Do not modify the linked list.

Follow up:
Can you solve it without using extra space?
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if (head == nullptr || head->next == nullptr) return nullptr;
        
        auto fast = head;
        auto slow = head;
        do
        {
            fast = fast->next;
            if (fast != nullptr)
            {
                fast = fast->next;
                slow = slow->next;
            }
        } while (fast != nullptr && fast != slow);
        
        if (fast == nullptr) return nullptr;
        
        slow = head;
        while (slow != fast)
        {
            slow = slow->next;
            fast = fast->next;
        }
        return fast;
    }
};
