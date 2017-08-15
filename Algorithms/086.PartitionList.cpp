/*
Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.
You should preserve the original relative order of the nodes in each of the two partitions.

For example,
Given 1->4->3->2->5->2 and x = 3,
return 1->2->2->4->3->5.
*/

ListNode* partition(ListNode* head, int x)
{
    if (head == nullptr) return nullptr;

    ListNode dummySmall(0);
    ListNode dummyLarge(0);
    ListNode *small = &dummySmall;
    ListNode *large = &dummyLarge;

    while (head != nullptr)
    {
        ListNode *next = head->next;
        if (head->val < x)
        {
            small->next = head;
            small = small->next;
            small->next = nullptr;
        }
        else
        {
            large->next = head;
            large = large->next;
            large->next = nullptr;
        }
        head = next;
    }

    small->next = dummyLarge.next;
    return dummySmall.next;
}
