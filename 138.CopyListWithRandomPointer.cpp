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

