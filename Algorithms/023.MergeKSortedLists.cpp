/*
Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.
*/

ListNode* mergeKLists(std::vector<ListNode*>& lists)
{
    if (lists.empty()) return nullptr;
    if (lists.size() == 1) return lists.front();

    std::function<ListNode*(ListNode*, ListNode*)> mergeTwoLists = [&](ListNode* l1, ListNode* l2) -> ListNode*
    {
        if (l1 == nullptr && l2 == nullptr) return nullptr;
        else if (l1 == nullptr) return l2;
        else if (l2 == nullptr) return l1;
        else if (l1->val > l2->val)
        {
            l2->next = mergeTwoLists(l1, l2->next);
            return l2;
        }
        else
        {
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        }
    };

    for (;;)
    {
        if (lists.size() == 1)
            break;

        std::vector<ListNode*> dummyLists;
        int i = 0;
        for (int iEnd = lists.size()-1; i < iEnd; i += 2)
        {
            auto list = mergeTwoLists(lists[i], lists[i+1]);
            dummyLists.emplace_back(list);
        }

        if (i < (int)lists.size())
            dummyLists.emplace_back(lists[i]);

        lists = dummyLists;
    }

    return lists.front();
}
