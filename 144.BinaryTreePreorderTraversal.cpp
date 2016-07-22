/*
Given a binary tree, return the preorder traversal of its nodes' values.
For example:
Given binary tree {1,#,2,3},
   1
    \
     2
    /
   3
return [1,2,3].
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

std::vector<int> preorderTraversal(TreeNode* root)
{
    std::vector<int> result;
    std::stack<TreeNode*> S;
    
    auto p = root;
    while (p != nullptr || !S.empty())
    {
        while (p != nullptr)
        {
            result.emplace_back(p->val);
            S.push(p);
            p = p->left;
        }
        
        if (!S.empty())
        {
            auto node = S.top();
            S.pop();
            
            p = node->right;
        }
    }
    
    return result;
}
