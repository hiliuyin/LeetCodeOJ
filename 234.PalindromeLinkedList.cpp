/*
Given a singly linked list, determine if it is a palindrome.

Follow up:
Could you do it in O(n) time and O(1) space?
*/

bool isPalindrome(ListNode* head)
{
    if (head == nullptr) return true;
    
    auto findMid = [](ListNode* head) -> ListNode*
    {
        int count = 0;
        for (auto p = head; p != nullptr; p = p->next)
            ++count;
        
        if (count%2 == 0)
            count = count/2;
        else
            count = count/2 + 1;
        
        ListNode* mid = head;
        for (int i = 0; i < count; ++i)
            mid = mid->next;

        return mid;
    };
    
    auto reverseList = [](ListNode* head) -> ListNode*
    {
        if (head == nullptr || head->next == nullptr) return head;
        
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while (curr != nullptr)
        {
            ListNode* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        return prev;
    };
    
    ListNode* mid = findMid(head);
    ListNode* rList = reverseList(mid);
    
    while (rList != nullptr)
    {
        if (rList->val != head->val)
            return false;
        rList = rList->next;
        head = head->next;
    }
    
    return false;
}
