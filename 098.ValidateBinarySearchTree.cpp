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
 
bool isValidBST(TreeNode* root)
{
    if (root == nullptr) return true;

    std::stack<TreeNode*> S;
    long long prevVal = (long long)INT_MIN - 1;
    while (root != nullptr || !S.empty())
    {
        while (root != nullptr)
        {
            S.push(root);
            root = root->left;
        }
        
        if (!S.empty())
        {
            auto node = S.top();
            S.pop();
            
            long long currVal = node->val;
            if (currVal <= prevVal)
                return false;
            
            prevVal = currVal;
            
            root = node->right;
        }
    }
    
    return true;
}
 
