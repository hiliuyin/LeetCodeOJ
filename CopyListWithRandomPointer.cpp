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

RandomListNode *copyRandomList(RandomListNode *head)
{
    if (head == nullptr) return nullptr;
    
    std::queue<RandomListNode*> Q; // Use the queue to cache the random pointer value in the original list
    RandomListNode *headCopy = new RandomListNode(head->label);
    Q.push(head->random);
    headCopy->random = head->random;
    head->random = headCopy;

    // [copy node].[random pointer] -> [original node].[random pointer]
    // [original node].[random pointer] -> [copy node]
    RandomListNode *dummyCopy = headCopy;
    RandomListNode *p = head->next;
    while (p != nullptr)
    {
        RandomListNode *nodeCopy = new RandomListNode(p->label);
        dummyCopy->next = nodeCopy;
        Q.push(p->random);
        nodeCopy->random = p->random;
        p->random = nodeCopy;
        dummyCopy = nodeCopy;
        p = p->next;
    }
    
    // We only restore random pointer in the copy list
    // cannot restore the original list here since there might be multiple random pointers points to the same node
    dummyCopy = headCopy;
    p = head;
    while (p != nullptr)
    {
        if (dummyCopy->random != nullptr)
            dummyCopy->random = dummyCopy->random->random;
            
        p = p->next;
        dummyCopy = dummyCopy->next;
    }
    
    // Restore the random pointer in the original list
    p = head;
    while (p != nullptr)
    {
        p->random = Q.front();
        Q.pop();
        p = p->next;
    }
    
    return headCopy;
}
