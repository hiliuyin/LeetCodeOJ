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

// Solution 1: recursion
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

// Solution 2: iteration
bool isSymmetric(TreeNode* root) {
    if (root == nullptr) return true;
    std::queue<TreeNode*> q1, q2;
    q1.push(root->left);
    q2.push(root->right);
    while (!q1.empty() && !q2.empty()) {
        auto left = q1.front();
        q1.pop();
        auto right = q2.front();
        q2.pop();
        
        if (left == nullptr && right == nullptr) continue;
        if (left == nullptr || right == nullptr) return false;
        if (left->val != right->val) return false;
        q1.push(left->left);
        q1.push(left->right);
        q2.push(right->right);
        q2.push(right->left);
    }
    return true;
}
