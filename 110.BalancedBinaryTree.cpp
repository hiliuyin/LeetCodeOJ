/*
Given a binary tree, determine if it is height-balanced.

For this problem, a height-balanced binary tree is defined as a binary tree 
in which the depth of the two subtrees of every node never differ by more than 1.
*/

bool isBalanced(TreeNode* root)
{
    if (root == nullptr) return true;
    
    std::function<int(TreeNode*)> maxDepth = [&](TreeNode *root) -> int
    {
        if (root == nullptr)
            return 0;
        else
            return std::max(maxDepth(root->left), maxDepth(root->right))+1;
    };
    
    int delta = std::abs(maxDepth(root->left) - maxDepth(root->right));
    
    return isBalanced(root->left) && isBalanced(root->right) && delta <=1;
}
