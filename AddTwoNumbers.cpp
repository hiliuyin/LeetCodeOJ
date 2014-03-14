// Add Two Numbers 
// You are given two linked lists representing two non-negative numbers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.
// 
// Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
// Output: 7 -> 0 -> 8
//

ListNode* doAddTwoNumbers(ListNode *l1, ListNode *l2, int carry)
{
    int sum;
    if (l1 == nullptr && l2 == nullptr)
    {
        if (carry == 0)
            return nullptr;
        else
            sum = carry;
    }
    else if (l1 == nullptr && l2 != nullptr)
    {
        sum = l2->val + carry;
    }
    else if (l1 != nullptr && l2 == nullptr)
    {
        sum = l1->val + carry;
    }
    else
    {
        sum = l1->val + l2->val + carry;
    }
    carry = sum/10;
    int rem = sum%10;
    
    ListNode *p = new ListNode(rem);
    
    if (l1 == nullptr && l2 == nullptr)
        p->next = doAddTwoNumbers(l1, l2, carry);
    else if (l1 == nullptr && l2 != nullptr)
        p->next = doAddTwoNumbers(nullptr, l2->next, carry);
    else if (l1 != nullptr && l2 == nullptr)
        p->next = doAddTwoNumbers(l1->next, nullptr, carry);
    else
        p->next = doAddTwoNumbers(l1->next, l2->next, carry);

    return p;
}

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
{
    return doAddTwoNumbers(l1, l2, 0);
}
