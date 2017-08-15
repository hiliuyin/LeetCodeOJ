/*
Given a singly linked list, determine if it is a palindrome.

Follow up:
Could you do it in O(n) time and O(1) space?
*/

bool isPalindrome(ListNode* head) {
    if (head == nullptr || head->next == nullptr) return true;
    
    ListNode* slow = head;
    ListNode* fast = head;
    while (fast->next != nullptr && fast->next->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }

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
    
    slow->next = reverseList(slow->next);
    slow = slow->next;
    while (slow != nullptr) {
        if (head->val != slow->val) return false;
        head = head->next;
        slow = slow->next;
    }
    return true;
}
