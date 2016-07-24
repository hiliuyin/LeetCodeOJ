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

TreeNode* invertTree(TreeNode* root)
{
    if (root == nullptr) return nullptr;
    
    if (root->left == nullptr && root->right == nullptr)
    {
        return root;
    }
    else if (root->left == nullptr)
    {
        root->left = root->right;
        root->right = nullptr;
        invertTree(root->left);
    }
    else if (root->right == nullptr)
    {
        root->right = root->left;
        root->left = nullptr;
        invertTree(root->right);
    }
    else
    {
        auto tmp = root->left;
        root->left = root->right;
        root->right = tmp;
        invertTree(root->left);
        invertTree(root->right);
    }

    return root;
}
