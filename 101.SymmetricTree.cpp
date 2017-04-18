/*
Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

For example, this binary tree [1,2,2,3,4,4,3] is symmetric:
    1
   / \
  2   2
 / \ / \
3  4 4  3
But the following [1,2,2,null,3,null,3] is not:
    1
   / \
  2   2
   \   \
   3    3

Note:
Bonus points if you could solve it both recursively and iteratively.
*/

bool isSymmetric(TreeNode* root) {
    if (root == nullptr) return true;
    
    std::function<bool(TreeNode*, TreeNode*)> helper = [&](TreeNode* left, TreeNode* right) {
        if (left == nullptr && right == nullptr) return true;
        if (left == nullptr && right != nullptr) return false;
        if (left != nullptr && right == nullptr) return false;
        if (left->val != right->val) return false;
        return helper(left->left, right->right) && helper(left->right, right->left);
    };
    
    return helper(root->left, root->right);
}
