/*
Given a singly linked list L: L0→L1→…→Ln-1→Ln,
reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→…

You must do this in-place without altering the nodes' values.

For example,
Given {1,2,3,4}, reorder it to {1,4,2,3}.
*/

void reorderList(ListNode* head)
{
    // using std::stack to implement an O(n) time complexity with extra O(n) space
    if (head == nullptr || head->next == nullptr || head->next->next == nullptr) return;
    
    std::stack<ListNode*> s;
    for (auto p = head; p != nullptr; p = p->next)
        s.push(p);
    
    for (auto curr = head;;)
    {
        ListNode* node = s.top();
        s.pop();
        
        if (node == curr || curr->next == node)
        {
            node->next = nullptr;
            break;
        }
        
        ListNode* next = curr->next;
        curr->next = node;
        node->next = next;
        curr = next;
    }
}
