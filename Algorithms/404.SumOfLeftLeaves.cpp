/*
Find the sum of all left leaves in a given binary tree.

Example:
    3
   / \
  9  20
    /  \
   15   7
There are two left leaves in the binary tree, with values 9 and 15 respectively. Return 24.
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
 
// Solution 1: use BFS
int sumOfLeftLeaves(TreeNode* root) {
    if (root == nullptr) return 0;
    
    int result = 0;
    std::queue<TreeNode*> que;
    que.emplace(root);
    while (!que.empty()) {
        auto node = que.front();
        que.pop();
        if (node->left != nullptr) {
            que.emplace(node->left);
            if (node->left->left == nullptr && node->left->right == nullptr)
                result += node->left->val;
        }
        if (node->right != nullptr)
            que.emplace(node->right);
    }
    return result;
}

// Solution 2: use recursive
int sumOfLeftLeaves(TreeNode* root) {
    if (root == nullptr) return 0;
    int result = 0;
    if (root->left != nullptr && root->left->left == nullptr && root->left->right == nullptr)
        result += root->left->val;
    result += sumOfLeftLeaves(root->left) + sumOfLeftLeaves(root->right);
    return result;
}

