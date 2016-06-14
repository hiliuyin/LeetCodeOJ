/*
You are given two linked lists representing two non-negative numbers. 
The digits are stored in reverse order and each of their nodes contain a single digit. 
Add the two numbers and return it as a linked list.

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
*/

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
{
    std::function<void(ListNode*, ListNode*, int, ListNode*)> addHelper = [&](ListNode* l1, ListNode* l2, int carry, ListNode* prev)
    {
        if (l1 == nullptr && l2 == nullptr)
        {
            prev->next = ((carry == 0) ? nullptr : new ListNode(carry));
        }
        else if (l1 == nullptr)
        {
            int sum = l2->val + carry;
            carry = sum / 10;
            prev->next = new ListNode(sum % 10);
            addHelper(nullptr, l2->next, carry, prev->next);
        }
        else if (l2 == nullptr)
        {
            int sum = l1->val + carry;
            carry = sum / 10;
            prev->next = new ListNode(sum % 10);
            addHelper(l1->next, nullptr, carry, prev->next);
        }
        else
        {
            int sum = l1->val + l2->val + carry;
            carry = sum / 10;
            prev->next = new ListNode(sum % 10);
            addHelper(l1->next, l2->next, carry, prev->next);
        }
    };

    ListNode dummy(0);
    addHelper(l1, l2, 0, &dummy);
    return dummy.next;
}
