/*
Given preorder and inorder traversal of a tree, construct the binary tree.

Note:
You may assume that duplicates do not exist in the tree.
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
TreeNode* buildTree(std::vector<int>& preorder, std::vector<int>& inorder)
{
    if (preorder.size() != inorder.size()) return nullptr;
    
    std::function<TreeNode*(int, int, int, int)> helper = [&](int from1, int to1, int from2, int to2) -> TreeNode*
    {
        if (from1 > to1 || from2 > to2) return nullptr;
        
        int val = preorder[from1];
        auto node = new TreeNode(val);
        
        int i = from2;
        for (; i <= to2; ++i)
        {
            if (inorder[i] == val)
                break;
        }

        node->left = helper(from1+1, from1 + i - from2, from2, i - 1);
        node->right = helper(from1 + i - from2 + 1, to1, i+1, to2);
        
        return node;
    };
    
    auto root = helper(0, (int)preorder.size()-1, 0, (int)inorder.size()-1);
    
    return root;
}
