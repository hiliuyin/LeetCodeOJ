// Copy List with Random Pointer 
// A linked list is given such that each node contains an additional random pointer which could point to any node in the list or null.
// 
// Return a deep copy of the list.

/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */

// 方法一
RandomListNode* copyRandomList(RandomListNode *head)
{
    if (head == nullptr) return nullptr;
    
    RandomListNode dummyHead(0);
    for (auto p = head, pCopy = &dummyHead; p != nullptr; p = p->next)
    {
        pCopy->next = new RandomListNode(p->label);
        pCopy = pCopy->next;
    }
    
    for (auto p = head, pCopy = dummyHead.next; p != nullptr; p = p->next, pCopy = pCopy->next)
    {
        if (p->random == nullptr)
        {
            pCopy->random = nullptr;
        }
        else
        {
            auto randomLoc = p->random;
            
            for (auto q = head, qCopy = dummyHead.next; q != nullptr; )
            {
                if (q == randomLoc)
                {
                    pCopy->random = qCopy;
                    break;
                }
                q = q->next;
                qCopy = qCopy->next;
            }
        }
    }
    
    return dummyHead.next;
}

// 方法二
RandomListNode *copyRandomList(RandomListNode *head) {
    if (head == nullptr) return head;
    RandomListNode* pCur = head;
    
    //Copy the RandomListNode
    // 1-2-3-4-5  ==> 1-1-2-2-3-3-4-4-5-5
    while (pCur != nullptr)
    {
        RandomListNode* pNext = pCur->next;
        pCur->next = new RandomListNode(pCur->label);
        pCur->next->next = pNext;
        pCur = pNext;
    }
    
    //Add the random value for new RandomListNode
    pCur = head;
    while (pCur != nullptr)
    {
        RandomListNode* pNext = pCur->next->next;
        if (pCur->random == nullptr)
            pCur->next->random = nullptr;
        else
            pCur->next->random = pCur->random->next;
        pCur = pNext;
    }
    
    //split the list to two lists
    RandomListNode* head2 = head->next;
    RandomListNode* pCur2 = head2;
    pCur = head;
    while (pCur2 != nullptr)
    {
        pCur->next = pCur->next->next;
        if (pCur2->next != nullptr)
            pCur2->next = pCur2->next->next;
        pCur = pCur->next;
        pCur2 = pCur2->next;
    }
    
    return head2;
}
