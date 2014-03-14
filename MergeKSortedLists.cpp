// Merge k Sorted Lists
// Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.

ListNode* mergeTwoLists(ListNode *l1, ListNode *l2)
{
    if (l1 == nullptr && l2 == nullptr) return nullptr;
    
    if (l1 == nullptr && l2 != nullptr) return l2;
    
    if (l1 != nullptr && l2 == nullptr) return l1;

    ListNode *head = (l1->val <= l2->val) ? l1 : l2;

    ListNode *p, *q;
    if (l1->val <= l2->val)
    {
        p = l1;
        q = mergeTwoLists(l1->next, l2);
        p->next = q;
    }
    else
    {
        p = l2;
        q = mergeTwoLists(l1, l2->next);
        p->next = q;
    }
    
    return head;
}

ListNode *mergeKLists(vector<ListNode *> &lists)
{
    ListNode *p = nullptr;
    
    for (int i = 0; i < lists.size(); ++i)
    {
        p = mergeTwoLists(p, lists[i]);
    }
    
    return p;
}
