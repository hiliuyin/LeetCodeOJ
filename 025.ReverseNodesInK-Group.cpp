/*
Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.
If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.
You may not alter the values in the nodes, only nodes itself may be changed.
Only constant memory is allowed.

For example,
Given this linked list: 1->2->3->4->5
For k = 2, you should return: 2->1->4->3->5
For k = 3, you should return: 3->2->1->4->5
*/

/*
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
ListNode *reverseKGroup(ListNode *head, int k) {
    if (head == nullptr || k <= 1) return head;

    ListNode dummyHead(0);
    ListNode *beginK = head;
    ListNode *endK = head;
    ListNode *prevNode = &dummyHead;
    for (;;)
    {
        int steps = k;
        while (endK != nullptr && steps-- > 0)
            endK = endK->next;
        if (steps > 0) break;

        ListNode *pPrev = endK;
        ListNode *pCurr = beginK;
        do {
            ListNode *pDummy = pCurr->next;
            pCurr->next = pPrev;
            pPrev = pCurr;
            pCurr = pDummy;
        } while (pCurr != endK);

        beginK->next = endK;
        prevNode->next = pPrev;
        prevNode = beginK;
        beginK = endK;
    }

    return dummyHead.next;
}
