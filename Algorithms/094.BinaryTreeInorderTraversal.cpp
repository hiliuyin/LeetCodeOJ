/*
Given a binary tree, return the inorder traversal of its nodes' values.

For example:
Given binary tree [1,null,2,3],
   1
    \
     2
    /
   3
return [1,3,2].

Note: Recursive solution is trivial, could you do it iteratively?
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

// Solution 1: Recusive solution
vector<int> inorderTraversal(TreeNode* root) {
    std::vector<int> result;
    std::function<void(TreeNode*)> helper = [&](TreeNode *root)
    {
        if (root != nullptr)
        {
            helper(root->left);
            result.emplace_back(root->val);
            helper(root->right);
        }
    };
    helper(root);
    return result;
}

// Solution 2: Using std::stack
std::vector<int> inorderTraversal(TreeNode* root) {
    if (root == nullptr) return {};
    std::vector<int> res;
    std::stack<TreeNode*> s;
    while (root != nullptr || !s.empty()) {
        if (root != nullptr) {
            s.push(root);
            root = root->left;
        }
        else {
            auto node = s.top();
            s.pop();
            res.emplace_back(node->val);
            root = node->right;
        }
    }
    return res;
}

// Solution 3: Iteratively?
