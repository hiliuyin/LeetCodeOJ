/*
Remove all elements from a linked list of integers that have value val.

Example
Given: 1 --> 2 --> 6 --> 3 --> 4 --> 5 --> 6, val = 6
Return: 1 --> 2 --> 3 --> 4 --> 5
*/

ListNode* removeElements(ListNode* head, int val) {
    ListNode dummyHead(0);
    dummyHead.next = head;
    
    ListNode* prev = &dummyHead;
    ListNode* p = head;
    while (p != nullptr) {
        if (p->val == val) {
            prev->next = p->next;
        }
        else {
            prev = p;
        }
        p = p->next;
    }
    
    return dummyHead.next;
}
