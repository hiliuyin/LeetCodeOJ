/*
Given a binary tree and a sum, determine if the tree has a root-to-leaf path such that adding up all the values along the path equals the given sum.

For example:
Given the below binary tree and sum = 22,
              5
             / \
            4   8
           /   / \
          11  13  4
         /  \      \
        7    2      1
return true, as there exist a root-to-leaf path 5->4->11->2 which sum is 22.
*/

bool hasPathSum(TreeNode* root, int sum) {
    if (root == nullptr) return false;
    if (root->left == nullptr && root->right == nullptr && root->val == sum) return true;
    return hasPathSum(root->left, sum - root->val) || hasPathSum(root->right, sum - root->val);
}

bool hasPathSum(TreeNode* root, int sum) {
    std::function<bool(TreeNode*, int)> helper = [&](TreeNode* node, int x) {
        if (node == nullptr) return false;
        if (node->left == nullptr && node->right == nullptr) return x + node->val == sum;
        return helper(node->left, x + node->val) || helper(node->right, x + node->val);
    };
    return helper(root, 0);
}
