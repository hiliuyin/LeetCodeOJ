/*
Given a singly linked list, determine if it is a palindrome.

Follow up:
Could you do it in O(n) time and O(1) space?
*/

bool isPalindrome(ListNode* head) {
    if (head == nullptr || head->next == nullptr) return true;
    
    int len = 0;
    for (ListNode* p = head; p != nullptr; p = p->next)
        ++len;
    
    ListNode* node = head;
    for (int i = 0, iEnd = (len%2 == 0) ? len/2 : (len/2+1); i < iEnd; ++i)
        node = node->next;
    
    auto reverseList = [&](ListNode* p){
        ListNode* prev = nullptr;
        while (p != nullptr) {
            ListNode* next = p->next;
            p->next = prev;
            prev = p;
            p = next;
        }
        return prev;
    };
    
    ListNode* tail = reverseList(node);
    for (int i = 0, iEnd = len/2; i < iEnd; ++i) {
        if (head->val != tail->val) return false;
        head = head->next;
        tail = tail->next;
    }
    return true;
}
