/*
Given a binary search tree with non-negative values, find the minimum absolute difference between values of any two nodes.

Example:
Input:
   1
    \
     3
    /
   2
Output:
1
Explanation:
The minimum absolute difference is 1, which is the difference between 2 and 1 (or between 2 and 3).

Note: There are at least two nodes in this BST.
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
int getMinimumDifference(TreeNode* root) {
    if (root == nullptr) return INT_MAX;
    
    int diff = INT_MAX;
    TreeNode* node = root->left;
    while (node != nullptr) {
        diff = std::min(diff, std::abs(root->val - node->val));
        node = node->right;
    }
    
    node = root->right;
    while (node != nullptr) {
        diff = std::min(diff, std::abs(root->val - node->val));
        node = node->left;
    }
    return std::min(diff, std::min(getMinimumDifference(root->left), getMinimumDifference(root->right)));
}
