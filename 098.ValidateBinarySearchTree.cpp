/*
Given a binary tree, determine if it is a valid binary search tree (BST).

Assume a BST is defined as follows:
The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.

Example 1:
    2
   / \
  1   3
Binary tree [2,1,3], return true.
Example 2:
    1
   / \
  2   3
Binary tree [1,2,3], return false.
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
 
{
    if (root == nullptr) return true;
    
    std::stack<TreeNode*> S;
    TreeNode *prev = nullptr;
    while (root != nullptr || !S.empty())
    {
        while (root != nullptr)
        {
            S.push(root);
            root = root->left;
        }
        
        if (!S.empty())
        {
            auto curr = S.top();
            S.pop();
            
            if (prev != nullptr && prev->val >= curr->val)
                return false;
            
            prev = curr;
            
            root = curr->right;
        }
    }
    
    return true;
}

 
