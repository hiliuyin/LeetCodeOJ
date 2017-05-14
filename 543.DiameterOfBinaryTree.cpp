/*
Given a binary tree, you need to compute the length of the diameter of the tree. The diameter of a binary tree is the length of the longest path between any two nodes in a tree. This path may or may not pass through the root.

Example:
Given a binary tree 
          1
         / \
        2   3
       / \     
      4   5    
Return 3, which is the length of the path [4,2,1,3] or [5,2,1,3].

Note: The length of path between two nodes is represented by the number of edges between them.
*/

int diameterOfBinaryTree(TreeNode* root) {
    if (root == nullptr) return 0;

    std::function<int(TreeNode*)> maxDepth = [&](TreeNode* t) {
        if (t == nullptr) return 0;
        return std::max(maxDepth(t->left), maxDepth(t->right)) + 1;
    };
    
    return std::max(maxDepth(root->left) + maxDepth(root->right),
        std::max(diameterOfBinaryTree(root->left), diameterOfBinaryTree(root->right)));
}
