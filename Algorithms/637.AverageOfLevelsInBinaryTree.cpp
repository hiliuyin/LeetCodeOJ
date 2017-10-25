/*
Given a non-empty binary tree, return the average value of the nodes on each level in the form of an array.

Example 1:
Input:
    3
   / \
  9  20
    /  \
   15   7
Output: [3, 14.5, 11]

Explanation:
The average value of nodes on level 0 is 3,  on level 1 is 14.5, and on level 2 is 11. Hence return [3, 14.5, 11].

Note:
The range of node's value is in the range of 32-bit signed integer.
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
 
 vector<double> averageOfLevels(TreeNode* root) {
    if (root == nullptr) return {};
    
    std::vector<double> result;
    std::queue<TreeNode*> q;
    q.push(root);
    q.push(nullptr);
    double val = 0;
    int count = 0;
    while (!q.empty()) {
        auto node = q.front();
        q.pop();
        if (node != nullptr) {
            if (node->left != nullptr) q.push(node->left);
            if (node->right != nullptr) q.push(node->right);
            val += node->val;
            count++;
        } else {
            if (count != 0) result.emplace_back(val/count);
            val = 0.0;
            count = 0;
            if (!q.empty())
                q.push(nullptr);
        }
    }
    
    return result;
}
