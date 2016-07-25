/*
Given inorder and postorder traversal of a tree, construct the binary tree.

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
TreeNode* buildTree(std::vector<int>& inorder, std::vector<int>& postorder)
{
    if (inorder.size() != postorder.size()) return nullptr;
    
    std::function<TreeNode*(int, int, int, int)> helper = [&](int from1, int to1, int from2, int to2) -> TreeNode*
    {
        if (from1 > to1 || from2 > to2) return nullptr;
        
        int val = postorder[to2];
        auto node = new TreeNode(val);
        
        int i = from1;
        for (; i <= to1; ++i)
        {
            if (inorder[i] == val)
                break;
        }
        
        node->left = helper(from1, i-1, from2, from2+i-from1-1);
        node->right = helper(i+1, to1, from2+i-from1, to2-1);
        
        return node;
    };
    
    auto root = helper(0, (int)inorder.size()-1, 0, (int)inorder.size()-1);
    return root;
}
