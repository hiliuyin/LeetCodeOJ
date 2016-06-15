/*
Write a program to find the node at which the intersection of two singly linked lists begins.

For example, the following two linked lists:
A:       a1 → a2
                ↘
                  c1 → c2 → c3
                ↗            
B:  b1 → b2 → b3
begin to intersect at node c1.

Notes:
If the two linked lists have no intersection at all, return null.
The linked lists must retain their original structure after the function returns.
You may assume there are no cycles anywhere in the entire linked structure.
Your code should preferably run in O(n) time and use only O(1) memory.
*/

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
{
    if (headA == nullptr || headB == nullptr) return nullptr;
    
    int lengthA = 0;
    for (ListNode *p = headA; p != nullptr; p = p->next) lengthA++;
    
    int lengthB = 0;
    for (ListNode *p = headB; p != nullptr; p = p->next) lengthB++;
    
    if (lengthA > lengthB)
    {
        int diff = lengthA - lengthB;
        while (diff-- != 0)
            headA = headA->next;
    }
    else
    {
        int diff = lengthB - lengthA;
        while (diff-- != 0)
            headB = headB->next;
    }
    
    while (headA != headB)
    {
        headA = headA->next;
        headB = headB->next;
    }
    
    return headA;
}
