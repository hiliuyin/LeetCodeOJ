/*
Given a singly linked list, group all odd nodes together followed by the even nodes. 
Please note here we are talking about the node number and not the value in the nodes.

You should try to do it in place. The program should run in O(1) space complexity and O(nodes) time complexity.

Example:
Given 1->2->3->4->5->NULL,
return 1->3->5->2->4->NULL.

Note:
The relative order inside both the even and odd groups should remain as it was in the input. 
The first node is considered odd, the second node even and so on ...
*/

ListNode* oddEvenList(ListNode* head)
{
    if (head == nullptr) return nullptr;

    ListNode dummyOdd(0);
    ListNode dummyEven(0);
    ListNode *odd = &dummyOdd;
    ListNode *even = &dummyEven;
    int num = 1;
    while (head != nullptr)
    {
        ListNode *next = head->next;
        if (num%2 != 0)
        {
            odd->next = head;
            odd = odd->next;
            odd->next = nullptr;
        }
        else
        {
            even->next = head;
            even = even->next;
            even->next = nullptr;
        }
        head = next;
        num++;
    }

    odd->next = dummyEven.next;
    return dummyOdd.next;
}
