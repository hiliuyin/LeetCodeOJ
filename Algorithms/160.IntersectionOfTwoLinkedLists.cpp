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

// Solution 1:
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    int lenA = 0, lenB = 0;
    ListNode* pA = headA, *pB = headB;
    while (pA != nullptr) {
        pA = pA->next;
        ++lenA;
    }
    while (pB != nullptr) {
        pB = pB->next;
        ++lenB;
    }

    pA = headA;
    pB = headB;
    if (lenA > lenB) {
        while (lenA-- > lenB) {
            pA = pA->next;
        }
    }
    else if (lenB > lenA) {
        while (lenB-- > lenA) {
            pB = pB->next;
        }
    }
    
    while (pA != pB) {
        pA = pA->next;
        pB = pB->next;
    }
    return pA;
}

// Solution 2: elegant and simple
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    ListNode* pA = headA, *pB = headB;
    while (pA != pB) {
        pA = pA == nullptr ? headB : pA->next;
        pB = pB == nullptr ? headA : pB->next;
    }
    return pA;
}
