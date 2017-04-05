/*
Invert a binary tree.
     4
   /   \
  2     7
 / \   / \
1   3 6   9
to
     4
   /   \
  7     2
 / \   / \
9   6 3   1
*/

// Solution 1: recursive
TreeNode* invertTree(TreeNode* root)
{
    if (root == nullptr) return nullptr;

    std::swap(root->left, root->right);
    if (root->left == nullptr)
        invertTree(root->right);
    else if (root->right == nullptr)
        invertTree(root->left);
    else
    {
        invertTree(root->left);
        invertTree(root->right);
    }
    
    return root;
}

// A more simple method
TreeNode* invertTree(TreeNode* root) {
    if (root != nullptr) {
        invertTree(root->left);
        invertTree(root->right);
        std::swap(root->left, root->right);
    }
    
    return root;
}

// Solution 2: iteration
TreeNode* invertTree(TreeNode* root)
{
    if (root == nullptr) return nullptr;
    
    std::stack<TreeNode*> S;
    S.push(root);
    
    while (!S.empty())
    {
        auto node = S.top();
        S.pop();
        
        std::swap(node->left, node->right);
        if (node->left != nullptr)
            S.push(node->left);
        if (node->right != nullptr)
            S.push(node->right);
    }

    return root;
}
