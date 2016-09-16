/*
Given a binary tree, flatten it to a linked list in-place.

For example,
Given
         1
        / \
       2   5
      / \   \
     3   4   6
The flattened tree should look like:
   1
    \
     2
      \
       3
        \
         4
          \
           5
            \
             6
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
 
void flatten(TreeNode* root) {
    if (root == nullptr) return;
    
    std::stack<TreeNode*> S;
    S.push(root);
    TreeNode* prev = nullptr;
    while (!S.empty())
    {
        auto node = S.top();
        S.pop();
        
        if (node->right != nullptr)
            S.push(node->right);
        if (node->left != nullptr)
            S.push(node->left);
        
        node->left = nullptr; // single link list implementation; for double link list, just modify node->left = prev;
        if (prev != nullptr)
            prev->right = node;
        prev = node;
    }
}
