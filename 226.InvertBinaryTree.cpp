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
    if (root->left == nullptr) {
        invertTree(root->right);
    }
    else if (root->right == nullptr) {
        invertTree(root->left);
    }
    else {
        invertTree(root->left);
        invertTree(root->right);
    }
    
    return root;
}

// A more simple method
TreeNode* invertTree(TreeNode* root) {
    if (root != nullptr) {
        (void)invertTree(root->left);
        (void)invertTree(root->right);
        std::swap(root->left, root->right);
    }
    return root;
}

// Solution 2: iteration    
TreeNode* invertTree(TreeNode* root) {
    if (root == nullptr) return root;
    
    std::queue<TreeNode*> Q;
    Q.emplace(root);
    
    while (!Q.empty()) {
        auto node = Q.front();
        Q.pop();
        
        std::swap(node->left, node->right);
        if (node->left != nullptr) Q.emplace(node->left);
        if (node->right != nullptr) Q.emplace(node->right);
    }
    return root;
}
