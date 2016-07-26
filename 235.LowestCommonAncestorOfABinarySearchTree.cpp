/*
Given a binary search tree (BST), find the lowest common ancestor (LCA) of two given nodes in the BST.

According to the definition of LCA on Wikipedia: 
“The lowest common ancestor is defined between two nodes v and w as the lowest node in T that has both v and w as descendants 
(where we allow a node to be a descendant of itself).”

        _______6______
       /              \
    ___2__          ___8__
   /      \        /      \
   0      _4       7       9
         /  \
         3   5
For example, the lowest common ancestor (LCA) of nodes 2 and 8 is 6.
Another example is LCA of nodes 2 and 4 is 2, since a node can be a descendant of itself according to the LCA definition.
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
 
// Solution 1: recursive
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
{
    if (root == nullptr || p == nullptr || q == nullptr) return nullptr;
    
    if ((p->val < root->val && q->val > root->val)
     || (p->val > root->val && q->val < root->val))
        return root;
    else if (p->val < root->val && q->val < root->val)
        return lowestCommonAncestor(root->left, p, q);
    else if (p->val > root->val && q->val > root->val)
        return lowestCommonAncestor(root->right, p, q);
    else if (p->val == root->val)
        return p;
    else // if (q->val == root->val)
        return q;
}

// Solution 2: iterative
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
{
    if (root == nullptr || p == nullptr || q == nullptr) return nullptr;
    
    TreeNode* ancestor = root;
    while (ancestor != nullptr)
    {
        if ((ancestor == p || ancestor == q)
         || (ancestor->val > p->val && ancestor->val < q->val)
         || (ancestor->val < p->val && ancestor->val > q->val))
            break;
        
        if (ancestor->val < p->val && ancestor->val < q->val)
            ancestor = ancestor->right;
        else
            ancestor = ancestor->left;
    }
    return ancestor;
}
