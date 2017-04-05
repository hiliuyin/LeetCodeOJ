/*
You are given two linked lists representing two non-negative numbers. 
The digits are stored in reverse order and each of their nodes contain a single digit. 
Add the two numbers and return it as a linked list.

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
*/

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    std::function<void(ListNode*, ListNode*, int, ListNode*)> addHelper =
        [&](ListNode* node1, ListNode* node2, int carry, ListNode* prev) {
            if (node1 == nullptr && node2 == nullptr) {
                prev->next = carry == 0 ? nullptr : new ListNode(carry);
            }
            else if (node1 == nullptr) {
                int sum = node2->val + carry;
                prev->next = new ListNode(sum % 10);
                addHelper(nullptr, node2->next, sum/10, prev->next);
            }
            else if (node2 == nullptr) {
                int sum = node1->val + carry;
                prev->next = new ListNode(sum % 10);
                addHelper(node1->next, nullptr, sum/10, prev->next);
            }
            else {
                int sum = node1->val + node2->val + carry;
                prev->next = new ListNode(sum % 10);
                addHelper(node1->next, node2->next, sum/10, prev->next);
            }
        };

    ListNode dummy(0);
    addHelper(l1, l2, 0, &dummy);
    return dummy.next;
}
