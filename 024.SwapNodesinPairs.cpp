/*
Given a linked list, swap every two adjacent nodes and return its head.

For example,
Given 1->2->3->4, you should return the list as 2->1->4->3.

Your algorithm should use only constant space. You may not modify the values in the list, only nodes itself can be changed.
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
    ListNode* swapPairs(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return head;
        
        ListNode dummyHead(0);
        for (auto left = head, right = head->next, prevRight = &dummyHead; left != nullptr && right != nullptr;)
        {
            prevRight->next = right;

            left->next = right->next;
            right->next = left;
            
            prevRight = left;
            
            left = left->next;
            if (left != nullptr)
                right = left->next;
        }
        return dummyHead.next;
    }
};
