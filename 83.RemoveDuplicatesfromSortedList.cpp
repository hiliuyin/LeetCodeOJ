// Given a sorted linked list, delete all duplicates such that each element appear only once.
// For example,
// Given 1->1->2, return 1->2.
// Given 1->1->2->3->3, return 1->2->3.

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == nullptr) return nullptr;
        
        ListNode* currentNode = head;
        int currentVal = head->val;
        for (ListNode* node = head->next; node != nullptr;)
        {
            if (node->val == currentVal)
            {
                ListNode* toDeleteNode = node;
                node = node->next;
                currentNode->next = node;
                delete toDeleteNode;
            }
            else
            {
                currentNode = node;
                currentVal = node->val;
                node = node->next;
            }
        }
        
        return head;
    }
};
