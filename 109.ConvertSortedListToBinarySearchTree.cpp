/*
Given a singly linked list where elements are sorted in ascending order, convert it to a height balanced BST.
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if (head == nullptr) return nullptr;

        vector<int> nums;
        while (head != nullptr)
        {
            nums.emplace_back(head->val);
            head = head->next;
        }

        std::function<TreeNode* (int, int)>
            sortedListToBSTHelper = [&](int low, int high) -> TreeNode*
        {
           if (low > high) return nullptr;
           if (low == high)
               return new TreeNode(nums[low]);

           int mid = low + (high - low)/2;
           TreeNode* root = new TreeNode(nums[mid]);
           root->left = sortedListToBSTHelper(low, mid-1);
           root->right = sortedListToBSTHelper(mid+1, high);

           return root;
        };
         
        TreeNode* root = sortedListToBSTHelper(0, nums.size()-1);
        return root;
    }
};
